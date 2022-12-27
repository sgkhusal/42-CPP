#!/bin/bash

cat 19920104_091532.log | cut -d ' ' -f2 > old_log
cat log | cut -d ' ' -f2 > new_log
diff old_log new_log > diff_log
