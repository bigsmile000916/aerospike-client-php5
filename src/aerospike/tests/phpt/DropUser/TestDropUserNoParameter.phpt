--TEST--
Drop user - drop user no parmaeter

--SKIPIF--
<?php
include dirname(__FILE__)."/../../astestframework/astest-phpt-loader.inc";
aerospike_phpt_skipif("DropUser", "testDropUserNoParameter");

--FILE--
<?php
include dirname(__FILE__)."/../../astestframework/astest-phpt-loader.inc";
aerospike_phpt_runtest("DropUser", "testDropUserNoParameter");
--EXPECT--
ERR_PARAM
