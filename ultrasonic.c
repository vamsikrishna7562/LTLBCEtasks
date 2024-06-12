const int trigPin = 4;  // GPIO pin for the ultrasonic sensor trigger
const int echoPin = 5;  // GPIO pin for the ultrasonic sensor echo
const int ledPin = 2;   // GPIO pin for the LED

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  // Send a short pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo signal to calculate the distance
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;  // Calculate the distance in cm
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Glow the LED based on the distance
  if (distance < 20) {
    analogWrite(ledPin, 255); // Glow the LED at full brightness
  } else {
    analogWrite(ledPin, 0); // Turn off the LED
  }
  
  delay(100); // Wait for 0.1 seconds before taking the next reading
}