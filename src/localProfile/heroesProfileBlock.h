#ifndef MERCENARY_BATTLES_HEROESPROFILEBLOCK_H
#define MERCENARY_BATTLES_HEROESPROFILEBLOCK_H

#include "common/profileModule/profileBlockInterface.h"
#include "json/document.h"
#include "json/ostreamwrapper.h"
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace cardsApp::localProfile {

    class heroesProfileBlock : public common::profileModule::profileBlockInterface {
      public:
        heroesProfileBlock();
        ~heroesProfileBlock();

        bool load(const rapidjson::GenericValue<rapidjson::UTF8<char>>::ConstObject&) override;
        bool save(rapidjson::Value&, rapidjson::Document::AllocatorType&) override;

        std::map<int, int>& getAllHeroes() { return localHeroes; }
        bool hasHero(int id);
        bool addHero(int id);


      private:
        std::map<int, int> localHeroes;
    };
}// namespace cardsApp::localProfile


#endif// MERCENARY_BATTLES_HEROESPROFILEBLOCK_H
