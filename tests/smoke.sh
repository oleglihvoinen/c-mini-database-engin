#!/usr/bin/env bash
set -euo pipefail
rm -f /tmp/minidb-test.dat
printf 'INSERT 1 ACME 10.5\nSELECT 1\nDELETE 1\nSELECT 1\nQUIT\n' | ./minidb /tmp/minidb-test.dat | tee /tmp/minidb.out
grep -q $'1\tACME\t10.50' /tmp/minidb.out
grep -q 'NOT FOUND' /tmp/minidb.out
