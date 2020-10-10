#include "settingManager.h"
#include "rapidjson/document.h"
#include <rapidjson/ostreamwrapper.h>
#include "debugModule/logManager.h"

using namespace mb::coreModule;

settingManager::settingManager(cocos2d::Size frameResolution, const cocos2d::Size designResolution, const bool showDisplayStats) :
		frameResolutionSize(frameResolution )
		, designResolutionSize(designResolution )
		, showDisplayStats( showDisplayStats )
{}

settingManager settingManager::load()
{
	// default
	cocos2d::Size frameResolution( 1024, 768 );
	cocos2d::Size designResolution( 480, 320 );
	auto stats = false;

	// load json
	const std::string& regionStr = cocos2d::FileUtils::getInstance()->getStringFromFile( "config/setting.json" );
	rapidjson::Document doc;
	doc.Parse<0>( regionStr.c_str() );

	if( doc.HasParseError() )
	{
		LOG_ERROR("settingManager::load: json parse error");
		return settingManager(frameResolution, designResolution, stats);
	}

	if( doc.IsNull() )
	{
		LOG_ERROR("settingManager::load: json is empty");
		return settingManager(frameResolution, designResolution, stats);
	}

	const auto frameResolutionItr = doc.FindMember( "frameResolution" );
	if( doc.MemberEnd() != frameResolutionItr )
	{
		const auto xItr = frameResolutionItr->value.FindMember( "x" );
		const auto yItr = frameResolutionItr->value.FindMember( "y" );
		if( frameResolutionItr->value.MemberEnd() != xItr
			&& xItr->value.IsInt()
			&& frameResolutionItr->value.MemberEnd() != yItr
			&& yItr->value.IsInt() )
			frameResolution.setSize( xItr->value.GetInt(), yItr->value.GetInt() );
	}

	const auto designResolutionItr = doc.FindMember( "designResolution" );
	if( doc.MemberEnd() != designResolutionItr )
	{
		const auto xItr = designResolutionItr->value.FindMember( "x" );
		const auto yItr = designResolutionItr->value.FindMember( "y" );
		if( designResolutionItr->value.MemberEnd() != xItr
			&& xItr->value.IsInt()
			&& frameResolutionItr->value.MemberEnd() != yItr
			&& yItr->value.IsInt() )
			designResolution.setSize( xItr->value.GetInt(), yItr->value.GetInt() );
	}

	const auto showDisplayStatsItr = doc.FindMember( "showDisplayStats" );
	if( doc.MemberEnd() != showDisplayStatsItr )
		stats = showDisplayStatsItr->value.GetBool();

	return settingManager( frameResolution, designResolution, stats );
}