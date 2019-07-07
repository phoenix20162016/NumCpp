/// @file
/// @author David Pilger <dpilger26@gmail.com>
/// [GitHub Repository](https://github.com/dpilger26/NumCpp)
/// @version 1.0
///
/// @section License
/// Copyright 2019 David Pilger
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this
/// software and associated documentation files(the "Software"), to deal in the Software
/// without restriction, including without limitation the rights to use, copy, modify,
/// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to the following
/// conditions :
///
/// The above copyright notice and this permission notice shall be included in all copies
/// or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
/// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
/// PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
/// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
/// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
/// @section Description
/// Methods for working with NdArrays
///
#pragma once

#include"NumCpp/NdArray/NdArray.hpp"

#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>

namespace nc
{
    //============================================================================
    // Method Description:
    ///						Return evenly spaced values within a given interval.
    ///
    ///						Values are generated within the half - open interval[start, stop)
    ///						(in other words, the interval including start but excluding stop).
    ///						For integer arguments the function is equivalent to the Python built - in
    ///						range function, but returns an ndarray rather than a list.
    ///
    ///						When using a non - integer step, such as 0.1, the results will often
    ///						not be consistent.It is better to use linspace for these cases.
    ///
    ///                     NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arange.html
    ///
    /// @param				inStart
    /// @param				inStop
    /// @param				inStep: (Optional, defaults to 1)
    /// @return
    ///				NdArray
    ///
    template<typename dtype>
    NdArray<dtype> arange(dtype inStart, dtype inStop, dtype inStep = 1)
    {
        if (inStep > 0 && inStop < inStart)
        {
            std::string errStr = "ERROR: arange: stop value must be larger than the start value for positive step.";
            std::cerr << errStr << std::endl;
            throw std::invalid_argument(errStr);
        }

        if (inStep < 0 && inStop > inStart)
        {
            std::string errStr = "ERROR: arange: start value must be larger than the stop value for negative step.";
            std::cerr << errStr << std::endl;
            throw std::invalid_argument(errStr);
        }

        std::vector<dtype> values;

        dtype theValue = inStart;

        if (inStep > 0)
        {
            while (theValue < inStop)
            {
                values.push_back(theValue);
                theValue += inStep;
            }
        }
        else
        {
            while (theValue > inStop)
            {
                values.push_back(theValue);
                theValue += inStep;
            }
        }

        return NdArray<dtype>(values);
    }

    //============================================================================
    // Method Description:
    ///						Return evenly spaced values within a given interval.
    ///
    ///						Values are generated within the half - open interval[start, stop)
    ///						(in other words, the interval including start but excluding stop).
    ///						For integer arguments the function is equivalent to the Python built - in
    ///						range function, but returns an ndarray rather than a list.
    ///
    ///						When using a non - integer step, such as 0.1, the results will often
    ///						not be consistent.It is better to use linspace for these cases.
    ///
    ///                     NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arange.html
    ///
    /// @param
    ///				inStop: start is 0 and step is 1
    /// @return
    ///				NdArray
    ///
    template<typename dtype>
    NdArray<dtype> arange(dtype inStop)
    {
        if (inStop <= 0)
        {
            std::string errStr = "ERROR: arange: stop value must ge greater than 0.";
            std::cerr << errStr << std::endl;
            throw std::invalid_argument(errStr);
        }

        return arange<dtype>(0, inStop, 1);
    }

    //============================================================================
    // Method Description:
    ///						Return evenly spaced values within a given interval.
    ///
    ///						Values are generated within the half - open interval[start, stop)
    ///						(in other words, the interval including start but excluding stop).
    ///						For integer arguments the function is equivalent to the Python built - in
    ///						range function, but returns an ndarray rather than a list.
    ///
    ///						When using a non - integer step, such as 0.1, the results will often
    ///						not be consistent.It is better to use linspace for these cases.
    ///
    ///                     NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arange.html
    ///
    /// @param
    ///				inSlice
    /// @return
    ///				NdArray
    ///
    template<typename dtype>
    NdArray<dtype> arange(const Slice& inSlice)
    {
        return arange<dtype>(inSlice.start, inSlice.stop, inSlice.step);
    }
}
