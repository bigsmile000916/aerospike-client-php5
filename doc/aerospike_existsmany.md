
# Aerospike::existsMany

Aerospike::existsMany - check if a batch of records exist in the Aerospike database

## Description

```
public int Aerospike::existsMany ( array $keys, array &$metadata [, array $options ] )
```

**Aerospike::existsMany()** will check if a batch of records from a list of given
*keys* exists in the database, and returned an indexed array matching the order
of the *keys*.
If the key exists its metadata will be returned in the *metadata* variable,
and non-existent records will have a NULL.

**Note** that the protocol existsMany() will use (batch-direct or batch-index) is
configurable through the config parameter Aerospike::USE\_BATCH\_DIRECT or
`php.ini` config parameter `aerospike.use_batch_direct`. By default batch-index
is used with servers that support it (version >= 3.6.0).

## Parameters

**keys** an array of initialized keys, each an array with keys ['ns','set','key'] or ['ns','set','digest'].

**metadata** filled by an array of metadata arrays.

**[options](aerospike.md)** including
- **Aerospike::OPT_READ_TIMEOUT**

## Return Values

Returns an integer status code.  Compare to the Aerospike class status
constants.  When non-zero the **Aerospike::error()** and
**Aerospike::errorno()** methods can be used.

## Examples

```php
<?php

$config = ["hosts" => [["addr"=>"localhost", "port"=>3000]], "shm"=>[]];
$client = new Aerospike($config, true);
if (!$client->isConnected()) {
   echo "Aerospike failed to connect[{$client->errorno()}]: {$client->error()}\n";
   exit(1);
}

$key1 = $client->initKey("test", "users", 1234);
$key2 = $client->initKey("test", "users", 1235); // this key does not exist
$key2 = $client->initKey("test", "users", 1236);
$keys = [$key1, $key2, $key3];
$status = $client->existsMany($keys, $metadata);
if ($status == Aerospike::OK) {
    var_dump($metadata);
} else {
    echo "[{$client->errorno()}] ".$client->error();
}

?>
```

We expect to see:

```
array(3) {
  [0]=>
  array(2) {
    ["generation"]=>
    int(6)
    ["ttl"]=>
    int(4294967295)
  }
  [1]=>
  NULL
  [2]=>
  array(2) {
    ["generation"]=>
    int(6)
    ["ttl"]=>
    int(4294967295)
  }
}
```
