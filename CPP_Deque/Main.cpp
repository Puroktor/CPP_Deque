#include "Deque.h"
#include <iostream>
#include <deque>

using std::cout;
using std::endl;

void testDequeFrontOperations()
{
    cout << "-------Front-------" << endl;
    auto deque = new Colelctions::Deque<int>();
    auto stdDeque = new std::deque<int>();

    deque->push_front(1);
    deque->push_front(2);
    deque->push_front(3);

    stdDeque->push_front(1);
    stdDeque->push_front(2);
    stdDeque->push_front(3);

    cout << deque->at(1) << " expected " << stdDeque->at(1) << endl;
    cout << deque->front() << " expected " << stdDeque->front() << endl;

    deque->pop_front();
    deque->pop_front();
    stdDeque->pop_front();
    stdDeque->pop_front();

    cout << deque->front() << " expected " << stdDeque->front() << endl;

    deque->pop_front();
    stdDeque->pop_front();

    cout << "Empty: " << deque->empty() << " expected " << stdDeque->empty() << endl;
    cout << "-------------------" << endl;
    delete deque;
    delete stdDeque;
}

void testDequeBackOperations()
{
    cout << "-------Back-------" << endl;
    auto deque = new Colelctions::Deque<char>();
    auto stdDeque = new std::deque<char>();

    deque->push_back('a');
    deque->push_back('b');
    deque->push_back('c');
    stdDeque->push_back('a');
    stdDeque->push_back('b');
    stdDeque->push_back('c');

    cout << deque->at(1) << " expected " << stdDeque->at(1) << endl;
    cout << deque->back() << " expected " << stdDeque->back() << endl;

    deque->pop_back();
    deque->pop_back();
    stdDeque->pop_back();
    stdDeque->pop_back();

    cout << deque->back() << " expected " << stdDeque->back() << endl;
    cout << "Size: " << deque->size() << " expected " << stdDeque->size() << endl;
    cout << "-------------------" << endl;

    delete deque;
    delete stdDeque;
}

void testDequeMixedOperations()
{
    cout << "-------Mixed-------" << endl;
    auto deque = new Colelctions::Deque<const char*>();
    auto stdDeque = new std::deque<const char*>();

    deque->push_back("abc");
    deque->push_front("31da");
    deque->push_front("+12d");
    deque->push_back("-87!3");
    stdDeque->push_back("abc");
    stdDeque->push_front("31da");
    stdDeque->push_front("+12d");
    stdDeque->push_back("-87!3");

    cout << deque->front() << " expected " << stdDeque->front() << endl;
    cout << deque->back() << " expected " << stdDeque->back() << endl;

    deque->pop_back();
    deque->pop_front();
    stdDeque->pop_back();
    stdDeque->pop_front();

    cout << deque->back() << " expected " << stdDeque->back() << endl;
    cout << deque->front() << " expected " << stdDeque->front() << endl;

    cout << "Size: " << deque->size() << " expected " << stdDeque->size() << endl;
    cout << "Empty: " << deque->empty() << " expected " << stdDeque->empty() << endl;

    cout << "-------------------" << endl;
    delete deque;
    delete stdDeque;
}

int main()
{
    testDequeFrontOperations();
    testDequeBackOperations();
    testDequeMixedOperations();
}
