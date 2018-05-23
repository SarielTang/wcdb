/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef Assertion_hpp
#define Assertion_hpp

#include <WCDB/Reporter.hpp>

//TODO add #file and #line into assert/fatal
#ifdef DEBUG

//debug assert
#define WCTAssert(cond, message)                                               \
    if (!(cond)) {                                                             \
        WCDB::Reporter::shared()->report(                                      \
            WCDB::Error::fatal((message), __FILE__, __LINE__));                \
    }

//remedial assert
#define WCTRemedialAssert(cond, message, remedial) WCTAssert((cond), (message))

//fatal error
#define WCTFatalError(message) WCTAssert(false, (message))

//remedial error
#define WCTRemedialError(message, remedial) WCTFatalError(message)

//inner assert
#define WCTInnerAssert(cond)                                                   \
    WCTAssert(cond,                                                            \
              "If you think it's a bug caused by WCDB, please report to us.")

//inner fatal error
#define WCTInnerFatalError() WCTInnerAssert(false)

#else //ELSE

#define WCTAssert(cond, message)                                               \
    if (!(cond)) {                                                             \
        WCDB::Reporter::shared()->report(                                      \
            WCDB::Error::error((message), __FILE__, __LINE__));                \
    }

//remedial assert
#define WCTRemedialAssert(cond, message, remedial)                             \
    if (!(cond)) {                                                             \
        WCDB::Reporter::shared()->report(                                      \
            WCDB::Error::error((message), __FILE__, __LINE__));                \
        remedial                                                               \
    }

#define WCTFatalError(message) WCTAssert(false, (message))

//remedial fatal error
#define WCTRemedialFatalError(message, remedial)                               \
    WCTRemedialAssert(false, (message), remedial)

//inner assert
#define WCTInnerAssert(cond)

#define WCTInnerFatalError()

#endif //DEBUG

#define WCTWarning(message)                                                    \
    WCDB::Reporter::shared()->report(                                          \
        WCDB::Error::warning((message), __FILE__, __LINE__))

#endif /* Assertion_hpp */