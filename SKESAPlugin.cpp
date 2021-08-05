#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "SKESAPlugin.h"

void SKESAPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string filename;
   ifile >> filename;
   fastqFiles.push_back(filename);
 }
}

void SKESAPlugin::run() {
   
}

void SKESAPlugin::output(std::string file) {
 // spades.py -o 02_SKESA -1 $1 -2 $2 --careful
	std::string command = "skesa --fastq "+std::string(PluginManager::prefix())+"/"+fastqFiles[0]+","+std::string(PluginManager::prefix())+"/"+fastqFiles[1]+" > "+file;
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<SKESAPlugin> SKESAPluginProxy = PluginProxy<SKESAPlugin>("SKESA", PluginManager::getInstance());
