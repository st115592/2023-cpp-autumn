#include<ctime>
#include<cstdlib>
#include<iostream>

#include"header.h"

int main(int argc, char* argv[])
{
	int* A = nullptr;
	int len = 0;
	int n = 0;
	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			printArray(A, len);
		}
		int choice = 0;
		{
			std::cin >> choice;
		}
		{
			switch (choice)
			{
			case 0:
				exit = true;
				break;
			case 1:
				printArray(A, len);
				system("pause");
				break;
			case 2:
			{
				int element = 0;
				std::cout << "Input element to add : ";
				std::cin >> element;
				addElement(A, len, element);
				break;
			}
			case 3:
			{
				int index = 0;
				std::cout << "Input index to extract : ";
				std::cin >> index;
                extractElement(A, len, index);
				break;
			}
			case 4:
            {
                Reversearray(A, len);
                break;
			}
			case 5:
            {
                MaxMinArray(A, len);
                break;
            }
            case 6:
            {
                selectionSort(A, len);
                break;
            }
            case 7:
            {
                arrayDeleteDuplicate(A, len);
                break;
            }
            case 8:
            {
                std::cout << "input amount of elements to add : ";
                std::cin >> n;
                RandomArray(A, len, n);
                break;
            }
			default:
				std::cout << "Unknown command" << std::endl;
				system("pause");
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}


