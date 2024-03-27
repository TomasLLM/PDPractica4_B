#include <Arduino.h>
TaskHandle_t Tasca1;
TaskHandle_t Tasca2;
TaskHandle_t Tasca3;
const double Ptr = 34;
const int led1 = 32;
const int led2 = 25;

void CodiTasca1(void*parameter){
  Serial.print("La tasca 1 està corrent al core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led1, HIGH);
    vTaskDelay(500);
    digitalWrite(led1, LOW);
    vTaskDelay(500);
  } 
}

void CodiTasca2(void*parameter){
  Serial.print("La tasca 2 està corrent al core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(led2, HIGH);
    vTaskDelay(1000);
    digitalWrite(led2, LOW);
    vTaskDelay(1000);
  }
}

void CodiTasca3(void*parameter){
  Serial.print("La tasca 3 està corrent al core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    double test = analogRead(Ptr);
    Serial.print("El valor del voltatge es ");
    Serial.println(test);
    vTaskDelay(1000);
  }
}

void setup(){
  Serial.begin(115200); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  xTaskCreatePinnedToCore(CodiTasca1,"Tasca1",10000,NULL,1,&Tasca1,0);                         
  vTaskDelay(500); 
  xTaskCreatePinnedToCore(CodiTasca2,"Tasca2",10000,NULL,1,&Tasca2,1);          
  vTaskDelay(500); 
  xTaskCreatePinnedToCore(CodiTasca3,"Tasca3",10000,NULL,1,&Tasca3,1);          
  vTaskDelay(5000); 
}
