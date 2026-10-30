#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>



int main(){

  const float MAX_CELL_VOLTAGE = 4.20f;
  const float MIN_CELL_VOLTAGE = 3.00f;
  const uint16_t MAX_PACK_CAPACITY_AH = 100;


  char bmsModel[] = "Lithium-X4";
  char packHealthGrade = 'A';
  uint16_t rawVoltageMilliVolts = 3850;
  int16_t rawCurrentMilliAmps = -12500;
  uint32_t totalOperatingSeconds = 1296000;
  uint32_t totalEnergyDeliveredJoules = 46800000000ULL;
  double cellInternalResistanceOhms = 1.25e-3;

  float actualVoltage = (float) rawVoltageMilliVolts / 1000.0f;
  float actualCurrent = (float) rawCurrentMilliAmps / 1000.0f;
  float voltageRange = MAX_CELL_VOLTAGE - MIN_CELL_VOLTAGE;
  float currentOffset = actualVoltage - MIN_CELL_VOLTAGE;
  float stateOfChargePercent = (currentOffset / voltageRange) * 100.0f;


  float instantaneousPowerWatts = actualVoltage * actualCurrent;

  bool isOverVoltage = actualVoltage > MAX_CELL_VOLTAGE;
  bool isUnderVoltage = actualVoltage < MIN_CELL_VOLTAGE;
  bool isDischaring = actualCurrent < 0.0f;

  bool isSystemNominal = (!isOverVoltage && !isUnderVoltage) || (actualCurrent == 0.0f);

  uint8_t activeBankID = 1;
  uint8_t passiveBankID = 2;
  uint8_t tempBank;

  tempBank = activeBankID;
  activeBankID = passiveBankID;
  passiveBankID = tempBank;

  printf("=== BMS SYSTEM MEMORY FOOTPRINT ===\n");
  printf("uint16_t (Voltage): %zu byte(s)\n", sizeof(rawVoltageMilliVolts));
  printf("uint32_t (Uptime): %zu byte(s)\n", sizeof(totalOperatingSeconds));
  printf("uint64_t (Energy): %zu byte(s)\n", sizeof(totalEnergyDeliveredJoules));
  printf("uint64_t (Resist): %zu byte(s)\n", sizeof(cellInternalResistanceOhms));

  printf("=== BMS TELEMETRY DASHBOARD [%s] ===\n", bmsModel);
  printf("Pack Grade: %c | System Status Nominal: %d\n", packHealthGrade, isSystemNominal);
  printf("Active Power Bank (Swapped): Slot #%d\n", activeBankID);
  printf("Pack Voltage:   %.3f V\n", actualVoltage);
  printf("Pack Current:   %.2f A\n", actualCurrent);
  printf("Power Output:   %.2f W\n", instantaneousPowerWatts);
  printf("State of Charge: %.1f %%\n", stateOfChargePercent);
  printf("Total Energy Output:%llu Joules\n", totalEnergyDeliveredJoules);

  return 0;

}






