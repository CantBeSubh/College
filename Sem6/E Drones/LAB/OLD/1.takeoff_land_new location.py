######## Program to take off the drone and land in new location:

from dronekit import connect, VehicleMode, LocationGlobalRelative
import time

# Connect to the vehicle
vehicle = connect('udp:127.0.0.1:14550')

# Arm and take off
vehicle.mode = VehicleMode("GUIDED")
vehicle.armed = True
vehicle.simple_takeoff(10)

# Wait for the drone to reach a certain altitude
while True:
    altitude = vehicle.location.global_relative_frame.alt
    if altitude >= 9.5:  # target altitude - 0.5 meters
        break
    time.sleep(1)

# Move the drone to a new location
new_location = LocationGlobalRelative(37.793105, -122.398768, 20)
vehicle.simple_goto(new_location)

# Wait for the drone to reach the new location
while True:
    distance = vehicle.location.global_relative_frame.distance_to(new_location)
    if distance <= 1:  # target radius in meters
        break
    time.sleep(1)

# Land the drone
vehicle.mode = VehicleMode("LAND")

# Close the connection
vehicle.close()
