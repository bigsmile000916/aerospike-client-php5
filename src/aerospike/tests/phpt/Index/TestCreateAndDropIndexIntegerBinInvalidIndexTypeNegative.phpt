--TEST--
createIndex and dropIndex - Invalid index type

--FILE--
<?php
include dirname(__FILE__)."/../../astestframework/astest-phpt-loader.inc";
aerospike_phpt_runtest("Index", "testCreateAndDropIndexIntegerBinInvalidIndexTypeNegative");
--EXPECT--
ERR_PARAM

