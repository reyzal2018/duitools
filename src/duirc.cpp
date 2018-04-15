// duirc.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <Windows.h>
#include <ShellAPI.h>
//使用7z打包资源文件
//参数1 uires所在路径
//参数2 目标zip文件目录
int main(int argc, char* argv[])
{
	for (size_t i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	if (argc < 3)
	{
		printf("参数太少\n");
		return 0;
	}

	char szPath[260];
	char szDst[260];
	char szExePath[260];
	char szCmdLine[1024];
	strcpy(szPath, argv[1]);
	strcpy(szDst, szPath);
	strcat(szDst, "\\duires.zip");
	strcat(szPath, "\\uires\\*");
	strcpy(szExePath, argv[0]);
	*strrchr(szExePath, '\\') = '\0';
	strcat(szExePath, "\\7z.exe");
	sprintf(szCmdLine, "%s a -tzip \"%s\" \"%s\"", szExePath, szDst, szPath);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	memset(&si, 0, sizeof(STARTUPINFO));
	si.wShowWindow = SW_HIDE;
	memset(&pi, 0, sizeof(PROCESS_INFORMATION));
	si.cb = sizeof(STARTUPINFO);
	CreateProcess(NULL, szCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, 5 * 60 * 1000);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	printf("%s\n", szCmdLine);
    return 0;
}

