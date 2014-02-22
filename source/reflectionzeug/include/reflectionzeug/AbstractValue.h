
#pragma once

#include "reflectionzeug/reflectionzeug.h"

namespace reflectionzeug
{
    
/** \brief The base class for value implementations of ValuePropertyTemplate.
 */
template <typename Type>
class AbstractValue
{
public:
    virtual ~AbstractValue() { };
    
    virtual Type get() const = 0;
    virtual void set(const Type & value) = 0;
};

} // namespace reflectionzeug