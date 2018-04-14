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
#ifndef itkInputFunctionBase_h
#define itkInputFunctionBase_h

#include "itkFunctionBase.h"

namespace itk
{
namespace Statistics
{
/** \class InputFunctionBase
 * \brief This is the itkInputFunctionBase class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename TMeasurementVector, typename TTargetVector>
class InputFunctionBase : public FunctionBase<TMeasurementVector, TTargetVector>
{
public:
  ITK_DISALLOW_COPY_AND_ASSIGN(InputFunctionBase);

  /** Standard class type alias. */
  using Self = InputFunctionBase;
  using Superclass = FunctionBase<TMeasurementVector, TTargetVector>;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** Run-time type information (and related methods). */
  itkTypeMacro(InputFunctionBase, FunctionBase);

  /** Input type */
  using InputVectorType = TMeasurementVector;

  /** Output type */
  using OutputType = TTargetVector;

  /** Evaluate at the specified input position */
  OutputType Evaluate(const InputVectorType& input) const override = 0;

  virtual void SetSize(unsigned int) = 0;

protected:

  InputFunctionBase() {};
  ~InputFunctionBase() override {};

  /** Method to print the object. */
  void PrintSelf( std::ostream& os, Indent indent ) const override
    {
    os << indent << "InputFunctionBase(" << this << ")" << std::endl;
    Superclass::PrintSelf( os, indent );
    }

private:

};//class

} // end namespace Statistics
} // end namespace itk

#endif
