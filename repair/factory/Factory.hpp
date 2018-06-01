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

#ifndef Factory_hpp
#define Factory_hpp

#include <WCDB/FactoryArchiver.hpp>
#include <WCDB/FactoryMaterials.hpp>
#include <WCDB/FactoryRestorer.hpp>
#include <future>
#include <list>
#include <string>

namespace WCDB {

namespace Repair {

class Assembler;

class Factory {
public:
    Factory(const std::string &database);

    const std::string database;
    const std::string directory;

    std::list<std::string> getAssociatedPaths() const;

    std::string getFirstMaterialPath() const;
    std::string getLastMaterialPath() const;

    FactoryArchiver archiver() const;
    FactoryRestorer restorer() const;
};

} //namespace Repair

} //namespace WCDB

#endif /* Factory_hpp */