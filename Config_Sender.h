#define MAX_BATTERY_PARAMETERS 2
#define INVALID_TEMPERATURE 65535
#define TEMPERATURE_OFFSET 0.75

typedef struct {
   float (*SensorReadFunc_fp)(void);  
   float (*ProcessSensorOutputFunc_fp)(float);
} tst_ReadBatteryParameters;

extern const tst_ReadBatteryParameters ReadBatteryParameters_st[MAX_BATTERY_PARAMETERS];
