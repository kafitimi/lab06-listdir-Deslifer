#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count,folder,file,size;
bool dir,zx;
wchar_t d1,d2;

/*int main1() {
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
		if (dir && count>2){
			SetCurrentDirectory(s);
			GetCurrentDirectory(512, s);
			main1();

		}

    	// ...
    	// здесь будет обход в глубину
	} while (FindNextFile(hFind, &fileinfo) != 0);
	FindClose(hFind);


        //dfs();                     	// запустить обход в глубину
   	 
    	wprintf(L"File count = %d, Folder count = %d\n", count,folder);
    	return 0;
}*/


void dfs() {
    // начинает перебор файлов и папок в текущей папке
    // 1) папки . и .. пропускаем
    // 2) если папка, то заходим в нее и вызываем dfs
    // 3) если файл, то посчитаем его в суммах count и size
    // 4) выходим в родительскую папку
		wchar_t s[512];
		HANDLE hFind;
		WIN32_FIND_DATA fileinfo;

		hFind=FindFirstFile(L"*", &fileinfo);
		FindNextFile(hFind, &fileinfo);
		FindNextFile(hFind, &fileinfo);
		do {
			count++;
			size += fileinfo.nFileSizeLow;
			dir=(fileinfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
			if (dir) {
				folder++;
			}				 // некоторые файлы не считаются??
			else
				file++;
			wprintf(L"file #%d, dir=%d, name <%s>, size=%d\n", count,dir,fileinfo.cFileName,fileinfo.nFileSizeLow);
			if (dir) {       
				SetCurrentDirectory(fileinfo.cFileName);
				dfs();
			}

    	// ...
    	// здесь будет обход в глубину
		} while (FindNextFile(hFind, &fileinfo) != 0);
		FindClose(hFind);


                  	// запустить обход в глубину
   // SetCurrentDirectory(L"..");
	//GetCurrentDirectory(512, s);
	//dfs();

}




int main(int argc, wchar_t* argv[]) {
    wchar_t s[512];               	// текущая папка
    GetCurrentDirectory(512, s);  	// получить текущую папку
    wprintf(L"Starting in: %s\n", s);
    count = 0;                  	// обнулить счетчик файлов
    size = 0;                   	// обнулить суммарный размер файлов
	folder=0;
	file = 0;
    dfs();                      	// запустить обход в глубину из текущей папки
 
    printf("File count = %d, folder count = %d, size = %d byte\n", file,folder,size);
    return 0;
}

