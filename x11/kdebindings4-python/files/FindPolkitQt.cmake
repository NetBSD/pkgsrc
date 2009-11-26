# - Try to find Polkit-qt
# Once done this will define
#
#  POLKITQT_FOUND - system has Polkit-qt
#  POLKITQT_INCLUDE_DIR - the Polkit-qt include directory
#  POLKITQT_LIBRARIES - Link these to use all Polkit-qt libs
#  POLKITQT_CORE_LIBRARY
#  POLKITQT_GUI_LIBRARY
#  POLKITQT_DEFINITIONS - Compiler switches required for using Polkit-qt

# Copyright (c) 2008, Adrien Bustany, <madcat@mymadcat.com>
# Copyright (c) 2009, Daniel Nicoletti, <dantti85-pk@yahoo.com.br>
# Copyright (c) 2009, Dario Freddi, <drf54321@gmail.com>
# Copyright (c) 2009, Michal Malek, <michalm@jabster.pl>
#
# Redistribution and use is allowed according to the terms of the GPLv2+ license.

if (POLKITQT_INCLUDE_DIR AND POLKITQT_LIB)
    set(POLKITQT_FIND_QUIETLY TRUE)
endif (POLKITQT_INCLUDE_DIR AND POLKITQT_LIB)

include(FindPkgConfig)

if (NOT POLKITQT_MIN_VERSION)
  set(POLKITQT_MIN_VERSION "0.9.0")
endif (NOT POLKITQT_MIN_VERSION)

pkg_search_module( POLKITQT polkit-qt )

if (POLKITQT_FOUND)
    if (POLKITQT_VERSION VERSION_LESS POLKITQT_MIN_VERSION)
        message(STATUS "Found Polkit-Qt release < ${POLKITQT_MIN_VERSION}")
        message(STATUS "You need Polkit-Qt version ${POLKITQT_MIN_VERSION} or newer to compile this component")
        set(POLKITQT_FOUND FALSE)
        return()
    else (POLKITQT_VERSION VERSION_LESS POLKITQT_MIN_VERSION)
        message(STATUS "Found Polkit-Qt release >= ${POLKITQT_MIN_VERSION}")
    endif (POLKITQT_VERSION VERSION_LESS POLKITQT_MIN_VERSION)
else (POLKITQT_FOUND)
    set(POLKITQT_FOUND FALSE)
    message(STATUS "Cannot find Polkit-Qt library!")
    return()
endif (POLKITQT_FOUND)


# find_path( POLKITQT_INCLUDE_DIR PolicyKit/policykit-qt/Polkit-qt )
find_path( POLKITQT_INCLUDE_DIR
    NAMES PolicyKit/polkit-qt/
    HINTS ${POLKITQT_INCLUDEDIR}
)

find_library( POLKITQT_CORE_LIBRARY 
    NAMES polkit-qt-core 
    HINTS ${POLKITQT_LIBDIR}
)
find_library( POLKITQT_GUI_LIBRARY 
    NAMES polkit-qt-gui 
    HINTS ${POLKITQT_LIBDIR}
)

if (POLKITQT_INCLUDE_DIR AND POLKITQT_CORE_LIBRARY AND POLKITQT_GUI_LIBRARY)
   set(POLKITQT_FOUND TRUE)
else (POLKITQT_INCLUDE_DIR AND POLKITQT_CORE_LIBRARY AND POLKITQT_GUI_LIBRARY)
   set(POLKITQT_FOUND FALSE)
endif (POLKITQT_INCLUDE_DIR AND POLKITQT_CORE_LIBRARY AND POLKITQT_GUI_LIBRARY)

set(POLKITQT_LIBRARIES ${POLKITQT_CORE_LIBRARY} ${POLKITQT_GUI_LIBRARY})

set(POLKITQT_INCLUDE_DIR ${POLKITQT_INCLUDE_DIR}/PolicyKit/polkit-qt ${POLKITQT_INCLUDE_DIR}/PolicyKit/)

set(POLICY_FILES_INSTALL_DIR ${POLKITQT_PREFIX}/share/PolicyKit/policy/)

if (POLKITQT_FOUND)
  if (NOT POLKITQT_FIND_QUIETLY)
    message(STATUS "Found Polkit-Qt: ${POLKITQT_LIBRARIES}")
  endif (NOT POLKITQT_FIND_QUIETLY)
else (POLKITQT_FOUND)
  if (POLKITQT_FIND_REQUIRED)
    message(FATAL_ERROR "Could NOT find Polkit-Qt")
  endif (POLKITQT_FIND_REQUIRED)
endif (POLKITQT_FOUND)

mark_as_advanced(POLKITQT_INCLUDE_DIR POLKITQT_LIB)

macro(dbus_add_activation_system_service _sources)
    pkg_search_module( DBUS dbus-1 )
    foreach (_i ${_sources})
        get_filename_component(_service_file ${_i} ABSOLUTE)
        string(REGEX REPLACE "\\.service.*$" ".service" _output_file ${_i})
        set(_target ${CMAKE_CURRENT_BINARY_DIR}/${_output_file})
        configure_file(${_service_file} ${_target})
        install(FILES ${_target} DESTINATION ${DBUS_PREFIX}/share/dbus-1/system-services )
    endforeach (_i ${ARGN})
endmacro(dbus_add_activation_system_service _sources)
