﻿# CMakeList.txt : CMake project for WarBinder, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.11)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("WarBinder")


include(FetchContent)
# Include SDL for controller and mouse detection
FetchContent_Declare(
	SDL2
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
	GIT_TAG 859844eae358447be8d66e6da59b6fb3df0ed778
)

FetchContent_MakeAvailable(SDL2)
# Include wxWidgets for window control. Note that this should be easily replaceable in the future
#FetchContent_Declare(
#	wxWidgets
#	GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
#	GIT_TAG 085a136dcb11aca5b1102193f006f8056d5f0876
#)

#FetchContent_GetProperties(wxWidgets)
#FetchContent_MakeAvailable(wxWidgets)

# Add source to this project's executable.
add_subdirectory(src)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET WarBinder PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
