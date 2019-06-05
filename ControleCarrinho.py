#!/usr/bin/python
import rospy
import RPi.GPIO as GPIO
import time

Stop = 0
#V controla o motor
#Z controla a polaridade
PIN_DIR_V = 40
PIN_DIR_Z = 38
PIN_ESQ_V = 36
PIN_ESQ_Z = 32

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(PIN_DIR_V,GPIO.OUT)
GPIO.setup(PIN_DIR_Z,GPIO.OUT)
GPIO.setup(PIN_ESQ_V,GPIO.OUT)
GPIO.setup(PIN_ESQ_Z,GPIO.OUT)

controleMotorDir = GPIO.PWM(PIN_DIR_V,100)
controlePolaridadeDir = GPIO.PWM(PIN_DIR_Z,100)
controleMotorEsq = GPIO.PWM(PIN_ESQ_V,100)
controlePolaridadeEsq = GPIO.PWM(PIN_ESQ_Z,100)

controleMotorDir.start(0)
controleMotorEsq.start(0)
controlePolaridadeDir.start(0)
controlePolaridadeEsq.start(0)

def goAhead():
    cicloMotor = 93
    while True:
        controleMotorEsq.changeDutyCycle(cicloMotor)
        controleMotorDir.ChangeDutyCycle(ciclomotor)
        print ("Potencia: {0}".format(cicloMotor))
        time.sleep(0.4)
        cicloMotor = cicloMotor + 1
        if(cicloMotor == 96):
            break
        
def stopRobot():
    controleMotorDir.changeDutyCycle(Stop)
    controleMotorEsq.changeDutyCycle(Stop)
    print ("Potencia: {0}".format(cicloMotor))
    time.sleep(0.4)

def goRight():
    cicloMotor = 93
    while True:
        controleMotorDir.ChangeDutyCycle(Stop)
        controleMotorEsq.changeDutyCycle(cicloMotor)
        print ("Potencia: {0}".format(cicloMotor))
        time.sleep(0.4)
        cicloMotor = cicloMotor + 1
        if(cicloMotor == 96):
            break

def goLeft():
    cicloMotor = 93
    while True:
        controleMotorDir.ChangeDutyCycle(cicloMotor)
        controleMotorEsq.changeDutyCycle(Stop)
        print ("Potencia: {0}".format(cicloMotor))
        time.sleep(0.4)
        cicloMotor = cicloMotor + 1
        if(cicloMotor == 96):
            break

goAhead()
goLeft()
goRight()
