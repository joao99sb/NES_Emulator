#pragma once
#include <cstdint>
#include<array>
#include "jv6502.h"
#include "jv2C02.h"
#include "Cartridge.h"


class Bus
{
public:
	Bus();
	~Bus();

public://devices
	jv6502 CPU;

	jv2C02 PPU;

	// fake ram
	std::array<uint8_t, 2 * 1024> cpuRam;

	//Cartridge
	std::shared_ptr<Cartridge> cart;

public:
	void cpuWrite(uint16_t addr, uint8_t data);
	uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);

	// System Interface
	void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void reset();
	void clock();

private:
	uint32_t systemClockCounter = 0;

};

