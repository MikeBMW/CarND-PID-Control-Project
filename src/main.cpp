#include <uWS/uWS.h>
#include <iostream>
#include "json.hpp"
#include "PID.h"
#include <math.h>

// for convenience
using json = nlohmann::json;

// For converting back and forth between radians and degrees.
constexpr double pi() { return M_PI; }
double deg2rad(double x) { return x * pi() / 180; }
double rad2deg(double x) { return x * 180 / pi(); }

// Checks if the SocketIO event has JSON data.
// If there is data the JSON object in string format will be returned,
// else the empty string "" will be returned.
std::string hasData(std::string s) {
  auto found_null = s.find("null");
  auto b1 = s.find_first_of("[");
  auto b2 = s.find_last_of("]");
  if (found_null != std::string::npos) {
    return "";
  }
  else if (b1 != std::string::npos && b2 != std::string::npos) {
    return s.substr(b1, b2 - b1 + 1);
  }
  return "";
}

int main()
{
  uWS::Hub h;

  PID pid;
  // TODO: Initialize the pid variable.
  //pid.Init(0.15 ,0.01, 2.2);
  //pid.Init(0 ,0, 0);	// 1 leave the track, add P a little;      
  //pid.Init(0.1 ,0, 0);	// 2  can not go back to track; 
  //pid.Init(0.1 ,0, 1.0); 	// 3  too go to right side;
  //pid.Init(0.1 ,0, 2.0); 	//  
  //pid.Init(0.1 ,0.01, 2.0);   //  
  //pid.Init(0.1 ,0.01, 2.5);
  //pid.Init(0.1 ,0.01, 1.0);    // 4 almost go out of the road
  //pid.Init(0.15 ,0.01, 1.0);   //  
  //pid.Init(0.15 ,0.01, 1.2);
  //pid.Init(0.15 ,0.015, 1.2);
  //pid.Init(0.15 ,0.008, 1.2);
  //pid.Init(0.12 ,0.008, 1.2);
  //pid.Init(0.1 ,0.008, 1.2);
  //pid.Init(0.1 ,0.008, 1.0);
  //pid.Init(0.1 ,0.011, 1.0);
  //pid.Init(0.12 ,0.011, 1.0);
  //pid.Init(0.12 ,0.011, 1.2);
  //pid.Init(0.12 ,0.011, 1.1);
  //pid.Init(0.11 ,0.011, 1.1);
  //pid.Init(0.09 ,0.011, 1.1);
  //pid.Init(0.09 ,0.015, 1.1);
  //pid.Init(0.08 ,0.01, 1.1);
  //pid.Init(0.08 ,0.01, 1);
  //pid.Init(0.07 ,0.01, 1);      // 
  //pid.Init(0.07 ,0.007, 1);
  //pid.Init(0.07 ,-0.007, 1);
  //pid.Init(0.07 ,0.009, 1);
  //pid.Init(0.07 ,0.01, 1);
  //pid.Init(0.09 ,0.01, 1);
  //pid.Init(0.09 ,0.01, 0.9);
  //pid.Init(0.1 ,0.01, 1.0);   
  //pid.Init(0.09 ,0.01, 1.0);
  //pid.Init(0.09 ,0.011, 1.0);
  //pid.Init(0.09 ,0.005, 1.0);
  //pid.Init(0.07 ,0.005, 1.0);
  //pid.Init(0.07 ,0.007, 1.0);
  //pid.Init(0.06 ,0.007, 1.0);
  //pid.Init(0.06 ,0.006, 0.8);
  //pid.Init(0.07 ,0.006, 0.8);
  //pid.Init(0.08 ,0.006, 0.8);
  //pid.Init(0.08 ,0.008, 0.8);
  //pid.Init(0.09 ,0.009, 0.9);
  //pid.Init(0.1 ,0.009, 0.9);  // 
  //pid.Init(0.11 ,0.009, 0.9);
  //pid.Init(0.12 ,0.009, 1.0);  //5  a little slow, decrease "d"
  pid.Init(0.12 ,0.009, 0.9);   // 6 latest version
  //pid.Init(0.13 ,0.009, 0.9);   // 7 become worse


//#ffmpeg -f x11grab -s xga -r 10 -i :0.0+0+0 pid1.avi 


  


  h.onMessage([&pid](uWS::WebSocket<uWS::SERVER> ws, char *data, size_t length, uWS::OpCode opCode) {
    // "42" at the start of the message means there's a websocket message event.
    // The 4 signifies a websocket message
    // The 2 signifies a websocket event
    if (length && length > 2 && data[0] == '4' && data[1] == '2')
    {
      auto s = hasData(std::string(data).substr(0, length));
      if (s != "") {
        auto j = json::parse(s);
        std::string event = j[0].get<std::string>();
        if (event == "telemetry") {
          // j[1] is the data JSON object
          double cte = std::stod(j[1]["cte"].get<std::string>());
          double speed = std::stod(j[1]["speed"].get<std::string>());
          double angle = std::stod(j[1]["steering_angle"].get<std::string>());
          double steer_value;
          /*
          * TODO: Calcuate steering value here, remember the steering value is
          * [-1, 1].
          * NOTE: Feel free to play around with the throttle and speed. Maybe use
          * another PID controller to control the speed!
          */

	  pid.UpdateError(cte);

  	  steer_value = pid.TotalError();
          
          // DEBUG
          std::cout << "CTE: " << cte << " Steering Value: " << steer_value << std::endl;

          json msgJson;
          msgJson["steering_angle"] = steer_value;
          msgJson["throttle"] = 0.3;
          //msgJson["throttle"] = 0.28;
          auto msg = "42[\"steer\"," + msgJson.dump() + "]";
          std::cout << msg << std::endl;
          ws.send(msg.data(), msg.length(), uWS::OpCode::TEXT);
        }
      } else {
        // Manual driving
        std::string msg = "42[\"manual\",{}]";
        ws.send(msg.data(), msg.length(), uWS::OpCode::TEXT);
      }
    }
  });

  // We don't need this since we're not using HTTP but if it's removed the program
  // doesn't compile :-(
  h.onHttpRequest([](uWS::HttpResponse *res, uWS::HttpRequest req, char *data, size_t, size_t) {
    const std::string s = "<h1>Hello world!</h1>";
    if (req.getUrl().valueLength == 1)
    {
      res->end(s.data(), s.length());
    }
    else
    {
      // i guess this should be done more gracefully?
      res->end(nullptr, 0);
    }
  });

  h.onConnection([&h](uWS::WebSocket<uWS::SERVER> ws, uWS::HttpRequest req) {
    std::cout << "Connected!!!" << std::endl;
  });

  h.onDisconnection([&h](uWS::WebSocket<uWS::SERVER> ws, int code, char *message, size_t length) {
    ws.close();
    std::cout << "Disconnected" << std::endl;
  });

  int port = 4567;
  if (h.listen(port))
  {
    std::cout << "Listening to port " << port << std::endl;
  }
  else
  {
    std::cerr << "Failed to listen to port" << std::endl;
    return -1;
  }
  h.run();
}
