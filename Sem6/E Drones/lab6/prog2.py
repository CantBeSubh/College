
import time
from dronekit import connect, VehicleMode, LocationGlobalRelative

# Connect to the PX4 vehicle
connection_string = 'udp:127.0.0.1:14550'
vehicle = connect(connection_string, wait_ready=True)

# Set the vehicle mode to GUIDED
vehicle.mode = VehicleMode("GUIDED")

# Arm the vehicle
vehicle.armed = True
while not vehicle.armed:
    print("Waiting for vehicle to arm...")
    time.sleep(1)

# Define the mission waypoints
waypoints = [
    LocationGlobalRelative(-35.363261, 149.165230, 10),
    LocationGlobalRelative(-35.362933, 149.164652, 10),
    LocationGlobalRelative(-35.363275, 149.164340, 10),
    LocationGlobalRelative(-35.363700, 149.164889, 10)
]
# Move to each waypoint in turn with a fixed altitude of 20 meters
for waypoint in waypoints:
    # Set the target waypoint with a fixed altitude of 20 meters
    target_altitude = 20
    target_location = LocationGlobalRelative(waypoint.lat, waypoint.lon, target_altitude)
    vehicle.simple_goto(target_location)

    # Wait for the vehicle to reach the waypoint
    while True:
        current_pos = vehicle.location.global_relative_frame
        dist = current_pos.distance_to(target_location)
        if dist < 1:
            break
        time.sleep(1)

# Set the vehicle mode to RTL (Return to Launch)
vehicle.mode = VehicleMode("RTL")

# Wait for the vehicle to return to the launch point and land
while vehicle.armed:
    print("Waiting for vehicle to land...")
    time.sleep(1)

# Disconnect from the vehicle
vehicle.close()
