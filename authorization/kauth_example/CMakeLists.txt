project(kauthorization_example)

include(MacroLibrary)

add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(${KDE4_INCLUDES})


set( kauth_example_sources
     main.cpp
     mainwindow.cpp )

qt4_wrap_ui(kauth_example_uis mainwindow.ui)

kde4_add_executable(kauth_example ${kauth_example_sources} ${kauth_example_uis})
target_link_libraries(kauth_example ${KDE4_KFILE_LIBS} ${KDE4_KIO_LIBS})
install(TARGETS kauth_example ${INSTALL_TARGETS_DEFAULT_ARGS})

# Auth example helper
kde4_add_executable(kauth_example_helper  helper/helper.cpp)
target_link_libraries(kauth_example_helper ${KDE4_KDECORE_LIBS})
install(TARGETS kauth_example_helper DESTINATION ${LIBEXEC_INSTALL_DIR})

kde4_install_auth_helper_files(kauth_example_helper org.kde.auth.example root)
kde4_install_auth_actions(org.kde.auth.example actions.actions)
