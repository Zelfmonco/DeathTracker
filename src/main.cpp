#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <filesystem>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace geode::prelude;

std::string filename;
int attempts;
int percentage;
int value;
int id;

int getLineAndIncrement(int line_Number)
{
	std::vector<std::string> lines;
	std::string line;

	std::fstream rfile;
	rfile.open(filename);

	while (getline(rfile, line))
	{
		lines.push_back(line);
	}

	rfile.close();

	std::ofstream wfile;

	wfile.open(filename);

	if(wfile.fail())
	{
		FLAlertLayer::create("DeathTracker", "error opening" + filename, "OK")->show();
	}

	for (int i = 0; i < lines.size(); i++)
	{
		if(i != line_Number)
			wfile << lines[i] << std::endl;
		else
		{
			wfile << value + 1 << std::endl;
		}
	}
	wfile.close();
	return 0;
}

int getLineAndValue(int line_Number, GJGameLevel *level)
{
	id = level->m_levelID.value();
	line_Number++;

	std::ifstream rfile;

	std::string path = Mod::get()->getSaveDir().generic_string();
	filename = path + "/level_" + std::to_string(id) + ".txt";

	rfile.open(filename);
	if (rfile.fail())
	{
		std::ofstream file;

		std::string path = Mod::get()->getSaveDir().generic_string();
		filename = path + "/level_" + std::to_string(id) + ".txt";

		file.open(filename);

		int eline = 0;
		while(eline < 100)
		{
			file << "0\n";
			eline++;
		}

		file.close();
		rfile.open(filename);
	}

	int current_line = 0;
	std::string line;

	while (!rfile.eof())
	{
		current_line++;
		getline(rfile, line);
		if (current_line == line_Number) break;
	}
	value = std::stoi(line);
	
	rfile.close();
	getLineAndIncrement(percentage);
	return value;
};

class $modify(PlayerObject)
{
	void playDeathEffect()
	{
		auto pl = PlayLayer::get();
		percentage = pl->getCurrentPercentInt();
		getLineAndValue(percentage, pl->m_level);
	}	
};

