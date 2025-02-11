#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> pessoas;
    vector<string> tem;
    vector<string> pode;
    int conta_pessoas = -1;
    string entrada;
    int contador_comp = 0;

    while (true) {
        conta_pessoas++;
        cout << "Digite o nome de uma pessoa, ou T para parar: ";
        cin >> entrada;
        if (entrada == "T") break;
        else {
            pessoas.push_back(entrada);
        }
        cout << "Digite o que essa pessoa tem: ";
        cin >> entrada;
        tem.push_back(entrada);

        cout << "Digite o que essa pessoa pode desenhar: ";
        cin >> entrada;
        pode.push_back(entrada);
    }

    for (int i = 0; i <= conta_pessoas; i++) {
        for (int j = 0; j <= conta_pessoas; j++) {
            if (i == j) continue; // Skip comparison with self
            contador_comp = 0;
            for (unsigned int l = 0; l < tem[j].length(); l++) {
                int res = pode[i].find(tem[j][l]);
                if (res != string::npos) {
                    contador_comp++;
                }
                if (contador_comp == 0 && l == (tem[j].length() - 1)) {
                    cout << endl << pessoas[i] << " nao pode tirar: " << pessoas[j] << endl;
                }
            }
        }
    }
}