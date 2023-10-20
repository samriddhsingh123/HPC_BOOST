# Read the two rows
header_row = "GID|EventCount|CpuCount|Total runtime [s]|TEMP_CORE|PWR_PKG_ENERGY|PWR_PP0_ENERGY|PWR_PP1_ENERGY|PWR_DRAM_ENERGY|PWR_PLATFORM_ENERGY|UNCORE_CLOCK|PP0_TEMP|PP1_TEMP|IO_REQUESTS|DRAM_READS|DRAM_WRITES|VOLTAGE_CORE|MPERF|APERF|PPERF|UOPS_ISSUED_CYCLES_GE_2_UOPS_EXEC|UOPS_ISSUED_CYCLES_GE_3_UOPS_EXEC|UOPS_ISSUED_CYCLES_GE_4_UOPS_EXEC|UOPS_ISSUED_CYCLES_GE_5_UOPS_EXEC|INSTR_RETIRED_ANY|CPU_CLK_UNHALTED_CORE|CPU_CLK_UNHALTED_REF"
values_row = "1 31 4 6.8364609139159e-05 41.0 40.0 41.0 39.0 0.0118408203125 0.0 0.0 0.0 0.00299072265625 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.00079345703125 0.0 0.0 0.0 0.00042724609375 0.0 0.0 0.0 1126618.0 0.0 0.0 0.0 44.0 0.0 0.0 0.0 44.0 0.0 0.0 0.0 6148.0 0.0 0.0 0.0 20383.0 0.0 0.0 0.0 3343.0 0.0 0.0 0.0 0.5821533203125 0.582275390625 0.58251953125 0.5821533203125 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 1118.0 5373.0 10685.0 45585.0 724.0 3857.0 12928.0 115357.0 272.0 1242.0 5639.0 8726.0 996.0 5099.0 18567.0 124083.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 273922.0 0.0 0.0 0.0 5066.0 0.0 0.0 0.0 0.0 0.0 0.0 0.0 14963.0 25996.0 57169.0 504139.0 72358.0 125961.0 277332.0 2446499.0"

# Split the rows into lists of columns
header_columns = header_row.split('|')
values_columns = values_row.split()

# Check if the number of columns matches
if len(header_columns) == len(values_columns):
    print("The number of columns in the header and values rows match.")
else:
    print(len(header_columns) - len(values_columns))
    print("The number of columns in the header and values rows do not match.")
