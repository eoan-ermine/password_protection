cmake_minimum_required(VERSION 3.16)
project(pass_protection LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(isMultiConfig)
    if(NOT "Asan" IN_LIST CMAKE_CONFIGURATION_TYPES)
        list(APPEND CMAKE_CONFIGURATION_TYPES Asan)
    endif()
else()
    set(allowedBuildTypes Asan Debug Release RelWithDebInfo MinSizeRel)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${allowedBuildTypes}")

    if(CMAKE_BUILD_TYPE AND NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
        message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
    endif()
endif()

set(CMAKE_C_FLAGS_ASAN
    "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer" CACHE STRING
    "Flags used by the C compiler for Asan build type or configuration." FORCE)

set(CMAKE_CXX_FLAGS_ASAN
    "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer" CACHE STRING
    "Flags used by the C++ compiler for Asan build type or configuration." FORCE)

set(CMAKE_EXE_LINKER_FLAGS_ASAN
    "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address -shared-libasan" CACHE STRING
    "Linker flags to be used to create executables for Asan build type." FORCE)

set(CMAKE_SHARED_LINKER_FLAGS_ASAN
    "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -fsanitize=address -shared-libasan" CACHE STRING
    "Linker lags to be used to create shared libraries for Asan build type." FORCE)

qt_add_executable(pass_protection
    pass_protection/resources/pass_protection.qrc

    pass_protection/forms/authorization.ui
    pass_protection/forms/authorizationform.hpp
    pass_protection/forms/authorizationform.cpp
    pass_protection/forms/change.ui
    pass_protection/forms/changeform.hpp
    pass_protection/forms/changeform.cpp
    pass_protection/forms/mainwindow.ui
    pass_protection/forms/mainwindowform.hpp
    pass_protection/forms/mainwindowform.cpp
    pass_protection/forms/registration.ui
    pass_protection/forms/registrationform.hpp
    pass_protection/forms/registrationform.cpp

    pass_protection/validators.cpp
    pass_protection/validators.h
    pass_protection/database_manager.hpp
    pass_protection/database_manager.cpp

    pass_protection/main.cpp
)

set_target_properties(pass_protection PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(pass_protection  PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
    Qt::Sql
)