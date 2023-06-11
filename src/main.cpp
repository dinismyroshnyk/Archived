#include <Arduino.h>

// --- Definitions ---
#define TMP_SENSOR A0
#define POT_LED A1
#define POT_TMP A2
#define SW1 2
#define SW2 3
#define LED_YELLOW 4
#define LED_RED 5
#define BUZZER 6
#define DISPLAY_A 7
#define DISPLAY_B 8
#define DISPLAY_C 9
#define DISPLAY_D 10
#define DISPLAY_E 11
#define DISPLAY_F 12
#define DISPLAY_G 13
#define DEBOUNCE_TIME 200

// --- Global variables ---
bool flag = false;

// --- Prototypes ---
void collect_tmp_sensor_data(float *min_temperature, float *max_temperature, float *sum_temperature);
void print_tmp_sensor_data(float *min_temperature, float *max_temperature, float *sum_temperature);
void blinking_led();
void warning_buzzer_led(float temperature);
void sw1_interrupt();
void display_number(int display_number);

// --- Main start ---
void setup() {
  Serial.begin(9600);
  for (int i = SW1; i <= SW2; i++) pinMode(i, INPUT_PULLUP);
  for (int i = LED_YELLOW; i <= DISPLAY_G; i++) pinMode(i, OUTPUT);
  display_number(0);
  attachInterrupt(digitalPinToInterrupt(SW1), sw1_interrupt, RISING);
}

void loop() {
  static float min_temperature = 100, max_temperature = 0, sum_temperature = 0;
  collect_tmp_sensor_data(&min_temperature, &max_temperature, &sum_temperature);
  print_tmp_sensor_data(&min_temperature, &max_temperature, &sum_temperature);
  blinking_led();
}
// --- Main end ---

// --- Functions ---

void collect_tmp_sensor_data(float *min_temperature, float *max_temperature, float *sum_temperature) {
  static unsigned long time = 0;
  float temperature = map(analogRead(TMP_SENSOR), 0, 1023, -1, 498); //LM35
  //float temperature = map(analogRead(TMP_SENSOR), 0, 1023, -49, 448); //TMP36
  if (millis() - time >= 15000) {
    if (temperature < *min_temperature) *min_temperature = temperature;
    if (temperature > *max_temperature) *max_temperature = temperature;
    *sum_temperature += temperature;
    time = millis();
    warning_buzzer_led(temperature);
  }
}

void print_tmp_sensor_data(float *min_temperature, float *max_temperature, float *sum_temperature) {
  static unsigned long time = 0;
  if (millis() - time >= 60000) {
    Serial.println("----------");
    Serial.print("Min: ");
    Serial.println(*min_temperature);
    Serial.print("Max: ");
    Serial.println(*max_temperature);
    Serial.print("Avg: ");
    Serial.println(*sum_temperature / 4);
    Serial.println("----------");
    *min_temperature = 100;
    *max_temperature = 0;
    *sum_temperature = 0;
    time = millis();
  }
}

void blinking_led() {
  static unsigned long time = 0;
  if (millis() - time >= map(analogRead(POT_LED), 0, 1023, 1000, 10000)) {
    digitalWrite(LED_YELLOW, !digitalRead(LED_YELLOW));
    time = millis();
  }
}

void warning_buzzer_led(float temperature) {
  static int counter = 0;
  if (flag) {
    counter = 0;
    flag = false;
  }
  if (temperature >= map(analogRead(POT_TMP), 0, 1023, 0, 50)) {
    digitalWrite(LED_RED, HIGH);
    tone(BUZZER, 1000, 5000);
    counter++;
    display_number(counter);
    if (counter >= 9) counter = -1;
  }
}

void sw1_interrupt() {
  if (digitalRead(LED_RED) == HIGH) digitalWrite(LED_RED, LOW);
  if (digitalRead(SW1) == LOW && digitalRead(SW2) == LOW) {
    flag = true;
    display_number(0);
  }
}

void display_number(int display_number) {
  static const byte NUMBERS[][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1 
  {1,1,0,1,1,0,1}, // 2 
  {1,1,1,1,0,0,1}, // 3  
  {0,1,1,0,0,1,1}, // 4  
  {1,0,1,1,0,1,1}, // 5 
  {1,0,1,1,1,1,1}, // 6 
  {1,1,1,0,0,0,0}, // 7   
  {1,1,1,1,1,1,1}, // 8  
  {1,1,1,1,0,1,1}  // 9  
  };
  for (int i = 0; i < 7; i++) digitalWrite(DISPLAY_A + i, NUMBERS[display_number][i]);
}