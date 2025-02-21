import serial
import time

# Connect to Arduino (update COM port accordingly)
arduino = serial.Serial('COM3', 9600)
time.sleep(2)  # Allow connection to establish

# Function to send command to Arduino
def send_command(joint, angle):
    command = f"{joint} {angle}\n"
    arduino.write(command.encode())
    print(f"Sent: {command.strip()}")
    time.sleep(1)

# Example usage
try:
    while True:
        print("\nEnter command to move the robotic arm:")
        print("Options: BASE, SHOULDER, ELBOW, GRIPPER")
        joint = input("Enter joint name: ").upper()
        if joint not in ['BASE', 'SHOULDER', 'ELBOW', 'GRIPPER']:
            print("Invalid joint. Try again.")
            continue

        angle = input("Enter angle (0 to 180): ")
        if not angle.isdigit() or not (0 <= int(angle) <= 180):
            print("Invalid angle. Enter a value between 0 and 180.")
            continue

        send_command(joint, angle)

except KeyboardInterrupt:
    print("\nExiting program.")
    arduino.close()
