#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

char *make_name(char *name)
{
	char *new_name;

	int i, j, len;

	len = strlen(name);
	//printf("length: %d\n", len);
	new_name = (char *)malloc(sizeof(len));
	
	if(len <= 1)
		return;
	i = j = 0;
	while(name[i]){
		if((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))
			break;
	//	printf("%c", name[i]);
		i++;
	}
	while(name[i]){
		new_name[j] = name[i];
		i++;
		j++;
	}
	new_name[j] = '\0';

	return new_name;

}

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	char old_path[255] = {0,};
	char new_path[255] = {0,};

	if(argc < 2){
		printf("Wrong format!");
		exit(1);
	}


	if((dp = opendir(argv[1])) == NULL){
		printf("Can't read the directory!");
		exit(1);
	}
	while((dirp = readdir(dp)) != NULL){
		if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
			continue;
		printf("%s\n", dirp->d_name);
		
		strcpy(old_path, argv[1]);
		strcpy(new_path, argv[1]);
		
		strcat(old_path, dirp->d_name);
		strcat(new_path, make_name(dirp->d_name));

		if(rename(old_path, new_path) < 0){
			printf("Can't rename %s\n", dirp->d_name);
		}
		printf("%s\n", new_path);
	}

	if(closedir(dp) < 0){
		printf("Can't close directory");
		exit(1);
	}

	return 0;
}
