
# CarND-PID-Control-Project
## explain my project
1 "1_p0_i0_d0.avi"
at beginning, I set P to 0, I to 0 and D to 0, the car go straight and go out of the road;

2 "2_p0.1_i0_d0.avi"
set P to 0.1, the car can follow the target route, but the car can't go back to the middle of the road quickly;

3 "3_p0.1_i0_d1.0.avi"
the car can go back to the road middle quickly, but it is a little near the right side of the road, so think about the "I";

4 "4_p0.1_i0.01_d1.0.avi"
there is not the system error, the car can turn through the big corner,but at the beginning, the car can't go back to the road quickly, that means the P is a little smaller, so increase P;

5 "5_p0.12_i0.009_d1.0.avi"
There is no problem at the beginning moment, but the speed is a little slow, the car swing to fast, so decrease "D" a little.

6 "6_p0.12_i0.009_d0.9.avi"
The speed of the car is more than 30km/h, and it always near the middle of the road.
good luck for myself!

7 "7_p0.13_i0.009_d0.9.avi"
It becomes worse, so keep to use ""6_p0.12_i0.009_d0.9.avi""

##The effect of P I D:
P: P stands for proportional, the proportional term produces an output value that is proportional to the current error value.

I: Integral term.The contribution from the integral term is proportional to both the magnitude of the error and the duration of the error.

D: Derivation term. The derivation of the process error is calculated by determining the slope of the error over time and multiplying this rate of change by the derivative gain .Derivative action predicts system behavior and thus imporves settling time and stability of the system.
