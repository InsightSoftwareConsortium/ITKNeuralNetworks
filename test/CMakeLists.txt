itk_module_test()

set(NeuralNetworksTests
NNetClassifierTest1.cxx
NNetClassifierTest2.cxx
NNetClassifierTest3.cxx
NNetClassifierTest4.cxx
RBFTest1.cxx
QPropXORTest1.cxx
XORTest1.cxx
XORTest2.cxx
itkLogSigmoidTransferFunctionTest.cxx
itkSigmoidTransferFunctionTest.cxx
itkNeuralNetworkIOTest.cxx
  )

CreateTestDriver(NeuralNetworks "${NeuralNetworks-Test_LIBRARIES}" "${NeuralNetworksTests}")

itk_add_test(NAME NNetClassifierTest1
      COMMAND NeuralNetworksTestDriver --redirectOutput ${ITK_TEST_OUTPUT_DIR}/NNetClassifierTest1.txt
    NNetClassifierTest1
        DATA{Input/train.txt} DATA{Input/test.txt})
set_tests_properties(NNetClassifierTest1 PROPERTIES ATTACHED_FILES_ON_FAIL ${ITK_TEST_OUTPUT_DIR}/NNetClassifierTest1.txt)


itk_add_test(NAME NNetClassifierTest2
      COMMAND NeuralNetworksTestDriver NNetClassifierTest2
              DATA{Input/train.txt} DATA{Input/test.txt})

itk_add_test(NAME NNetClassifierTest3
      COMMAND NeuralNetworksTestDriver --redirectOutput ${ITK_TEST_OUTPUT_DIR}/NNetClassifierTest3.txt
    NNetClassifierTest3
        DATA{Input/train.txt} DATA{Input/test.txt})
set_tests_properties(NNetClassifierTest3 PROPERTIES ATTACHED_FILES_ON_FAIL ${ITK_TEST_OUTPUT_DIR}/NNetClassifierTest3)

itk_add_test(NAME NNetClassifierTest4
      COMMAND NeuralNetworksTestDriver NNetClassifierTest4
              DATA{Input/train.txt} DATA{Input/test.txt})
itk_add_test(NAME RBFTest1
      COMMAND NeuralNetworksTestDriver --redirectOutput RBFTest1.txt
          RBFTest1
              DATA{Input/rbf_multivar_gauss_train.txt} DATA{Input/rbf_multivar_gauss_test.txt})
set_tests_properties(RBFTest1 PROPERTIES ATTACHED_FILES_ON_FAIL ${ITK_TEST_OUTPUT_DIR}/RBFTest1.txt)

itk_add_test(NAME QPropXORTest1
      COMMAND NeuralNetworksTestDriver QPropXORTest1
              DATA{Input/qpropxortest.txt})
itk_add_test(NAME XORTest1
      COMMAND NeuralNetworksTestDriver XORTest1
              DATA{Input/xortest.txt})
itk_add_test(NAME XORTest2
      COMMAND NeuralNetworksTestDriver XORTest2
              DATA{Input/xortest.txt})

itk_add_test(NAME itkLogSigmoidTransferFunctionTest
      COMMAND NeuralNetworksTestDriver itkLogSigmoidTransferFunctionTest)
itk_add_test(NAME itkSigmoidTransferFunctionTest
      COMMAND NeuralNetworksTestDriver itkSigmoidTransferFunctionTest)

itk_add_test(NAME itkNeuralNetworkIOTest
      COMMAND NeuralNetworksTestDriver itkNeuralNetworkIOTest
              DATA{Input/xornet.txt} DATA{Input/xortest.txt} ${ITK_TEST_OUTPUT_DIR})
