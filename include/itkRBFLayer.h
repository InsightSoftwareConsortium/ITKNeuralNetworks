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
#ifndef itkRBFLayer_h
#define itkRBFLayer_h

#include "itkCompletelyConnectedWeightSet.h"
#include "itkLayerBase.h"
#include "itkObject.h"
#include "itkMacro.h"
#include "itkRadialBasisFunctionBase.h"
#include "itkEuclideanDistanceMetric.h"

namespace itk
{
namespace Statistics
{
/** \class RBFLayer
 * \brief This is the itkRBFLayer class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename TMeasurementVector, typename TTargetVector>
class ITK_TEMPLATE_EXPORT RBFLayer : public LayerBase<TMeasurementVector, TTargetVector>
{
public:
  using Self = RBFLayer;
  using Superclass = LayerBase<TMeasurementVector, TTargetVector>;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** Method for creation through the object factory. */
  itkTypeMacro(RBFLayer, LayerBase);
  itkNewMacro(Self);

  using ValueType = typename Superclass::ValueType;
  using ValuePointer = typename Superclass::ValuePointer;
  using NodeVectorType = vnl_vector<ValueType>;
  using InternalVectorType = typename Superclass::InternalVectorType;
  using OutputVectorType = typename Superclass::OutputVectorType;
  using LayerInterfaceType = typename Superclass::LayerInterfaceType;
  using WeightSetType = CompletelyConnectedWeightSet<TMeasurementVector,TTargetVector>;

  using WeightSetInterfaceType = typename Superclass::WeightSetInterfaceType;
  using InputFunctionInterfaceType = typename Superclass::InputFunctionInterfaceType;
  using TransferFunctionInterfaceType = typename Superclass::TransferFunctionInterfaceType;

  //Distance Metric
  using DistanceMetricType = EuclideanDistanceMetric<InternalVectorType>;
  using DistanceMetricPointer = typename DistanceMetricType::Pointer;
  using RBFType = RadialBasisFunctionBase<ValueType>;

  //Member Functions
  itkGetConstReferenceMacro(RBF_Dim, unsigned int);
  void SetRBF_Dim(unsigned int size);
  void SetNumberOfNodes(unsigned int numNodes) override;
  ValueType GetInputValue(unsigned int i) const override;
  void SetInputValue(unsigned int i, ValueType value);

  ValueType GetOutputValue(unsigned int) const override;
  virtual void SetOutputValue(unsigned int, ValueType);

  ValueType * GetOutputVector() override;
  void SetOutputVector(TMeasurementVector value);

  void ForwardPropagate() override;
  void ForwardPropagate(TMeasurementVector input) override;

  void BackwardPropagate() override;
  void BackwardPropagate(TTargetVector itkNotUsed(errors)) override {};

  void SetOutputErrorValues(TTargetVector) override;
  ValueType GetOutputErrorValue(unsigned int node_id) const override;

  ValueType GetInputErrorValue(unsigned int node_id) const override;
  ValueType * GetInputErrorVector() override;
  void SetInputErrorValue(ValueType, unsigned int node_id) override;

  //TMeasurementVector GetCenter(int i);
  InternalVectorType GetCenter(unsigned int i) const;
  void SetCenter(TMeasurementVector c,unsigned int i);

  ValueType GetRadii(unsigned int i) const;
  void SetRadii(ValueType c,unsigned int i);

  ValueType Activation(ValueType) override;
  ValueType DActivation(ValueType) override;

  /** Set/Get the bias */
  itkSetMacro( Bias, ValueType );
  itkGetConstReferenceMacro( Bias, ValueType );

  void SetDistanceMetric(DistanceMetricType* f);
  itkGetModifiableObjectMacro(DistanceMetric, DistanceMetricType );

  itkSetMacro(NumClasses,unsigned int);
  itkGetConstReferenceMacro(NumClasses,unsigned int);

  void SetRBF(RBFType* f);
  itkGetModifiableObjectMacro(RBF, RBFType);

protected:

  RBFLayer();
  ~RBFLayer() override;

  /** Method to print the object. */
  void PrintSelf( std::ostream& os, Indent indent ) const override;

private:

  NodeVectorType   m_NodeInputValues;
  NodeVectorType   m_NodeOutputValues;
  NodeVectorType   m_InputErrorValues;
  NodeVectorType   m_OutputErrorValues;

  typename DistanceMetricType::Pointer  m_DistanceMetric;

  std::vector<InternalVectorType>       m_Centers;  // ui....uc
  InternalVectorType                    m_Radii;
  unsigned int                          m_NumClasses;
  ValueType                             m_Bias;
  unsigned int                          m_RBF_Dim;
  typename RBFType::Pointer             m_RBF;
};

} // end namespace Statistics
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkRBFLayer.hxx"
#endif

#endif
