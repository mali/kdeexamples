cmake_minimum_required(VERSION 2.8.12)

set(REQUIRED_QT_VERSION 5.2.0)

project(kmessagewidgetdemo)

# we need some parts of the ECM CMake helpers
find_package (ECM 0.0.9 REQUIRED NO_MODULE)
set (CMAKE_MODULE_PATH ${ECM_MODULE_PATH})
include(ECMOptionalAddSubdirectory)
include(CMakePackageConfigHelpers)


include(KDEInstallDirs)
include(KDECompilerSettings)
include(KDECMakeSettings)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED Core Widgets)

# Load the frameworks we need
find_package(KF5 REQUIRED COMPONENTS
  I18n
  WidgetsAddons
  ConfigWidgets
  CoreAddons
)

set(SRCS main.cpp window.cpp)

add_executable(kmessagewidgetdemo ${SRCS})
target_link_libraries(kmessagewidgetdemo
  KF5::I18n
  KF5::WidgetsAddons
  KF5::ConfigWidgets
  KF5::CoreAddons
)
install(TARGETS kmessagewidgetdemo ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES ${SRCS} window.h README DESTINATION ${DATA_INSTALL_DIR}/kdeexamples/kdeui/kmessagewidgetdemo)
