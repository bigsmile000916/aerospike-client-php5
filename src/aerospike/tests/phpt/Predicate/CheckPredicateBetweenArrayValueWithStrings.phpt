--TEST--
PredicateEquals - string args to become an array of (min, max) integer

--FILE--
<?php
include dirname(__FILE__)."/../../astestframework/astest-phpt-loader.inc";
aerospike_phpt_runtest("Predicate", "testPredicateBetweenArrayValueWithStrings");
--EXPECT--
OK
