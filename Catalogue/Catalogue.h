#ifndef CATALOGUE_H
#define CATALOGUE_H


/////////////////////////////////////////////////////////////////////////////
// Catalogue.h - Support Operations on Catalogue						  //
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
* This module provides catalogue class. Its main function is to interact
* with the DataStore and perform all the calculations. The Catalogue shows
* the summary of the files and the paths present in the data store.
* The catalogue also displays the duplicate files. It also
* searches for the text given by the user and displays the files
* which has that text present
*
* Public Interface:
* =================
*	Catalogue(DataStore& ds):: store_(ds);
*
*	void findSummary();
*	void duplicateFiles();
*	void search(const std::string& text);
*	void showCatalogue();
*
* Required Files:
* ===============
* Catalogue.h, Catalogue.cpp DataStore.h FileManager.h Display.h
*
* Build Command:
* ==============
* cl /EHa /TEST_CATALOGUE Catalogue.cpp
*
* Maintenance History:
* ====================
* ver 1.0, First Release
*/
#include"../DataStore/DataStore.h"
#include"../FileManager/FileSystem.h"
#include"../Display/Display.h"
#include<string>
#include<set>

class Catalogue
{

public:
	
	Catalogue(DataStore& ds);

	void findSummary();
	void duplicateFiles();
	void search(const std::string& text);
	void newSearch(const std::string& text, const std::string& pattern);
	void showCatalogue();

private:
	DataStore& store_;
	Display disp_;
};


#endif