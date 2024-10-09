#include <stdio.h>
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>

#define TIME_STEP 64
#define THRESHOLD 5
#define MAX_SPEED 5
#define CORNER_SPEED 0

int main() {
  wb_robot_init();

  // Obtenez les tags des moteurs
  WbDeviceTag left_motor = wb_robot_get_device("left wheel motor");
  WbDeviceTag right_motor = wb_robot_get_device("right wheel motor");
  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);

  // Obtenez les tags des capteurs
  WbDeviceTag ir_left = wb_robot_get_device("ir_left");
  WbDeviceTag ir_middle = wb_robot_get_device("ir_middle");
  WbDeviceTag ir_right = wb_robot_get_device("ir_right");
  
  // Activez les capteurs
  wb_distance_sensor_enable(ir_left, TIME_STEP);
  wb_distance_sensor_enable(ir_middle, TIME_STEP);
  wb_distance_sensor_enable(ir_right, TIME_STEP);

  while (wb_robot_step(TIME_STEP) != -1) {
    double value_left = wb_distance_sensor_get_value(ir_left);
    double value_middle = wb_distance_sensor_get_value(ir_middle);
    double value_right = wb_distance_sensor_get_value(ir_right);

    // Affichez les valeurs des capteurs
    printf("IR Left: %f, IR Middle: %f, IR Right: %f\n", value_left, value_middle, value_right);
    

    // Logique de direction basée sur les valeurs des capteurs
    if (value_middle > 2) {
        // Comparez la valeur gauche et droite et tournez vers le côté avec la plus grande valeur
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
