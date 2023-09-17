/*Exercício 3:
Faça um programa para um supermercado para a consulta de preço de produtos. O
programa deverá armazenar de cada produto o seu código, seu nome e seu preço.
Ao utilizar o programa o usuário deve poder:

1. Inserir um novo produto
2. Excluir um produto cadastrado
3. Listar todos os produtos com seus respectivos códigos e preços
4. Consultar o preço de um produto através de seu código.

O código deve ser formado de uma string numérica de 13 caracteres
O nome deve ter um tamanho de no máximo 20 caracteres
O preço deve ter duas casas decimais
O sistema deve permitir o cadastro de até 300 produtos diferentes.
O sistema deve controlar para que não tenha produtos com o mesmo código ou
mesmo nome, não permitindo o seu cadastro.
O sistema deverá ser feito modularizados, com qualidade e utilizando estrutura na
sua implementação.*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definição da estrutura Produto
struct Produto {
    string codigo;
    string nome;
    double preco;
};

// Função para inserir um novo produto
void inserirProduto(vector<Produto>& produtos) {
    Produto produto;

    // Solicita os dados do produto ao usuário
    cout << "Digite o código do produto (13 caracteres numéricos): ";
    cin >> produto.codigo;

    // Verifica se o código já existe
    for (const Produto& p : produtos) {
        if (p.codigo == produto.codigo) {
            cout << "Produto com o mesmo código já cadastrado." << endl;
            return;
        }
    }

    cout << "Digite o nome do produto (até 20 caracteres): ";
    cin.ignore(); // Limpa o buffer de entrada
    getline(cin, produto.nome);

    cout << "Digite o preço do produto: ";
    cin >> produto.preco;

    // Adiciona o produto ao vetor de produtos
    produtos.push_back(produto);
    cout << "Produto cadastrado com sucesso." << endl;
}

// Função para listar todos os produtos
void listarProdutos(const vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }

    cout << "Lista de Produtos:" << endl;
    for (const Produto& produto : produtos) {
        cout << "Código: " << produto.codigo << ", Nome: " << produto.nome << ", Preço: R$ " << produto.preco << endl;
    }
}

// Função para consultar o preço de um produto pelo código
void consultarPreco(const vector<Produto>& produtos) {
    string codigo;
    cout << "Digite o código do produto para consultar o preço: ";
    cin >> codigo;

    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo) {
            cout << "Preço do produto: R$ " << produto.preco << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

// Função para excluir um produto pelo código
void excluirProduto(vector<Produto>& produtos) {
    string codigo;
    cout << "Digite o código do produto a ser excluído: ";
    cin >> codigo;

    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->codigo == codigo) {
            produtos.erase(it);
            cout << "Produto excluído com sucesso." << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

int main() {
    vector<Produto> produtos;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Inserir Produto" << endl;
        cout << "2. Listar Produtos" << endl;
        cout << "3. Consultar Preço" << endl;
        cout << "4. Excluir Produto" << endl;
        cout << "5. Sair" << endl;

        int opcao;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserirProduto(produtos);
                break;
            case 2:
                listarProdutos(produtos);
                break;
            case 3:
                consultarPreco(produtos);
                break;
            case 4:
                excluirProduto(produtos);
                break;
            case 5:
                cout << "Saindo do programa." << endl;
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
