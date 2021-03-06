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
#ifndef itkBackPropagationLayer_h
#define itkBackPropagationLayer_h

#include "itkCompletelyConnectedWeightSet.h"
#include "itkLayerBase.h"
#include "itkObject.h"
#include "itkMacro.h"

namespace itk
{
namespace Statistics
{
/** \class BackPropagationLayer
 * \brief This is the itkBackPropagationLayer class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename TMeasurementVector, typename TTargetVector>
class ITK_TEMPLATE_EXPORT BackPropagationLayer : public LayerBase<TMeasurementVector, TTargetVector>
{
public:
  using Self = BackPropagationLayer;
  using Superclass = LayerBase<TMeasurementVector, TTargetVector>;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** Method for creation through the object factory. */
  itkTypeMacro(BackPropagationLayer, LayerBase);
  itkNewMacro(Self);

  using ValueType = typename Superclass::ValueType;
  using NodeVectorType = vnl_vector<ValueType>;
  using InternalVectorType = typename Superclass::InternalVectorType;
  using OutputVectorType = typename Superclass::OutputVectorType;
  using LayerInterfaceType = typename Superclass::LayerInterfaceType;
  using WeightSetType = CompletelyConnectedWeightSet<TMeasurementVector,TTargetVector>;

  using WeightSetInterfaceType = typename Superclass::WeightSetInterfaceType;
  using InputFunctionInterfaceType = typename Superclass::InputFunctionInterfaceType;
  using TransferFunctionInterfaceType = typename Superclass::TransferFunctionInterfaceType;
  //Member Functions
  void SetNumberOfNodes(unsigned int numNodes) override;
  ValueType GetInputValue(unsigned int i) const override;
  virtual void SetInputValue(unsigned int i, ValueType value);

  ValueType GetOutputValue(unsigned int) const override;
  virtual void SetOutputValue(unsigned int, ValueType);

  ValueType * GetOutputVector() override;
  void SetOutputVector(TMeasurementVector value);

  void ForwardPropagate() override;
  void ForwardPropagate(TMeasurementVector input) override;

  void BackwardPropagate() override;
  void BackwardPropagate(InternalVectorType errors) override;

  void SetOutputErrorValues(TTargetVector) override;
  ValueType GetOutputErrorValue(unsigned int node_id) const override;

  ValueType GetInputErrorValue(unsigned int node_id) const override;
  ValueType * GetInputErrorVector() override;
  void SetInputErrorValue(ValueType, unsigned int node_id) override;

  ValueType Activation(ValueType) override;
  ValueType DActivation(ValueType) override;

  /** Set/Get the bias */
  itkSetMacro( Bias, ValueType );
  itkGetConstReferenceMacro( Bias, ValueType );

protected:

  BackPropagationLayer();
  ~BackPropagationLayer() override;

  /** Method to print the object. */
  void PrintSelf( std::ostream& os, Indent indent ) const override;

private:

  NodeVectorType   m_NodeInputValues;
  NodeVectorType   m_NodeOutputValues;
  NodeVectorType   m_InputErrorValues;
  NodeVectorType   m_OutputErrorValues;
  ValueType        m_Bias;
};

} // end namespace Statistics
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkBackPropagationLayer.hxx"
#endif

#endif
