add_library(dragonbones_target STATIC
        #header
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/DragonBonesHeaders.h
        #animation
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/Animation.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/Animation.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/AnimationState.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/AnimationState.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/BaseTimelineState.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/BaseTimelineState.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/IAnimatable.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/TimelineState.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/TimelineState.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/WorldClock.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/WorldClock.h
        #armature
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/Animation.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/Animation.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/AnimationState.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/AnimationState.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/BaseTimelineState.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/BaseTimelineState.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/IAnimatable.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/TimelineState.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/TimelineState.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/WorldClock.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/animation/WorldClock.h
        #core
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/core/BaseObject.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/core/BaseObject.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/core/DragonBones.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/core/DragonBones.h
        #event
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/event/EventObject.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/event/EventObject.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/event/IEventDispatcher.h
        #factory
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/factory/BaseFactory.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/factory/BaseFactory.h
        #geom
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/geom/ColorTransform.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/geom/Matrix.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/geom/Point.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/geom/Point.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/geom/Rectangle.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/geom/Transform.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/geom/Transform.h
        #model
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/AnimationConfig.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/AnimationConfig.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/AnimationData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/AnimationData.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/ArmatureData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/ArmatureData.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/BoundingBoxData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/BoundingBoxData.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/CanvasData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/CanvasData.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/ConstraintData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/ConstraintData.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/DisplayData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/DisplayData.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/DragonBonesData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/DragonBonesData.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/SkinData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/SkinData.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/TextureAtlasData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/TextureAtlasData.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/UserData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/model/UserData.h
        #parser
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/parser/BinaryDataParser.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/parser/BinaryDataParser.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/parser/DataParser.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/parser/DataParser.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/parser/JSONDataParser.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/parser/JSONDataParser.h

        #cocos-2dx
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/CCArmatureDisplay.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/CCArmatureDisplay.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/CCDragonBonesHeaders.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/CCFactory.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/CCFactory.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/CCSlot.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/CCSlot.h
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/CCTextureAtlasData.cpp
        ${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/CCTextureAtlasData.h
        )

#add_library(dragonbones_cc_target STATIC
#        #Cocos2d-x
#        ${CMAKE_SOURCE_DIR}/lib/dragonBones/Cocos2DX_3.x/src/dragonBones/cocos2dx/CCArmatureDisplay.cpp
#        ${CMAKE_SOURCE_DIR}/lib/dragonBones/Cocos2DX_3.x/src/dragonBones/cocos2dx/CCArmatureDisplay.h
#        ${CMAKE_SOURCE_DIR}/lib/dragonBones/Cocos2DX_3.x/src/dragonBones/cocos2dx/CCDragonBonesHeaders.h
#        ${CMAKE_SOURCE_DIR}/lib/dragonBones/Cocos2DX_3.x/src/dragonBones/cocos2dx/CCFactory.cpp
#        ${CMAKE_SOURCE_DIR}/lib/dragonBones/Cocos2DX_3.x/src/dragonBones/cocos2dx/CCFactory.h
#        ${CMAKE_SOURCE_DIR}/lib/dragonBones/Cocos2DX_3.x/src/dragonBones/cocos2dx/CCSlot.cpp
#        ${CMAKE_SOURCE_DIR}/lib/dragonBones/Cocos2DX_3.x/src/dragonBones/cocos2dx/CCSlot.h
#        ${CMAKE_SOURCE_DIR}/lib/dragonBones/Cocos2DX_3.x/src/dragonBones/cocos2dx/CCTextureAtlasData.cpp
#        ${CMAKE_SOURCE_DIR}/lib/dragonBones/Cocos2DX_3.x/src/dragonBones/cocos2dx/CCTextureAtlasData.h
#        )

target_include_directories(dragonbones_target INTERFACE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/lib/dragonBones/>
        )
#target_include_directories(dragonbones_cc_target INTERFACE
#        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/lib/dragonBones/cocos2dx/>
#        )
