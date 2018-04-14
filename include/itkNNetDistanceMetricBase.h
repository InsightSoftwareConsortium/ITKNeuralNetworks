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
#ifndef itkNNetDistanceMetricBase_h
#define itkNNetDistanceMetricBase_h

#include "itkFunctionBase.h"

namespace itk
{
namespace Statistics
{
/** \class NNetDistanceMetricBase
 * \brief This is the itkNNetDistanceMetricBase class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename TMeasurementVector>
class NNetDistanceMetricBase : public FunctionBase<TMeasurementVector, double>
{
public:
  ITK_DISALLOW_COPY_AND_ASSIGN(NNetDistanceMetricBase );

  /** Standard class type alias. */
  using Self = NNetDistanceMetricBase;
  using Superclass = FunctionBase<TMeasurementVector,double>;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** Run-time type information (and related methods). */
  itkTypeMacro(NNetDistanceMetricBase, FunctionBase);

  /** Input type */
  using InputVectorType = TMeasurementVector;

  /** Evaluate at the specified input position */
  virtual double Evaluate(const InputVectorType& x1, const InputVectorType& x2) const = 0;

  /** Evaluate */
  virtual double Evaluate(const InputVectorType& ) const {return 0;}

protected:
  NNetDistanceMetricBase() {};
  ~NNetDistanceMetricBase() {};

  /** Method to print the object. */
  virtual void PrintSelf( std::ostream& os, Indent indent ) const
    {
    os << indent << "NNetDistanceMetricBase(" << this << ")" << std::endl;
    Superclass::PrintSelf( os, indent );
    }
};

} // end namespace Statistics
} // end namespace itk

#endif
