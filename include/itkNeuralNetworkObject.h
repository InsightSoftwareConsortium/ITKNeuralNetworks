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
#ifndef itkNeuralNetworkObject_h
#define itkNeuralNetworkObject_h

#include "itkDataObject.h"
#include "itkLayerBase.h"
#include "itkLearningFunctionBase.h"

namespace itk
{
namespace Statistics
{
/** \class NeuralNetworkObject
 * \brief This is the itkNeuralNetworkObject class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename TMeasurementVector, typename TTargetVector >
class ITK_TEMPLATE_EXPORT NeuralNetworkObject : public DataObject
{
public:

  using Self = NeuralNetworkObject;
  using Superclass = DataObject;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  itkTypeMacro(NeuralNetworkObject, DataObject);

  using MeasurementVectorType = TMeasurementVector;
  using ValueType = typename MeasurementVectorType::ValueType;
  using NetworkOutputType = Array<ValueType>;
  using TargetVectorType = TTargetVector;

  using LayerInterfaceType = LayerBase<TMeasurementVector, TTargetVector>;

  virtual NetworkOutputType GenerateOutput(TMeasurementVector samplevector)=0;

  virtual void BackwardPropagate(NetworkOutputType errors) = 0;
  virtual void UpdateWeights(ValueType) = 0;

protected:

  NeuralNetworkObject();
  ~NeuralNetworkObject() override;

  /** Method to print the object. */
  void PrintSelf( std::ostream& os, Indent indent ) const override;

  ValueType m_LearningRate;

};

} // end namespace Statistics
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkNeuralNetworkObject.hxx"
#endif

#endif
