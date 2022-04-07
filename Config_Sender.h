#define MAX_BATTERY_PARAMETERS 2

typedef struct {
   int (*SensorReadFunc_fp)(float *sensorValues);     
} tst_ReadBatteryParameters;

extern const tst_ReadBatteryParameters ReadBatteryParameters_st[MAX_BATTERY_PARAMETERS];
