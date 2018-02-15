
# CarND-PID-Control-Project
## explain my project
1 "1_p0_i0_d0.avi"
at beginning, I set P to 0, I to 0 and D to 0, the car go straight and go out of the road;

2 "2_p0.1_i0_d0.avi"
set P to 0.1, at the beginning the car can follow the target route, but the oscillates of the car is very faster, that means I need to increase D to suppress sudden changes;

3 "3_p0.1_i0_d1.0.avi"
The effect of "D" is good, it suppress the fast oscillate, but it is a little near the right side of the road, so think about the "I", there is some system error;

4 "4_p0.1_i0.01_d1.0.avi"
The the system error become much smaller, the car can turn through the big corner where have enough space on the right side.But at the very beginning of the video, the car can't go back to the middle of the road quickly, that means the P is a little smaller, the car can't follow the target route quickly, so increase P to increase proportional gain;

5 "5_p0.12_i0.009_d1.0.avi"
There is no problem at the beginning moment, but the speed is a little slow, sometimes less than 30km/h whenever the oscillation is big and following the term "D" suppress the sudden changes, so I want to decrease "D" a little to make the car become more smooth rather than jerk.

6 "6_p0.12_i0.009_d0.9.avi"
The speed of the car is more than 30km/h, and it always near the middle of the road.
good luck for myself!

7 "7_p0.13_i0.009_d0.9.avi"
It becomes worse, so keep to use ""6_p0.12_i0.009_d0.9.avi""

## The effect of P I D

P: P stands for proportional, the proportional term produces an output value that is proportional to the current error value.

I: Integral term.The contribution from the integral term is proportional to both the magnitude of the error and the duration of the error.

D: Derivation term. The derivation of the process error is calculated by determining the slope of the error over time and multiplying this rate of change by the derivative gain .Derivative action predicts system behavior and thus imporves settling time and stability of the system.
