/////////////////////////////////////////////////////////////////////////////
// Catalogue.cpp - Support Operations on CataLogue						  //
// ver 1.0                                                                //
// ----------------------------------------------------------------------- // 
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2013                             //
// Platform:    Lenovo V570, Core i5, Windows 7 SP2	                       //
// Application: Object Oriented Design,Project-1 2015                      //
// Author:      Tanmay Fadnavis, Syracuse University					  //
//				315-560-3370, tfadnavi@syr.edu							//
/////////////////////////////////////////////////////////////////////////////

#include"Catalogue.h"
#include"../DataStore/DataStore.h"
#include"../FileManager/FileSystem.h"
#include"../Display/Display.h"

#include<iostream>
#include <sstream>
#include <string>

//Implementation of the methods

Catalogue::Catalogue(DataStore& ds) : store_(ds)
{
	
	
}

void Catalogue::findSummary() 
{	
	int noOfFiles=0;
	int noOfPaths=0;
	noOfPaths = store_.getPathSize();
	noOfFiles = store_.getFileSize();
	disp_.showSummary(noOfFiles, noOfPaths);
}

void Catalogue::showCatalogue()
{
	std::cout << "FileName \t\t\t\t\t\t Paths \n\n";
	std::set<std::string> tempPath;
	for (auto& temp : store_)
	{
		for (auto it : temp.second)
		{
			std::string path = *it;
			tempPath.insert(path);
		}
		disp_.showAll(temp.first, tempPath);
		tempPath.clear();
		std::cout << "\n-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-\n";
	}
	
}

void Catalogue::duplicateFiles()
{
	std::cout << "Duplicate files are - Demonstrating Requirement-5\n";
	std::cout << "FileName \t\t\t\t\t\t Paths \n\n";
	std::set<std::string> tempPath;
	for (auto& temp : store_)
	{
		if (temp.second.size() > 1)
		{
			for (auto it : temp.second)
			{
				std::string path = *it;
				tempPath.insert(path);
			}
			disp_.showDuplicates(temp.first, tempPath);
			tempPath.clear();
			std::cout << "\n-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-\n";
		}
	}
}

void Catalogue::search(const std::string& text)
{
	std::cout << "Demonstrating requirement-6: The search text \"" << text <<"\" found in \n";
	std::cout << "FileName \t\t\t\t\t\t Paths \n\n";
	for (auto& temp : store_)
	{
		for (auto it : temp.second)
		{
			std::string path = *it;
			std::string file = FileSystem::Path::fileSpec(path, temp.first);
			//FileSystem::File currentFile = FileSystem::File(file);
			std::ifstream infile(file);
			std::string line;
			while (std::getline(infile, line))
			{
				std::istringstream iss(line);
				if (line.find(text) != std::string::npos)
				{
					disp_.showSearchFiles(temp.first, path);
					line = "";
					break;
				}
			}
			
		}
	}
}

//New search method.

void Catalogue::newSearch(const std::string& text,const std::string& pattern)
{
	std::cout << "Demonstrating requirement-8: The search text \"" << text << "\" found in \n";
	std::cout << "FileName \t\t\t\t\t\t Paths \n\n";
	for (auto& temp : store_)
	{
		//if (FileSystem::Path::getExt())
		for (auto it : temp.second)
		{
			std::string path = *it;
			std::string file = FileSystem::Path::fileSpec(path, temp.first);
			std::string fileExt = FileSystem::Path::getExt(file);
			if (fileExt.compare(pattern.substr(pattern.find(".") + 1)) == 0 || (pattern=="*.*"))
			{
				//FileSystem::File currentFile = FileSystem::File(file);
				std::ifstream infile(file);
				std::string line;
				while (std::getline(infile, line))
				{
					std::istringstream iss(line);
					if (line.find(text) != std::string::npos)
					{
						disp_.showSearchFiles(temp.first, path);
						line = "";
						break;
					}
				}
			}

		}
	}
}


#ifdef TEST_CATALOGUE

int main()
{
	DataStore ds;
	bool directorySearch = false;
	bool duplicateFiles = false;
	std::string searchText = "";
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

}

#endif