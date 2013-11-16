//===--- Enum.h - Runtime declarations for enums ---------------*- C++ -*--===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
//
// Swift runtime functions in support of enums.
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_RUNTIME_ENUM_H
#define SWIFT_RUNTIME_ENUM_H

namespace swift {
  
struct OpaqueValue;
struct ValueWitnessTable;
struct Metadata;
  
/// \brief Initialize the value witness table for a generic, single-payload
///        enum instance.
///
/// \param vwtable - pointer to the instantiated but uninitialized value
///                  witness table for the enum.
/// \param payload - type metadata for the payload case of the enum.
/// \param emptyCases - the number of empty cases in the enum.
extern "C" void swift_initEnumValueWitnessTableSinglePayload(
                                                    ValueWitnessTable *vwtable,
                                                    const Metadata *payload,
                                                    unsigned emptyCases);

/// \brief Return an integer value representing which case of a single-payload
///        enum is inhabited.
///
/// \param value - pointer to the enum value.
/// \param payload - type metadata for the payload case of the enum.
/// \param emptyCases - the number of empty cases in the enum.
///
/// \returns -1 if the payload case is inhabited. If an empty case is inhabited,
///          returns a value greater than or equal to zero and less than
///          emptyCases.
extern "C" int swift_getEnumCaseSinglePayload(const OpaqueValue *value,
                                               const Metadata *payload,
                                               unsigned emptyCases);

/// \brief Store the tag value for the given case.
///
/// \param value - pointer to the enum value. If the case being initialized is
///                the payload case (-1), then the payload should be
///                initialized.
/// \param payload - type metadata for the payload case of the enum.
/// \param whichCase - unique value identifying the case. -1 for the payload
///                    case, or a value greater than or equal to zero and less
///                    than emptyCases for an empty case.
/// \param emptyCases - the number of empty cases in the enum.
extern "C" void swift_storeEnumTagSinglePayload(OpaqueValue *value,
                                                 const Metadata *payload,
                                                 int whichCase,
                                                 unsigned emptyCases);

}

#endif