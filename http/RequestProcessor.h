
#ifndef UNTITLED_REQUESTPROCESSOR_H
#define UNTITLED_REQUESTPROCESSOR_H

#include <memory>
#include "Response.h"
#include "Request.h"

namespace http {
    class RequestProcessor {
    public:
        virtual std::shared_ptr<Response> doProcessing(std::shared_ptr<Request>) = 0;
    };
}


#endif //UNTITLED_REQUESTPROCESSOR_H
