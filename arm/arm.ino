#include <Servo.h>

// Define servo objects
Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo gripperServo;

void setup() {
  Serial.begin(9600);  // Start serial communication

  // Attach servos to pins
  baseServo.attach(9);
  shoulderServo.attach(10);
  elbowServo.attach(11);
  gripperServo.attach(12);

  // Set initial positions
  baseServo.write(90);
  shoulderServo.write(90);
  elbowServo.write(90);
  gripperServo.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command.startsWith("BASE")) {
      int angle = command.substring(5).toInt();
      baseServo.write(angle);
      Serial.println("Base moved to " + String(angle) + " degrees");
    }

    else if (command.startsWith("SHOULDER")) {
      int angle = command.substring(9).toInt();
      shoulderServo.write(angle);
      Serial.println("Shoulder moved to " + String(angle) + " degrees");
    }

    else if (command.startsWith("ELBOW")) {
      int angle = command.substring(6).toInt();
      elbowServo.write(angle);
      Serial.println("Elbow moved to " + String(angle) + " degrees");
    }

    else if (command.startsWith("GRIPPER")) {
      int angle = command.substring(8).toInt();
      gripperServo.write(angle);
      Serial.println("Gripper moved to " + String(angle) + " degrees");
    }

    else {
      Serial.println("Invalid command. Use BASE, SHOULDER, ELBOW, or GRIPPER followed by angle.");
    }
  }
}
