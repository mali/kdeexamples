project(nepomukexampleservice)

include_directories(
  ${QT_INCLUDES}
  ${KDE4_INCLUDES}
  ${SOPRANO_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}
  ${SOPRANO_INCLUDE_DIR}
  ${NEPOMUK_CORE_INCLUDE_DIR}
  )

set( SRCS
  exampleservice.cpp
)

kde4_add_plugin(nepomukexampleservice ${SRCS})

target_link_libraries(nepomukexampleservice
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KIO_LIBS}
  ${NEPOMUK_CORE_LIBRARY}
  ${SOPRANO_LIBRARIES}
  )

install(
  FILES nepomukexampleservice.desktop
  DESTINATION ${SERVICES_INSTALL_DIR})

install(
  TARGETS nepomukexampleservice
  DESTINATION ${PLUGIN_INSTALL_DIR})
# -----------------------------
