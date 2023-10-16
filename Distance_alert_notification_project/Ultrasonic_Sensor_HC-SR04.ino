// First declare variables for input, output and further calculations
const int trigPin = 9;
const int echoPin = 10;
float duration, distance;

// Setting up the program
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW); // Setting trigger pin to low first and wait for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Setting the trigger pin to high and start the output with 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); // Get the input back from soundwave

  distance = (duration*.0343)/2; // Calculating the distance in centimeters as it uses microseconds and divided by two as the sound goes to and fro

  // Setting the condition to get the alert
  if (distance <= 10) {
    Serial.println("Warning! Distance too close.");
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);  
  }
  else {
      Serial.print("Distance: ");
      Serial.println(distance);
      delay(100);
  }
}
