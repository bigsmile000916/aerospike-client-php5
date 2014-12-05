#ifndef __AEROSPIKE_GENERAL_CONSTANTS_H__
#define __AEROSPIKE_GENERAL_CONSTANTS_H__

#include "aerospike/aerospike_index.h"
#define MAX_GENERAL_CONSTANT_STR_SIZE 512

/*
 *******************************************************************************************************
 * Enum for PHP client's index constant values.
 *******************************************************************************************************
 */
enum Aerospike_index_constants {
    INDEX_TYPE_STRING = AS_INDEX_STRING,     /* Secondary index on a string bin */
    INDEX_TYPE_INTEGER = AS_INDEX_NUMERIC    /* Secondary index on an integer bin */
};

/*
 *******************************************************************************************************
 * Enum for PHP client's operate constant values.
 *******************************************************************************************************
 */
enum Aerospike_operate_constants {
    OPERATOR_WRITE   = 0,
    OPERATOR_READ    = 1,
    OPERATOR_INCR    = 2,
    OPERATOR_PREPEND = 4,
    OPERATOR_APPEND  = 5,
    OPERATOR_TOUCH   = 8,
};
/*
 *******************************************************************************************************
 * Structure to map constant number to constant name string for Aerospike General Long constants.
 *******************************************************************************************************
 */
typedef struct Aerospike_General_Long_Constants {
    int constantno;
    char constant_str[MAX_GENERAL_CONSTANT_STR_SIZE];
} AerospikeGeneralLongConstants;

/*
 *******************************************************************************************************
 * Structure to map constant number to constant name string for Aerospike General String constants.
 *******************************************************************************************************
 */
typedef struct Aerospike_General_String_Constants {
    char constant_value[MAX_GENERAL_CONSTANT_STR_SIZE];
    char constant_str[MAX_GENERAL_CONSTANT_STR_SIZE];
} AerospikeGeneralStringConstants;

/*
 *******************************************************************************************************
 * Instance of Mapper of constant number to constant name string for Aerospike General Long constants.
 *******************************************************************************************************
 */
static AerospikeGeneralLongConstants aerospike_general_long_constants[] = {
    { INDEX_TYPE_STRING,    "INDEX_TYPE_STRING"  },
    { INDEX_TYPE_INTEGER,   "INDEX_TYPE_INTEGER" },
    { OPERATOR_WRITE,       "OPERATOR_WRITE" },
    { OPERATOR_READ,        "OPERATOR_READ" },
    { OPERATOR_INCR,        "OPERATOR_INCR" },
    { OPERATOR_PREPEND,     "OPERATOR_PREPEND" },
    { OPERATOR_APPEND,      "OPERATOR_APPEND" },
    { OPERATOR_TOUCH,       "OPERATOR_TOUCH" }
};

/*
 *******************************************************************************************************
 * Instance of Mapper of constant number to constant name string for Aerospike General String constants.
 *******************************************************************************************************
 */
static AerospikeGeneralStringConstants aerospike_general_string_constants[] = {
    { "=",         "OP_EQ"  },
    { "BETWEEN",   "OP_BETWEEN" }
};

#define AEROSPIKE_GENERAL_LONG_CONSTANTS_ARR_SIZE (sizeof(aerospike_general_long_constants)/sizeof(AerospikeGeneralLongConstants))
#define AEROSPIKE_GENERAL_STRING_CONSTANTS_ARR_SIZE (sizeof(aerospike_general_string_constants)/sizeof(AerospikeGeneralStringConstants))

/*
 *******************************************************************************************************
 * MACRO to expose general long constants in Aerospike class.
 *
 * @param Aerospike_ce          The zend class ent
 * ry for Aerospike class.
 *******************************************************************************************************
 */
#define EXPOSE_GENERAL_CONSTANTS_LONG_ZEND(Aerospike_ce)                                        \
do {                                                                                            \
    int32_t i;                                                                                  \
    for (i = 0; i < AEROSPIKE_GENERAL_LONG_CONSTANTS_ARR_SIZE; i++) {                           \
        zend_declare_class_constant_long(                                                       \
                Aerospike_ce, aerospike_general_long_constants[i].constant_str,                 \
                    strlen(aerospike_general_long_constants[i].constant_str),                   \
                aerospike_general_long_constants[i].constantno TSRMLS_CC);                      \
    }                                                                                           \
} while(0);

/*
 *******************************************************************************************************
 * MACRO to expose general string constants in Aerospike class.
 *
 * @param Aerospike_ce          The zend class entry for Aerospike class.
 *******************************************************************************************************
 */
#define EXPOSE_GENERAL_CONSTANTS_STRING_ZEND(Aerospike_ce)                                      \
do {                                                                                            \
    int32_t i;                                                                                  \
    for (i = 0; i < AEROSPIKE_GENERAL_STRING_CONSTANTS_ARR_SIZE; i++) {                         \
        zend_declare_class_constant_string(                                                     \
                Aerospike_ce, aerospike_general_string_constants[i].constant_str,               \
                    strlen(aerospike_general_string_constants[i].constant_str),                 \
                        aerospike_general_string_constants[i].constant_value TSRMLS_CC);        \
    }                                                                                           \
} while(0);
#endif
