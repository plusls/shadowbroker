%module pytrch
%{
#define SWIG_FILE_WITH_INIT
#define SWIG_PYTHON_STRICT_BYTE_CHAR
typedef void* TcLogger;
struct Config_struct
{
    uint8_t tmp[0x48];
};
struct Params_struct
{
    uint8_t tmp[0x38];
};
struct Paramchoice_struct
{
    uint8_t tmp[0x48];
};
struct Paramgroup_struct
{
    uint8_t tmp[0x40];
};
struct Parameter_struct
{
    uint8_t tmp[0x80];
};
#include "trch-1.h"
static PyObject* TrchError;  /* add this! */
SWIGINTERN int
SWIG_AsVal_char (PyObject *, char *);
SWIGINTERN int
SWIG_AsVal_short (PyObject *, short *);
SWIGINTERN int
SWIG_AsVal_int (PyObject *, int *);
SWIGINTERN int
SWIG_AsVal_long_SS_long (PyObject *, long long *);
SWIGINTERN int
SWIG_AsVal_unsigned_SS_char (PyObject *, unsigned char *);
SWIGINTERN int
SWIG_AsVal_unsigned_SS_short (PyObject *, unsigned short *);
SWIGINTERN int
SWIG_AsVal_unsigned_SS_int (PyObject *, unsigned int *);
SWIGINTERN int
SWIG_AsVal_unsigned_SS_long_SS_long (PyObject *, unsigned long long *);
SWIGINTERN PyObject*
SWIG_From_char (char);
SWIGINTERN PyObject*
SWIG_From_short (short);
SWIGINTERN PyObject*
SWIG_From_int (int);
SWIGINTERN PyObject*
SWIG_From_long_SS_long (long long);
SWIGINTERN PyObject*
SWIG_From_unsigned_SS_char (unsigned char);
SWIGINTERN PyObject*
SWIG_From_unsigned_SS_short (unsigned short);
SWIGINTERN PyObject*
SWIG_From_unsigned_SS_int (unsigned int);
SWIGINTERN PyObject*
SWIG_From_unsigned_SS_long_SS_long (unsigned long long);
SWIGINTERN int
toInterger(char* typeName, PyObject * obj, void* ptr)
{
    if (!strcmp(typeName, "char"))
        return SWIG_AsVal_char(obj, (char*)ptr);
    else if (!strcmp(typeName, "short"))
        return SWIG_AsVal_short(obj, (short*)ptr);
    else if (!strcmp(typeName, "int"))
        return SWIG_AsVal_int(obj, (int*)ptr);
    else if (!strcmp(typeName, "posh_i64_t"))
        return SWIG_AsVal_long_SS_long(obj, (posh_i64_t*)ptr);
    else if (!strcmp(typeName, "SOCKET"))
        return SWIG_AsVal_unsigned_SS_long_SS_long(obj, (SOCKET*)ptr);
    else if (!strcmp(typeName, "unsigned char"))
        return SWIG_AsVal_unsigned_SS_char(obj, (unsigned char*)ptr);
    else if (!strcmp(typeName, "unsigned short"))
        return SWIG_AsVal_unsigned_SS_short(obj, (unsigned short*)ptr);
    else if (!strcmp(typeName, "unsigned int"))
        return SWIG_AsVal_unsigned_SS_int(obj, (unsigned int*)ptr);
    else if (!strcmp(typeName, "posh_u64_t"))
        return SWIG_AsVal_unsigned_SS_long_SS_long(obj, (posh_u64_t*)ptr);
    else
        return -1;
}
SWIGINTERN PyObject*
fromInterger(char *typeName, void* ptr)
{
    if (!strcmp(typeName, "char"))
        return SWIG_From_char(*(char*)ptr);
    else if (!strcmp(typeName, "short"))
        return SWIG_From_short(*(short*)ptr);
    else if (!strcmp(typeName, "int"))
        return SWIG_From_int(*(int*)ptr);
    else if (!strcmp(typeName, "posh_i64_t"))
        return SWIG_From_long_SS_long(*(posh_i64_t*)ptr);
    else if (!strcmp(typeName, "SOCKET"))
        return SWIG_From_unsigned_SS_long_SS_long(*(SOCKET*)ptr);
    else if (!strcmp(typeName, "unsigned char"))
        return SWIG_From_unsigned_SS_char(*(unsigned char*)ptr);
    else if (!strcmp(typeName, "unsigned short"))
        return SWIG_From_unsigned_SS_short(*(unsigned short*)ptr);
    else if (!strcmp(typeName, "unsigned int"))
        return SWIG_From_unsigned_SS_int(*(unsigned int*)ptr);
    else if (!strcmp(typeName, "posh_u64_t"))
        return SWIG_From_unsigned_SS_long_SS_long(*(posh_u64_t*)ptr);
    else
        return SWIG_Py_Void();
}
char fuck1(){return 0;}
unsigned char fuck2(){return 0;}
short fuck3(){return 0;}
unsigned short fuck4(){return 0;}
int fuck5(){return 0;}
unsigned int fuck6(){return 0;}
long long fuck7(){return 0;}
unsigned long long fuck8(){return 0;}

%}

