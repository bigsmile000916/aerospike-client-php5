--TEST--
ScanApply - Percent is int

--FILE--
<?php
include dirname(__FILE__)."/../../astestframework/astest-phpt-loader.inc";
aerospike_phpt_runtest("ScanApply", "testScanApplyPercentIsInt");
--XFAIL--
Fails due to a known C client bug.
--EXPECT--
OK
