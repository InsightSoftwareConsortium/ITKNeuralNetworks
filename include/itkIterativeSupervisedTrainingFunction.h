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
#ifndef itkIterativeSupervisedTrainingFunction_h
#define itkIterativeSupervisedTrainingFunction_h

#include "itkTrainingFunctionBase.h"

namespace itk
{
namespace Statistics
{
/** \class IterativeSupervisedTrainingFunction
 * \brief This is the itkIterativeSupervisedTrainingFunction class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename TSample, typename TTargetVector, typename ScalarType>
class ITK_TEMPLATE_EXPORT IterativeSupervisedTrainingFunction : public TrainingFunctionBase<TSample, TTargetVector, ScalarType>
{
public:

  using Self = IterativeSupervisedTrainingFunction;
  using Superclass = TrainingFunctionBase<TSample, TTargetVector, ScalarType>;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** Method for creation through the object factory. */
  itkTypeMacro(IterativeSupervisedTrainingFunction, TrainingFunctionBase);

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  using NetworkType = typename Superclass::NetworkType;
  using InternalVectorType = typename Superclass::InternalVectorType;

  void SetNumOfIterations(SizeValueType i);

  void Train(NetworkType* net, TSample* samples, TTargetVector* targets) override;

  itkSetMacro(Threshold, ScalarType);

protected:

  IterativeSupervisedTrainingFunction();
  ~IterativeSupervisedTrainingFunction() override{};

  /** Method to print the object. */
  void PrintSelf( std::ostream& os, Indent indent ) const override;

  ScalarType m_Threshold;
  bool       m_Stop; //stop condition
};

} // end namespace Statistics
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
  #include "itkIterativeSupervisedTrainingFunction.hxx"
#endif

#endif
