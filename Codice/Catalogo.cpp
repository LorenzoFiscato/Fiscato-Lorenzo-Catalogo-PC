//
// Created by utente on 20/10/2026.
//

#include "Catalogo.h"

#include <iostream>

Catalogo::Catalogo() {
    if (!LoadFromFile(fileName))
        std::cout<<"Errore nel caricamento dei dati"<<std::endl;
}
auto Catalogo::FindComputer(const Computer &computer) {
    return std::find_if(computers.begin(), computers.end(),[&computer]
        (const Computer& c){ return c.GetCodice() == computer.GetCodice(); });
}

bool Catalogo::AddComputer(const Computer &computer) {
    auto it = FindComputer(computer);

    if (it != computers.end()) return false;

    computers.push_back(computer);

    if (!SaveToFile(fileName))
        std::cout<<"Errore nel salvataggio dei dati"<<std::endl;
    return true;
}

bool Catalogo::RemoveComputer(const Computer &computer) {
    auto it = FindComputer(computer);

    if (it == computers.end()) return false;
    computers.erase(it);

    if (!SaveToFile(fileName))
        std::cout<<"Errore nel salvataggio dei dati"<<std::endl;
    return true;
}

Computer* Catalogo::SearchComputerByCode(const std::string &code) {
    auto it = std::find_if(computers.begin(), computers.end(),
        [&code](const Computer& c){ return c.GetCodice() == code; });

    if (it == computers.end()) return nullptr;

    return &*it;
}

std::vector<Computer> Catalogo::SearchBetterComputers(int vel, int dimRam, int dimDisco) {
    std::vector<Computer> betterComputers = std::vector<Computer>();
    for (const auto &c : computers) {
        if (c.GetVelocita() > vel && c.GetDimRam() > dimRam && c.GetDimDisco() > dimDisco)
            betterComputers.push_back(c);
    }
    return betterComputers;
}

bool Catalogo::SaveToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) return false;

    for (const auto& c : computers) {
        file << c.GetCodice() << ","
             << c.GetMarca() << ","
             << c.GetModello() << ","
             << c.GetVelocita() << ","
             << c.GetDimRam() << ","
             << c.GetDimDisco() << ","
             << c.GetDimMonitor() << ","
             << c.GetAnnoAcquisto() << "\n";
    }

    file.close();
    return true;
}


bool Catalogo::LoadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) return false;

    computers.clear();

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string codice, marca, modello;
        int vel, ram, disco, anno;
        double monitor;
        char comma;

        std::getline(ss, codice, ',');
        std::getline(ss, marca, ',');
        std::getline(ss, modello, ',');
        ss >> vel >> comma
           >> ram >> comma
           >> disco >> comma
           >> monitor >> comma
           >> anno;

        Computer c(std::move(marca), std::move(modello), vel, ram, disco, monitor, anno);

        computers.push_back(c);

    }

    file.close();
    return true;
}
