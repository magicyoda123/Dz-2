/////////////////////////
// main.cpp
////////////////////////

#include <stdio.h>
#include <string.h>
#include <errno.h> // ���������� ������
int commandDetection(char *argv[]) // ������� ��� ������������� ������������ �������� � �������� �������
{
	if (strcmp(argv[0], "-c") == 0)
	{
		
		return 0;
	}
	else if (strcmp(argv[0], "-d") == 0)
	{
		return 1;
	}
	else 
	{
		return 2;
	}
}
int main(int argc, char* argv[]){

	/* ��������� argc ���������� ����� ���������� ���������� ��� ������� ��������.
	   ����� ��������� ��� �� ���������� � �������� � argv[0]
	*/

	if (argc >= 3) // ��������� ������������� ����������� ����������
	{
		int result = -1; // ���������� ������������ ��� ����������� ������� { -c ��� -d}
		result = commandDetection(&argv[1]);
		switch (result)
		{
		case 0: // ������� ����
			{
				FILE *f = fopen(argv[2], "a+");// ������� ��� ��������� ���� � ���� ����� ��� �� ��������.
				if (f == NULL)
				{
					printf("Error 1: Cannot create file\n");
					printf("Err name:%d", errno);
				}
				else
				{
					fclose(f);
					printf("File succesfully created\n");
				}
				break;
			}
		case 1: // ������� ����
			{
				int ret = remove(argv[2]); // �������� ������������ �������� �������� �����
				if (ret == 0)
				{
					printf("File deleted successfully\n");
				}
				else
				{
					printf("Error 2: Cannot delete file\n");
					printf("Err name:%d", errno);
				}
				break;
			}
		case 2: // 
			{
				printf("Unknown command");
				break;
			}
		
		}
	}
	else
	{
		printf("Error 0:There are not enough arguments"); // ������������ ���������� ��� ���������� ��������
	}
	getchar();
	//end;
	return 0;
}