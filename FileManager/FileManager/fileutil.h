#pragma once
#include<iostream>
#include<io.h>
#include<string>
#include<unordered_set>

void searchDir(const std::string& path, std::unordered_set<std::string>& subFiles);

void deletFile(const char* filename);
