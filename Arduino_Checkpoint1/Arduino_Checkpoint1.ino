#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int64.h>

ros::NodeHandle nh;


std_msgs::Int64 int_mul_result;
ros::Publisher publisher("MUL_result", &int_mul_result);

void Input_num_Callback( const std_msgs::Int64& msg){

  int_mul_result.data = 2*msg.data;
  publisher.publish(&int_mul_result);
//  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

//char hello[13] = "user's input is ";
ros::Subscriber<std_msgs::Int64> sub("Input_number", &Input_num_Callback );


void setup()
{
//  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(publisher);
}

void loop()
{
  // wait for input number callback
  nh.spinOnce();
  delay(1000);
}
