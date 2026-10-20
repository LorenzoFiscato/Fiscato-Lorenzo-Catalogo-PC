
#ifndef CODICE_CATALOGO_H
#define CODICE_CATALOGO_H
#include "Computer.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


class Catalogo {
private:
    std::string fileName = "ComputerSalvati.CSV";
    std::vector<Computer> computers = std::vector<Computer>();

    auto FindComputer(const Computer& computer);

    bool SaveToFile(const std::string& filename) const;
    bool LoadFromFile(const std::string& filename);

public:
    Catalogo();

    bool AddComputer(const Computer& computer);

    bool RemoveComputer(const Computer& computer);

    Computer* SearchComputerByCode(const std::string& code);

    std::vector<Computer> SearchBetterComputers(int vel, int dimRam, int dimDisco);


};


#endif
