#include "ros/ros.h"          // 加入ROS公用程序
#include "std_msgs/Int64.h"  // 所要publish的message header，在此是std_msgs package底下的String.msg
#include <sstream>
#include <iostream>

// 1. Publish Topic: /Input_number
// 2. Subscribe Topic: /MUL_result
std_msgs::Int64 input_number;
ros::Publisher RPi_pub;

void MUL_result_Callback(const std_msgs::Int64::ConstPtr& msg)
{
  ROS_INFO("message from Arduino: %ld", msg->data);
  // std_msgs::Int64 input_number;  // 建立暫存的message，先將資料存入此變數，再進行publish
    
    // static int num = 0;

    // input_number.data = num;   // 寫入msg message中的data欄位 
  std::cin>>input_number.data;
    // key : put "delay" before ros::spinOnce(); to allow Arduino to handle data and send back.
  RPi_pub.publish(input_number);
    // loop_rate.sleep(); 
  ROS_INFO("user's input is %ld", input_number.data); 


}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "RPi");  //一開始必須先初始化，指定node名稱為talker

  /* 該node與ROS系統通訊的存取點(handle)，建構子會初始化該node，
     當離開此scope，解構子會關閉該node */
  ros::NodeHandle n;     

  /* advertise()會將建立topic的資訊告訴master node，回傳一個Publisher物件(在此為chatter_pub)
     之後可使用該物件的 publish() 方法進行publish
     而預計publish的message為std_msgs package的String.msg (std::msgs::String)   
     指定的topic名稱為chatter
     10指的是message queue，若publish太快，超過1000個message，新publish的message會被捨棄
  */ 
  RPi_pub = n.advertise<std_msgs::Int64>("Input_number", 10);
  ros::Subscriber RPi_sub = n.subscribe("MUL_result", 10, MUL_result_Callback);  

  // ros::Rate loop_rate(2);   // 2Hz

  // int count = 0;
  // while (ros::ok())
  // {
  // std_msgs::Int64 input_number;  // 建立暫存的message，先將資料存入此變數，再進行publish
    
    // static int num = 0;

    // input_number.data = num;   // 寫入msg message中的data欄位 
  std::cin>>input_number.data;
    // key : put "delay" before ros::spinOnce(); to allow Arduino to handle data and send back.
  RPi_pub.publish(input_number);
    // loop_rate.sleep(); 
  ROS_INFO("user's input is %ld", input_number.data); 
    // ros::spinOnce();   // 呼叫一次 callback function，在subscriber才有用
    // num++;

  // }
  ros::spin();
  return 0;
}