/*************************************************************************
    > File Name: listDir.c
    > Author: wht
    > Mail: vi_pzp@163.com 
    > Created Time: 2016年06月06日 星期一 13时22分35秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>

const char *fileName = "/home/wht/myProject/log/";

int listDir(const char *fileName)
{
	DIR *dirp = NULL;
	struct dirent *ent = NULL;

	dirp = opendir(fileName);
	if (NULL == dirp)
	{
	//	printf("opendir failed\n");
		return -1;
	}

	while(ent = readdir(dirp))
	{
		if (ent->d_type == 8 ||
				ent->d_type == 10)
		{
			printf("%s/%s\n", fileName, ent->d_name);
			continue ;
		}
		else if (ent->d_type == 4)
		{
			if ((strcmp(ent->d_name, ".") == 0)
					|| (0 == strcmp(ent->d_name, "..")))
			{
				continue ;
			}
			char filePath[256] = {0};
			snprintf(filePath, 256, "%s/%s",fileName, ent->d_name);
			listDir(filePath);
		}
	}
	
	closedir(dirp);
	return 0;
}

int main(int argc, char **argv)
{
	listDir(fileName);
	return 0;
}
