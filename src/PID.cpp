//#include <limits>
#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_; // Proportional
  Ki = Ki_; // Integral
  Kd = Kd_; // Differential

  // Assuming the car is far from the CTE.
  p_error = 0.0; // prev cte
  // At the very beginning, the total area between the position of ther car and the CTE is null.
  i_error = 0.0; // I cte
  // Assuming the position of the car is far from CTE, at the begining.
  d_error = 0.0; // D cte
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  //return 0.0;  // TODO: Add your total error calc here!
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}