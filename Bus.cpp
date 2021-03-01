#include "Bus.h"

Bus::Bus() {

	//Clear ram contents
	for (auto& i : cpuRam) i = 0x00;
	CPU.ConnectBus(this);
}

Bus::~Bus(){}

void Bus::cpuWrite(uint16_t addr, uint8_t data) {

	if (cart->cpuWrite(addr, data)) {

	}

	else if (addr >= 0x0000 && addr <= 0x1FFF)
		cpuRam[addr & 0x07FF] = data;
	else if (addr >=  0x2000 && addr <= 0x3FFF)
		PPU.cpuWrite(addr & 0x0007, data);


}


uint8_t Bus::cpuRead(uint16_t addr, bool bReadOnly) {

	uint8_t data = 0x00;

	if (cart->cpuWrite(addr, data)) {

	}
	else if (addr >= 0x0000 && addr <= 0x1FFF)
		data = cpuRam[addr & 0x07FF];
	else if (addr >= 0x2000 && addr <= 0x3FFF)
		data = PPU.cpuRead(addr & 0x0007, bReadOnly);
	
	return data;
}

void Bus::insertCartridge(const std::shared_ptr<Cartridge>& cartridge)
{
	this->cart = cartridge;
	PPU.ConnectCartridge(cartridge);
}

void Bus::reset()
{
	CPU.reset();
	systemClockCounter = 0;
}

void Bus::clock()
{
}
