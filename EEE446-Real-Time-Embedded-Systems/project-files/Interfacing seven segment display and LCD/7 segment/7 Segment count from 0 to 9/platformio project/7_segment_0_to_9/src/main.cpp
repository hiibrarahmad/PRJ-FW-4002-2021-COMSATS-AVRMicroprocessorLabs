#include <Arduino.h>

// Define the pins that will be used to control the segments of the 7-segment display
int segment_a = 2;
int segment_b = 3;
int segment_c = 4;
int segment_d = 5;
int segment_e = 6;
int segment_f = 7;
int segment_g = 8;

// Define an array of 7-segment codes for each digit from 0 to 9
int segments[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayDigit(int digit) {
  // Set each segment of the 7-segment display according to the 7-segment code for the given digit
  digitalWrite(segment_a, segments[digit][0]);
  digitalWrite(segment_b, segments[digit][1]);
  digitalWrite(segment_c, segments[digit][2]);
  digitalWrite(segment_d, segments[digit][3]);
  digitalWrite(segment_e, segments[digit][4]);
  digitalWrite(segment_f, segments[digit][5]);
  digitalWrite(segment_g, segments[digit][6]);
}

void setup() {
  // Set the pins that control the segments of the 7-segment display as output pins
  pinMode(segment_a, OUTPUT);
  pinMode(segment_b, OUTPUT);
  pinMode(segment_c, OUTPUT);
  pinMode(segment_d, OUTPUT);
  pinMode(segment_e, OUTPUT);
  pinMode(segment_f, OUTPUT);
  pinMode(segment_g, OUTPUT);
}

void loop() {
  // Loop through each digit from 0 to 9
  for (int i = 0; i < 10; i++) {
    // Display the current digit on the 7-segment display
    displayDigit(i);
    // Wait for 1 second before displaying the next digit
    delay(1000);
  }
}
