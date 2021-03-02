#Author:Christian Hsu
import math #Math function imported for use in programs.
def subprogram1(bodyWeight,canalDiameter,canalOffset,ultTenStrength):#Defining subprogram one with 4 variables passed as arguments
    stemdia=canalDiameter
    appTenStress=0
    while appTenStress<ultTenStrength:#A loop that checks if appTenStress of an implant at a set diameter is less than the UTS of material
        appTenStress=(4*bodyWeight*3.5*(8*canalOffset-stemdia))/(math.pi*stemdia**3)#Calculation of appTenStress
        if appTenStress<ultTenStrength:#If appTenStress is lower than reduce stem diameter used in calculation by 0.0001
            stemdia-=0.0001
        elif appTenStress>ultTenStrength:#When UTS is larger set the minStemDia to the diameter used in calculation
            minStemDia=stemdia
    print ("\nBodyweight is:",round(bodyWeight,4),"N")#Series of print statements with values rounded for accuracy.
    print ("Canal Diamter is:",round(canalDiameter,4),"mm")
    print ("Ultimate Tensile Strength of Implant is",round(ultTenStrength,4),"MPa")
    print ("Minimum Stem Diameter of Implant is",round(minStemDia,4),"mm")
    print ("Tensile Stress with this diameter is",round(appTenStress,4),"N\n")
            
    
def subprogram2(bodyWeight,stemDia,teamNumber):
    csa=((stemDia/2)**2*math.pi)/4#Calculations of cross section area
    stressampmax=(10*bodyWeight)/csa#Calculates stress amplitude max and min
    stressampmin=(-10*bodyWeight)/csa
    stressamp=(stressampmax-stressampmin)/2#Calculates stress amplitude
    file=open('SN Data - Sample Metal.txt','r')#Open file for reading
    Input=file.readlines()#Reading and closing the file
    file.close()
    sampledata=[]#Initializes a list to store data
    for line in Input:#Loop that takes the data and splits the values for usage and puts them into new list
        split_data=line.split()
        split_float=[float(split_data[0]), float(split_data[1])]
        sampledata.append(split_float)
    for i in range(len(sampledata)):#Loop that takes the second value of the data and calculates for K
        k=6+math.log(sampledata[i][1],10)**(teamNumber/30)#Calculations for k and adjusted stress value
        adjustedstress=k*stressamp
        if adjustedstress>sampledata[i][0]:#If adjusted stresss is bigger than the corresponding stress value from data sets variables to those values and breaks out of for loop
            stressFail=adjustedstress
            cyclesFail=sampledata[i][1]
            break
        else:#Else statement used incase no failure
            stressFail=0
            cyclesFail=0
    if stressFail!=0 and cyclesFail!=0:#Depending on results prints statements with values
        print ("\nNumber of cycles at which failure to fatigue is expected to occur=",cyclesFail)
        print ("Maximum stress amplitude at which failure occurs=",round(stressFail,2),"MPA\n")
    else:
        print ("\nImplant will not fail under applied cyclical load\n")

def subprogram3(bodyWeight,outerDia,canalDiameter,modulusBone,modulusImplant):#Defines subprogram 3 with 5 variables passed as arguments
    compStrength=(30*bodyWeight*4)/(math.pi*(outerDia**2-canalDiameter**2))#Calculates compStrength and the corresponding stressReduc
    stressReduc=compStrength*math.sqrt((2*modulusBone)/(modulusBone+modulusImplant))
    Eratio=math.sqrt(modulusImplant/modulusBone)#Calculates the Eratio
    yrsfail=1
    stressFail=181.72
    while stressReduc<stressFail:#Checks when stressReduc is less than stressFail
        stressFail=0.001*yrsfail**2-3.437*yrsfail*Eratio+181.72#Calculates stressfail and adds another year to yrsfail
        if stressFail<stressReduc:#If stressFail is lower than StressReduc than prints the year and stress at which it occurs
            print ("\nYears after implantation before there is a risk of femoral fracture:",round(yrsfail,2))
            print ("The stress on the bone after",round(yrsfail,2),"years is",round(stressFail,2),'\n')
        yrsfail+=1
            
        
def main():#Defining main function with no arguments
    choice=0#Variables are initialized for use throughout the program
    teamNumber=7.0
    bodyWeight=72*9.8
    outerDia=32.0
    canalDiameter=17.0
    canalOffset=40.0
    modulusBone=18.6#J.Y. Rho,R.B. Ashman,C.H Turner,"Young's Modulus of Trabecular and Cortical Bone Material:Ultrasonic and Microtensile Measurements",US National Library of Medicine National Institutes of Health,1993[Online].Availaible: https://www.ncbi.nlm.nih.gov/pubmed/8429054.[Accessed:04-Dec-2018]
    ultTenStrength=1000.0#Titanium
    modulusImplant=110.0#Titanium
    stemDia=16
    while choice!='4':#A while loop for the choice menu. Runs while choice is not 4 therefore any errors are accounted for as well
        choice=input("\nChoose a Number\n1.Subprogram 1\n2.Subprogram 2\n3.Subprogram 3\n4.Exit\n")#Takes user input
        if choice=='1':
            subprogram1(bodyWeight,canalDiameter,canalOffset,ultTenStrength)#Runs subprogram 1
        elif choice=='2':
            subprogram2(bodyWeight,stemDia,teamNumber)#Runs subprogram 2
        elif choice=='3':
            subprogram3(bodyWeight,outerDia,canalDiameter,modulusBone,modulusImplant)#Runs subprogram 3
        elif choice=='4':
            break
        elif choice!='4':
            print("\nInvalid Option\n")

main()#Run main function
