/////////////////////////
// main.cpp
////////////////////////

#include <stdio.h>
#include <string.h>
#include <errno.h> // библиотека ошибок
int commandDetection(char *argv[]) // функция для определенения необходимого действия в файловой системе
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

	/* перменная argc показывает число аргументов переданных при запуске прогрммы.
	   адрес программы так же передается и хранится в argv[0]
	*/

	if (argc >= 3) // проверяем достаточность колличества аргументов
	{
		int result = -1; // переменная обозначающая тип выполняемой команды { -c или -d}
		result = commandDetection(&argv[1]);
		switch (result)
		{
		case 0: // создать файл
			{
				FILE *f = fopen(argv[2], "a+");// создаем или открываем файл с того места где он закончен.
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
		case 1: // удалить файл
			{
				int ret = remove(argv[2]); // значение возвращаемое функцией удаления файла
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
		printf("Error 0:There are not enough arguments"); // недостаточно аргументов для исполнения действий
	}
	getchar();
	//end;-
	return 0;
}