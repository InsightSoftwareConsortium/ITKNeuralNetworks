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
#ifndef itkTrainingFunctionBase_h
#define itkTrainingFunctionBase_h

#include <iostream>
#include "itkLightProcessObject.h"
#include "itkNeuralNetworkObject.h"
#include "itkSquaredDifferenceErrorFunction.h"
#include "itkMeanSquaredErrorFunction.h"
namespace itk
{
namespace Statistics
{
/** \class TrainingFunctionBase
 * \brief This is the itkTrainingFunctionBase class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename TSample, typename TTargetVector, typename ScalarType>
class ITK_TEMPLATE_EXPORT TrainingFunctionBase : public LightProcessObject
{
public:
  using Self = TrainingFunctionBase;
  using Superclass = LightProcessObject;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** Method for creation through the object factory. */
  itkTypeMacro(TrainingFunctionBase, LightProcessObject);

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  using ValueType = ScalarType;
  using VectorType = typename TSample::MeasurementVectorType;
  using OutputVectorType = typename TTargetVector::MeasurementVectorType;
  using InternalVectorType = Array<ValueType>;

  using InputSampleVectorType = std::vector<VectorType>;
  using OutputSampleVectorType = std::vector<OutputVectorType>;
  using NetworkType = NeuralNetworkObject<VectorType, OutputVectorType>;
  using PerformanceFunctionType = ErrorFunctionBase<InternalVectorType, ScalarType>;
  using DefaultPerformanceType = SquaredDifferenceErrorFunction<InternalVectorType, ScalarType>;

  void SetTrainingSamples(TSample* samples);
  void SetTargetValues(TTargetVector* targets);
  void SetLearningRate(ValueType);

  ValueType GetLearningRate();

  itkSetMacro(Iterations, SizeValueType);
  itkGetConstReferenceMacro(Iterations, SizeValueType);

  void SetPerformanceFunction(PerformanceFunctionType* f);

  virtual void Train(NetworkType* itkNotUsed(net), TSample* itkNotUsed(samples), TTargetVector* itkNotUsed(targets))
    {
    // not implemented
    };

  inline VectorType
  defaultconverter(typename TSample::MeasurementVectorType v)
    {
    VectorType temp;
    for (unsigned int i = 0; i < v.Size(); i++)
      {
      temp[i] = static_cast<ScalarType>(v[i]);
      }
    return temp;
    }

  inline OutputVectorType
  targetconverter(typename TTargetVector::MeasurementVectorType v)
    {
    OutputVectorType temp;

    for (unsigned int i = 0; i < v.Size(); i++)
      {
      temp[i] = static_cast<ScalarType>(v[i]);
      }
    return temp;
    }

protected:

  TrainingFunctionBase();
  ~TrainingFunctionBase() ITK_OVERRIDE {}

  /** Method to print the object. */
  void PrintSelf( std::ostream& os, Indent indent ) const override;

  TSample*                m_TrainingSamples;// original samples
  TTargetVector*          m_SampleTargets;  // original samples
  InputSampleVectorType   m_InputSamples;   // itk::vectors
  OutputSampleVectorType  m_Targets;        // itk::vectors
  SizeValueType           m_Iterations;
  ValueType               m_LearningRate;

  typename PerformanceFunctionType::Pointer m_PerformanceFunction;
};

} // end namespace Statistics
} // end namespace itk
#ifndef ITK_MANUAL_INSTANTIATION
#include "itkTrainingFunctionBase.hxx"
#endif

#endif
