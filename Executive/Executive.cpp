/////////////////////////////////////////////////////////////////////////////
// Executive.cpp - The main entry point for the application- File Catalogue//
// ver 1.0                                                                //
// ----------------------------------------------------------------------- // 
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2013                             //
// Platform:    Lenovo V570, Core i5, Windows 7 SP2	                       //
// Application: Object Oriented Design,Project-1 2015                      //
// Author:      Tanmay Fadnavis, Syracuse University					  //
//				315-560-3370, tfadnavi@syr.edu							//
/////////////////////////////////////////////////////////////////////////////
/*
* Module Operations:
* ==================
* This is the main entry point for the application- File Catalogue.
* The main() starts the application. It takes the input from command
* line and builds the Data Store and Displays the appropriate output.
* Public Interface:
* =================
*	int main(int argc, char *argv[])
*
* Required Files:
* ===============
* Display.h DataStore.h FileManager.h FileSystem.h Catalogue.h
*
* Build Command:
* ==============
* cl /EHa / Executive.cpp
*
* Maintenance History:
* ====================
* ver 1.0, First Release
*/

#include"../DataStore/DataStore.h"
#include"../FileManager/FileManager.h"
#include"../FileManager/FileSystem.h"
#include"../Catalogue/Catalogue.h"

#include<iostream>
#include<map>
#include<vector>

int main(int argc, char *argv[])
{
	std::string inputPath = argv[1];
	DataStore ds;
	FileManager fm(inputPath, ds);
	int noOfArguments = argc;
	bool directorySearch = false;
	bool duplicateFiles = false;
	std::string searchText = "";
	for (int i = 2; i <= argc-1; i++)
	{
		//For recursive search
		std::string tempArg = std::string(argv[i]);

		if (tempArg.find("/s") != std::string::npos)
			directorySearch = true;
		else if (tempArg.find("/d") != std::string::npos)
			duplicateFiles = true;
		else if (tempArg.find(".") != std::string::npos)
		{
			fm.addPattern(argv[i]);
		}
		else if (tempArg.find("/f") != std::string::npos)
		{
			searchText = tempArg.substr(tempArg.find("/f")+2);
		}
	} 
	fm.search(directorySearch);
	Catalogue cs(ds);
	cs.findSummary();
	cs.showCatalogue();
	if (duplicateFiles)
	{
		cs.duplicateFiles();
	}	
	if (searchText != "")
	{
		cs.search(searchText);
	}	
	std::string newSearch, newPattern;
	while (true){
		std::cout << "\n Enter Text to search or 'e' to exit \n";
		std::cin >> newSearch;
		if (newSearch == "e")
			exit(0);
		std::cout << "\n Enter Pattern\n";
		std::cin >> newPattern;
		cs.newSearch(newSearch, newPattern);
	}
	return 0;
}
