cmake_minimum_required(VERSION 3.9.5)
project(NeuralNetworks)

set(NeuralNetworks_LIBRARIES ) # header-only module

if(NOT ITK_SOURCE_DIR)
  find_package(ITK REQUIRED)
  list(APPEND CMAKE_MODULE_PATH ${ITK_CMAKE_DIR})
  include(ITKModuleExternal)
else()
  itk_module_impl()
endif()
