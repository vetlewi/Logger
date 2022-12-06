// Copyright (c) 2022. Vetle Wegner Ingeberg/University of Oslo.
// All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <doctest/doctest.h>

#include <logger/logger.h>
#include <logger/version.h>

#include <string_view>
#include <sstream>


static OCL::Severity severities[] =
        {OCL::none, OCL::fatal, OCL::error, OCL::warning, OCL::info, OCL::debug, OCL::verbose};
const char *severity_str[] = {"Unknown", "Fatal", "Error", "Warning", "Info", "Debug", "Verbose"};

static bool endsWith(std::string_view str, std::string_view suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

TEST_SUITE_BEGIN( "Logger" );


TEST_CASE("Logger version")
{
    static_assert(std::string_view(LOGGER_VERSION) == std::string_view(VERSION));
    CHECK(std::string(LOGGER_VERSION) == std::string(VERSION));
}

TEST_CASE("Severities")
{
    for ( auto s : severities ){
        SUBCASE( OCL::Logger::severity_str[s] ) {
            std::stringstream str_res;
            str_res << OCL::Logger(s);
            CHECK(endsWith(str_res.str(), std::string(severity_str[s]) + " - "));
        }
    }
}