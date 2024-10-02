import turtle as t
import colorsys as cs

t.tracer(2)
t.bgcolor("black")
t.pensize(2)
n=100
h=0
for i in range(1000):
    for i in range(4):
        c=cs.hsv_to_rgb(h,1,1)
        h+=1/n
        t.color(c)
        t.circle(49+i*5,90)
        t.forward(100)
        t.left(90)
    t.right(10)
t.done()