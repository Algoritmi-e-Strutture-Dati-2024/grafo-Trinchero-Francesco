#include <iostream>
#include "Grafo.h"

int main() {
    // Creazione del grafo
    Grafo<std::string> grafo;

    // Aggiunta dei nodi con i nuovi nomi
    grafo.aggiungiNodo("La Spezia");
    grafo.aggiungiNodo("Genova");
    grafo.aggiungiNodo("Pisa");
    grafo.aggiungiNodo("Carrara");
    grafo.aggiungiNodo("Parma");

    // Aggiunta degli archi (con i pesi)
    grafo.aggiungiArco("La Spezia", "Genova", 80);
    grafo.aggiungiArco("Genova", "Pisa", 90);
    grafo.aggiungiArco("Pisa", "Parma", 40);
    grafo.aggiungiArco("Parma", "Carrara", 120);
    grafo.aggiungiArco("Carrara", "Genova", 70);
    grafo.aggiungiArco("Pisa", "Carrara", 100);

    // Visualizzazione della matrice di adiacenza
    grafo.stampa();

    // Ricerca: Verifica se un nodo esiste
    if (grafo.verificaNodo("Pisa")) {
    std::cout << "Verifica se il nodo 'Pisa' esiste: Esiste\n";
} else {
    std::cout << "Verifica se il nodo 'Pisa' esiste: Non esiste\n";
}

    // Stampa dei nodi adiacenti a 'Genova'
    grafo.nodiAdiacenti("Genova");

    // Verifica se esiste un arco tra 'Genova' e 'Pisa'
    if (grafo.verificaArco("Genova", "Pisa")) {
    std::cout << "Verifica se esiste un arco tra 'Genova' e 'Pisa': Esiste\n";
} else {
    std::cout << "Verifica se esiste un arco tra 'Genova' e 'Pisa': Non esiste\n";
}

    // Manipolazione: Rimuovere un nodo
    grafo.rimuoviNodo("Parma");
    std::cout << "Dopo aver rimosso il nodo 'Parma', grafo aggiornato:\n";
    grafo.stampa();

    // Rimuovere un arco specifico
    grafo.rimuoviArco("Genova", "Pisa");
    std::cout << "Dopo aver rimosso l'arco tra 'Genova' e 'Pisa', grafo aggiornato:\n";
    grafo.stampa();

    // Aggiunta di un nuovo nodo e di un nuovo arco
    grafo.aggiungiNodo("Lucca");
    grafo.aggiungiArco("Carrara", "Lucca", 60);
    std::cout << "Dopo aver aggiunto il nodo 'Lucca' e l'arco tra 'Carrara' e 'Lucca', grafo aggiornato:\n";
    grafo.stampa();

    // Operazione aggiuntiva: Verifica la connettività tra 'La Spezia' e 'Carrara'
    std::cout << "Verifica se i nodi 'La Spezia' e 'Carrara' sono connessi: ";
    // Metodo che verifica la connettività (da implementare)

    // Operazione aggiuntiva: Trova l'arco con peso minore per 'Genova'
    grafo.arcoConPesoMinore("Genova");

    return 0;
}

    // Trova l'arco con peso minore tra gli archi uscenti di un nodo dato in input
    int arcoConPesoMinore(const T& nodo) const {
        int indice = trovaIndice(nodo);
        if (indice == -1) {
            std::cout << "Errore: il nodo non esiste.\n";
            return -1; // Errore: nodo non trovato
        }

        int pesoMinimo = INF;
        for (int i = 0; i < numeroNodi; ++i) {
            if (esisteNodo[i] && matriceAdiacenza[indice][i] != INF) {
                if (matriceAdiacenza[indice][i] < pesoMinimo) {
                    pesoMinimo = matriceAdiacenza[indice][i];
                }
            }
        }

        return (pesoMinimo == INF) ? -1 : pesoMinimo; // Se non ci sono archi uscenti, ritorna -1
    }
};
