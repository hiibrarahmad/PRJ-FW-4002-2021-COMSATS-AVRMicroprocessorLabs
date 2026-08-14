#include <Arduino.h>

#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int numRows = 2; // Change this to match the number of rows on your LCD
int numCols = 16; // Change this to match the number of columns on your LCD

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(numCols, numRows);
}

void loop() {
  // Print numbers on the LCD
  for (int i = 0; i < 10; i++) {
    
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print("Hello World"); // Print a label
    lcd.setCursor(0, 1); // Set the cursor to the first column of the second row
    lcd.print(i); // Print the number
    delay(1000); // Wait for 1 second
  }
}
