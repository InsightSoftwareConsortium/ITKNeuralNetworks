/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkNeuralNetworkFileReader_h
#define itkNeuralNetworkFileReader_h

#include "itkMetaImageIO.h"

#include "itkMultilayerNeuralNetworkBase.h"

#include "itkBackPropagationLayer.h"

#include "itkSumInputFunction.h"
#include "itkProductInputFunction.h"

#include "itkIdentityTransferFunction.h"
#include "itkLogSigmoidTransferFunction.h"
#include "itkSigmoidTransferFunction.h"
#include "itkTanSigmoidTransferFunction.h"
#include "itkSymmetricSigmoidTransferFunction.h"

namespace itk
{
/** \class NeuralNetworkFileReader
 * \brief Reader for Neural Network
 *
 * This class will enable the user to load neural network and define
 * weights and other network parameters from a text file.
 *
 * This class was contributed to the Insight Journal by Raghu Venkatram.
 * The original paper can be found at
 *  https://hdl.handle.net/1926/203
 *
 * \author Raghu Venkatram
 *
 * \sa NeuralNetworkFileWriter
 * \sa MultilayerNeuralNetworkBase
 * \ingroup NeuralNetworks
 */
template< typename TNetwork >
class ITK_TEMPLATE_EXPORT NeuralNetworkFileReader:public Object
{
public:

  /** SmartPointer type alias support */
  using Self = NeuralNetworkFileReader;
  using Superclass = Object;
  using Pointer = SmartPointer< Self >;
  using ConstPointer = SmartPointer< const Self >;

  /** Run-time type information (and related methods). */
  itkTypeMacro(NeuralNetworkFileReader, Object);

  /** Method for creation through the object factory */
  itkNewMacro(Self);

  using MeasurementVectorType = typename TNetwork::MeasurementVectorType;
  using TargetVectorType = typename TNetwork::TargetVectorType;
  using BackPropagationLayerType = Statistics::BackPropagationLayer<
    MeasurementVectorType, TargetVectorType >;
  using BackPropagationLayerPointer = typename BackPropagationLayerType::Pointer;
  using MeasurementVectorValueType = typename MeasurementVectorType::ValueType;

  using LayerInterfaceType = typename TNetwork::LayerInterfaceType;
  using WeightSetType = typename LayerInterfaceType::WeightSetType;
  using WeightSetPointer = typename WeightSetType::Pointer;

// using NetworkPointer = typename TNetwork::Pointer;
// using NetworkConstPointer = typename TNetwork::ConstPointer;

//  using TransferFunctionPointer = typename LayerInterfaceType::TransferFunctionType::Pointer   ;
//  using TransferFunctionConstPointer = typename LayerInterfaceType::TransferFunctionType::ConstPointer;

//  using InputFunctionPointer = typename LayerInterfaceType::InputFunctionType::Pointer        ;
//  using InputFunctionConstPointer = typename LayerInterfaceType::InputFunctionType::ConstPointer  ;

//  using ValueType = typename LayerInterfaceType::ValueType;

  /** Set the filename  */
  itkSetStringMacro(FileName);

  /** Get the filename */
  itkGetStringMacro(FileName);

  /** Read NeuralNetwork */
  void Update();

  TNetwork * GetOutput() const;

#ifdef IGNORE
#undef IGNORE
#endif
  using NetworkWriteWeightsType = enum { IGNORE = 0, ASCII = 1, BINARY = 2 };
  itkSetEnumMacro(ReadWeightValuesType, NetworkWriteWeightsType);
  itkGetEnumMacro(ReadWeightValuesType, NetworkWriteWeightsType);

protected:
  NeuralNetworkFileReader();
  ~NeuralNetworkFileReader() override;
  void PrintSelf(std::ostream & os, Indent indent) const override;

private:

  void ClearFields();

  using FieldsContainerType = std::vector< MET_FieldRecordType * >;
  using LayersContainer = std::vector< typename TNetwork::LayerInterfaceType::Pointer >;
  using WeightsContainer = std::vector< typename TNetwork::LayerInterfaceType::WeightSetInterfaceType::Pointer >;

  using LineType = struct {
    std::string name;
    std::string value;
  };

  using LinesContainer = std::list< LineType >;

  typename TNetwork::Pointer m_Network;

  NetworkWriteWeightsType m_ReadWeightValuesType;
  LayersContainer         m_Layers;
  WeightsContainer        m_Weights;
  LinesContainer          m_NameValue;
  std::string             m_FileName;
  FieldsContainerType     m_Fields;
  std::ifstream           m_InputFile;
  bool                    m_BinaryDataByteOrderMSB;
};
} // namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkNeuralNetworkFileReader.hxx"
#endif

#endif
