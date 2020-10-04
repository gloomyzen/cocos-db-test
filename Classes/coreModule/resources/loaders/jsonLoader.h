#ifndef MERCENARY_BATTLES_JSONLOADER_H
#define MERCENARY_BATTLES_JSONLOADER_H

#include <fstream>
#include "rapidjson/document.h"
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>
#include <string>

namespace mercenaryBattles {

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
			rapidjson::Document loadJson(const std::string &path);
		};
	}
}//mercenaryBattles::coreModule


#endif //MERCENARY_BATTLES_JSONLOADER_H
