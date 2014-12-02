
# Aerospike::increment

Aerospike::increment - increments a numeric value in a bin

## Description

```
public int Aerospike::increment ( array $key, string $bin, int $offset [, int $initial_value = 0 [, array $options ]] )
```

**Aerospike::increment()** will increment a *bin* containing a numeric value by the *offest* or
set it to the *initial_value* if it does not exist.

## Parameters

**key** the key under which the record can be found. An array with keys ['ns','set','key'] or ['ns','set','digest'].

**bin** the name of the bin in which we have a numeric value.

**offset** the integer by which to increment the value in the bin.

**initial_value** the integer to set in the bin if it is empty

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
$status = $db->increment($key, 'pto', -4);
if ($status == Aerospike::OK) {
    echo "Decremented four vacation days from the user's PTO balance.\n";
} else {
    echo "[{$db->errorno()}] ".$db->error();
}

?>
```

We expect to see:

```
Decremented four vacation days from the user's PTO balance.
```

