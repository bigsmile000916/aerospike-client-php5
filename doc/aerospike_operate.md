
# Aerospike::operate

Aerospike::operate - multiple operations on a single record

## Description

```
public int Aerospike::operate ( array $key, array $operations [, array &$returned [, array $options]] )
```

**Aerospike::operate()** allows for multiple per-bin operations on a *record*
with a given *key*, with write operations happening before read ones.
Non-existent bins being read will have a NULL value.

## Parameters

**key** the key identifying the record. An array with keys ['ns','set','key'] or ['ns','set','digest'].

**operations** an array of one or more per-bin operations conforming
to the following structure:
```
Write Operation:
  op => Aerospike::OPERATOR_WRITE
  bin => bin name
  val => the value to store in the bin

Increment Operation:
  op => Aerospike::OPERATOR_INCR
  bin => bin name
  val => the integer by which to increment the value in the bin

Prepend Operation:
  op => Aerospike::OPERATOR_PREPEND
  bin => bin name
  val => the string to prepend the string value in the bin

Append Operation:
  op => Aerospike::OPERATOR_APPEND
  bin => bin name
  val => the string to append the string value in the bin

Read Operation:
  op => Aerospike::OPERATOR_READ
  bin => name of the bin we want to read after any write operations

Touch Operation: reset the time-to-live of the record and increment its generation
  op => Aerospike::OPERATOR_TOUCH
```
*examples:*
```
array(
  array("op" => Aerospike::OPERATOR_APPEND, "bin" => "name", "val" => " Ph.D."),
  array("op" => Aerospike::OPERATOR_INCR, "bin" => "age", "val" => 1),
  array("op" => Aerospike::OPERATOR_READ, "bin" => "age"),
  array("op" => Aerospike::OPERATOR_TOUCH)
)
```

**returned** an array of bins retrieved by read operations

**[options](aerospike.md)** including
- **Aerospike::OPT_POLICY_KEY**
- **Aerospike::OPT_WRITE_TIMEOUT**
- **Aerospike::OPT_POLICY_RETRY**
- **Aerospike::OPT_POLICY_GEN**
- **Aerospike::OPT_POLICY_COMMIT_LEVEL**
- **Aerospike::OPT_POLICY_REPLICA**
- **Aerospike::OPT_POLICY_CONSISTENCY**

## Return Values

Returns an integer status code.  Compare to the Aerospike class status
constants.  When non-zero the **Aerospike::error()** and
**Aerospike::errorno()** methods can be used.

## Examples

```php
<?php

$config = array("hosts"=>array(array("addr"=>"localhost", "port"=>3000)));
$db = new Aerospike($config);
if (!$db->isConnected()) {
   echo "Aerospike failed to connect[{$db->errorno()}]: {$db->error()}\n";
   exit(1);
}

$key = $db->initKey("test", "users", 1234);
$operations = array(
  array("op" => Aerospike::OPERATOR_APPEND, "bin" => "name", "val" => " Ph.D."),
  array("op" => Aerospike::OPERATOR_INCR, "bin" => "age", "val" => 1),
  array("op" => Aerospike::OPERATOR_READ, "bin" => "age"),
  array("op" => Aerospike::OPERATOR_TOUCH)
);
$status = $db->operate($key, $operations, $returned);
if ($status == Aerospike::OK) {
    var_dump($returned);
} else {
    echo "[{$db->errorno()}] ".$db->error();
}

?>
```

We expect to see:

```
array(1) {
  ["age"]=>
  int(34)
}
```

