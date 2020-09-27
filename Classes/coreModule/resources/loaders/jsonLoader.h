#ifndef MERCENARY_BATTLES_JSONLOADER_H
#define MERCENARY_BATTLES_JSONLOADER_H

#include "cocos2d.h"
#include <fstream>
#include "rapidjson/document.h"
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>
#include <string>

namespace mercenaryBattles {
	using namespace cocos2d;

	namespace coreModule {
		class jsonLoader {
		public:
			jsonLoader();
			~jsonLoader();

			/**
			 * Method for load unparsed json, as is, with is object check
			 * @param path Path to json in resources folder
			 * @param prefix @only for gtest
			 * @return rapidjson::Document
			 */
			rapidjson::Document loadJson(const std::string &path, const std::string &prefix = "");
		};
	}
}//mercenaryBattles::coreModule


#endif //MERCENARY_BATTLES_JSONLOADER_H
