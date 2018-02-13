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
#ifndef itkTransferFunctionBase_h
#define itkTransferFunctionBase_h

#include "itkFunctionBase.h"
#include "itkArray.h"

namespace itk
{
namespace Statistics
{
/** \class TransferFunctionBase
 * \brief This is the itkTransferFunctionBase class.
 *
 * \ingroup ITKNeuralNetworks
 */

template<typename ScalarType>
class TransferFunctionBase : public FunctionBase<ScalarType, ScalarType>
{
public:

  /** Standard class type alias. */
  using Self = TransferFunctionBase;
  using Superclass = FunctionBase<ScalarType, ScalarType>;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** Run-time type information (and related methods). */
  itkTypeMacro(TransferFunctionBase, FunctionBase);

  /** Input type */
  using InputType = ScalarType;

  /** Output type */
  using OutputType = ScalarType;
  using ArrayType = Array<ScalarType>;

  /** Evaluate at the specified input position */
  OutputType Evaluate(const InputType& input) const override = 0;

  /** Evaluate the derivative at the specified input position */
  virtual OutputType EvaluateDerivative(const InputType& input) const = 0;

protected:
  TransferFunctionBase() {};
  ~TransferFunctionBase() ITK_OVERRIDE {};

  /** Method to print the object. */
  void PrintSelf( std::ostream& os, Indent indent ) const override
    {
    os << indent << "TransferFunctionBase(" << this << ")" << std::endl;
    Superclass::PrintSelf( os, indent );
    }

private:

  ITK_DISALLOW_COPY_AND_ASSIGN(TransferFunctionBase);
};

} // end namespace Statistics
} // end namespace itk
#endif
