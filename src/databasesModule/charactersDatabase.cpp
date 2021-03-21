#include "charactersDatabase.h"
#include "common/coreModule/resources/resourceManager.h"
#include "common/debugModule/logManager.h"

using namespace mb::databasesModule;

charactersDatabase::charactersDatabase() {}

charactersDatabase::~charactersDatabase() {
    for (auto& [_, db] : charactersDb) {
        delete db;
        db = nullptr;
    }
}
void charactersDatabase::load(const rapidjson::Document& json) {
    if (getPath().empty()) {
        LOG_ERROR("charactersDatabase::load: path is empty!");
        return;
    }
    if (!json.IsObject()) {
        LOG_ERROR(STRING_FORMAT("charactersDatabase::load: file from path '%s' is not object!", getPath().c_str()));
        return;
    }
    auto characters = json.FindMember("characters");
    if (characters != json.MemberEnd() && characters->value.IsObject()) {
        auto object = characters->value.GetObjectJ();
        for (auto characterIt = object.MemberBegin(); characterIt != object.MemberEnd(); ++characterIt) {
            if (characterIt->name.IsString() && characterIt->value.IsObject()) {
                auto tempId = characterIt->name.GetString();
                auto item = new sCharacterData();
                item->id = std::atoi(tempId);
                if (item->load(characterIt->value.GetObjectJ())) {
                    charactersDb.insert({item->id, item});
                }
            } else {
                LOG_ERROR(STRING_FORMAT("charactersDatabase::load: file from path '%s' has errors!", getPath().c_str()));
            }
        }
    }
}

sCharacterData* charactersDatabase::getCharacterById(int id) {
    auto find = charactersDb.find(id);
    if (find != charactersDb.end()) {
        return find->second;
    }
    return nullptr;
}
bool sCharacterData::load(const rapidjson::GenericValue<rapidjson::UTF8<char>>::ConstObject& object) {
    bool result = true;
    if (object["propertyPath"].IsString()) {
        bonesString = object["propertyPath"].GetString();
    } else {
        result = false;
    }
    if (object["iconPath"].IsString()) {
        iconPatch = object["iconPath"].GetString();
    } else {
        result = false;
    }
    return result;
}
