--TEST--
queryApply() with all mandatory arguments

--DESCRIPTION--
This testcase will test for queryApply() with all correct arguments and check
whether records which satisfy predicate are modified through get() API

--FILE--
<?php
include dirname(__FILE__)."/../../astestframework/astest-phpt-loader.inc";
aerospike_phpt_runtest("QueryApply", "normal_001");
?>

--EXPECT--
OK
