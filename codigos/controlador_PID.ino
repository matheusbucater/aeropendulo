#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define POT_PIN A0

#define PIN_IN1 5
#define PIN_IN2 6

// #define SUM_EK_LIMIT 1000.0 // Limit for integral windup

// -------------- MOTOR DRIVE --------------
typedef struct {
  int in1;
  int in2;
} t_motor;

t_motor motor_init(int in1, int in2);
void motor_forward(t_motor m, double speed);
void motor_brake(t_motor m);
// -----------------------------------------

void TaskControlPendulum( void *pvParameters );

SemaphoreHandle_t xSerialSemaphore;

double potVal;
t_motor motor;

double K_P, K_I, K_D;
double theta_barra;
double ek, ekm1, sum_ek;

void setup()
{
  K_P = 0.05; K_I = 0.1; K_D = 0.5;
  theta_barra = radians(40);
  potVal = 0; ek = 0; ekm1 = 0; sum_ek = 0;

  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);

  motor = motor_init(PIN_IN1, PIN_IN2);
  motor_brake(motor);

  Serial.begin(9600);
  while (!Serial) { }

  if ( xSerialSemaphore == NULL )
  {
    xSerialSemaphore = xSemaphoreCreateMutex();
    if ( ( xSerialSemaphore ) != NULL ) xSemaphoreGive(xSerialSemaphore);
  }

  // Serial.println("Time;Theta;PWM");

  xTaskCreate(
    TaskControlPendulum, // Subroutine
    "ControlPendulum",   // Name
    256,                 // Stack size
    NULL,                // Parameters
    1,                   // Priority
    NULL                 // Task Handle
  );
}

void loop() {}

void TaskControlPendulum(void *pvParameters __attribute__((unused)))
{
  TickType_t xLastWakeTime = xTaskGetTickCount();

  for (;;)
  {
    potVal = radians((analogRead( POT_PIN ) - 497) / 4);

    ek = theta_barra - potVal;
    sum_ek += ek;
    double Ts = pdTICKS_TO_MS( 1 );

    double u_P = K_P * ek;
    double u_I = K_I * sum_ek * Ts;
    double u_D = K_D * (ek - ekm1) / Ts;
    ekm1 = ek;

    double u = u_P + u_I + u_D;
    motor_forward(motor, u);

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      Serial.print("theta_barra:");
      Serial.print(theta_barra * 180 / 3.14159265);
      Serial.print(",");
      Serial.print("theta:");
      Serial.println(potVal* 180 / 3.14159265);

      // Serial.print(pdTICKS_TO_MS( xTaskGetTickCount() ));
      // Serial.print(";");
      // Serial.print(potVal);
      // Serial.print(";");
      // Serial.println(u);

      xSemaphoreGive( xSerialSemaphore );
    }

    vTaskDelay( 1 );
  }
}

t_motor motor_init(int in1, int in2)
{
  t_motor motor = { in1, in2 };
  return motor;
}
void motor_forward(t_motor m, double speed)
{
  analogWrite(m.in1, speed);
  digitalWrite(m.in2, LOW);
}
void motor_brake(t_motor m)
{
  digitalWrite(m.in1, LOW);
  digitalWrite(m.in2, LOW);
}
