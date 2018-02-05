#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	p_error = 0.0;
    	d_error = 0.0;
    	i_error = 0.0;
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	/*
	p.push_back(_Kp);
        p.push_back(_Ki);
        p.push_back(_Kd);
	it = 0;
	for (int i = 0; i < 3; ++i) {
        
        	dp.push_back(1);
    	}*/
	std::cout << "Kp,Ki,Kd  " << Kp<<"  "<<Ki<<"  "<<Kd<<std::endl;
}

void PID::UpdateError(double cte) {
	//bool twiddle = false;
	
	d_error = cte - p_error ;
	p_error = cte;//put it at second one
    	i_error += cte;
	//std::cout << "dpi   "<<d_error<<"  "<<p_error<<" "<<i_error <<std::endl;
	/*
	if(twiddle) {
		if((it>n)&&i(it<2n)){
			err += cte * cte;
		}
		if(it == 2n){
			err /= n;
			sum = dp[0]+dp[1]+dp[2];
			if(sum>0.2){
				for (int i = 0; i < 3; ++i) {
					p[i] += dp[i];
					if (err < best_err){
						best_err = err;
						dp[i] *= 1.1;
					}else{
						p[i] -= 2 * dp[i]
						if (err < best_err){
						    best_err = err;
						    dp[i] *= 1.1;
						}
						else{
						    p[i] += dp[i];
						    dp[i] *= 0.9;
						}
					}        	
    				}				
			}
		}
		it++;		
	}*/       
}

double PID::TotalError() {
	double P = (- Kp * p_error);
	double I = (- Ki * i_error);
	double D = (- Kd * d_error);
	double Error = P+I+D;
	//return - Kp * p_error - Ki * i_error - Kd * d_error;
	//std::cout << "total Kp,Ki,Kd  " << Kp<<"  "<<Ki<<"  "<<Kd<<std::endl;
	//std::cout << "total dpi   "<<d_error<<"  "<<p_error<<" "<<i_error <<std::endl;
	//std::cout << "total P I D Error   "<<P<<"  "<<I<<" "<<D<<"  "<<Error<<std::endl;
	return Error;
}

