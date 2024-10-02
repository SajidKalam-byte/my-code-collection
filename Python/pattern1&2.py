import math
from turtle import*
import turtle as t
import colorsys as cs

def hearta(k):
    return 15*math.sin(k)**3
def heartb(k):
    return 12*math.cos(k)-5*\
        math.cos(2*k)-2*\
            math.cos(3*k)-\
                math.cos(4*k)
speed(11111)
#bgcolor("black")
t.tracer(2)
t.bgcolor("black")
t.pensize(2)
n=100
h=0
for i in range(1000):
    goto(hearta(i)*20,heartb(i)*20)
    for j in range(4):
        color("red")
        c=cs.hsv_to_rgb(h,1,1)
        h+=1/n
        t.color(c)
        t.circle(49+i*5,90)
        t.forward(100)
        t.left(90)
    goto(0,0)
    t.right(10)
done()
t.done()
#______________#
