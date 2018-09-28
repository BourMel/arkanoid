cmake_minimum_required(VERSION 3.7)

project(Arkanoid LANGUAGES CXX)

IF (MSVC)
	set (CMAKE_PREFIX_PATH "c:/sdl2")
ENDIF()

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC arkanoid.cpp windowmanager.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_nullptr)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sprites.bmp
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

IF (MSVC)
	file(COPY ${SDL2_LIBDIR}/SDL2.dll
		DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release/)
	file(COPY ${SDL2_LIBDIR}/SDL2.dll
		DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug/)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
ENDIF()
