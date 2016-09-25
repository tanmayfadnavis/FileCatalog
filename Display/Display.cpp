/////////////////////////////////////////////////////////////////////////////
// Display.cpp - Supports operations to display file/paths information 	  //
// ver 1.0                                                                //
// ----------------------------------------------------------------------- // 
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2013                             //
// Platform:    Lenovo V570, Core i5, Windows 7 SP2	                       //
// Application: Object Oriented Design,Project-1 2015                      //
// Author:      Tanmay Fadnavis, Syracuse University					  //
//				315-560-3370, tfadnavi@syr.edu							//
/////////////////////////////////////////////////////////////////////////////

#include"Display.h"
#include <iostream>
#include <string>


//Implementing methods

void Display::showSummary(const int noOfFiles, const int noOfPaths)
{
	std::cout << "The Summary of the total files and paths - Demonstrating requirement-7\n";
	std::cout << "-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-\n";
	std::cout << noOfFiles << " files found in " << noOfPaths << " directories\n";
	std::cout << "-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-\n";
}


void Display::showAll(std::string fileName, std::set<std::string> paths)
{
	
	std::cout << fileName <<"\t\t\t\t";
	for (std::set<std::string>::iterator it = paths.begin(); it != paths.end(); ++it)
		std::cout <<  *it << "\n\t\t\t\t\t\t";
	
}

void Display::showDuplicates(std::string fileName, std::set<std::string> paths)
{

	std::cout << fileName << "\t\t\t\t";
	for (std::set<std::string>::iterator it = paths.begin(); it != paths.end(); ++it)
		std::cout << *it << "\n\t\t\t\t\t\t";
	
}


void Display::showSearchFiles(std::string fileName, std::string path)
{
	std::cout  << fileName << "\t\t\t\t" << path <<"\n";

}

#ifdef TEST_DISPLAY

int main()
{
	Display d;
	int noOfFiles = 3;
	int noOfPaths = 4;
	d.showSummary(noOfFiles, noOfPaths);
	std::string fileName = "ObjectOrirntedDesign.txt";
	std::string path = "../TestPath";
	std::set<std::string> paths;
	paths.insert("../TestPath");
	paths.insert("../TestPath/Folder1");
	d.showAll(fileName, paths);
	d.showDuplicates(fileName, paths);
	d.showSearchFiles(fileName, path);

}


#endif