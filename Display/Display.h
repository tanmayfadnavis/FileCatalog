#ifndef DISPLAY_H
#define DISPLAY_H


/////////////////////////////////////////////////////////////////////////////
// Display.h - Supports operations to display file/paths information      //
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
* This module provides Display class. The Display class provides
* methods to display the information, it receives from the Catalogue
* such as to display the summary of the DataStore, to display
* duplicate files, etc.
*
* Public Interface:
* =================
*	void showSummary(const int noOfFiles,const int noOfPaths);
*	void showDuplicates(std::string fileName, std::set<std::string> paths);
*	void showAll(std::string fileName,std::set<std::string> paths);
*	void showSearchFiles(std::string fileName, std::string path);
*
* Required Files:
* ===============
* Display.h Display.cpp
*
* Build Command:
* ==============
* cl /EHa /TEST_DISPLAY Display.cpp
*
* Maintenance History:
* ====================
* ver 1.0, First Release
*/


#include<set>

class Display
{
public:

	void showSummary(const int noOfFiles,const int noOfPaths);
	void showDuplicates(std::string fileName, std::set<std::string> paths);
	void showAll(std::string fileName,std::set<std::string> paths);
	void showSearchFiles(std::string fileName, std::string path);
};



#endif