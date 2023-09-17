/*Exercício 1:

Uma empresa de ônibus faz diariamente 5 viagens de ida e 5 viagens de volta entre
as cidades do Rio de Janeiro e São Paulo. Cada ônibus tem 40 assentos para serem
preenchidos por passageiros. A empresa costuma vender as passagens
antecipadamente, e para cada passagem vendida é anotado o número do assento, a
data e hora, o CPF, o nome e a idade do passageiro. As passagens são vendidas por
80 reais cada.

Faça um programa para gerenciar a venda de passagens de ônibus. O programa deve
possibilitar obter as seguintes informações:

1. Qual o total arrecadado para uma determinada viagem.
2. Qual o total arrecadado em um determinado mês.
3. Qual o nome do passageiro de uma determinada poltrona P de uma
determinada viagem.
4. Qual o horário de viagem mais rentável.
5. Qual a média de idade dos passageiros.*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Passagem {
    string nome;
    string dataHora;
    string cpf;
    int idade;
};

int main() {
    const int NUM_VIAGENS = 5;
    const int NUM_ASSENTOS = 40;
    const double PRECO_PASSAGEM = 80.0;

    vector<vector<Passagem>> registros(NUM_VIAGENS, vector<Passagem>(NUM_ASSENTOS));

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Registrar Passagem" << endl;
        cout << "2. Total Arrecadado para uma Viagem" << endl;
        cout << "3. Total Arrecadado em um Mês" << endl;
        cout << "4. Nome do Passageiro de uma Poltrona" << endl;
        cout << "5. Horário de Viagem Mais Rentável" << endl;
        cout << "6. Média de Idade dos Passageiros" << endl;
        cout << "7. Sair" << endl;

        int opcao;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int numViagem, numAssento;
                cout << "Digite o número da viagem (1 a " << NUM_VIAGENS << "): ";
                cin >> numViagem;
                cout << "Digite o número do assento (1 a " << NUM_ASSENTOS << "): ";
                cin >> numAssento;

                if (numViagem >= 1 && numViagem <= NUM_VIAGENS && numAssento >= 1 && numAssento <= NUM_ASSENTOS) {
                    Passagem passagem;
                    cout << "Digite o nome do passageiro: ";
                    cin.ignore();
                    getline(cin, passagem.nome);
                    cout << "Digite a data e hora (DD/MM/YYYY HH:MM): ";
                    cin.ignore();
                    getline(cin, passagem.dataHora);
                    cout << "Digite o CPF do passageiro: ";
                    cin >> passagem.cpf;
                    cout << "Digite a idade do passageiro: ";
                    cin >> passagem.idade;

                    registros[numViagem - 1][numAssento - 1] = passagem;

                    cout << "Passagem registrada com sucesso." << endl;
                } else {
                    cout << "Viagem ou assento inválido." << endl;
                }
                break;
            }
            case 2: {
                int numViagem;
                cout << "Digite o número da viagem (1 a " << NUM_VIAGENS << "): ";
                cin >> numViagem;

                if (numViagem >= 1 && numViagem <= NUM_VIAGENS) {
                    double totalArrecadado = 0.0;
                    for (const Passagem& passagem : registros[numViagem - 1]) {
                        if (!passagem.nome.empty()) {
                            totalArrecadado += PRECO_PASSAGEM;
                        }
                    }
                    cout << "Total arrecadado para a viagem " << numViagem << ": R$ " << totalArrecadado << endl;
                } else {
                    cout << "Viagem inválida." << endl;
                }
                break;
            }
            case 3: {
                string mes;
                cout << "Digite o mês (MM): ";
                cin >> mes;
                double totalArrecadadoMes = 0.0;
                for (const vector<Passagem>& viagem : registros) {
                    for (const Passagem& passagem : viagem) {
                        if (!passagem.nome.empty() && passagem.dataHora.substr(3, 2) == mes) {
                            totalArrecadadoMes += PRECO_PASSAGEM;
                        }
                    }
                }
                cout << "Total arrecadado em " << mes << ": R$ " << totalArrecadadoMes << endl;
                break;
            }
            case 4: {
                int numViagem, numAssento;
                cout << "Digite o número da viagem (1 a " << NUM_VIAGENS << "): ";
                cin >> numViagem;
                cout << "Digite o número do assento (1 a " << NUM_ASSENTOS << "): ";
                cin >> numAssento;

                if (numViagem >= 1 && numViagem <= NUM_VIAGENS && numAssento >= 1 && numAssento <= NUM_ASSENTOS) {
                    const Passagem& passagem = registros[numViagem - 1][numAssento - 1];
                    if (!passagem.nome.empty()) {
                        cout << "Nome do passageiro da poltrona " << numAssento << ": " << passagem.nome << endl;
                    } else {
                        cout << "Poltrona vazia." << endl;
                    }
                } else {
                    cout << "Viagem ou assento inválido." << endl;
                }
                break;
            }
            case 5: {
                string horarioMaisRentavel;
                double arrecadacaoMaxima = 0.0;
                for (int i = 0; i < NUM_VIAGENS; ++i) {
                    double arrecadacaoViagem = 0.0;
                    for (const Passagem& passagem : registros[i]) {
                        if (!passagem.nome.empty()) {
                            arrecadacaoViagem += PRECO_PASSAGEM;
                        }
                    }
                    if (arrecadacaoViagem > arrecadacaoMaxima) {
                        arrecadacaoMaxima = arrecadacaoViagem;
                        horarioMaisRentavel = "Viagem " + to_string(i + 1);
                    }
                }
                cout << "Horário de viagem mais rentável: " << horarioMaisRentavel << endl;
                break;
            }
            case 6: {
                int somaIdades = 0;
                int totalPassageiros = 0;
                for (const vector<Passagem>& viagem : registros) {
                    for (const Passagem& passagem : viagem) {
                        if (!passagem.nome.empty()) {
                            somaIdades += passagem.idade;
                            totalPassageiros++;
                        }
                    }
                }
                if (totalPassageiros > 0) {
                    double mediaIdade = static_cast<double>(somaIdades) / totalPassageiros;
                    cout << "Média de idade dos passageiros: " << fixed << setprecision(2) << mediaIdade << " anos" << endl;
                } else {
                    cout << "Nenhum passageiro registrado." << endl;
                }
                break;
            }
            case 7:
                cout << "Saindo do programa." << endl;
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}