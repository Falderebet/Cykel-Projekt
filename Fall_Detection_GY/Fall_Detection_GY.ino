#include<Wire.h>
/*
const int MPU=0x68; 
int16_t AcX,AcY,AcZ; //Tmp,GyX,GyY,GyZ;
*/
// Nedestående behøves vidst ikke.
// int SCL = A5;
// int SDA = A4;


void setup() {
  // Set up af, Wire bibliotek.
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
  fallDetection();
  delay(500);
  
}


double fallDetection() {
    Wire.beginTransmission(MPU);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 12, true);
    AcX = Wire.read() << 8 | Wire.read();
    AcY = Wire.read() << 8 | Wire.read();
    AcZ = Wire.read() << 8 | Wire.read();

    // Test kode til at se om det virker, slet når du er færdig med at teste.
    Serial.print("Accelerometer: ");
    Serial.println("X = ");
    Serial.print(AcX);
    Serial.println("Y = ");
    Serial.print(AcY);
    Serial.println("Z = ");
    Serial.print(AcZ);

    double magnitude = sqrt((AcX*AcX) + (AcY* AcY) + (AcZ * AcZ));

    if(magnitude > 1.0) {
        return 1.0;
      }
    else {
        return 0.0;
      }
  }
