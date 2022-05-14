byte andar() {
  if (digitalRead(pinSensorT) == nivelSensor) {
     return 0;
  } else if (digitalRead(pinSensor1) == nivelSensor) {
     return 1;
  } else if (digitalRead(pinSensor2) == nivelSensor) {
     return 2;
  } else if (digitalRead(pinSensor3) == nivelSensor) {
     return 3;
  } else {
     return 9;
  }
}
