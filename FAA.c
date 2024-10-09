#include <stdio.h>
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>

#define TIME_STEP 64
#define THRESHOLD 5
#define THRESHOLD1 120
#define THRESHOLDD 350
#define THRESHOLD2 150
#define MAX_SPEED 5
#define CORNER_SPEED 0

int main() {
  wb_robot_init();

  WbDeviceTag left_motor = wb_robot_get_device("left wheel motor");
  WbDeviceTag right_motor = wb_robot_get_device("right wheel motor");
  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);

  // Obtenez les tags des capteurs
  WbDeviceTag ir_left = wb_robot_get_device("ir_left");
  WbDeviceTag ir_middle = wb_robot_get_device("ir_middle");
  WbDeviceTag ir_right = wb_robot_get_device("ir_right");
  WbDeviceTag sensor_7 = wb_robot_get_device("ps7"); // Capteur frontal gauche
  WbDeviceTag sensor_5 = wb_robot_get_device("ps5");
  WbDeviceTag sensor_6 = wb_robot_get_device("ps6");
  WbDeviceTag sensor_0 = wb_robot_get_device("ps0");
  
  // Activez les capteurs
  wb_distance_sensor_enable(ir_left, TIME_STEP);
  wb_distance_sensor_enable(ir_middle, TIME_STEP);
  wb_distance_sensor_enable(ir_right, TIME_STEP);
  wb_distance_sensor_enable(sensor_7, TIME_STEP);
  wb_distance_sensor_enable(sensor_5, TIME_STEP);
  wb_distance_sensor_enable(sensor_6, TIME_STEP);
  wb_distance_sensor_enable(sensor_0, TIME_STEP);
  

  while (wb_robot_step(TIME_STEP) != -1) {
    double value_left = wb_distance_sensor_get_value(ir_left);
    double value_middle = wb_distance_sensor_get_value(ir_middle);
    double value_right = wb_distance_sensor_get_value(ir_right);
    double value_7 = wb_distance_sensor_get_value(sensor_7);
    double value_5 = wb_distance_sensor_get_value(sensor_5);
    double value_6 = wb_distance_sensor_get_value(sensor_6);
    double value_0 = wb_distance_sensor_get_value(sensor_0);
    
     printf("IR Left: %f, IR Middle: %f, IR Right: %f\n", value_left, value_middle, value_right);
     printf("Sensor 0 value: %f\n", value_0);
     printf("Sensor 7 Value: %f\n", value_7);
     printf("Sensor 6 Value: %f\n", value_6);
     printf("Sensor 5 Value: %f\n", value_5);
     
        if (value_6 > THRESHOLDD || value_7 > THRESHOLD1 || value_0 > THRESHOLD1) {
            wb_motor_set_velocity(left_motor, MAX_SPEED);
            wb_motor_set_velocity(right_motor, 0);
            continue;
            
        } else if (value_5 > THRESHOLD2) {
            wb_motor_set_velocity(left_motor, MAX_SPEED);
            wb_motor_set_velocity(right_motor, MAX_SPEED);
            
         } else {
            wb_motor_set_velocity(left_motor, 0);
            wb_motor_set_velocity(right_motor, MAX_SPEED);
        }
        
        
    if (value_middle > 2) {
        if (value_left > value_right) {
          wb_motor_set_velocity(left_motor, CORNER_SPEED);
          wb_motor_set_velocity(right_motor, MAX_SPEED);
        } else {
          wb_motor_set_velocity(left_motor, MAX_SPEED);
          wb_motor_set_velocity(right_motor, CORNER_SPEED);
        }
    } else {
      // Avancer tout droit
      wb_motor_set_velocity(left_motor, MAX_SPEED);
      wb_motor_set_velocity(right_motor, MAX_SPEED);
    }

}
  wb_robot_cleanup();
  return 0;
}
