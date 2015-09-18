#!/bin/bash

make install
echo "extension = aerospike.so" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
echo "aerospike.udf.lua_system_path=/opt/aerospike/lua" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
echo "aerospike.udf.lua_user_path=/opt/aerospike/usr-lua" >> ~/.phpenv/versions/$(phpenv version-name)/etc/php.ini
$(phpenv which php) -m | grep aerospike
if [ $? -gt 0 ] ; then
    echo "The aerospike extension failed to load for $(phpenv version-name)"
    exit 1
fi
