
# Aerospike::removeBin

Aerospike::removeBin - removes a bin from a record

## Description

```
public int Aerospike::removeBin ( array $key, array $bins [, array $options ] )
```

**Aerospike::removeBin()** will remove the specified *bins* from the record* with
 a given *key*.

## Parameters

**key** the key for the record. An array with keys ['ns','set','key'] or ['ns','set','digest'].

**bins** the name of the bins to be removed from the record.

**[options](aerospike.md)** including
- **Aerospike::OPT_WRITE_TIMEOUT**
- **Aerospike::OPT_POLICY_KEY**
- **Aerospike::OPT_POLICY_RETRY**
- **Aerospike::OPT_POLICY_GEN**
- **Aerospike::OPT_POLICY_COMMIT_LEVEL**

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

$key = array("ns" => "test", "set" => "users", "key" => 1234);
$status = $db->removeBin($key, array("age"));
if ($status == Aerospike::OK) {
    echo "Removed bin 'age' from the record.\n";
} elseif ($status == Aerospike::ERR_RECORD_NOT_FOUND) {
    echo "The database has no record with the given key.\n";
} else {
    echo "[{$db->errorno()}] ".$db->error();
}

?>
```

We expect to see:

```
Removed bin 'age' from the record.
```

or

```
The database has no record with the given key.
```

