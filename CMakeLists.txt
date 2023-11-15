cmake_minimum_required(VERSION 3.16)
project(pass_protection LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_add_executable(pass_protection
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
)