#include "esphome.h"
#include "PZEM004Tv30.h"

class PZEM004TComponent : public PollingComponent, public Sensor {
 public:
  PZEM004T pzem;
  Sensor *voltage_sensor;
  Sensor *current_sensor;
  Sensor *power_sensor;
  Sensor *energy_sensor;
  Sensor *frequency_sensor;
  Sensor *power_factor_sensor;

  PZEM004TComponent(UARTComponent *parent) : PollingComponent(60000), pzem(parent) {}

  void setup() override {
    pzem.resetEnergy();
  }

  void update() override {
    float voltage = pzem.voltage();
    if (voltage != NAN) {
      voltage_sensor->publish_state(voltage);
    }

    float current = pzem.current();
    if (current != NAN) {
      current_sensor->publish_state(current);
    }

    float power = pzem.power();
    if (power != NAN) {
      power_sensor->publish_state(power);
    }

    float energy = pzem.energy();
    if (energy != NAN) {
      energy_sensor->publish_state(energy);
    }

    float frequency = pzem.frequency();
    if (frequency != NAN) {
      frequency_sensor->publish_state(frequency);
    }

    float power_factor = pzem.pf();
    if (power_factor != NAN) {
      power_factor_sensor->publish_state(power_factor);
    }
  }

  void set_voltage_sensor(Sensor *voltage_sensor) {
    this->voltage_sensor = voltage_sensor;
  }

  void set_current_sensor(Sensor *current_sensor) {
    this->current_sensor = current_sensor;
  }

  void set_power_sensor(Sensor *power_sensor) {
    this->power_sensor = power_sensor;
  }

  void set_energy_sensor(Sensor *energy_sensor) {
    this->energy_sensor = energy_sensor;
  }

  void set_frequency_sensor(Sensor *frequency_sensor) {
    this->frequency_sensor = frequency_sensor;
  }

  void set_power_factor_sensor(Sensor *power_factor_sensor) {
    this->power_factor_sensor = power_factor_sensor;
  }
};
