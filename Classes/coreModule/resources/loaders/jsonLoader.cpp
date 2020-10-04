#include "jsonLoader.h"
#include "cocos2d.h"

using namespace mercenaryBattles::coreModule;


jsonLoader::jsonLoader() {}
jsonLoader::~jsonLoader() {}

rapidjson::Document jsonLoader::loadJson(const std::string &path) {
#ifdef DEBUG
	std::ifstream ifs(path + ".json", std::ifstream::in);
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
#else
	//for production without stream
	auto fileUtils = cocos2d::FileUtils::getInstance();
	auto data = fileUtils->getDataFromFile(path + ".json");
	if (data.isNull()) {
		return nullptr;
	}
	rapidjson::Document document{};
	document.Parse(reinterpret_cast<const char *>(data.getBytes()));
	data.clear();
	if (!document.HasParseError() && document.IsObject()) {
		return document;
	} else {
		return nullptr;
	}
#endif
}
