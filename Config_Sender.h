#define MAX_BATTERY_PARAMETERS 2
#define DATA_STREAM_SIZE 50

#define INVALID_TEMPERATURE 65535
#define MIN_TEMP_LIMIT -10
#define MAX_TEMP_LIMIT  50
#define TEMPERATURE_OFFSET 0.75

#define INVALID_VOLTAGE 0
#define MIN_VOLTAGE_LIMIT 2.5
#define MAX_VOLTAGE_LIMIT 12

typedef struct {
   float (*SensorReadFunc_fp)(void);  
   float (*ProcessSensorOutputFunc_fp)(float);
   void (*PrintInConsole_fp)(int,float);
} tst_ReadBatteryParameters;

extern const tst_ReadBatteryParameters ReadBatteryParameters_st[MAX_BATTERY_PARAMETERS];
extern char BatteryParametersJSONString[MAX_BATTERY_PARAMETERS][50];
extern float TemperatureValue;
extern float VoltageValue;
