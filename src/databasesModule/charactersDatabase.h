#ifndef MERCENARY_BATTLES_CHARACTERSDATABASE_H
#define MERCENARY_BATTLES_CHARACTERSDATABASE_H

#include "cocos2d.h"
#include "common/databaseModule/databaseInterface.h"
#include "json/document.h"
#include "json/ostreamwrapper.h"
#include <map>
#include <string>
#include <vector>

namespace mb::databasesModule {

    struct sCharacterData {
        int id;
        std::string bonesString;
        std::string iconPatch;
        bool load(const rapidjson::GenericValue<rapidjson::UTF8<char>>::ConstObject&);
    };

    class charactersDatabase : public common::databaseModule::databaseInterface {
      public:
        charactersDatabase();
        ~charactersDatabase();
        void load(const rapidjson::Document&) override;
        const std::map<int, sCharacterData*>& getCharacters() { return charactersDb; }
        sCharacterData* getCharacterById(int);

      private:
        std::map<int, sCharacterData*> charactersDb;
    };
}// namespace mb::databasesModule


#endif// MERCENARY_BATTLES_CHARACTERSDATABASE_H
