//
//  ArraySequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Sequence.h"
#include "Node.h"
#include <iostream>

Sequence::Sequence()
{
    content = new Node*[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        content[i] = nullptr;
    }
    this->quantity = 0;
    this->init = 0;
    this->end = 0;
}

Sequence::~Sequence()
{
    delete [] content;
}

/**
 Returns the i-th element in this sequence.
 */
Node* Sequence::get(int i)
{
    // Cuidado aqui! Se eu quero acessar o 1o elemento, preciso acessar a posição 0.
    // Ou seja, para acessar o i-ésimo elemento da sequência, preciso acessar a posição i-1 do array
    return content[i-1];
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, Node* element)
{
    std::cout << "Método insert ainda não implementado." << std::endl;
    std::exit(-1);
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(Node* element)
{
    if(this->isEmpty()){
        this->insertEnd(element);
    }
    else{
        for(int i=end;i>0;i--){
            content[i] = content[i-1];
        }
        content[0] = element;
        ++this->quantity;
        ++this->end;
    }
    /*std::cout << "Método insertBegin ainda não implementado." << std::endl;
    std::exit(-1);*/
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(Node* element)
{
    content[end] = element;
    ++this->quantity;
    ++this->end;
    /*std::cout << "Método insertEnd ainda não implementado." << std::endl;
    std::exit(-1);*/
}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
Node* Sequence::remove(int i)
{
    std::cout << "Método remove ainda não implementado." << std::endl;
    std::exit(-1);
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeBegin()
{
    if(this->isEmpty()){
        return nullptr;
    }
    else{
        Node * removido;
        removido = content[init];
        unsigned int i;
        for(i=init; i<end-1; i++){
            content[i] = content[i+1];
        }
        --this->end;
        --this->quantity;
        return removido;
    }
    /*std::cout << "Método removeBegin ainda não implementado." << std::endl;
    std::exit(-1);*/
}

/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeEnd()
{
    if(this->isEmpty()){
        return nullptr;
    }
    else{
        --this->end;
        --this->quantity;
        return content[end];
    }
}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
