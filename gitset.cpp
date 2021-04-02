#ifdef __MINGW32__
#include <windows.h>
#endif
#include <iostream>
using namespace std;

bool DirectoryExists(const char* dirName) {
  DWORD attribs = ::GetFileAttributesA(dirName);
  if (attribs == INVALID_FILE_ATTRIBUTES) {
    return false;
  }
  return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}

int main(int argc, char** argv) {
	bool initialized = DirectoryExists(".git");
	
	if(!initialized)
    	system("git init");	

	if(argc > 1){
			string bccmd = "git branch -M ";
	    	string branchname;
	    	
		    if(argc == 3){
		    	branchname += argv[2];
			}else{
				branchname += "master";
			}
			
			bccmd += branchname;
			system(bccmd.c_str());
			
			string orcmd = "git remote add origin ";
			orcmd += argv[1];
			
			system(orcmd.c_str());
	}else{
		cout << "Command error: please provide the <origin-url> argument. " << endl;
	}
    
    return 0;
}
