#include <iostream>
#include "Catalogo.h"
#include "Computer.h"

void stampaMenu() {
    std::cout << "\n=== MENU CATALOGO COMPUTER ===\n";
    std::cout << "1. Visualizza/Stampa catalogo\n";
    std::cout << "2. Aggiungi un computer\n";
    std::cout << "3. Rimuovi un computer (tramite codice)\n";
    std::cout << "4. Cerca computer per codice\n";
    std::cout << "5. Cerca computer migliori (per requisiti)\n";
    std::cout << "0. Esci\n";
    std::cout << "Scelta: ";
}

int main() {
    Catalogo catalogo;
    int scelta = -1;

    do {
        stampaMenu();
        std::cin >> scelta;

        switch (scelta) {
            case 1: {
                std::cout << "\n--- TEST AGGIUNTA RAPIDA ---\n";
                break;
            }
            case 2: {
                std::string marca, modello;
                int vel, ram, disco, anno;
                double monitor;

                std::cout << "Inserisci Marca: ";
                std::cin >> marca;
                std::cout << "Inserisci Modello: ";
                std::cin >> modello;
                std::cout << "Velocita processore (MHz/GHz): ";
                std::cin >> vel;
                std::cout << "RAM (GB): ";
                std::cin >> ram;
                std::cout << "Disco (GB): ";
                std::cin >> disco;
                std::cout << "Dimensione Monitor (pollici): ";
                std::cin >> monitor;
                std::cout << "Anno d'acquisto: ";
                std::cin >> anno;

                Computer nuovoPc(std::move(marca), std::move(modello), vel, ram, disco, monitor, anno);
                if (catalogo.AddComputer(nuovoPc)) {
                    std::cout << ">>> Computer aggiunto con successo! (Salvato su file)\n";
                } else {
                    std::cout << ">>> Errore: Computer gia esistente nel catalogo.\n";
                }
                break;
            }
            case 3: {
                std::string codiceDaRimuovere;
                std::cout << "Inserisci il codice del computer da rimuovere (es. 1, 2...): ";
                std::cin >> codiceDaRimuovere;

                Computer* trovato = catalogo.SearchComputerByCode(codiceDaRimuovere);
                if (trovato != nullptr) {
                    if (catalogo.RemoveComputer(*trovato)) {
                        std::cout << ">>> Computer rimosso con successo! (Aggiornato su file)\n";
                    } else {
                        std::cout << ">>> Errore durante la rimozione.\n";
                    }
                } else {
                    std::cout << ">>> Computer con codice " << codiceDaRimuovere << " non trovato.\n";
                }
                break;
            }
            case 4: {
                std::string codiceCercato;
                std::cout << "Inserisci il codice da cercare: ";
                std::cin >> codiceCercato;

                Computer* c = catalogo.SearchComputerByCode(codiceCercato);
                if (c != nullptr) {
                    std::cout << "\nTrovato!\n";
                    std::cout << "Codice: " << c->GetCodice() << " | RAM: " << c->GetDimRam()
                              << "GB | Disco: " << c->GetDimDisco() << "GB | Vel: " << c->GetVelocita() << "\n";
                } else {
                    std::cout << ">>> Nessun computer trovato con questo codice.\n";
                }
                break;
            }
            case 5: {
                int minVel, minRam, minDisco;
                std::cout << "Inserisci velocita minima: ";
                std::cin >> minVel;
                std::cout << "Inserisci RAM minima: ";
                std::cin >> minRam;
                std::cout << "Inserisci Disco minimo: ";
                std::cin >> minDisco;

                std::vector<Computer> migliori = catalogo.SearchBetterComputers(minVel, minRam, minDisco);
                std::cout << "\n--- RISULTATI (" << migliori.size() <<" trovati) ---\n";
                for (const auto& c : migliori) {
                    std::cout << "Codice: " << c.GetCodice() << " | RAM: " << c.GetDimRam()
                              << "GB | Disco: " << c.GetDimDisco() << "GB\n";
                }
                break;
            }
            case 0:
                std::cout << "Chiusura programma. A presto!\n";
                break;
            default:
                std::cout << "Scelta non valida. Riprova.\n";
        }

    } while (scelta != 0);

    return 0;
}