project(krosssignalslot)

include_directories(${KDE4_INCLUDES})

set(SRCS main.cpp mainwindow.cpp)
set(SCRIPTS emitsignal.js onclick.js)

kde4_add_executable(krosssignalslot ${SRCS})
target_link_libraries(krosssignalslot ${KDE4_KDEUI_LIBS} ${KDE4_KROSSUI_LIBS} ${KDE4_KROSSCORE_LIBS})
install(TARGETS krosssignalslot ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES ${SCRIPTS} DESTINATION ${DATA_INSTALL_DIR}/kdeexamples/kross/krosssignalslot)
install(FILES ${SRCS} mainwindow.h README DESTINATION ${DATA_INSTALL_DIR}/kdeexamples/kross/krosssignalslot)
