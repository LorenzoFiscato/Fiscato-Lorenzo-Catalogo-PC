#ifndef CODICE_COMPUTER_H
#define CODICE_COMPUTER_H
#include <string>


class Computer {
private:
   std::string codice;
   std::string marca;
   std::string modello;
   int velProcessore;
   int dimRam;
   int dimDisco;
   double dimMonitor;
   int annoAcquisto;

   inline static int cont = 0;

public:
   Computer(const std::string&& ma, const std::string&& mod, int v,int dimR, int dimD, double dimM, int anno)
   : codice(std::to_string(++cont)),marca(ma),modello(mod), velProcessore(v),
   dimRam(dimR), dimDisco(dimD),dimMonitor(dimM), annoAcquisto(anno) {}

   const std::string& GetCodice() const { return codice; }
   const std::string& GetMarca() const { return marca; }
   const std::string& GetModello() const { return modello; }
   int GetVelocita() const { return velProcessore; }
   int GetDimRam() const { return dimRam; }
   int GetDimDisco() const { return dimDisco; }
   double GetDimMonitor() const { return dimMonitor; }
   int GetAnnoAcquisto() const { return annoAcquisto; }

};


#endif
