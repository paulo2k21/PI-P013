/*Exercício 2:
Crie um tipo estruturado (struct) empregado para armazenar dados (nome,
sobrenome, ano de nascimento, RG, ano de admissão, salário) de empregados de
uma empresa. Defina um vetor de empregados para armazenar até 50 empregados.
Faça uma função chamada “Reajusta_dez_porcento( )” que receba por parâmetro o
vetor de empregados e a quantidade de elementos no vetor e atualize o salário de
cada empregado em 10%. Crie uma função main para testar a função.*/

#include <iostream>
#include <string>

using namespace std;
struct Empregado
{
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};

void Reajusta_dez_porcento(Empregado empregados[], int numEmpregados)
{
    for (int i = 0; i < numEmpregados; i++)
    {
        empregados[i].salario *= 1.10;
    }
}

int main()
{
    const int maxEmpregados = 50;
    Empregado empregados[maxEmpregados];
    int numEmpregados;

    cout << "Quantos empregados deseja registrar (até 50)? ";
    cin >> numEmpregados;

    if (numEmpregados > maxEmpregados)
    {
        cout << "Número de empregados excede o limite. Configurando para 50." << endl;
        numEmpregados = maxEmpregados;
    }

    for (int i = 0; i < numEmpregados; i++)
    {
        cout << "Empregado #" << i + 1 << ":" << endl;
        cout << "Nome: ";
        cin >> empregados[i].nome;
        cout << "Sobrenome: ";
        cin >> empregados[i].sobrenome;
        cout << "Ano de Nascimento: ";
        cin >> empregados[i].anoNascimento;
        cout << "RG: ";
        cin >> empregados[i].RG;
        cout << "Ano de Admissão: ";
        cin >> empregados[i].anoAdmissao;
        cout << "Salário: ";
        cin >> empregados[i].salario;
    }
    Reajusta_dez_porcento(empregados, numEmpregados);
    cout << "\nDados dos empregados após o reajuste:" << endl;
    for (int i = 0; i < numEmpregados; i++)
    {
        cout << "Empregado #" << i + 1 << ":" << endl;
        cout << "Nome: " << empregados[i].nome << " " << empregados[i].sobrenome << endl;
        cout << "Ano de Nascimento: " << empregados[i].anoNascimento << endl;
        cout << "RG: " << empregados[i].RG << endl;
        cout << "Ano de Admissão: " << empregados[i].anoAdmissao << endl;
        cout << "Salário após reajuste: " << empregados[i].salario << endl;
    }

    return 0;
}
