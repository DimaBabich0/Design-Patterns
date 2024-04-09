#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Processor;
class Hdd;
class RAM;
class GPU;

class IVisitor abstract
{
public:
	virtual void VisitProcessor(Processor* proc) abstract;
	virtual void VisitHdd(Hdd* hdd) abstract;
	virtual void VisitRAM(RAM* ram) abstract;
	virtual void VisitGPU(GPU* gpu) abstract;
};

class AbstractDevice abstract
{
	string Producer;
public:
	string GetProducer() { return Producer; }
	void SetProducer(string Producer) { this->Producer = Producer; }

	virtual void Accept(IVisitor* visitor)abstract;
};

class Processor : public AbstractDevice
{
	string Frequency;
	string CoreCount;
public:
	string GetFrequency() { return Frequency; }
	string GetCoreCount() { return CoreCount; }

	void SetFrequency(string Frequency) { this->Frequency = Frequency; }
	void SetCoreCount(string CoreCount) { this->CoreCount = CoreCount; }

	void Accept(IVisitor* visitor) override { visitor->VisitProcessor(this); }
};
class Hdd : public AbstractDevice
{
	string Volume;
	string Type;
public:
	string GetVolume() { return Volume; }
	string GetType() { return Type; }

	void SetVolume(string Volume) { this->Volume = Volume; }
	void SetType(string Type) { this->Type = Type; }

	void Accept(IVisitor* visitor) override { visitor->VisitHdd(this); }
};
class RAM : public AbstractDevice
{
	string Capacity;
	string Frequency;
public:
	string GetCapacity() { return Capacity; }
	string GetFrequency() { return Frequency; }

	void SetCapacity(string Capacity) { this->Capacity = Capacity; }
	void SetFrequency(string Frequency) { this->Frequency = Frequency; }

	void Accept(IVisitor* visitor) override { visitor->VisitRAM(this); }
};
class GPU : public AbstractDevice
{
	string GraphicsChip;
	string MemoryCapacity;
	string MemoryFrequency;
	string CoreFrequency;
public:
	void SetGraphicsChip(string GraphicsChip) { this->GraphicsChip = GraphicsChip; }
	void SetMemoryCapacity(string MemoryCapacity) { this->MemoryCapacity = MemoryCapacity; }
	void SetMemoryFrequency(string MemoryFrequency) { this->MemoryFrequency = MemoryFrequency; }
	void SetCoreFrequency(string CoreFrequency) { this->CoreFrequency = CoreFrequency; }

	string GetGraphicsChip() { return GraphicsChip; }
	string GetMemoryCapacity() { return MemoryCapacity; }
	string GetMemoryFrequency() { return MemoryFrequency; }
	string GetCoreFrequency() { return CoreFrequency; }

	void Accept(IVisitor* visitor) override { visitor->VisitGPU(this); }
};

class HtmlVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + proc->GetProducer() + "</td></tr>";
		result += "<tr><td>Frequency<td><td>" + proc->GetFrequency() + "</td></tr>";
		result += "<tr><td>Core Count<td><td>" + proc->GetCoreCount() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + hdd->GetProducer() + "</td></tr>";
		result += "<tr><td>Type<td><td>" + hdd->GetType() + "</td></tr>";
		result += "<tr><td>Volume<td><td>" + hdd->GetVolume() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitRAM(RAM* ram) override
	{
		ofstream out("RAM.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + ram->GetProducer() + "</td></tr>";
		result += "<tr><td>Capacity<td><td>" + ram->GetCapacity() + "</td></tr>";
		result += "<tr><td>Frequency<td><td>" + ram->GetFrequency() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitGPU(GPU* gpu) override
	{
		ofstream out("GPU.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + gpu->GetProducer() + "</td></tr>";
		result += "<tr><td>Graphics Chip<td><td>" + gpu->GetGraphicsChip() + "</td></tr>";
		result += "<tr><td>Memory Capacity<td><td>" + gpu->GetMemoryCapacity() + "</td></tr>";
		result += "<tr><td>Memory Frequency<td><td>" + gpu->GetMemoryFrequency() + "</td></tr>";
		result += "<tr><td>Core Frequency<td><td>" + gpu->GetCoreFrequency() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
};
class XmlVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Processor><Producer>" + proc->GetProducer() + "</Producer>" +
			"<Frequency>" + proc->GetFrequency() + "</Frequency>" +
			"<CoreCount>" + proc->GetCoreCount() + "</CoreCount></Processor>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<HDD><Producer>" + hdd->GetProducer() + "</Producer>" +
			"<Type>" + hdd->GetType() + "</Type>" +
			"<Volume>" + hdd->GetVolume() + "</Volume></HDD>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitRAM(RAM* ram) override
	{
		ofstream out("RAM.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<RAM>";
		result += "<Producer>" + ram->GetProducer() + "</Producer>";
		result += "<Capacity>" + ram->GetCapacity() + "</Capacity>";
		result += "<Frequency>" + ram->GetFrequency() + "</Frequency>";
		result += "</RAM>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitGPU(GPU* gpu) override
	{
		ofstream out("GPU.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<GPU>";
		result += "<GraphicsChip>" + gpu->GetGraphicsChip() + "</GraphicsChip>";
		result += "<MemoryCapacity>" + gpu->GetMemoryCapacity() + "</MemoryCapacity>";
		result += "<MemoryFrequency>" + gpu->GetMemoryFrequency() + "</MemoryFrequency>";
		result += "<CoreFrequency>" + gpu->GetCoreFrequency() + "</CoreFrequency>";
		result += "</GPU>";
		out.write(result.c_str(), result.size());
		out.close();
	}
};
class TextVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.txt", ios::binary | ios::trunc | ios::out);
		string result = "\tProcessor\n";
		result += "Producer: " + proc->GetProducer() + "\n";
		result += "Frequency: " + proc->GetFrequency() + "\n";
		result += "Core Count: " + proc->GetCoreCount() + "\n";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("HDD.txt", ios::binary | ios::trunc | ios::out);
		string result = "\tHDD\n";
		result += "Producer: " + hdd->GetProducer() + "\n";
		result += "Type: " + hdd->GetType() + "\n";
		result += "Volume: " + hdd->GetVolume() + "\n";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitRAM(RAM* ram) override
	{
		ofstream out("RAM.txt", ios::binary | ios::trunc | ios::out);
		string result = "\tRAM\n";
		result += "Producer: " + ram->GetProducer() + "\n";
		result += "Capacity: " + ram->GetCapacity() + "\n";
		result += "Frequency: " + ram->GetFrequency() + "\n";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitGPU(GPU* gpu) override
	{
		ofstream out("GPU.txt", ios::binary | ios::trunc | ios::out);
		string result = "\tGPU\n";
		result += "Producer: " + gpu->GetProducer() + "\n";
		result += "Graphics chip: " + gpu->GetGraphicsChip() + "\n";
		result += "Memory capacity: " + gpu->GetMemoryCapacity() + "\n";
		result += "Memory frequency: " + gpu->GetMemoryFrequency() + "\n";
		result += "Core frequency: " + gpu->GetCoreFrequency() + "\n";
		out.write(result.c_str(), result.size());
		out.close();
	}
};
class ConsoleVisitor : public IVisitor
{
	int dProperty = 20;
	int dValue = 15;
public:
	void VisitProcessor(Processor* proc) override
	{
		cout << right << setw((dProperty + dValue) / 2) << "Processor" << endl;
		cout << left << setw(dProperty) << "Property" << setw(dValue) << "Value" << endl;
		cout << left << setw(dProperty) << "Producer:" << setw(dValue) << proc->GetProducer() << endl;
		cout << left << setw(dProperty) << "Frequency:" << setw(dValue) << proc->GetFrequency() << endl;
		cout << left << setw(dProperty) << "Core count:" << setw(dValue) << proc->GetCoreCount() << endl;
		cout << "---------------------------------" << endl << endl;
	}
	void VisitHdd(Hdd* hdd) override
	{
		cout << right << setw((dProperty + dValue) / 2) << "HDD" << endl;
		cout << left << setw(dProperty) << "Property" << setw(dValue) << "Value" << endl;
		cout << left << setw(dProperty) << "Producer:" << setw(dValue) << hdd->GetProducer() << endl;
		cout << left << setw(dProperty) << "Type:" << setw(dValue) << hdd->GetType() << endl;
		cout << left << setw(dProperty) << "Volume:" << setw(dValue) << hdd->GetVolume() << endl;
		cout << "---------------------------------" << endl << endl;
	}
	void VisitRAM(RAM* ram) override
	{
		cout << right << setw((dProperty + dValue) / 2) << "RAM" << endl;
		cout << left << setw(dProperty) << "Property" << setw(dValue) << "Value" << endl;
		cout << left << setw(dProperty) << "Producer:" << setw(dValue) << ram->GetProducer() << endl;
		cout << left << setw(dProperty) << "Capacity:" << setw(dValue) << ram->GetCapacity() << endl;
		cout << left << setw(dProperty) << "Frequency:" << setw(dValue) << ram->GetFrequency() << endl;
		cout << "---------------------------------" << endl << endl;
	}
	void VisitGPU(GPU* gpu) override
	{
		cout << right << setw((dProperty + dValue) / 2) << "GPU" << endl;
		cout << left << setw(dProperty) << "Property" << setw(dValue) << "Value" << endl;
		cout << left << setw(dProperty) << "Producer:" << setw(dValue) << gpu->GetProducer() << endl;
		cout << left << setw(dProperty) << "Graphics Chip:" << setw(dValue) << gpu->GetGraphicsChip() << endl;
		cout << left << setw(dProperty) << "Memory capacity:" << setw(dValue) << gpu->GetMemoryCapacity() << endl;
		cout << left << setw(dProperty) << "Memory frequency:" << setw(dValue) << gpu->GetMemoryFrequency() << endl;
		cout << left << setw(dProperty) << "Core frequency:" << setw(dValue) << gpu->GetCoreFrequency() << endl;
		cout << "---------------------------------" << endl << endl;
	}
};

class PC
{
	vector<AbstractDevice*> devices;
public:
	void Add(AbstractDevice* d)
	{
		devices.push_back(d);
	}
	void Remove(AbstractDevice* d)
	{
		auto iter = find(devices.begin(), devices.end(), d);
		if (iter != devices.end())
			devices.erase(iter);
	}
	void Accept(IVisitor* visitor)
	{
		for (AbstractDevice* d : devices)
			d->Accept(visitor);
	}
};

int main()
{
	PC* pc = new PC();
	Processor* proc = new Processor;
	proc->SetProducer("Intel");
	proc->SetFrequency("3.5");
	proc->SetCoreCount("4");
	pc->Add(proc);

	Hdd* hdd = new Hdd;
	hdd->SetProducer("Western Digital");
	hdd->SetType("SATA III");
	hdd->SetVolume("2");
	pc->Add(hdd);

	RAM* ram = new RAM;
	ram->SetProducer("Kingston");
	ram->SetCapacity("16 GB");
	ram->SetFrequency("3200 MHz");
	pc->Add(ram);

	GPU* gpu = new GPU;
	gpu->SetProducer("Asus");
	gpu->SetGraphicsChip("GeForce RTX 3060");
	gpu->SetMemoryCapacity("12 GB");
	gpu->SetMemoryFrequency("15000 MHz");
	gpu->SetCoreFrequency("1867 MHz");
	pc->Add(gpu);

	TextVisitor* txt = new TextVisitor;
	pc->Accept(txt);

	ConsoleVisitor* console = new ConsoleVisitor;
	pc->Accept(console);

	delete txt;
	delete console;

	delete hdd;
	delete proc;
	delete ram;
	delete gpu;
	delete pc;
}
