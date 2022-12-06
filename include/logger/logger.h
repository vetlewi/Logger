//
// Created by Vetle Wegner Ingeberg on 06/12/2022.
//

#ifndef ALL_LOGGER_H
#define ALL_LOGGER_H

#include <iosfwd>
#include <iomanip>
#include <string>

namespace OCL {

    /*!
     * A very simple logger. The logger may be configured with an optional file as target.
     */


    enum Severity {
        none = 0,       //!< If level is unknown
        fatal = 1,      //!< Fatal, application will fail
        error = 2,      //!< Error, application will continue to run
        warning = 3,    //!< Warning, application gives a warning in case of potential error
        info = 4,       //!< Information that is useful to the current progress of the application
        debug = 5,      //!< Information useful while debugging the application
        verbose = 6     //!< If even more information is required
    };

    class Logger {
        const Severity S;
    public:
        explicit Logger(const Severity &s) : S( s ){}

        friend std::ostream& operator<<(std::ostream &os, const Logger &log){
            std::time_t t = std::time(nullptr);
            std::tm tm = *std::localtime(&t);

            os << std::put_time(&tm, "%c %Z") << " - " << OCL::Logger::severity_str[log.S] << " - ";
            return os;
        }

        static const char *severity_str[];
    };

}

#endif //ALL_LOGGER_H
