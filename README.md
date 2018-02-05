# CarND-PID-Control-Project
at beginning, I set it to 0.1, and Kd is also 0.1, and Ki is zero;
I found the car didn't go back to the road, so I add Kp a little, such as 0.5;
then I found the  car can't turn around the biggest corner, so I add Kp a little, then I set Kp = 0.12, 0.13 and so on.When Kp = 0.17, I found the car swing too big, so I increase Kd a little,then the car drive better, so I keep add Kp, stop at 0.7;
I feel the car swing too big, so I decrease Kp to 0.15, I also increase Kd a little to 0.85, then I feel better;
even the car swing still big, but I don't dare to decrease Kp, because the car can't turn the biggest corner if I decrease Kp, so I let the car keep a little bigger Kp;
about Ki, I just use a very small value, Ki = 0.0001, then I add it a little. When I use Ki = 0.001, I feel the system bias become smaller, so I keep this value;
