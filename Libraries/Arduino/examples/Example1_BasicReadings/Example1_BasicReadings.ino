/*
  This is a library written for the AS726X Spectral Sensor (Visible or IR) with I2C firmware
  specially loaded. SparkFun sells these at its website: www.sparkfun.com

  Written by Nathan Seidle & Andrew England @ SparkFun Electronics, July 12th, 2017

  https://github.com/sparkfun/Qwiic_Spectral_Sensor_AS726X

  Do you like this library? Help support SparkFun. Buy a board!

  Development environment specifics:
  Arduino IDE 1.8.1

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.


  ---AVAILABLE FUNCTIONS---
  AS726X(TwoWire &wirePort = Wire, byte gain = 3, byte measurementMode = 3);
  void takeMeasurements();
  void takeMeasurementsWithBulb();
  void printMeasurements();
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
*/

#include "AS726X.h"

AS726X sensor;

void setup() {
  sensor.begin();
}

void loop() {
  sensor.takeMeasurements();
  sensor.printMeasurements();
}
