#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count,folder;

int main1() {
    	wchar_t s[512];              	// ������� �����
		bool dir;
    	GetCurrentDirectory(512, s);	// �������� ������� �����
    	wprintf(L"Starting in: %s\n", s);

    	count = 0;                  	// �������� ������� ������  
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
    	count++; // ��������� ����� �� ���������??
    	wprintf(L"file #%d, dir=%d, name <%s>\n", count,dir, fileinfo.cFileName);

    	// ...
    	// ����� ����� ����� � �������
	} while (FindNextFile(hFind, &fileinfo) != 0);
	FindClose(hFind);


        //dfs();                     	// ��������� ����� � �������
   	 
    	wprintf(L"File count = %d, Folder count = %d\n", count,folder);
    	return 0;
}


/*void dfs() {
	HANDLE hFind;                   	// ����� ������
	WIN32_FIND_DATA res;            	// ��������� ������

	CHAR dir[] = ".\\*";
	hFind = FindFirstFile(dir, &res);   // ����� ������ ����

	do {
    	count++; // ��������� ����� �� ���������??
    	_tprintf(TEXT("file #%d is <%s>\n"), count, res.cFileName);

    	// ...
    	// ����� ����� ����� � �������
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
}
*/
int main(){
	main1();

}
