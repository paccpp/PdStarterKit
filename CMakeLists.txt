cmake_minimum_required(VERSION 2.8)

set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_MACOSX_RPATH Off)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.4)
set(CMAKE_OSX_ARCHITECTURES "i386;x86_64")

include(pd.build/pd.cmake)

project(PdObjects)
set_pd_sources(${PROJECT_SOURCE_DIR}/pd/src/)
set_pd_external_path("${PROJECT_SOURCE_DIR}/externals/")

add_pd_external(dummy_tilde_project dummy~ ${PROJECT_SOURCE_DIR}/src/dummy_tilde.c)
