#include <iostream>
using namespace std;

int main()
{
    struct Lista
    {
        int num;
        Lista *prox;
        Lista *ant;
    };
    Lista *inicio = NULL;
    Lista *fim = NULL;
    Lista *aux;
    int op, numero;

    do
    {
        cout << "\nMenu de Opcoes";
        cout << "\n1-Inserir";
        cout << "\n2-Consultar";
        cout << "\n3-Remover";
        cout << "\n4-Esvaziar";
        cout << "\n5-Sair";

        cin >> op;

        if (op < 1 || op > 5)
            cout << "Op invalida";

        if (op == 1)
        {
            Lista *novo = new Lista();

            cin >> novo->num;

            if (inicio == NULL) // lista vazia - insercao no comeco
            {
                novo->prox = NULL;
                novo->ant = NULL;
                inicio = novo;
                fim = novo;
            }
            else // Lista contem elementos - analise
            {
                aux = inicio;

                while (aux != NULL && novo->num > aux->num)
                {
                    aux = aux->prox;
                }

                if (aux == inicio) // Insere no inicio
                {
                    novo->prox = inicio;
                    novo->ant = NULL;
                    inicio->ant = novo;
                    inicio = novo;
                }
                else if (aux == NULL) // Insere no fim
                {
                    fim->prox = novo;
                    novo->ant = fim;
                    fim = novo;
                    fim->prox = NULL;
                }
                else // Insere no meio
                {
                    novo->prox = aux;
                    aux->ant->prox = novo;
                    novo->ant = aux->ant;
                    aux->ant = novo;
                }
            }
        }
        if (op == 2) // Consultar
        {
            if (inicio == NULL)
                cout << "Lista Vazia";
            else
            {
                aux = inicio;
                while (aux != NULL)
                {
                    cout << aux->num << " ";
                    aux = aux->prox;
                }
            }
        }

        if (op == 2) // Consultar
        {
            if (inicio == NULL)
                cout << "Lista Vazia";
            else
            {
                aux = inicio;
                while (aux != NULL)
                {
                    cout << aux->num << " ";
                    aux = aux->prox;
                }
            }
        }
        if (op == 4)
        {
            if (inicio == NULL)
            {
                cout << "Lista Vazia";
            }
            else
            {
                cout << "Digite o elemento a ser removido\n";
                cin >> numero;
                aux = inicio;
                while (aux != NULL)
                {
                    if (aux->num == numero) // numero encontrado
                    {
                        if (aux == inicio) // primeiro da lista
                        {
                            inicio = aux->prox;
                            if (inicio != NULL)
                                inicio->ant = NULL;
                            delete (aux);
                            aux = inicio;
                        }
                        else if (aux == fim) // ultimo da lista
                        {
                            fim = fim->ant;
                            fim->prox = NULL;
                            delete (aux);
                            aux = NULL;
                        }
                        else // meio da lista
                        {
                            aux->ant->prox = aux->prox;
                            aux->prox->ant = aux->ant;
                            Lista *aux2;
                            aux2 = aux->prox;
                            delete (aux);
                            aux = aux2;
                        }
                    }
                    else
                    {
                        aux = aux->prox;
                    }
                }
            }
        }
        if (op == 5) // esvaziamento
        {
            if (inicio == NULL)
            {
                cout << "Lista Vazia";
            }
            else // Tem elementos
            {
                aux = inicio;
                while (aux != NULL)
                {
                    inicio = inicio->prox;
                    delete (aux);
                    aux = inicio;
                }
            }
        }
    } while (op != 5);
    return 0;
}