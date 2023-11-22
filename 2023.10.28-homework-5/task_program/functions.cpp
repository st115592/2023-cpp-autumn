#include<ctime>
#include<cstdlib>
#include<iostream>



void printArray(int* A, int len)
{
	if (A == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << A[i] << " ";
		}
	}
	std::cout << std::endl;
}

void expandArray(int*& A, int& len)
{
	int* AE = new int[len + 1] { 0 };
	if (A != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			AE[i] = A[i];
		}
		delete[] A;
	}
	A = AE;
	++len;
}

void addElement(int*& A, int& len, int element)
{
	expandArray(A, len);
	A[len - 1] = element;
}

void contractArray(int*& A, int& len)
{
	if (A != nullptr)
	{
		int* AC = new int[len - 1];
		for (int i = 0; i < len - 1; ++i)
		{
			AC[i] = A[i];
		}
		delete[] A;
		A = AC;
		--len;
	}
}

bool indexValid(int index, int len)
{
	return (index >= 0 && index < len);
}

int extractElement(int*& A, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = A[index];
		for (int i = index; i < len - 1; ++i)
		{
			A[i] = A[i + 1];
		}
		contractArray(A, len);
	}
	return res;
}

void Reversearray(int*& A, int& len)
{
    if (A == nullptr)
    {
        std::cout << "EMPTY" << std::endl;
    }
    else
    {
        int* AR = new int[len] { 0 };

        for (int i = 0; i < len; i++)
        {
            AR[i] = A[len - 1 - i];
        }

        delete[] A;
        A = AR;
    }
}
void MaxMinArray(int* A, int len)
{
    if (A == nullptr)
    {
        std::cout << "EMPTY" << std::endl;
    }
    else
    {
        int a_max = 0;
        for (int i = 0; i < len; ++i)
        {
            if(A[i] > A[a_max])
            {
                a_max = i;
            }
        }
        int a_min = 0;
        for (int i = 0; i < len; ++i)
        {
            if ( A[i] <= A[a_min])
            {
                a_min = i;
            }
        }
        int k = 0;
        k = A[a_max];
        A[a_max] = A[a_min];
        A[a_min] = k;
    }
}
int findSmallestPosition(int* A, int startPosition, int len)
{
	int smallestPosition = startPosition;

	for(int i = startPosition; i < len; i++)
	{
		if(A[i] < A[smallestPosition])
			smallestPosition = i;
	}
	return smallestPosition;
}

void selectionSort(int* A, int len)
{
    if (A == nullptr)
    {
        std::cout << "EMPTY" << std::endl;
    }
    else
    {
        for(int i = 0; i < len; i++)
        {
            int smallestPosition = findSmallestPosition(A, i, len);
            int k = 0;
            k = A[i];
            A[i] = A[smallestPosition];
            A[smallestPosition] = k;
        }
    }
}
void arrayDeleteDuplicate(int*& A, int& len)
{
    if (A == nullptr)
    {
        std::cout << "EMPTY" << std::endl;
    }
    else
    {
        int* AD = new int[len];
        int duplicate = 0;
        int size = 0;
        for (int i = 0; i < len; i++)
        {
            duplicate = 0;

            for (int j = 0; j < size; j++)
            {
                if (A[i] == AD[j])
                {
                    duplicate = 1;
                    break;
                }
            }
            if (duplicate == 0)
            {
                AD[size] = A[i];
                size++;
            }
        }
        delete[] A;
        len = size;
        A = AD;
    }
}
void RandomArray(int*& A, int& len, int n)
{
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        int randomElement = rand() % (100 - (-100) + 1) - 50;
            addElement(A, len, randomElement);
    }
}
void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print array" << std::endl;
	std::cout << "2 - Append element to array" << std::endl;
	std::cout << "3 - Extract element from array" << std::endl;
	std::cout << "4 - reverse array" << std::endl;
	std::cout << "5 - swap the max and min elements of array" << std::endl;
	std::cout << "6 - sort array" << std::endl;
	std::cout << "7 - Extract repeating element from array" << std::endl;
	std::cout << "8 - Append random elements to array" << std::endl;
}
