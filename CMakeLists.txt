# ~~~
# Copyright (c) 2020-2026 LunarG, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ~~~

cmake_minimum_required(VERSION 3.22.1)

# The VERSION field is generated with the "--generated-version" flag in the generate_source.py script
project(VULKAN_TOOLS VERSION 1.4.350 LANGUAGES CXX)

add_subdirectory(scripts)

find_package(VulkanHeaders ${PROJECT_VERSION} REQUIRED CONFIG)
find_package(VulkanLoader CONFIG)
find_package(VulkanUtilityLibraries REQUIRED CONFIG)
find_package(valijson REQUIRED CONFIG)

find_package(Qt6 COMPONENTS Core Gui Widgets Network QUIET)
if(Qt6_FOUND)
  get_target_property(QT_TARGET_TYPE Qt6::Core TYPE)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_VISIBILITY_PRESET "hidden")
set(CMAKE_VISIBILITY_INLINES_HIDDEN "YES")

include(GNUInstallDirs)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

option(BUILD_WERROR "Treat compiler warnings as errors")
if (BUILD_WERROR)
    add_compile_options("$<IF:$<CXX_COMPILER_ID:MSVC>,/WX,-Werror>")
endif()


option(RUN_ON_CI "Build only tests that can run on C.I." ON)

if (MSVC)
    add_compile_options("$<$<CONFIG:Release>:/Zi>")
    add_link_options("$<$<CONFIG:Release>:/DEBUG:FULL>")
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Windows|Linux|BSD")

    option(BUILD_APIDUMP "Build api_dump layer" ON)
    set(SDK_VERSION "" CACHE STRING "Vulkan SDK version")

elseif(ANDROID)

    # Currently the Android build only build the API dump and screen shot layer.
    # - libVkLayer_api_dump.so
    option(BUILD_APIDUMP "Build api_dump layer" ON)

elseif (APPLE)

    option(BUILD_APIDUMP "Build api_dump layer" ON)

endif()


if(BUILD_APIDUMP)
    message(STATUS "INFO: Building Vulkan Layers")
    add_subdirectory(layersvt)
endif()

