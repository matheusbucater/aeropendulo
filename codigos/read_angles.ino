#include <Arduino_FreeRTOS.h>
#include <semphr.h>

SemaphoreHandle_t xSerialSemaphore;

void TaskAnalogRead( void *pvParameters );

void setup() {

  Serial.begin(9600);
  
  while (!Serial) { ; }

  Serial.println("Time;Theta");

  if ( xSerialSemaphore == NULL )
  {
    xSerialSemaphore = xSemaphoreCreateMutex();
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );
  }

  xTaskCreate(
    TaskAnalogRead,
    "AnalogRead"
    128,
    NULL,
    1,
    NULL
  );
}

void loop() { }

void TaskAnalogRead( void *pvParameters __attribute__((unused)) )
{

  for (;;)
  {
    float sensorValue = (analogRead(A0)-497) / 4;
    // int sensorValue = analogRead(A0);

    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      Serial.print(pdTICKS_TO_MS( xTaskGetTickCount() ));
      Serial.print(";");
      Serial.println(sensorValue);

      xSemaphoreGive( xSerialSemaphore );
    }

    vTaskDelay(1);
  }
}