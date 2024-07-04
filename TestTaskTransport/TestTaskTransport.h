#pragma once

class Transport
{
public:
	virtual ~Transport() = default;
	virtual std::string getName() const = 0;
	virtual int getNumberOfWheels() const = 0;
	virtual int getMaxSpeed() const = 0;
	virtual int getMaxPassengers() const { return 0; }
};

class Motorcycle : public Transport {
public:
	std::string getName() const override { return "Мотоцикл"; }
	int getNumberOfWheels() const override { return 2; }
	int getMaxSpeed() const override { return 120; }
	int getMaxPassengers() const override { return 2; }
};

class Scooter : public Transport {
public:
	std::string getName() const override { return "Самокат"; }
	int getNumberOfWheels() const override { return 2; }
	int getMaxSpeed() const override { return 25; }
	int getMaxPassengers() const override { return 1; }
};

class Car : public Transport {
public:
	std::string getName() const override { return "Автомобиль"; }
	int getNumberOfWheels() const override { return 4; }
	int getMaxSpeed() const override { return 150; }
};

class Bus : public Transport {
public:
	std::string getName() const override { return "Автобус"; }
	int getNumberOfWheels() const override { return 6; }
	int getMaxSpeed() const override { return 100; }
	int getMaxPassengers() const override { return 20; }
};