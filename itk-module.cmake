# the top-level README is used for describing this module, just
# re-used it for documentation here
get_filename_component(MY_CURRENT_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(READ "${MY_CURRENT_DIR}/README.rst" DOCUMENTATION)

# itk_module() defines the module dependencies in NeuralNetworks
# NeuralNetworks depends on ITKCommon
# The testing module in NeuralNetworks depends on ITKTestKernel
# and ITKMetaIO(besides NeuralNetworks and ITKCore)
# By convention those modules outside of ITK are not prefixed with
# ITK.

# define the dependencies of the include module and the tests
itk_module(NeuralNetworks
  DEPENDS
    ITKCommon
    ITKStatistics
    ITKIOMeta
    ITKIOImageBase
  TEST_DEPENDS
    ITKTestKernel
  DESCRIPTION
    "${DOCUMENTATION}"
  EXCLUDE_FROM_DEFAULT
  ENABLE_SHARED
)
