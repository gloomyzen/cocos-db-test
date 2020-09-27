#include "jsonLoader.h"

using namespace mercenaryBattles::coreModule;

const std::string propFolder = "Re]sources/";

jsonLoader::jsonLoader() {}
jsonLoader::~jsonLoader() {}

rapidjson::Document jsonLoader::loadJson(const std::string &path, const std::string &prefix) {
	const std::string pref = prefix + propFolder;
	std::ifstream ifs(pref + path + ".json", std::ifstream::in);
	if (!ifs.is_open()) {
		return nullptr;
	}
	rapidjson::IStreamWrapper isw{ifs};
	rapidjson::Document document{};
	document.ParseStream(isw);
	if (!document.HasParseError() && document.IsObject()) {
		return document;
	} else {
		return nullptr;
	}
}
