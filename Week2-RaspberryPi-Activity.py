##Jaiya Morphet - morphetj- 400173769
##Zofia Olejarz - olejarzz - 400172238
##Victoria Ng - ngv1 - 400203337
##Christian Hsu - hsuc13 - 400210638



from gpiozero import DistanceSensor
from gpiozero import LED
from time import sleep
import robot_helper

def milestone_one():
    red_led = LED(20)
    green_led = LED(21)
    ultrasonic = DistanceSensor (echo = 19, trigger = 16)
    red_led.off()
    green_led.off()

    while True:
        distance = ultrasonic.distance*100
        print("Distance: ", distance)

        if distance > 25.0:
            green_led.on()
            red_led.off()

        elif distance <= 25 and distance > 15:
            green_led.off()
            red_led.on()

        elif distance <= 15:
            green_led.off()
            red_led.on()
            sleep(1)
            red_led.off()
            sleep(1)

        sleep(0.1)

def milestone_two(fwd, bkwd):
    from gpiozero import PololuDRV8835Robot
    from time import sleep
    
    robot = PololuDRV8835Robot()
    robot.forward(0.5)
    sleep(fwd)
    robot.stop()

    robot.backward(0.2)
    sleep(bkwd)
    robot.stop()

def milestone_three():
    from gpiozero import PololuDRV8835Robot
    from time import sleep
    from gpiozero import DistanceSensor

    robot = PololuDRV8835Robot()
    ultrasonic = DistanceSensor (echo = 19, trigger = 16)

    while True:
        distance = ultrasonic.distance*100

        if distance > 30.0:
            robot.forward(0.3)
        elif distance <= 30.0:
            robot.left(0.5)
            sleep(1.1)
            
        
    
    
def main():
    choice = input("Please choose which milestone you would like to run (1 , 2, or 3): ")
    if choice == "1":
        milestone_one()
    elif choice == "2":
        fwd = int(input("Please enter how long you would like to move the robot forward in seconds? "))
        bkwd = int(input("Please enter how long you would like to move the robot backward in seconds? "))
        robot_helper.run(milestone_two, (fwd, bkwd))
    elif choice == "3":
        robot_helper.run(milestone_three)
    else:
        print("Invalid choice!")

main()


##Q1. The given distance would change from <= 15 to <= 5 and the frequency of
##flashing would be changed by making the sleep between on and off reduced to
##increase the number of flashes per second.

##Q2. The pins are already fixed so we do not need to specify them.

##Q3. By inputting a parameter of 0.5 into the control of forward and backward
##for the robot, the speed would be at 50%.

##Q4. The speed needs to be slowed so that the ultrasonic sensor has time to
##collect information and properly evaluate the distance. If the speed was too
## high, there would not be enough time for the robot to know to make a turn.
## At 30% speed, the robot would be slower and have more time to know to turn.

##Q5. Our robot did not quite meet the objective. We found that it was rather
## inaccurate with when to make a turn. This could be verified by measuring
##out the 30cm and marking it with tape, then watching to see if the robot
## follows what is marked down.

##Q6. Make a loop so that if the distance is less than 80, continue turning,
##and if it is greater than 80 then break or stop.




