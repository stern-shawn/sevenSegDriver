int value = 0;
// pins 0-3 are data, 4 is ones place digit select, 5 is tens place select
int pins[] = {8, 9, 10, 11, 12, 13};

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  for(int i = 0; i < 6; i++) {
     pinMode(pins[i], OUTPUT);
  }

  // Avoid potential initial glitches
  digitalWrite(pins[4], LOW);
  digitalWrite(pins[5], LOW);
}

void loop() {
  // Get value
  /*if (value == 100) {
    value = 0;
  }*/
  value = random(0, 100);
  
  // Debug
  Serial.print("Value: ");
  Serial.println(value);
  
  // Print
  printToLED(value);
  //value++;
  delay(1000);
}

// Print the two-digit value to the pair of 7-seg LEDs
void printToLED(int input) {
  int ones = input % 10;
  int tens = input / 10;
  
  // Set pins high/low for the ones place digit, then enable the
  // respective 7-seg driver
  intToBin(ones);
  digitalWrite(pins[4], HIGH);
  
  // Disable both drivers before writing the tens place digit
  digitalWrite(pins[4], LOW);
  digitalWrite(pins[5], LOW);
  
  // Repeat for tens place!
  intToBin(tens);
  digitalWrite(pins[5], HIGH);
    
  digitalWrite(pins[4], LOW);
  digitalWrite(pins[5], LOW);
}

// Write the digit in binary
void intToBin(int input) {
  // Use bitshift and bitmasking to convert int to 4-bit binary
  for (int i = 0; i < 4; i++) {
    if (input >> i & 1) {
      digitalWrite(pins[i], HIGH);
    } else {
      digitalWrite(pins[i], LOW);
    }
  }
  
  /*
  switch(input) {
    case 0:
      digitalWrite(8, LOW);  
      digitalWrite(9, LOW);  
      digitalWrite(10, LOW);  
      digitalWrite(11, LOW);
      break;  
    case 1:
      digitalWrite(8, HIGH);  
      digitalWrite(9, LOW);  
      digitalWrite(10, LOW);  
      digitalWrite(11, LOW);
      break;  
    case 2:
      digitalWrite(8, LOW);  
      digitalWrite(9, HIGH);  
      digitalWrite(10, LOW);  
      digitalWrite(11, LOW);
      break;
    case 3:
      digitalWrite(8, HIGH);  
      digitalWrite(9, HIGH);  
      digitalWrite(10, LOW);  
      digitalWrite(11, LOW);
      break;  
    case 4:
      digitalWrite(8, LOW);  
      digitalWrite(9, LOW);  
      digitalWrite(10, HIGH);  
      digitalWrite(11, LOW);
      break;  
    case 5:
      digitalWrite(8, HIGH);  
      digitalWrite(9, LOW);  
      digitalWrite(10, HIGH);  
      digitalWrite(11, LOW);
      break;  
    case 6:
      digitalWrite(8, LOW);  
      digitalWrite(9, HIGH);  
      digitalWrite(10, HIGH);  
      digitalWrite(11, LOW);
      break;  
    case 7:
      digitalWrite(8, HIGH);  
      digitalWrite(9, HIGH);  
      digitalWrite(10, HIGH);  
      digitalWrite(11, LOW);
      break;  
    case 8:
      digitalWrite(8, LOW);  
      digitalWrite(9, LOW);  
      digitalWrite(10, LOW);  
      digitalWrite(11, HIGH);
      break;  
    case 9:
      digitalWrite(8, HIGH);  
      digitalWrite(9, LOW);  
      digitalWrite(10, LOW);  
      digitalWrite(11, HIGH);
      break;   
  }*/
}