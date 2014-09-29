setenv CLIENTREPO_3X ${PWD}/aerospike-client-c
setenv AEROSPIKE_C_CLIENT 3.0.80
setenv PATH ${PATH}:${PWD}/scripts

echo "Using Aerospike C API version: $AEROSPIKE_C_CLIENT"

if ( ! -d $CLIENTREPO_3X ) then
    echo "Downloading Aerospike C Client SDK..."
else
    echo "Aerospike C Client SDK is present."
endif
scripts/aerospike-client-c.sh

if ( $? -eq 0 ) then
    cd src/aerospike
endif
