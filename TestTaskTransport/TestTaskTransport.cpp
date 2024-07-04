#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "TestTaskTransport.h"
#include "TestTaskTransportFactory.h"

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);

	if (argc > 5) {
		cerr << "Usage: " << argv[0] << " <transport_types> from 0 to 3" << endl;
		return 1;
	}

	vector<unique_ptr<Transport>> transports;

	for (int i = 1; i < argc; ++i) {
		int type = stoi(argv[i]);
		auto transport = TransportFactory::createTransport(type);
		if (transport) {
			transports.push_back(move(transport));
		} else {
			cout << "НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА " << endl;
		}
	}

	for (const auto& transport : transports) {
		cout << "Наименование транспорта: " << transport->getName() << endl;
		cout << "Кол-во колес: " << transport->getNumberOfWheels() << endl;
		cout << "Максимальная скорость: " << transport->getMaxSpeed() << "км/ч" << endl;
		int maxPassengers = transport->getMaxPassengers();
		if (maxPassengers > 0) {
			cout << "Максимальное количество пассижиров: " << maxPassengers << endl;
		}
		cout << endl;
	}

	return 0;
}
