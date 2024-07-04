#pragma once

#include "TestTaskTransport.h"

class TransportFactory {
public:
	static std::unique_ptr<Transport> createTransport(int type) {
		switch (type) 
		{
		case 0: return std::make_unique<Motorcycle>();
		case 1: return std::make_unique<Scooter>();
		case 2: return std::make_unique<Car>();
		case 3: return std::make_unique<Bus>();
		default: return nullptr;			
		}
	}
};