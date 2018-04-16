cmake_minimum_required(VERSION 2.8)
project(duitools)

set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MTd /Fd$(OutDir)$(TargetName).pdb ")
set(CMAKE_CXX_FLAGS_MINSIZEREL  "${CMAKE_C_FLAGS_MINSIZEREL} /MT")
set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_C_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO  "${CMAKE_C_FLAGS_RELWITHDEBINFO} /MT /Fd$(OutDir)$(TargetName).pdb")

add_executable(duirc src/duirc.cpp)

add_executable(duiwizard src/duiwizard.cpp)
SET_TARGET_PROPERTIES(duiwizard PROPERTIES LINK_FLAGS "/level='requireAdministrator' /uiAccess='false'")

install(TARGETS duirc RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/bin")
install(TARGETS duiwizard RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/bin")
