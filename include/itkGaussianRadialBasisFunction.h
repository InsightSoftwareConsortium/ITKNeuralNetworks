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
#ifndef itkGaussianRadialBasisFunction_h
#define itkGaussianRadialBasisFunction_h

#include "itkRadialBasisFunctionBase.h"
#include "itkNNetDistanceMetricBase.h"

namespace itk
{
namespace Statistics
{
/** \class GaussianRadialBasisFunction
 * \brief This is the itkGaussianRadialBasisFunction class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename ScalarType>
class ITK_TEMPLATE_EXPORT GaussianRadialBasisFunction : public RadialBasisFunctionBase<ScalarType>
{
public:

  /** Standard class type alias. */
  using Self = GaussianRadialBasisFunction;
  using Superclass = RadialBasisFunctionBase<ScalarType>;
  using ArrayType = typename Superclass::ArrayType;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** Run-time type information (and related methods). */
  itkTypeMacro(GaussianRadialBasisFunction,RadialBasisFunctionBase);

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Evaluate at the specified input position */
  ScalarType Evaluate(const ScalarType& input) const override;

  virtual ScalarType EvaluateDerivative(const ScalarType& dist,const ArrayType& input,
                                      char mode,int element_id=0) const override;

protected:

  GaussianRadialBasisFunction();
  ~GaussianRadialBasisFunction() override;

  /** Method to print the object. */
  void PrintSelf( std::ostream& os, Indent indent ) const override;

};

} // end namespace Statistics
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
  #include "itkGaussianRadialBasisFunction.hxx"
#endif

#endif
