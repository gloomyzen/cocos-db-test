cmake_minimum_required(VERSION 3.6)

set(APP_NAME Mercenary_Battles)

project(${APP_NAME})

# Define project list
set(PROJECT_LIST
        Mercenary_Battles
        example_simple_draw
        )

# Define general app sources for target
set(Mercenary_Battles_sources
        Classes/AppDelegate.cpp
        )
set(Mercenary_Battles_headers
        Classes/AppDelegate.h
        )
set(Mercenary_Battles_modules
        Classes/debugModule
        )

# Define engine target and sources
if(XCODE)
    if(NOT DEFINED CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET)
        SET (CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET 8.0)
    endif()
endif()

if(NOT DEFINED BUILD_ENGINE_DONE) # to test cocos-db into root project
    set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
    set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

    include(CocosBuildSet)
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)
endif()
# Define dependency targets
include(${CMAKE_SOURCE_DIR}/lib/project_dependency.cmake)

function(generate_cc_target current_app)
    # record sources, headers, resources...
    set(GAME_SOURCE)
    set(GAME_HEADER)

    set(GAME_RES_FOLDER
            "${CMAKE_CURRENT_SOURCE_DIR}/Resources/${current_app}"
            )
    if(APPLE OR WINDOWS)
        cocos_mark_multi_resources(common_res_files RES_TO "Resources" FOLDERS ${GAME_RES_FOLDER})
    endif()

    # add cross-platforms source files and header files
    file(GLOB_RECURSE GAME_HEADER Classes/*.h include/*.hpp)
    file(GLOB_RECURSE GAME_SOURCE Classes/*.cpp)


    if(ANDROID)
        # change current_app to the share library name for Android, it's value depend on AndroidManifest.xml
        set(current_app MyGame)
        list(APPEND GAME_SOURCE
                proj.android/app/jni/hellocpp/main.cpp
                )
    elseif(LINUX)
        list(APPEND GAME_SOURCE
                proj.linux/main.cpp
                )
    elseif(WINDOWS)
        list(APPEND GAME_HEADER
                proj.win32/main.h
                proj.win32/resource.h
                )
        list(APPEND GAME_SOURCE
                proj.win32/main.cpp
                proj.win32/game.rc
                ${common_res_files}
                )
    elseif(APPLE)
        if(IOS)
            list(APPEND GAME_HEADER
                    proj.ios_mac/ios/AppController.h
                    proj.ios_mac/ios/RootViewController.h
                    )
            set(APP_UI_RES
                    proj.ios_mac/ios/LaunchScreen.storyboard
                    proj.ios_mac/ios/LaunchScreenBackground.png
                    proj.ios_mac/ios/Images.xcassets
                    )
            list(APPEND GAME_SOURCE
                    proj.ios_mac/ios/main.m
                    proj.ios_mac/ios/AppController.mm
                    proj.ios_mac/ios/RootViewController.mm
                    proj.ios_mac/ios/Prefix.pch
                    ${APP_UI_RES}
                    )
        elseif(MACOSX)
            set(APP_UI_RES
                    proj.ios_mac/mac/Icon.icns
                    proj.ios_mac/mac/Info.plist
                    )
            list(APPEND GAME_SOURCE
                    proj.ios_mac/mac/main.cpp
                    proj.ios_mac/mac/Prefix.pch
                    ${APP_UI_RES}
                    )
        endif()
        list(APPEND GAME_SOURCE ${common_res_files})
    endif()

    # mark app complie info and libs info
    set(all_code_files
            ${GAME_HEADER}
            ${GAME_SOURCE}
            )
    if(NOT ANDROID)
        add_executable(${current_app} ${all_code_files})
    else()
        add_library(${current_app} SHARED ${all_code_files})
        add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/platform/android ${ENGINE_BINARY_PATH}/cocos/platform)
        target_link_libraries(${current_app} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
    endif()

    target_link_libraries(${current_app} cocos2d project_dependency)
    target_include_directories(${current_app}
            PRIVATE Classes
            PRIVATE ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
            )

    # mark app resources
    setup_cocos_app_config(${current_app})
    if(APPLE)
        set_target_properties(${current_app} PROPERTIES RESOURCE "${APP_UI_RES}")

        if(MACOSX)
            set_xcode_property(${current_app} INFOPLIST_FILE "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/mac/Info.plist")
        elseif(IOS)
            set_xcode_property(${current_app} INFOPLIST_FILE "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/ios/Info.plist")
            set_xcode_property(${current_app} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
        endif()

        # For code-signing, set the DEVELOPMENT_TEAM:
        #set_xcode_property(${current_app} DEVELOPMENT_TEAM "GRLXXXX2K9")
    elseif(WINDOWS)
        cocos_copy_target_dll(${current_app})
    endif()

    if(LINUX OR WINDOWS)
        cocos_get_resource_path(APP_RES_DIR ${current_app})
        cocos_copy_target_res(${current_app} LINK_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
    endif()
endfunction()

function(add_modules module_path)
    #
endfunction()

foreach(project ${PROJECT_LIST})
    generate_cc_target(${project})
endforeach()
