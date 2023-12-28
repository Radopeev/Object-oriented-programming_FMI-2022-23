#include <iostream>
#include "BigNumber.h"
int main()
{
    std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") > BigNumber("4767846784647856547474446")) << std::endl;
    std::cout << std::boolalpha << (BigNumber("4767846784647856547476") < BigNumber("7643276342876783246893247")) << std::endl;
    std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") != BigNumber("4767846784647856547476")) << std::endl;
    std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") == BigNumber("7643276342876783246893247")) << std::endl;

    //std::cout << std::boolalpha << ((BigNumber("12345678901234567890") + BigNumber("4354678097643135")) == BigNumber("12350033579332211025")) << std::endl;
    //std::cout << std::boolalpha << ((BigNumber("12345678901234567890") - BigNumber("4354678097643135")) == BigNumber("12341324223136924755")) << std::endl;
    std::cout << std::boolalpha << ((BigNumber("12345678901234567890") * BigNumber("4354678097643135")) == BigNumber("53761457511741137249987999149935150")) << std::endl;
    //std::cout << std::boolalpha << ((BigNumber("12345678901234567890") / BigNumber("4354678097643135")) == BigNumber("2835")) << std::endl;
    //std::cout << std::boolalpha << ((BigNumber("12345678901234567890") % BigNumber("4354678097643135")) == BigNumber("166494416280165")) << std::endl;

    std::cout << std::boolalpha << ((BigNumber("-12345678901234567890") + BigNumber("4354678097643135")) == BigNumber("-12341324223136924755")) << std::endl;
    std::cout << std::boolalpha << ((BigNumber("-12345678901234567890") * BigNumber("4354678097643135")) == BigNumber("-53761457511741137249987999149935150")) << std::endl;
}
