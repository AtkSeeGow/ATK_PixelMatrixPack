#include <M5StickCPlus.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include <esp_bt.h>

hw_timer_t *timer = NULL;
portMUX_TYPE timerMux       = portMUX_INITIALIZER_UNLOCKED;
volatile uint8_t TimerCount = 0;

void IRAM_ATTR onTimer() {
    portENTER_CRITICAL_ISR(&timerMux);
    digitalWrite(10, TimerCount % 100);
    TimerCount++;
    portEXIT_CRITICAL_ISR(&timerMux);
}

void setup()
{
  pinMode(10, OUTPUT);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 50000, true);
  timerAlarmEnable(timer);

 
  M5.begin();
  M5.Axp.ScreenBreath(200);
}

void loop()
{
  float voltage = M5.Axp.GetBatVoltage();
  float current = M5.Axp.GetBatCurrent();
  float power = voltage * current;
  
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("Voltage: %.2fV", voltage);
  
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.printf("Current: %.2fmA", current);
  
  M5.Lcd.setCursor(0, 40);
  M5.Lcd.printf("Power: %.2fmW", power);
  
  delay(1000);
}