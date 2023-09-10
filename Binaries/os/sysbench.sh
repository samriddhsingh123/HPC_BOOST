sysbench memory --memory-block-size=1M --memory-total-size=10G run
sysbench fileio --file-total-size=10G --file-test-mode=seqwr prepare
sysbench fileio --file-total-size=10G --file-test-mode=seqwr run
sysbench fileio --file-total-size=10G --file-test-mode=seqwr cleanup