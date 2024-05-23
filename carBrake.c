#include <Servo.h>

Servo esc; // create servo object to control the ESC

const int escPin = 9;       // PWM pin connected to the ESC
const int interruptPin = 2; // Pin connected to the external interrupt

volatile bool brakeFlag = false; // Flag to indicate if braking is needed

void setup()
{
  esc.attach(escPin);                                                        // attaches the ESC to the PWM pin
  pinMode(interruptPin, INPUT_PULLUP);                                       // set the interrupt pin as input with internal pull-up resistor
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleBrake, RISING); // attach interrupt to the pin

  // Initial motor setup
  esc.writeMicroseconds(1500); // Neutral position (no motion)
  delay(1000);                 // Allow ESC to initialize
}

void loop()
{
  signal = pulseIn();
  if (brakeFlag)
  {
    // If brake flag is set, send brake signal
    esc.writeMicroseconds(1400); // Brake signal
    delay(500);                  // Brake for a short duration
    brakeFlag = false;           // Reset brake flag
  }
  else
  {
    esc.writeMicroseconds(signal); // Brake signal
    flag = 0;
  }
}

void handleBrake()
{
  if (flag == 0)
  {
    brakeFlag = true; // Set brake flag when interrupt occurs
    flag = 1;
  }
  else
  {
    brakeFlag = false;
  }
}
