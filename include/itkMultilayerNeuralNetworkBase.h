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
#ifndef itkMultilayerNeuralNetworkBase_h
#define itkMultilayerNeuralNetworkBase_h

#include "itkNeuralNetworkObject.h"

namespace itk
{
namespace Statistics
{
/** \class MultilayerNeuralNetworkBase
 * \brief This is the itkMultilayerNeuralNetworkBase class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename TMeasurementVector, typename TTargetVector,typename TLearningLayer=LayerBase<TMeasurementVector, TTargetVector> >
class ITK_TEMPLATE_EXPORT MultilayerNeuralNetworkBase : public NeuralNetworkObject<TMeasurementVector, TTargetVector>
{
public:

  using Self = MultilayerNeuralNetworkBase;
  using Superclass = NeuralNetworkObject<TMeasurementVector, TTargetVector>;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  itkTypeMacro(MultilayerNeuralNetworkBase, NeuralNetworkObject);

  /** New macro for creation of through a Smart Pointer. */
  itkNewMacro( Self );

  using ValueType = typename Superclass::ValueType;
  using MeasurementVectorType = typename Superclass::MeasurementVectorType;
  using TargetVectorType = typename Superclass::TargetVectorType;
  using NetworkOutputType = typename Superclass::NetworkOutputType;

  using LayerInterfaceType = typename Superclass::LayerInterfaceType;

  using LearningLayerType = TLearningLayer;
  using LearningFunctionInterfaceType = LearningFunctionBase<typename TLearningLayer::LayerInterfaceType, TTargetVector>;

  using WeightVectorType = std::vector<typename LayerInterfaceType::WeightSetInterfaceType::Pointer>;
        using LayerVectorType = std::vector<typename LayerInterfaceType::Pointer>;

        using TransferFunctionInterfaceType = TransferFunctionBase<ValueType>;
        using InputFunctionInterfaceType = InputFunctionBase<ValueType*, ValueType>;

//#define __USE_OLD_INTERFACE  Comment out to ensure that new interface works
#ifdef __USE_OLD_INTERFACE
  itkSetMacro(NumOfLayers, int);
  itkGetConstReferenceMacro(NumOfLayers, int);

  itkSetMacro(NumOfWeightSets, int);
  itkGetConstReferenceMacro(NumOfWeightSets, int);
#else
  int GetNumOfLayers(void) const
    {
    return m_Layers.size();
    }
  int GetNumOfWeightSets(void) const
    {
    return m_Weights.size();
    }

#endif

  void AddLayer(LayerInterfaceType *);
  LayerInterfaceType * GetLayer(int layer_id);
  const LayerInterfaceType * GetLayer(int layer_id) const;

  void AddWeightSet(typename LayerInterfaceType::WeightSetInterfaceType*);
  typename LayerInterfaceType::WeightSetInterfaceType* GetWeightSet(unsigned int id)
    {
    return m_Weights[id].GetPointer();
    }
#ifdef __USE_OLD_INTERFACE
  const typename LayerInterfaceType::WeightSetInterfaceType* GetWeightSet(unsigned int id) const;
#endif

  void SetLearningFunction(LearningFunctionInterfaceType* f);

  NetworkOutputType GenerateOutput(TMeasurementVector samplevector) override;

  void BackwardPropagate(NetworkOutputType errors) override;
  void UpdateWeights(ValueType) override;

  void SetLearningRule(LearningFunctionInterfaceType*);

  void SetLearningRate(ValueType learningrate);

  void InitializeWeights();

protected:
  MultilayerNeuralNetworkBase();
  ~MultilayerNeuralNetworkBase() override;

  LayerVectorType                                   m_Layers;
  WeightVectorType                                  m_Weights;
  typename LearningFunctionInterfaceType::Pointer   m_LearningFunction;
  ValueType                                         m_LearningRate;
  //#define __USE_OLD_INTERFACE  Comment out to ensure that new interface works
#ifdef __USE_OLD_INTERFACE
  //These are completely redundant variables that can be more reliably queried from
  // m_Layers->size() and m_Weights->size();
  int                             m_NumOfLayers;
  int                             m_NumOfWeightSets;
#endif
  /** Method to print the object. */
  void PrintSelf( std::ostream& os, Indent indent ) const override;
};

} // end namespace Statistics
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkMultilayerNeuralNetworkBase.hxx"
#endif

#endif
