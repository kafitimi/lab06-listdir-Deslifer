#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count,folder,size;
bool dir,zx;

/*int main1() {
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
		if (dir && count>2){
			SetCurrentDirectory(s);
			GetCurrentDirectory(512, s);
			main1();

		}

    	// ...
    	// ����� ����� ����� � �������
	} while (FindNextFile(hFind, &fileinfo) != 0);
	FindClose(hFind);


        //dfs();                     	// ��������� ����� � �������
   	 
    	wprintf(L"File count = %d, Folder count = %d\n", count,folder);
    	return 0;
}*/


void dfs() {
    // �������� ������� ������ � ����� � ������� �����
    // 1) ����� . � .. ����������
    // 2) ���� �����, �� ������� � ��� � �������� dfs
    // 3) ���� ����, �� ��������� ��� � ������ count � size
    // 4) ������� � ������������ �����

		HANDLE hFind;
		WIN32_FIND_DATA fileinfo;

		hFind=FindFirstFile(L"*", &fileinfo);
		//wprintf(L"%s\n", fileinfo.cFileName);
		
		do {
		dir=(fileinfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
		if (dir){
			folder++;
		}
    	count++; // ��������� ����� �� ���������??
		if (count>2){
    	wprintf(L"file #%d, dir=%d, name <%s>\n", count-2,dir, fileinfo.cFileName);
		}

    	// ...
    	// ����� ����� ����� � �������
	} while (FindNextFile(hFind, &fileinfo) != 0);
	FindClose(hFind);


        //dfs();                     	// ��������� ����� � �������
    SetCurrentDirectory(L"..");
}




int main(int argc, wchar_t* argv[]) {
    wchar_t s[512];               	// ������� �����
    GetCurrentDirectory(512, s);  	// �������� ������� �����
    wprintf(L"Starting in: %s\n", s);
	zx=1;
 
    count = 0;                  	// �������� ������� ������
    size = 0;                   	// �������� ��������� ������ ������
	folder=0;
    dfs();                      	// ��������� ����� � ������� �� ������� �����
 
    printf("File count = %d, folder count = %d, size = %lld\n", count,folder-2,size);
    return 0;
}

