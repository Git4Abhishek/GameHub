from turtle import Turtle, Screen
from paddle import Paddle
from ball import Ball
from scoreboard import Scoreboard
import time
screen = Screen()

screen.setup(width=700, height=600)
screen.bgcolor("black")
screen.title("Pong")
screen.tracer(0)

# Midline
midline = Turtle()
midline.goto(0, 292)
midline.color("white")
midline.pensize(3)
midline.setheading(270)
midline.hideturtle()
while midline.ycor() > -320:
    midline.forward(15)
    midline.penup()
    midline.forward(20)
    midline.pendown()

ball = Ball()

scoreboard = Scoreboard()

# scoreboard_r = Scoreboard()
# Right Paddle
paddle_r = Paddle()
paddle_r.goto(320, 0)
paddle_r.color("red")

# Left Paddle
paddle_l = Paddle()
paddle_l.goto(-320, 0)
paddle_l.color("blue")

screen.listen()
screen.onkey(paddle_l.up, "w")
screen.onkey(paddle_l.down, "s")
screen.onkey(paddle_r.up, "Up")
screen.onkey(paddle_r.down, "Down")

game_is_on = True

while game_is_on:
    screen.update()
    time.sleep(ball.move_speed)
    ball.move()

    if ball.ycor() > 280 or ball.ycor() < -280:
        ball.bounce_y()

    if ball.xcor() > 300 and ball.distance(paddle_r) < 50 or ball.xcor() < -300 and ball.distance(paddle_l) < 50:
        ball.bounce_x()

    if ball.xcor() > 330:
        scoreboard.increase_score_l()
        ball.reset_position()

    if ball.xcor() < -330:
        scoreboard.increase_score_r()
        ball.reset_position()

    if scoreboard.l_score > 5:
        scoreboard.goto(0, 0)
        scoreboard.write("Left side wins!", align="center", font=("Courier", 30, "normal"))
        game_is_on = False

    if scoreboard.r_score > 5:
        scoreboard.goto(0, 0)
        scoreboard.write("Right side wins!", align="center", font=("Courier", 30, "normal"))
        game_is_on = False

screen.exitonclick()
