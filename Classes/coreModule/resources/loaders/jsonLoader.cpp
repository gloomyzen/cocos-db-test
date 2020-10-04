#include "jsonLoader.h"
#include "cocos2d.h"

using namespace mercenaryBattles::coreModule;


jsonLoader::jsonLoader() {}
jsonLoader::~jsonLoader() {}

rapidjson::Document jsonLoader::loadJson(const std::string &path, const std::string &pref) {
	auto fileUtils = cocos2d::FileUtils::getInstance();
	auto data = fileUtils->getDataFromFile(path + ".json");
	if (data.isNull()) {
		return nullptr;
	}
	rapidjson::Document document{};
	document.Parse(reinterpret_cast<const char *>(data.getBytes()));
	if (!document.HasParseError() && document.IsObject()) {
		return document;
	} else {
		return nullptr;
	}
}
