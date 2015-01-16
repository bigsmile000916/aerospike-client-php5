
# Aerospike::append

Aerospike::append - appends a string to the string value in a bin

## Description

```
public int Aerospike::append ( array $key, string $bin, string $value [, array $options ] )
```

**Aerospike::append()** will append a string to the string value in *bin*.
Like other bin operations, append() only works on existing records
(i.e. ones that were previously created with a put()).


## Parameters

**key** the key under which the record can be found. An array with keys ['ns','set','key'] or ['ns','set','digest'].

**bin** the name of the bin in which we have a numeric value.

**value** the string to append to the string value in the bin.

**[options](aerospike.md)** including
- **Aerospike::OPT_POLICY_KEY**
- **Aerospike::OPT_WRITE_TIMEOUT**
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

$key = $db->initKey("test", "users", 1234);
$status = $db->append($key, 'name', ' Ph.D.');
if ($status == Aerospike::OK) {
    echo "Added the Ph.D. suffix to the user.\n";
} else {
    echo "[{$db->errorno()}] ".$db->error();
}

?>
```

We expect to see:

```
Added the Ph.D. suffix to the user.
```

