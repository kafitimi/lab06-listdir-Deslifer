#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count,folder,file,size;
bool dir,zx;
wchar_t d1,d2;

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
			}				 // ��������� ����� �� ���������??
			else
				file++;
			wprintf(L"file #%d, dir=%d, name <%s>, size=%d\n", count,dir,fileinfo.cFileName,fileinfo.nFileSizeLow);
			if (dir) {       
				SetCurrentDirectory(fileinfo.cFileName);
				dfs();
			}

    	// ...
    	// ����� ����� ����� � �������
		} while (FindNextFile(hFind, &fileinfo) != 0);
		FindClose(hFind);


                  	// ��������� ����� � �������
   // SetCurrentDirectory(L"..");
	//GetCurrentDirectory(512, s);
	//dfs();

}




int main(int argc, wchar_t* argv[]) {
    wchar_t s[512];               	// ������� �����
    GetCurrentDirectory(512, s);  	// �������� ������� �����
    wprintf(L"Starting in: %s\n", s);
    count = 0;                  	// �������� ������� ������
    size = 0;                   	// �������� ��������� ������ ������
	folder=0;
	file = 0;
    dfs();                      	// ��������� ����� � ������� �� ������� �����
 
    printf("File count = %d, folder count = %d, size = %d byte\n", file,folder,size);
    return 0;
}

