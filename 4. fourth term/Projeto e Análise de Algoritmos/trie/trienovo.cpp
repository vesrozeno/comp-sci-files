#include "trie.h"
#include <iostream>
#include <cstring>
#include <stdexcept>

Trie::Trie(unsigned alphabetSize)
    : amountOfKeysStored(0)
{
    TrieNode::alphabetSize = alphabetSize;
}


TrieNode* Trie::PrefixSearch(TrieNode *x, std::string prefix, int trieLevel){
    int i = 0;
    TrieNode *current = new TrieNode();
    current = x;

    for (i = 0; i < prefix.size(); i++)
        if(current->arrSubTries[prefix[i]] != nullptr)
            current = current->arrSubTries[prefix[i]];
        else 
            return nullptr;

    recursivePrint(prefix, current);
}

void Trie::recursivePrint(std::string prefix, TrieNode *current){
    int i = 0;

    if(current == nullptr)
        return;

    if(current->isLeaf){
        std::cout << prefix << std::endl;
    }

    for (i = 0; i < 127; i++){
        char letter = (char)i;
        prefix.push_back(letter);
        recursivePrint(prefix, current->arrSubTries[i]);
        prefix.pop_back();

    }
}

bool Trie::printPrefixedWords(std::string prefix){
    //se prefixo vazio, retorna erro
    if(prefix.empty())
        throw std::invalid_argument("The string must have some chars");
    
    //pesquisa e imprime as palavras com esse prefixo 
    TrieNode *x = PrefixSearch(trieRoot, prefix, 0);

    if(x == nullptr)
        return false;
    return true;
}

bool Trie::search(const std::string key)
{

    /* Não são permitidas buscas nulas */
    if (key.empty())
        throw std::invalid_argument("The string must have some chars");

    /* chama o método recursivo get que fará a busca na árvore */
    TrieNode* x = get(trieRoot, key, 0);

    /* Chave não encontrada */
    if (x == nullptr)
        return false;

    /* se isLeaf == true então a chave foi encontrada */
    return true;
}

TrieNode* Trie::get(TrieNode* x, const std::string key, int trieLevel)
{
    /* Nó nulo a chave não se encontra na árvore */
    if (x == nullptr)
        return nullptr;

    /*
     * Se a profundidade da árvore (trieLevel) for igual a quantidade de caracteres
     * (key.length()) então a chave tem um cadidato a "hit" se este nó for uma folha
     * (isLeafe() == true) então se tem um "hit" se não se tem um "miss"
     */
    if (trieLevel == key.length()) {
        if (x->isLeaf)
            return x;
        else
            return nullptr;
    }

    /*
     * Elemento não encontrado, recupera o próximo caractere e reinicia as
     * verificações com uma chamada recursiva
     */
    char c = key[trieLevel];
    return get(x->arrSubTries[c], key, trieLevel + 1);
}


void Trie::insert(const std::string key)
{
    /* Não são permitidas inserções nulas */
    if (key.empty())
        throw std::invalid_argument("The string must have some chars");

    /* chama o método recursivo get que fará a inserção na árvore */
    trieRoot = add(trieRoot, key, 0);
}

TrieNode* Trie::add(TrieNode* x, const std::string key, int trieLevel)
{
    /*
     * Se o nó é nulo então a chave completa não está na árvore, é necessário criar
     * um novo nó para alocar tal caractere, perceba que este nó deve ser do tamanho
     * do alfabeto adotado
     */
    if (x == nullptr) {
        x = new TrieNode();
        x->setAlphabetSize(TrieNode::alphabetSize);
    }

    /*
     * Se a profundidade da árvore (trieLevel) for igual a quantidade de caracteres
     * (key.length()) então a chave está completa dentro da árvore;
     */
    if (trieLevel == key.length()) {

        /*
         * Há que se verificar se a chave encontrada NÃO é uma folha. Caso NÃO seja
         * incrementa o indicador de quantidade de chaves armazenadas
         */
        if (!x->isLeaf) {
            this->amountOfKeysStored++;
        }

        /* Marca como folha */
        x->isLeaf = true;

        /* Retorna a folha inserida */
        return x;
    }

    /*
     * Se a profundidade da árvore (trieLevel) ainda não for igual a quantidade de
     * caracteres (key.length()) então prepara uma chamada recursiva para
     * verficação/criação de um novo nó
     */
    char c = key[trieLevel];
    x->arrSubTries[c] = add(x->arrSubTries[c], key, trieLevel + 1);

    /* Retorna a folha inserida */
    return x;
}

void Trie::deleteNode(const std::string key)
{

    /* Não são permitidas inserções nulas */
    if (key.empty())
        throw std::invalid_argument("The string must have some chars");

    /* chama o método recursivo get que fará a remoção na árvore */
    trieRoot = deleteNode(trieRoot, key, 0);
}

TrieNode* Trie::deleteNode(TrieNode* x, std::string key, int trieLevel)
{

    /* Nó nulo a chave não se encontra na árvore */
    if (x == nullptr)
        return nullptr;

    /*
     * Se a profundidade da árvore (trieLevel) for igual a quantidade de caracteres
     * (key.length()) então a chave tem um cadidato a remoção.
     */
    if (trieLevel == key.length()) {
        /*
         * Se este nó for uma folha (isLeafe() == true) então o nó é desmarcado como
         * folha e a contagem de item da trie é decrementada
         */
        if (x->isLeaf)
            amountOfKeysStored--;

        x->isLeaf = false;
    } else {

        /*
         * Se a profundidade da árvore (trieLevel) ainda não for igual a quantidade de
         * caracteres (key.length()) então prepara uma chamada recursiva para
         * verficação/remoção de próximo nó
         */
        char c = key[trieLevel];
        x->arrSubTries[c] = deleteNode(x->arrSubTries[c], key, trieLevel + 1);
    }

    /*
     * Na volta das chamadas recursivas, no momento em que uma folha for encontrada a
     * deleção da árvore é terminada retornando-se um nó válido
     */
    if (x->isLeaf)
        return x;

    /*
     * Se o nó não é valido, anula todos os nós abaixo deste e, em seguinda, retorna
     * um endereço nulo para o nivel acima
     */
    for (int i = 0; i < TrieNode::alphabetSize; i++)
        if (x->arrSubTries[i] != nullptr)
            return x;

    delete x;
    return nullptr;
}
