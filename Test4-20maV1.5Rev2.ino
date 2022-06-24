
// Include libraries this sketch will use
#include  <Wire.h>
#include  <MCP342X.h>

// Instantiate objects used in this project
MCP342X AI14(0x68);
 

void setup() {
  Wire.begin();  // join I2C bus
  //TWBR = 12;  // 400 kHz (maximum)
  
  Serial.begin(115200); // Open serial connection to send info to the host
 
  Serial.println("Starting up");
  Serial.println("Testing device connection...");
  Serial.println(AI14.testConnection() ? "MCP342X connection successful 1-4" : "MCP342X connection failed 1-4");
   
}  // End of setup()


//====mapfloat====

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  if ((in_max - in_min) + out_min != 0) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  } else {
    return 0;
  }
}


void loop() {
  static int32_t  adc0;
  static int32_t  adc1;
  static int32_t  adc2;
  static int32_t  adc3;
  
  AI14.configure( MCP342X_MODE_CONTINUOUS |
                  MCP342X_CHANNEL_1 |
                  MCP342X_SIZE_18BIT |
                  MCP342X_GAIN_1X
                );

  AI14.startConversion();
  AI14.getResult(&adc0);
  Serial.print("\tCh1: ");
 
  float val0 = mapfloat(adc0, 25286, 126635, 4, 20); 
  Serial.println(val0);
  AI14.configure( MCP342X_MODE_CONTINUOUS |
                  MCP342X_CHANNEL_2 |
                  MCP342X_SIZE_18BIT |
                  MCP342X_GAIN_1X
                );

  AI14.startConversion();
  AI14.getResult(&adc1);
  Serial.print("\tCh2: ");
  float val1 = mapfloat(adc1, 25286, 126635, 4, 20); 
  Serial.println(val1);

  AI14.configure( MCP342X_MODE_CONTINUOUS |
                  MCP342X_CHANNEL_3 |
                  MCP342X_SIZE_18BIT |
                  MCP342X_GAIN_1X
                );

  AI14.startConversion();
  AI14.getResult(&adc2);
  Serial.print("\tCh3: ");
  float val2 = mapfloat(adc2, 25286, 126635, 4, 20); 
  Serial.println(val2);

  AI14.configure( MCP342X_MODE_CONTINUOUS |
                  MCP342X_CHANNEL_4 |
                  MCP342X_SIZE_18BIT |
                  MCP342X_GAIN_1X
                );

  AI14.startConversion();
  AI14.getResult(&adc3);
  Serial.print("\tCh4: ");
  float val3 = mapfloat(adc3, 25286, 126635, 4, 20); 
  Serial.println(val3);

 
}  // End of loop()
