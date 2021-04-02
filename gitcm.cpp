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
	
	if(!initialized){
		cerr << "Before using this command , don't forget to init and set the origin first, this command will initializing this project for you." << endl;
    	system("git init");	
	}else{
  	    system("git add .");
	    	
	    if(argc > 2){
		    string cmcmd = "git commit -m ";
		    string cmmsg;
		    
		    string pscmd = "git push -u origin ";
		    string branchname;
		    
		    
		    for(int i = 1; i < argc; i++){
		    	if(i == argc - 1){
		    		cout << "Branch name: " << argv[i] << endl;
		    		branchname += argv[i];
				}else{
					cmmsg += argv[i];
					cmmsg += " ";
				}
			}
			
			cmcmd += "\"";
			cmcmd += cmmsg;
			cmcmd += "\"";
			cout << "Commit message: " << cmcmd << endl;
		
			pscmd += branchname;
			
			system(cmcmd.c_str());
			system(pscmd.c_str());	  	
		}
	}
    
    return 0;
}
