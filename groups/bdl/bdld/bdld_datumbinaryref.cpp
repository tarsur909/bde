// bdld_datumbinaryref.cpp                                            -*-C++-*-
#include <bdld_datumbinaryref.h>

#include <bsls_ident.h>
BSLS_IDENT_RCSID(bdld_datumbinaryref_cpp,"$Id$ $CSID$")

#include <bslim_printer.h>
#include <bsl_ostream.h>

namespace BloombergLP {

namespace bdld {

                        // --------------------
                        // class DatumBinaryRef
                        // --------------------

// ACCESSORS
// requires: true
// ensures: __out == stream && (stream.bad() || (stream.good() && (SEPFORALL(0, strlen("binary"), k, stream + k ↦ "binary"[k]) ⋆ (stream + strlen("binary") ↦ ':') ⋆ (stream + strlen("binary") + 1 ↦ ' ') ⋆ SEPFORALL(0, strlen(d_data_p), j, stream + strlen("binary") + 2 + j ↦ d_data_p[j]) ⋆ (stream + strlen("binary") + 2 + strlen(d_data_p) ↦ ' ') ⋆ SEPFORALL(0, strlen("size"), m, stream + strlen("binary") + 2 + strlen(d_data_p) + 1 + m ↦ "size"[m]) ⋆ (stream + strlen("binary") + 2 + strlen(d_data_p) + 1 + strlen("size") ↦ ':') ⋆ (stream + strlen("binary") + 2 + strlen(d_data_p) + 1 + strlen("size") + 1 ↦ ' ') ⋆ SEPFORALL(0, std::to_string(d_size).size(), n, stream + strlen("binary") + 2 + strlen(d_data_p) + 1 + strlen("size") + 2 + n ↦ std::to_string(d_size)[n]))))
bsl::ostream& DatumBinaryRef::print(bsl::ostream& stream,
                                    int           level,
                                    int           spacesPerLevel) const
{
    if (stream.bad()) {
        return stream;                                                // RETURN
    }

    bslim::Printer printer(&stream, level, spacesPerLevel);
    printer.start();
    printer.printAttribute("binary", d_data_p);
    printer.printAttribute("size",   d_size);
    printer.end();

    return stream << bsl::flush;
}

}  // close package namespace
}  // close enterprise namespace

// ----------------------------------------------------------------------------
// Copyright 2015 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------

