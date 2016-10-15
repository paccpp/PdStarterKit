cmake_minimum_required(VERSION 3.0)

# Fetch submodules
message(STATUS "Updating Git Submodules")
execute_process(
	COMMAND git submodule update --init --recursive
	WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_MACOSX_RPATH Off)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.4)
set(CMAKE_OSX_ARCHITECTURES "i386;x86_64")

include(pd.build/pd.cmake)

project(PdStarterKit)
set_pd_sources(${PROJECT_SOURCE_DIR}/pd/src/)
set_pd_external_path("${PROJECT_SOURCE_DIR}/externals/")

include(scripts/utilities.cmake)

# Generate a project for every folder in the "source/projects" folder
SUBDIRLIST(PROJECT_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/source/projects)
foreach (project_dir ${PROJECT_DIRS})
	if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/source/projects/${project_dir}/CMakeLists.txt")
		message("Generating: ${project_dir}")
		add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/source/projects/${project_dir})
	endif ()
endforeach ()
