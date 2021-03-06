/**
 * Inclui:
 *  - cin
 *  - cout
 */
#include <iostream>
/**
 * Inclui:
 *  - system
 */
#include <cstdlib>
 /**
 * Inclui:
 *  - ifstream
 */
#include <fstream>
/**
 * Classe parceadora de Net List
 */
#include "parser.cpp"
/**
 * Fabrica construtora dos modelos dos elementos
 */
#include "factory.cpp"

/* Necessario para nao precisar escrever std:: */
using namespace std;

int main()
{
    string fileName;
    bool repeat;
    ifstream myNet;

    do {
        //system("cls"); /*Limpa o console do Windows*/
        system("clear"); /*Limpa o console do Linux*/

        if (repeat == true) {
            cout << "Arquivo " << fileName << " nao foi encontrado, tente novamente.\n";
            cout << "Obs. O Arquivo deve estar na mesma pasta do executavel.\n\n";
        }
        repeat = true;

        cout << "EEL525 - Circutos Eletricos II\n";
        cout << "UFRJ/Poli/DEL - Departamento de Engenharia Eletronica\n";
        cout << "Desenvolvido por: Igor Abreu\n";
        cout << "Programa de analise no dominio do tempo de elementos lineares e nao lineares\n";
        cout << "Nome do arquivo contendo a NetList: [ex. minha.net] ";
        cin >> fileName;
        /* Abrindo a net list*/
        myNet.open(fileName);
        if (myNet.is_open()) {
            repeat = false;
        }
    } while (repeat == true);

    /**
     * Lista de elementos a serem construidos
     * @param  myNet Arquivo da netlist
     * @return       Vetor de vetores devidamente separados com os componentes
     */
    Parser* elementsList = new Parser(myNet);

    Factory* components = new Factory(elementsList->getElements());

}