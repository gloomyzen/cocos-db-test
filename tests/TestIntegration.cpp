#include "cocos2d.h"
#include "databasesModule/databaseManager.h"
#include "databasesModule/charactersDatabase.h"
#include "common/databaseModule/databaseManagerInterface.h"
#include "common/utilityModule/stringUtility.h"
#include <gtest/gtest.h>

using namespace common::utilityModule;
using namespace common::databaseModule;
//using namespace mb::databasesModule;

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

namespace DBTests::test {
    class TempClass : public testing::Test {};
}// namespace DBTests::test
using namespace DBTests::test;

TEST_F(TempClass, cocos2dSimpleIntegrationTest) {
    auto size1 = cocos2d::Size(1.f, 2.f);
    auto size2 = cocos2d::Size(2.f, 1.f);
    EXPECT_EQ(size1.width, size2.height);
    EXPECT_TRUE(size1.width != size2.width);
}

TEST_F(TempClass, commonStringUtilsTest) {
    EXPECT_EQ(stringUtility::capitalizeString("test room is awesome!"), std::string("Test room is awesome!"));
    EXPECT_EQ(stringUtility::toLowerString("Test RoOm IS aweSome!"), std::string("test room is awesome!"));
    auto stringArray = stringUtility::explodeString("test room is awesome!");
    EXPECT_TRUE(!stringArray.empty());
    EXPECT_TRUE(stringArray.size() == 4);
    auto stringArray1 = stringUtility::explodeString("test room is awesome!", &stringUtility::capitalizeString);
    EXPECT_TRUE(!stringArray1.empty());
    EXPECT_EQ(stringArray1.front(),  std::string("Test"));
    auto stringArray2 = stringUtility::explodeString("TEST ROOM IS AWESOME!", &stringUtility::toLowerString);
    EXPECT_TRUE(!stringArray2.empty());
    EXPECT_EQ(stringArray2.front(),  std::string("test"));
}

TEST_F(TempClass, databaseTest) {
    using namespace mb::databasesModule;

    GET_DATABASE_MANAGER().addDatabase(databaseManager::eDatabaseList::CHARACTER_DB, "properties/database/characters/db.json", new charactersDatabase());
    GET_DATABASE_MANAGER().executeLoadData();
    auto characterDb = GET_DATABASE_MANAGER().getDatabase<charactersDatabase>(databaseManager::eDatabaseList::CHARACTER_DB);
    EXPECT_TRUE(characterDb->isLoaded());
    EXPECT_TRUE(!characterDb->getCharacters().empty());
}