#include <gtest/gtest.h>

#include <chrono>

#include "databento/constants.hpp"
#include "databento/datetime.hpp"
#include "databento/dbn.hpp"

namespace databento {
namespace test {
TEST(DbnTests, TestMetadataToString) {
  const Metadata target{1,
                        dataset::kGlbxMdp3,
                        false,
                        Schema::Ohlcv1D,
                        UnixNanos{std::chrono::seconds{1696959347}},
                        UnixNanos{std::chrono::seconds{1696950000}},
                        {},
                        false,
                        SType::RawSymbol,
                        SType::InstrumentId,
                        false,
                        {"NGG3", "NGQ4"},
                        {"ng"},
                        {"nf"},
                        {{"NGG3", {{20220601, 20220701, "3"}}},
                         {"NGQ4", {{20220601, 20220701, "4"}}}}};
  const auto res = ToString(target);
  ASSERT_EQ(res, R"(Metadata {
    version = 1,
    dataset = "GLBX.MDP3",
    has_mixed_schema = false,
    schema = ohlcv-1d,
    start = 2023-10-10T17:35:47.000000000Z,
    end = 2023-10-10T15:00:00.000000000Z,
    limit = 0,
    has_mixed_stype_in = false,
    stype_in = raw_symbol,
    stype_out = instrument_id,
    ts_out = false,
    symbols = { "NGG3", "NGQ4" },
    partial = { "ng" },
    not_found = { "nf" },
    mappings = {
        SymbolMapping { raw_symbol = "NGG3", intervals = { MappingInterval { start_date = 20220601, end_date = 20220701, symbol = "3" } } },
        SymbolMapping { raw_symbol = "NGQ4", intervals = { MappingInterval { start_date = 20220601, end_date = 20220701, symbol = "4" } } }
    }
})");
}
}  // namespace test
}  // namespace databento
