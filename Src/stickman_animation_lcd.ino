#include <LiquidCrystal_I2C.h> // calling LCD I2C library
LiquidCrystal_I2C lcd(0x27, 16, 2); // set I2C address and LCD size

// grid design on special character 1
byte PersonPose1[8] = {
  0b01110, // image byte on row 1
  0b01110, // image byte on row 2
  0b00100, // image byte on row 3
  0b00111, // image byte on row 4
  0b01100, // image byte on row 5
  0b10110, // image byte on row 6
  0b00101, // image byte on row 7
  0b11001 // image byte on row 8
};

// grid design on special character 2
byte PersonPose2[8] = {
  0b01110, // image byte on row 1
  0b01110, // image byte on row 2
  0b00100, // image byte on row 3
  0b10100, // image byte on row 4
  0b01110, // image byte on row 5
  0b00101, // image byte on row 6
  0b01010, // image byte on row 7
  0b10001 // image byte on row 8
};

// setup method
void setup() {
  Serial.begin(9600); // initiate serial communication at baudrate 9600
  startingLCD(); // calls the startingLCD method
}

// loop method
void loop(){
  stickmanRight(); // calls the stickmanRight method
  stickmanLeft(); // calls the stickmanLeft method
}

// method for starting the LCD
void startingLCD(){
  lcd.init(); // I2C LCD Initiation
  lcd.backlight(); // turn on the LCD backlight
  lcd.setCursor(4,0); // set the cursor on row 1, column 4
  lcd.print("Stick Man"); // print text -> Stick Man
  lcd.setCursor(4,1); // set the cursor on row 2, column 4
  lcd.print("Animation"); // print text -> Animation
  delay(10000); // delay time -> 10 second
  lcd.createChar(0, PersonPose1); // custom character initialization -> PersonPose1
  lcd.createChar(1, PersonPose2); // custom character initialization -> PersonPose2
}

// stick man moves towards the right
void stickmanRight(){
  for(int count = 0; count < 8; count++){ // count forward from column 1 -> column 8
    lcd.clear(); // erase text on the LCD screen
    if((count % 2) == 0) { // if the count is even:
      lcd.setCursor(count,0); // set the cursor on row 1
      lcd.write((byte)0); // display special characters -> PersonPose1
    } 
    else { // if the count is odd:
      lcd.setCursor(count,0); // set the cursor on row 1
      lcd.write((byte)1); // display special characters -> PersonPose2
    }
    delay(1000); // delay time -> 1 second
  }
  for(int count = 8; count <= 16; count++){ // count forward from column 8 -> column 16
    lcd.clear(); // erase text on the LCD screen
    if((count % 2) == 0) { // if the count is even:
      lcd.setCursor(count,1); // set the cursor on row 2
      lcd.write((byte)0); // display special characters -> PersonPose1
    } 
    else { // if the count is odd:
      lcd.setCursor(count,1); // set the cursor on row 2
      lcd.write((byte)1); // display special characters -> PersonPose2
    }
    delay(1000); // delay time -> 1 second
  } 
}

// stick man moves towards the left
void stickmanLeft(){
   for(int count = 16; count >= 8; count--){ // count down from column 16 -> column 8
    lcd.clear(); // erase text on the LCD screen
    if((count % 2) == 0) { // if the count is even:
      lcd.setCursor(count,0); // set the cursor on row 1
      lcd.write((byte)0); // display special characters -> PersonPose1
    } 
    else{ // if the count is odd:
      lcd.setCursor(count,0); // set the cursor on row 1
      lcd.write((byte)1); // display special characters -> PersonPose2
    }
    delay(1000); // delay time -> 1 second
  }
  for(int count = 7; count > -1; count--){ // count down from column 8 -> column 1
    lcd.clear(); // erase text on the LCD screen
    if((count % 2) == 0) { // if the count is even:
      lcd.setCursor(count,1); // set the cursor on row 2
      lcd.write((byte)0); // display special characters -> PersonPose1
    } 
    else{ // if the count is odd:
      lcd.setCursor(count,1); // set the cursor on row 2
      lcd.write((byte)1); // display special characters -> PersonPose2
    }
    delay(1000); // delay time -> 1 second
  }
}