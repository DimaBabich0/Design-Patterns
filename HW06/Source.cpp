#include <iostream>
#include <string>
using namespace std;

class GraphicsCard
{
public:
	void Start()
	{
		cout << "Graphics card: start." << endl;
	}
	void CheckConnectionMonitor()
	{
		cout << "Graphics card: check the connection to the monitor." << endl;
	}
	void OutputRAMData()
	{
		cout << "Graphics card: output of RAM data." << endl;
	}
	void DisplayAboutDiskReader()
	{
		cout << "Graphics card: display information about the disk reader." << endl;
	}
	void DisplayAboutHardDrive()
	{
		cout << "Graphics card: display information about the hard drive." << endl;
	}
	void DisplayFarewellMessage()
	{
		cout << "Graphics card: display the data of the farewell message." << endl;
	}
};

class RAM
{
public:
	void StartDevices()
	{
		cout << "RAM: Start the devices." << endl;
	}
	void Analysis()
	{
		cout << "RAM: Memory analysis." << endl;
	}
	void Cleaning()
	{
		cout << "RAM: memory cleaning." << endl;
	}
};

class HardDrive
{
public:
	void Start()
	{
		cout << "Hard drive: start." << endl;
	}
	void CheckBootSector()
	{
		cout << "Hard drive: Check the boot sector." << endl;
	}
	void Stop()
	{
		cout << "Hard drive: stop the device." << endl;
	}
};

class OpticalDiskReader
{
public:
	void Start()
	{
		cout << "Optical disk reader: start." << endl;
	}
	void CheckDiskAvailability()
	{
		cout << "Optical disc reader: check for disk availability." << endl;
	}
	void Stop()
	{
		cout << "Optical disc reader: return to original position." << endl;
	}
};

class PowerSupply
{
public:
	void GetPower()
	{
		cout << "Power supply: get power supply." << endl;
	}
	void PowerToGraphicsCard()
	{
		cout << "Power supply: power to the video card." << endl;
	}
	void PowerToRAM()
	{
		cout << "Power supply: power to RAM." << endl;
	}
	void PowerToDiskReader()
	{
		cout << "Power supply: power the disk reader." << endl;
	}
	void PowerToHardDrive()
	{
		cout << "Power supply: power to the hard drive." << endl;
	}
	void StopPowerGraphicsCard()
	{
		cout << "Power supply: stop power supply graphics card." << endl;
	}
	void StopPowerRAM()
	{
		cout << "Power supply: stop the RAM power." << endl;
	}
	void StopPowerDiskReader()
	{
		cout << "Power supply: stop powering the disk reader." << endl;
	}
	void StopPowerHardDrive()
	{
		cout << "Power supply: stop power to the hard drive." << endl;
	}
	void StopPower()
	{
		cout << "Power supply: stop power supply." << endl;
	}
};

class Sensors
{
public:
	void CheckVoltage()
	{
		cout << "Sensors: check voltage." << endl;
	}
	void CheckTempInPowerSupply()
	{
		cout << "Sensors: check the temperature in the power supply." << endl;
	}
	void CheckTempInGraphicsCard()
	{
		cout << "Sensors: check the temperature in the graphics card." << endl;
	}
	void CheckRAMTemperature()
	{
		cout << "Sensors: Check the RAM temperature." << endl;
	}
	void CheckRAMAllSystems()
	{
		cout << "Sensors: check the temperature of all systems." << endl;
	}
};

class PC
{
	GraphicsCard graphicsCard;
	RAM ram;
	HardDrive hardDrive;
	OpticalDiskReader opticalDiskReader;
	PowerSupply powerSupply;
	Sensors sensors;
public:
	void Start()
	{
		powerSupply.GetPower();
		sensors.CheckVoltage();
		sensors.CheckTempInPowerSupply();
		sensors.CheckTempInGraphicsCard();
		powerSupply.PowerToGraphicsCard();
		graphicsCard.Start();
		graphicsCard.CheckConnectionMonitor();
		sensors.CheckRAMTemperature();
		powerSupply.PowerToRAM();
		ram.StartDevices();
		ram.Analysis();
		graphicsCard.OutputRAMData();
		powerSupply.PowerToDiskReader();
		opticalDiskReader.Start();
		opticalDiskReader.CheckDiskAvailability();
		graphicsCard.DisplayAboutDiskReader();
		powerSupply.PowerToHardDrive();
		hardDrive.Start();
		hardDrive.CheckBootSector();
		graphicsCard.DisplayAboutHardDrive();
		sensors.CheckRAMAllSystems();
	}
	void Stop()
	{
		hardDrive.Stop();
		ram.Cleaning();
		ram.Analysis();
		graphicsCard.DisplayFarewellMessage();
		opticalDiskReader.Stop();
		powerSupply.StopPowerGraphicsCard();
		powerSupply.StopPowerRAM();
		powerSupply.StopPowerDiskReader();
		powerSupply.StopPowerHardDrive();
		sensors.CheckVoltage();
		powerSupply.StopPower();
	}
};

int main()
{
	PC pc;
	pc.Start();

	system("pause");
	system("cls");

	pc.Stop();
	return 0;
}