#pragma once

void printArray(int* A, int len);
void expandArray(int*& A, int& len);
void addElement(int*& A, int& len, int element);
void contractArray(int*& A, int& len);
bool indexValid(int index, int len);
int extractElement(int*& A, int& len, int index);
void Reversearray(int*& A, int& len);
void RandomArray(int*& A, int& len, int n);
void arrayDeleteDuplicate(int*& A, int& len);
void selectionSort(int* A, int len);
int findSmallestPosition(int* A, int startPosition, int len);
void MaxMinArray(int* A, int len);
void printMenu();

