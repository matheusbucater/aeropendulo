#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define POT_PIN A0

#define PIN_IN1 5
#define PIN_IN2 6

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

int pwm;

void setup()
{
  potVal = 0;
  pwm = 80;

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

  Serial.println("Time;Theta");

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

  for (;;)
  {
    potVal = (analogRead(POT_PIN) - 497) / 4;

    motor_forward(motor, pwm);

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      Serial.print(pdTICKS_TO_MS( xTaskGetTickCount() ));
      Serial.print(";");
      Serial.println(potVal);

      xSemaphoreGive( xSerialSemaphore );
    }

    vTaskDelay(1);
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
