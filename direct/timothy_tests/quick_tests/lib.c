#include "lib.h"


void join_paths(char *path1,char *path2,char *new_path ){

	//strcat(new_path,path1);	/*since all functions have this then pull it out*/
	if ( (path1[(sizeof(path1)/sizeof(char))-2]=='/') && path2[0]!='/') {
		/*paths are compatiable. concatanate them. note -2 is because of \0*/  
		strcat(new_path,path1);
		strcat(new_path,path2);		
		//char new_path[(sizeof(path1)/sizeof(char))+(sizeof(path2)/sizeof(char))];
		//strcpy(new_path,strcat(path1,path2)); 
		//return new_path;
	}	
	else if ((path1[(sizeof(path1)/sizeof(char))-2]!='/') && path2[0]=='/') {
		/*paths are compatiable. concatanate them*/  
		strcat(new_path,path1);
		strcat(new_path,path2);		

	}
	else if ((path1[(sizeof(path1)/sizeof(char))-2]!='/') && path2[0]!='/') {
			/*need to add a "/". */  
		strcat(new_path,path1);
		strcat(new_path,"/");
		strcat(new_path,path2);


	}
	else if ((path1[(sizeof(path1)/sizeof(char))-2]=='/') && path2[0]=='/') {
		/*need to remove a "/". */
		/*yaffs does not mind the extra slash. */		
		strcat(new_path,path1);
		strcat(new_path,path2);

	} 
	else{
		//error 
		//return -1;
	}
}
