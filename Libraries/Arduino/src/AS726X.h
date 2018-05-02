/*
 Name:		AS726X.h
 Created:	7/11/2017 12:06:22 PM
 Author:	andrew.england
 Editor:	http://www.visualmicro.com
*/

#ifndef _AS726X_h
#define _AS726X_h
#include "Arduino.h"
#include "Wire.h"
class AS726X {
public:
	AS726X();
	void begin(TwoWire &wirePort = Wire, byte gain = 3, byte measurementMode = 3);
	void takeMeasurements();
	void takeMeasurementsWithBulb();
	void printMeasurements();
	void printUncalibratedMeasurements();
	byte getTemperature();
	float getTemperatureF();
	void setMeasurementMode(byte mode);
	boolean dataAvailable();
	void enableIndicator();
	void disableIndicator();
	void setIndicatorCurrent(byte current);
	void enableBulb();
	void disableBulb();
	void setBulbCurrent(byte current);
	void softReset();
	void setGain(byte gain);
	void setIntegrationTime(byte integrationValue);
	void enableInterrupt();
	void disableInterrupt();

	//Get the various AS7261 readings
	int getX();
	int getY();
	int getZ();
	int getNIR();
	int getDark();
	int getClear();

	//Get the various color readings
	int getViolet();
	int getBlue();
	int getGreen();
	int getYellow();
	int getOrange();
	int getRed();

	//Get the various NIR readings
	int getR();
	int getS();
	int getT();
	int getU();
	int getV();
	int getW();

	//Returns the various calibration data
	float getCalibratedX();
	float getCalibratedY();
	float getCalibratedZ();

	float getCalibratedViolet();
	float getCalibratedBlue();
	float getCalibratedGreen();
	float getCalibratedYellow();
	float getCalibratedOrange();
	float getCalibratedRed();

	float getCalibratedR();
	float getCalibratedS();
	float getCalibratedT();
	float getCalibratedU();
	float getCalibratedV();
	float getCalibratedW();

	//Calibrated color data
	float getCalibratedx1931();
	float getCalibratedy1931();
	float getCalibratedupri();
	float getCalibratedvpri();
	float getCalibrateducolor();
	float getCalibratedvcolor();
	float getCalibratedLUX();
	float getCalibratedDUV();
	float getCalibratedCCT();

private:
	TwoWire *_i2cPort;
	int getChannel(byte channelRegister);
	float getCalibratedValue(byte calAddress);
	unsigned long getCalibratedLongValue(byte calAddress);
	float convertBytesToFloat(uint32_t myLong);
	boolean clearDataAvailable();
	byte virtualReadRegister(byte virtualAddr);
	void virtualWriteRegister(byte virtualAddr, byte dataToWrite);
	void writeRegister(byte addr, byte val);
	byte readRegister(byte addr);
#define AS726X_ADDR 0x49 //7-bit unshifted default I2C Address
#define SENSORTYPE_AS7262 0x3E
#define SENSORTYPE_AS7263 0x3F

	//Register addresses
#define AS726x_DEVICE_TYPE 0x00
#define AS726x_HW_VERSION 0x01
#define AS726x_CONTROL_SETUP 0x04
#define AS726x_INT_T 0x05
#define AS726x_DEVICE_TEMP 0x06
#define AS726x_LED_CONTROL 0x07

#define AS72XX_SLAVE_STATUS_REG 0x00
#define AS72XX_SLAVE_WRITE_REG 0x01
#define AS72XX_SLAVE_READ_REG 0x02

	//The same register locations are shared between the AS7262 and AS7263, they're just called something different

	//AS7261 Registers
#define AS7261_X 0x08
#define AS7261_Y 0x0A
#define AS7261_Z 0x0C
#define AS7261_N 0x0E
#define AS7261_D 0x10
#define AS7261_C 0x12

#define AS7261_X_CAL 0x14
#define AS7261_Y_CAL 0x18
#define AS7261_Z_CAL 0x1C

  // The AS7261 differs here
#define AS7261_x1931_CAL 0x20
#define AS7261_y1931_CAL 0x24
#define AS7261_upri_CAL 0x28
#define AS7261_vpri_CAL 0x2C
#define AS7261_u_CAL 0x30
#define AS7261_v_CAL 0x34
#define AS7261_DUV_CAL 0x38
#define AS7261_LUX_CAL 0x3C
#define AS7261_CCT_CAL 0x40


	//AS7262 Registers
#define AS7262_V 0x08
#define AS7262_B 0x0A
#define AS7262_G 0x0C
#define AS7262_Y 0x0E
#define AS7262_O 0x10
#define AS7262_R 0x12
#define AS7262_V_CAL 0x14
#define AS7262_B_CAL 0x18
#define AS7262_G_CAL 0x1C
#define AS7262_Y_CAL 0x20
#define AS7262_O_CAL 0x24
#define AS7262_R_CAL 0x28

	//AS7263 Registers
#define AS7263_R 0x08
#define AS7263_S 0x0A
#define AS7263_T 0x0C
#define AS7263_U 0x0E
#define AS7263_V 0x10
#define AS7263_W 0x12
#define AS7263_R_CAL 0x14
#define AS7263_S_CAL 0x18
#define AS7263_T_CAL 0x1C
#define AS7263_U_CAL 0x20
#define AS7263_V_CAL 0x24
#define AS7263_W_CAL 0x28

#define AS72XX_SLAVE_TX_VALID 0x02
#define AS72XX_SLAVE_RX_VALID 0x01

#define SENSORTYPE_AS7261 0x3D
#define SENSORTYPE_AS7262 0x3E
#define SENSORTYPE_AS7263 0x3F

#define POLLING_DELAY 5 //Amount of ms to wait between checking for virtual register changes

	byte _sensorVersion = 0;
};

#endif
