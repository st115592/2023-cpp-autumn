#include "��_�����_�����.h"

��������� �������(������ �������, ������ ������ = ��������, ������ ���� = �����������)
{
	���� (������� <= ����)
	{
		�������;
	}

	������ ����� = ������� - ������ - ����;

	���� (������� == ��������)
	{
		����::������� << �������� << " " << ������ << " " << ���� << ����::����_����;
	}
	������
	{
		�������(������� - ��������, ������, ����);
		�������(������� - �������, ����, �����);
		����::������� << ���� << " " << ������ << " " << ���� << ����::����_����;
		�������(������� - �������, �����, ������);
		�������(������� - ��������, ������, ����);
	}
}

������ main(������ ������������, �����* ������������[])
{
	������ � = ����;
	����::�������� >> �;
	�������(�);
	������� ����;
}