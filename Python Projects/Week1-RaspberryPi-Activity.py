'''
Jaiya Morphet - morphetj- 400173769
Zofia Olejarz - olejarzz - 400172238
Victoria Ng - ngv1 - 400203337
Christian Hsu - hsuc13 - 400210638
'''




from gpiozero import LED
from gpiozero import Button
import time

def milestone_one():
        while True: 
            choice = input('Input ON or OFF or Q: ')
            if choice == 'ON':
                print('Turning the light on')
            elif choice == 'OFF':
                print('Turning the light off')
            elif choice == 'Q':
                print('Goodbye')

                break
            else:
                print('Invalid Input. Please try again')

def milestone_two():
    light = LED(20)
    push = Button(21)
    led = False
    light.off()
    while True:
        if push.is_pressed == True:
            if led == True:
                light.off()
                led = False
            elif led == False:
                light.on()
                led = True
            time.sleep(0.3)
                

    
def main():
    select = input('What milestone would you like to run?')
    if select == '1':
        milestone_one()
    elif select == '2':
        milestone_two()
        
            
main()

'''Reflective Questions 
1. No it wouldn't run as intended if the user put lowercase keystrokes because we only
identified capital letters. Instead, our if statement could include all the possible ON
combinations with different cases.

2. We could add additional while loops within the while True loop if the light is on and ON
is selected, it will print that it is already on. If the light is off, it will print that it
is already off. 

3. It is necessary to include the 0.3 seconds to allow the user time to release their finger
from the button without it turning on and off.

4. Add time (3) turn.off inside another elif statement with push.is_pressed == False
when light.on().

5. Change to LED(18) and led = True with light.on().'''




    