%init %{
    TrchError = PyErr_NewException("_pytrch.TrchError", NULL, NULL);
    Py_INCREF(TrchError);
    PyModule_AddObject(m, "TrchError", TrchError);
%}

%pythoncode %{
    TrchError = _pytrch.TrchError
%}

// should free MarshalledValue
%typemap(out) MarshalledValue {
    $result = SWIG_FromCharPtr((const char *)$1);
    freeMarshalledValue($1);
}

// check self NULL
%define CHECK_SELF(typeName)
%typemap(check) (typeName self) {
  if (!$1) {
        SWIG_Python_SetErrorMsg(TrchError, "self cannot be NULL");
        SWIG_fail;
    }
}
%enddef
CHECK_SELF(Config)
CHECK_SELF(Paramchoice)
CHECK_SELF(Parameter)
CHECK_SELF(Paramgroup)
// CHECK_SELF(Params)

// out type
%define OUT_TYPE(typeName)
%typemap(argout) typeName *outPtr {
    Py_DECREF($result);
    if (result < 0)
    {
        SWIG_Python_SetErrorMsg(TrchError, "function failed");
        SWIG_fail;
    }
    $result = fromInterger(#typeName, $1);
}

%typemap(in, numinputs=0) (typeName *outPtr)(typeName temp) {
    $1 = &temp;
}
%enddef
OUT_TYPE(char)
OUT_TYPE(short)
OUT_TYPE(int)
OUT_TYPE(posh_i64_t)
OUT_TYPE(SOCKET)
OUT_TYPE(unsigned char)
OUT_TYPE(unsigned short)
OUT_TYPE(unsigned int)
OUT_TYPE(posh_u64_t)

// in list type
%define IN_LIST_TYPE(typeName)
%typemap(in) (size_t inSize, typeName *inPtr) {
    if (!PyList_Check($input)) {
        SWIG_exception_fail(SWIG_TypeError, "Not a list");
    }
    $1 = PyList_Size($input);
    $2 = (typeName *) malloc(($1)*sizeof(typeName));
    for (size_t i = 0; i < $1; i++) {
        PyObject *item = PyList_GetItem($input,i);
        if (!SWIG_IsOK(toInterger(#typeName, item, $2 + i))) {
            SWIG_exception_fail(SWIG_TypeError, "invalid list contents");
        }
    }
}
%typemap(freearg) (size_t inSize, typeName *inPtr) {
   if ($2) free($2);
}
%enddef
IN_LIST_TYPE(char)
IN_LIST_TYPE(short)
IN_LIST_TYPE(int)
IN_LIST_TYPE(posh_i64_t)
IN_LIST_TYPE(SOCKET)
IN_LIST_TYPE(unsigned char)
IN_LIST_TYPE(unsigned short)
IN_LIST_TYPE(unsigned int)
IN_LIST_TYPE(posh_u64_t)

// out list type
%define OUT_LIST_TYPE(typeName)
%typemap(argout) (size_t *outSize, typeName **outPtr) {
    Py_DECREF($result);
    if (result < 0 || ($result = PyList_New(0)) == 0)
    {
        SWIG_Python_SetErrorMsg(TrchError, "function failed");
        SWIG_fail;
    }
    if (*$1 > 0)
    {
        for (size_t i = 0; i < *$1; ++i) 
        {
            PyList_Append($result, fromInterger(#typeName, (*$2) + i ));
        }
    }
}

%typemap(in, numinputs=0) (size_t *outSize, typeName **outPtr)(size_t temp1, typeName *temp2) {
    $1 = &temp1;
    $2 = &temp2;
}
%enddef
OUT_LIST_TYPE(char)
OUT_LIST_TYPE(short)
OUT_LIST_TYPE(int)
OUT_LIST_TYPE(posh_i64_t)
OUT_LIST_TYPE(SOCKET)
OUT_LIST_TYPE(unsigned char)
OUT_LIST_TYPE(unsigned short)
OUT_LIST_TYPE(unsigned int)
OUT_LIST_TYPE(posh_u64_t)

// in u string list
%typemap(in) (size_t inSize, unsigned char **inPtr, size_t *inPtrSize) {
    if (!PyList_Check($input)) {
        SWIG_exception_fail(SWIG_TypeError, "Not a list");
    }
    $1 = PyList_Size($input);
    $2 = (unsigned char **) malloc(($1)*sizeof(unsigned char*));
    $3 = (size_t *) malloc(($1)*sizeof(size_t));
    for (size_t i = 0; i < $1; i++) {
        PyObject *item = PyList_GetItem($input,i);
        if (!SWIG_IsOK(SWIG_AsCharPtrAndSize(item, (char**)&$2[i], &$3[i], NULL))) {
            SWIG_exception_fail(SWIG_TypeError, "list must contain strings");
        }
    }
}

%typemap(freearg) (size_t inSize, unsigned char **inPtr, size_t *inPtrSize) {
   if ($2) free($2);
   if ($3) free($3);
}

// out u string list
%typemap(argout) (size_t *outSize, unsigned char ***outPtr, size_t **outPtrSize) {
    Py_DECREF($result);
    if (result < 0 || ($result = PyList_New(0)) == 0)
    {
        SWIG_Python_SetErrorMsg(TrchError, "function failed");
        SWIG_fail;
    }
    if (*$1 > 0)
    {
        for (size_t i = 0; i < *$1; ++i) 
        {
            PyList_Append($result, SWIG_FromCharPtrAndSize((*$2)[i], (*$3)[i]));
        }
    }
}

%typemap(in, numinputs=0) (size_t *outSize, unsigned char ***outPtr, size_t **outPtrSize)(size_t temp1, unsigned char **temp2, size_t *temp3) {
    $1 = &temp1;
    $2 = &temp2;
    $3 = &temp3;
}


// int u string
%typemap(in) (unsigned char *inPtr, size_t inPtrSize) {
    if (!SWIG_IsOK(SWIG_AsCharPtrAndSize($input, (char**)&$1, &$2, NULL))) {
        SWIG_exception_fail(SWIG_TypeError, "argument " "1"" of type '" "unsigned char *""'");
    }
}


// out u string
%typemap(argout) (unsigned char **outPtr, size_t *outPtrSize) {
    Py_DECREF($result);
    if (result < 0)
    {
        SWIG_Python_SetErrorMsg(TrchError, "function failed");
        SWIG_fail;
    }
    if ( *$1 && *$2)
        $result = SWIG_FromCharPtrAndSize((const char *)*$1, *$2);
    else
        $result = SWIG_Py_Void();
}

%typemap(in, numinputs=0) (unsigned char **outPtr, size_t *outPtrSize)(unsigned char *temp1, size_t temp2) {
    $1 = &temp1;
    $2 = &temp2;
}

// in Params
// use default
// out Params
%typemap(argout) Params *outParams {
    Py_DECREF($result);
    if ( *$1 )
        $result =  SWIG_NewPointerObj(SWIG_as_voidptr(*$1), SWIGTYPE_p_Params_struct, 0);
    else
        $result = SWIG_Py_Void(); 
}

%typemap(in, numinputs=0) (Params *outParams)(Params temp) {
    $1 = &temp;
}

// in string (char *)
// use default
// out string (char*)
%typemap(argout) char **outCharPtr {
    Py_DECREF($result);
    if (result < 0)
    {
        SWIG_Python_SetErrorMsg(TrchError, "function failed");
        SWIG_fail;
    }
    if ( *$1 )
        $result = SWIG_FromCharPtr((const char *)*$1);
    else
        $result = SWIG_Py_Void();
}

%typemap(in, numinputs=0) (char **outCharPtr)(char *temp) {
    $1 = &temp;
}

// in string list
%typemap(in) (size_t inSize, char **inPtr) {
    if (!PyList_Check($input))
    {
        SWIG_exception_fail(SWIG_TypeError, "Not a list");
    }
    $1 = PyList_Size($input);
    $2 = (char **) malloc(($1)*sizeof(char*));
    for (size_t i = 0; i < $1; i++) {
        PyObject *item = PyList_GetItem($input,i);
        if (!SWIG_IsOK(SWIG_AsCharPtrAndSize(item, &$2[i], NULL, NULL))) {
            SWIG_exception_fail(SWIG_TypeError, "list must contain strings");
        }
    }
}

%typemap(freearg) (size_t inSize, char **inPtr) {
   if ($2) free($2);
}


// out string list
%typemap(argout) (size_t *outSize, char ***outPtr) {
    Py_DECREF($result);
    if (result < 0 || ($result = PyList_New(0)) == 0)
    {
        SWIG_Python_SetErrorMsg(TrchError, "function failed");
        SWIG_fail;
    }
    if (*$1 > 0)
    {
        for (size_t i = 0; i < *$1; ++i) 
        {
            PyList_Append($result, SWIG_FromCharPtr((*$2)[i]));
        }
    }
}

%typemap(in, numinputs=0) (size_t *outSize, char ***outPtr)(size_t temp1, char **temp2) {
    $1 = &temp1;
    $2 = &temp2;
}



%include "trch-1.h"
