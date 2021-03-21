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
    //todo
}

sCharacterData* charactersDatabase::getCharacterById(int id) {
    //todo
    return nullptr;
}
bool sCharacterData::load(const rapidjson::Document& json) {
    //todo
    return false;
}
