#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count,folder;

int main1() {
    	wchar_t s[512];              	// текущая папка
		bool dir;
    	GetCurrentDirectory(512, s);	// получить текущую папку
    	wprintf(L"Starting in: %s\n", s);

    	count = 0;                  	// обнулить счетчик файлов  
		folder=0;
		HANDLE hFind;
		WIN32_FIND_DATA fileinfo;

		hFind=FindFirstFile(L"*", &fileinfo);
		wprintf(L"%s\n", fileinfo.cFileName);
		
		do {
		dir=(fileinfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
		if (dir){
			folder++;
		}
    	count++; // некоторые файлы не считаются??
    	wprintf(L"file #%d, dir=%d, name <%s>\n", count,dir, fileinfo.cFileName);

    	// ...
    	// здесь будет обход в глубину
	} while (FindNextFile(hFind, &fileinfo) != 0);
	FindClose(hFind);


        //dfs();                     	// запустить обход в глубину
   	 
    	wprintf(L"File count = %d, Folder count = %d\n", count,folder);
    	return 0;
}


/*void dfs() {
	HANDLE hFind;                   	// номер поиска
	WIN32_FIND_DATA res;            	// результат поиска

	CHAR dir[] = ".\\*";
	hFind = FindFirstFile(dir, &res);   // найти первый файл

	do {
    	count++; // некоторые файлы не считаются??
    	_tprintf(TEXT("file #%d is <%s>\n"), count, res.cFileName);

    	// ...
    	// здесь будет обход в глубину
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
}
*/
int main(){
	main1();

}
