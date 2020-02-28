#include <stdint.h>
#include <stdbool.h>
// typedef uint64_t _QWORD;
// typedef uint32_t _DWORD;
// typedef uint16_t _WORD;
// typedef uint8_t _BYTE;
// typedef uint8_t _BOOL8;
typedef struct Config_struct* Config;
typedef struct Params_struct* Params;
typedef struct Paramchoice_struct* Paramchoice;
typedef struct Paramgroup_struct* Paramgroup;
typedef struct Parameter_struct* Parameter;



typedef char* MarshalledValue;
typedef long long posh_i64_t;
typedef unsigned long long posh_u64_t;
// x64
#ifdef _WIN64
typedef unsigned long long SOCKET;
#else
typedef unsigned int SOCKET;
#endif

MarshalledValue Boolean_List_marshal(size_t inSize, int *inPtr); // ok
MarshalledValue Boolean_marshal(int); // ok
char *Boolean_type(); // ok
MarshalledValue Buffer_List_marshal(size_t inSize, unsigned char **inPtr, size_t *inPtrSize); // ok
MarshalledValue Buffer_marshal(unsigned char *inPtr, size_t inPtrSize); // ok
char *Buffer_type(); // ok
Config Config_create(char *, char *, char *, char *, char *, char *); // ok
void Config_delete(Config self); // ok
Config Config_duplicate(Config self); // ok
char* Config_getConfigVersion(Config self); // ok
int Config_getConstants(Config self, Params *); // wait test
char *Config_getID(Config self); // ok
int Config_getInputParams(Config self, Params *outParams); // ok
char *Config_getName(Config self); // ok
char* Config_getNamespaceUri(Config self); // ok
signed int Config_getOutputParams(Config self, Params *outParams); // ok
char* Config_getSchemaVersion(Config self); // ok
char* Config_getVersion(Config self); // ok
MarshalledValue Config_marshal(Config self, char *, char *); // ok
void Config_printUsage(Config self, char*, TcLogger, int); // wait test
int Config_setConstants(Config self, Params); // wait test
int Config_setInputParams(Config self, Params); // wait test
int Config_setOutputParams(Config self, Params); // wait test
Config Config_unmarshal(char *str); // ok
void FinalizeXMLUnmarshal(); // ok
MarshalledValue IPv4_List_marshal(size_t inSize, char **inPtr); // ok
MarshalledValue IPv4_marshal(char *); // ok
char *IPv4_type(); // ok
MarshalledValue IPv6_List_marshal(size_t inSize, char **inPtr); // ok
MarshalledValue IPv6_marshal(char *); // ok
char *IPv6_type(); // ok
void InitializeXMLUnmarshal(); // ok
char *List_format(); // ok
MarshalledValue LocalFile_List_marshal(size_t inSize, char **inPtr); // ok
MarshalledValue LocalFile_marshal(char *); // ok
char *LocalFile_type(); // ok
int Paramchoice_addParamgroup(Paramchoice self, Paramgroup); // wait test
Paramchoice Paramchoice_create(char *, char *, char *, char *, char*); // wait test
void Paramchoice_delete(Paramchoice self); // wait test
int Paramchoice_getDefaultValue(Paramchoice self, char **outCharPtr); // wait test
int Paramchoice_getDescription(Paramchoice self, char **outCharPtr); // wait test
int Paramchoice_getName(Paramchoice self, char **outCharPtr); // wait test
unsigned int Paramchoice_getNumParamgroups(Paramchoice self); // wait test
Paramgroup Paramchoice_getParamgroup(Paramchoice self, size_t); // wait test
char* Paramchoice_getValue(Paramchoice self, char **outCharPtr); // wait test
int Paramchoice_hasValidValue(Paramchoice self); // wait test
int Paramchoice_hasValue(Paramchoice self); // wait test
int Paramchoice_isValid(Paramchoice self);// wait test
int Paramchoice_matchName(Paramchoice self, char*); // wait test
int Paramchoice_setValue(Paramchoice self, char*); // wait test


Parameter Parameter_Boolean_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_Boolean_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_Boolean_List_getValue(Parameter self, size_t *outSize, int **outPtr); // wait test
int Parameter_Boolean_List_setValue(Parameter self, size_t inSize, int *inPtr); // wait test
Parameter Parameter_Boolean_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_Boolean_getValue(Parameter self, int *outPtr); // wait test
int Parameter_Boolean_setValue(Parameter self, int); // wait test


Parameter Parameter_Buffer_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_Buffer_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_Buffer_List_getValue(Parameter self, size_t *outSize, unsigned char ***outPtr, size_t **outPtrSize); // wait test
int Parameter_Buffer_List_setValue(Parameter self, size_t inSize, unsigned char **inPtr, size_t *inPtrSize); // wait test
Parameter Parameter_Buffer_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_Buffer_getValue(Parameter self, unsigned char **outPtr, size_t *outPtrSize); // wait test
int Parameter_Buffer_setValue(Parameter self, unsigned char *inPtr, size_t inPtrSize); // wait test


Parameter Parameter_IPv4_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_IPv4_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_IPv4_List_getValue(Parameter self, size_t *outSize, char ***outPtr); // wait test
int Parameter_IPv4_List_setValue(Parameter self, size_t inSize, char **inPtr); // wait test
Parameter Parameter_IPv4_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_IPv4_getValue(Parameter self, char **outCharPtr); // wait test
int Parameter_IPv4_setValue(Parameter self, char *); // wait test


Parameter Parameter_IPv6_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_IPv6_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_IPv6_List_getValue(Parameter self, size_t *outSize, char ***outPtr); // wait test
int Parameter_IPv6_List_setValue(Parameter self, size_t inSize, char **inPtr); // wait test
Parameter Parameter_IPv6_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_IPv6_getValue(Parameter self, char **outCharPtr); // wait test
int Parameter_IPv6_setValue(Parameter self, char *); // wait test


Parameter Parameter_LocalFile_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_LocalFile_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_LocalFile_List_getValue(Parameter self, size_t *outSize, char ***outPtr); // wait test
int Parameter_LocalFile_List_setValue(Parameter self, size_t inSize, char **inPtr); // wait test
Parameter Parameter_LocalFile_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_LocalFile_getValue(Parameter self, char **outCharPtr); // wait test
int Parameter_LocalFile_setValue(Parameter self, char *); // wait test


int Parameter_Port_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_Port_List_getValue(Parameter self, size_t *outSize, unsigned short **outPtr); // wait test
int Parameter_Port_List_setValue(Parameter self, size_t inSize, unsigned short *inPtr); // wait test
int Parameter_Port_getValue(Parameter self, unsigned short *outPtr); // wait test
int Parameter_Port_setValue(Parameter self, unsigned short); // wait test


Parameter Parameter_S16_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_S16_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_S16_List_getValue(Parameter self, size_t *outSize, short **outPtr); // wait test
int Parameter_S16_List_setValue(Parameter self, size_t inSize, short *inPtr); // wait test
Parameter Parameter_S16_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_S16_getValue(Parameter self, short *outPtr); // wait test
int Parameter_S16_setValue(Parameter self, short); // wait test


Parameter Parameter_S32_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_S32_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_S32_List_getValue(Parameter self, size_t *outSize, int **outPtr); // wait test
int Parameter_S32_List_setValue(Parameter self, size_t inSize, int *inPtr); // wait test
Parameter Parameter_S32_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_S32_getValue(Parameter self, int *outPtr); // wait test
int Parameter_S32_setValue(Parameter self, int); // wait test


Parameter Parameter_S64_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_S64_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_S64_List_getValue(Parameter self, size_t *outSize, posh_i64_t **outPtr); // wait test
int Parameter_S64_List_setValue(Parameter self, size_t inSize, posh_i64_t *inPtr); // wait test
Parameter Parameter_S64_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_S64_getValue(Parameter self, posh_i64_t *outPtr); // wait test
int Parameter_S64_setValue(Parameter self, posh_i64_t); // wait test


Parameter Parameter_S8_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_S8_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_S8_List_getValue(Parameter self, size_t *outSize, char **outPtr); // wait test
int Parameter_S8_List_setValue(Parameter self, size_t inSize, char *inPtr); // wait test
Parameter Parameter_S8_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_S8_getValue(Parameter self, char *outPtr); // wait test
int Parameter_S8_setValue(Parameter self, char); // wait test

Parameter Parameter_Socket_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_Socket_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_Socket_List_getValue(Parameter self, size_t *outSize, SOCKET **outPtr); // wait test
int Parameter_Socket_List_setValue(Parameter self, size_t inSize, SOCKET *inPtr); // wait test
Parameter Parameter_Socket_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_Socket_getValue(Parameter self, SOCKET *outPtr); // wait test
int Parameter_Socket_setValue(Parameter self, SOCKET); // wait test


Parameter Parameter_String_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_String_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_String_List_getValue(Parameter self, size_t *outSize, char ***outPtr); // wait test
int Parameter_String_List_setValue(Parameter self, size_t inSize, char **inPtr); // wait test
Parameter Parameter_String_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_String_getValue(Parameter self, char **outCharPtr); // wait test
int Parameter_String_setValue(Parameter self, char *); // wait test


Parameter Parameter_TcpPort_List_create(char *, char *, int, char *, char *, char*); // wait test
Parameter Parameter_TcpPort_create(char *, char *, int, char *, char *, char*); // wait test


Parameter Parameter_U16_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_U16_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_U16_List_getValue(Parameter self, size_t *outSize, unsigned short **outPtr); // wait test
int Parameter_U16_List_setValue(Parameter self, size_t inSize, unsigned short *inPtr); // wait test
Parameter Parameter_U16_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_U16_getValue(Parameter self, unsigned short *outPtr); // wait test
int Parameter_U16_setValue(Parameter self, unsigned short); // wait test


Parameter Parameter_U32_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_U32_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_U32_List_getValue(Parameter self, size_t *outSize, unsigned int **outPtr); // wait test
int Parameter_U32_List_setValue(Parameter self, size_t inSize, unsigned int *inPtr); // wait test
Parameter Parameter_U32_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_U32_getValue(Parameter self, unsigned int *outPtr); // wait test
int Parameter_U32_setValue(Parameter self, unsigned int); // wait test


Parameter Parameter_U64_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_U64_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_U64_List_getValue(Parameter self, size_t *outSize, posh_u64_t **outPtr); // wait test
int Parameter_U64_List_setValue(Parameter self, size_t inSize, posh_u64_t *inPtr); // wait test
Parameter Parameter_U64_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_U64_getValue(Parameter self, posh_u64_t *outPtr); // wait test
int Parameter_U64_setValue(Parameter self, posh_u64_t); // wait test


Parameter Parameter_U8_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_U8_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_U8_List_getValue(Parameter self, size_t *outSize, unsigned char **outPtr); // wait test
int Parameter_U8_List_setValue(Parameter self, size_t inSize, unsigned char *inPtr); // wait test
Parameter Parameter_U8_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_U8_getValue(Parameter self, unsigned char *outPtr); // wait test
int Parameter_U8_setValue(Parameter self, unsigned char); // wait test


Parameter Parameter_UString_List_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_UString_List_getSize(Parameter self, posh_u64_t *outPtr); // maybe error
int Parameter_UString_List_getValue(Parameter self, size_t *outSize, unsigned char ***outPtr, size_t **outPtrSize); // wait test
int Parameter_UString_List_setValue(Parameter self, size_t inSize, unsigned char **inPtr, size_t *inPtrSize); // wait test
Parameter Parameter_UString_create(char *, char *, int, char *, char *, char*); // wait test
int Parameter_UString_getValue(Parameter self, unsigned char **outPtr, size_t *outPtrSize); // wait test
int Parameter_UString_setValue(Parameter self, unsigned char *inPtr, size_t inPtrSize); // wait test


Parameter Parameter_UdpPort_List_create(char *, char *, int, char *, char *, char*); // wait test
Parameter Parameter_UdpPort_create(char *, char *, int, char *, char *, char*); // wait test


void Parameter_delete(Parameter self); // ok
int Parameter_getDescription(Parameter self, char **outCharPtr); // wait test
int Parameter_getFormat(Parameter self, char **outCharPtr); // wait test
int Parameter_getInvalidReason(Parameter self, char **); // wait test
int Parameter_getMarshalledDefault(Parameter self, char **outCharPtr); // wait test
int Parameter_getMarshalledValue(Parameter self, char **outCharPtr); // maybe error
int Parameter_getName(Parameter self, char **outCharPtr); // wait test
int Parameter_getType(Parameter self, char **outCharPtr); // wait test
int Parameter_hasValidValue(Parameter self); // wait test
int Parameter_hasValue(Parameter self); // wait test
void Parameter_hide(Parameter self); // wait test
int Parameter_isHidden(Parameter self); // wait test
int Parameter_isRequired(Parameter self); // wait test
int Parameter_isValid(Parameter self); // wait test
void Parameter_markInvalid(Parameter self); // wait test
void Parameter_markInvalidWithReason(Parameter self, char *); // wait test
int Parameter_matchFormat(Parameter self, char *); // wait test
int Parameter_matchFormatAndType(Parameter self, char *, char *); // wait test
int Parameter_matchName(Parameter self, char *); // wait test
int Parameter_matchType(Parameter self, char *); // wait test
int Parameter_resetValue(Parameter self); // wait test
int Parameter_setMarshalledValue(Parameter self, char *); // wait test
int Paramgroup_addParamchoice(Paramgroup self, Paramchoice); // wait test
int Paramgroup_addParameter(Paramgroup self, Parameter); // wait test
Paramgroup Paramgroup_create(char *, char *, char *, char *); // wait test
void Paramgroup_delete(Paramgroup self); // wait test
int Paramgroup_getDescription(Paramgroup self, char **outCharPtr); // wait test
int Paramgroup_getName(Paramgroup self, char **outCharPtr); // wait test
unsigned int Paramgroup_getNumParamchoices(Paramgroup self); // wait test
unsigned int Paramgroup_getNumParameters(Paramgroup self); // wait test
Paramchoice Paramgroup_getParamchoice(Paramgroup self, size_t); // wait test
Parameter Paramgroup_getParameter(Paramgroup self, size_t); // wait test
int Paramgroup_isValid(Paramgroup self); // wait test
int Paramgroup_matchName(Paramgroup self, char *); // wait test
int Paramgroup_removeParameter(Paramgroup self, Parameter); // wait test
int Params_addParamchoice(Params self, Paramchoice); // wait test
int Params_addParameter(Params self, Parameter); // wait test
Params Params_create(char *, char *, char *); // wait test
void Params_delete(Params self); // wait test
Params Params_duplicate(Params self); // wait test
Paramchoice Params_findParamchoice(Params self, char*); // wait test
Parameter Params_findParameter(Params self, char*); // wait test
int Params_getCallbackIPv4Values(Params self, char *, char *, char **, char **); // wait test
int Params_getCallbackIPv6Values(Params self, char *, char *, char **, char **); // wait test
int Params_getCallbackPortValues(Params self, char *, char *, unsigned short *, unsigned short *); // wait test
int Params_getName(Params self, char **outCharPtr); // ok
unsigned int Params_getNumParamchoices(Params self); // wait test
unsigned int Params_getNumParameters(Params self); // wait test
Paramchoice Params_getParamchoice(Params self, size_t); // wait test
Parameter Params_getParameter(Params self, size_t); // wait test
int Params_isValid(Params self); // wait test
int Params_parseCommandLine(Params self, int, char **, int *); // wait test
void Params_printInvalid(Params self, TcLogger); // wait test
void Params_removeParameter(Params self, Parameter); // wait test
int Params_validateCallbackPorts(Params self, char *, char *); // wait test
MarshalledValue Port_List_marshal(size_t inSize, unsigned short *inPtr); // ok
MarshalledValue Port_marshal(unsigned short); // ok
MarshalledValue S16_List_marshal(size_t inSize, short *inPtr); // ok
MarshalledValue S16_marshal(short); // ok
char *S16_type(); // ok
MarshalledValue S32_List_marshal(size_t inSize, int *inPtr); // ok
MarshalledValue S32_marshal(int); // ok
char *S32_type();// ok
MarshalledValue S64_List_marshal(size_t inSize, posh_i64_t *inPtr);
MarshalledValue S64_marshal(posh_i64_t); // ok
char *S64_type();// ok
MarshalledValue S8_List_marshal(size_t inSize, char *inPtr); // ok
MarshalledValue S8_marshal(char); // ok
char *S8_type(); // ok
char *Scalar_format(); // ok
MarshalledValue Socket_List_marshal(size_t inSize, SOCKET *inPtr); // ok
MarshalledValue Socket_marshal(SOCKET); // ok
char *Socket_type(); // ok
MarshalledValue String_List_marshal(size_t inSize, char **inPtr); // ok
MarshalledValue String_marshal(char *); // ok
char *String_type(); // ok
char *TcpPort_type(); // ok
MarshalledValue U16_List_marshal(size_t inSize, unsigned short *inPtr); // ok
MarshalledValue U16_marshal(unsigned short); // ok
char *U16_type(); // ok
MarshalledValue U32_List_marshal(size_t inSize, unsigned int *inPtr); // ok
MarshalledValue U32_marshal(unsigned int); // ok
char *U32_type(); // ok
MarshalledValue U64_List_marshal(size_t inSize, posh_u64_t *inPtr); // ok
MarshalledValue U64_marshal(posh_u64_t); // ok
char *U64_type(); // ok
MarshalledValue U8_List_marshal(size_t inSize, unsigned char *inptr); // ok
MarshalledValue U8_marshal(unsigned char); // ok
char *U8_type(); // ok
MarshalledValue UString_List_marshal(size_t inSize, unsigned char **inPtr, size_t *inPtrSize); // ok
MarshalledValue UString_marshal(unsigned char *inPtr, size_t inPtrSize); // ok
char *UString_type(); // ok
char *UdpPort_type(); // ok
void freeMarshalledValue(MarshalledValue); // ok
char fuck1();
unsigned char fuck2();
short fuck3();
unsigned short fuck4();
int fuck5();
unsigned int fuck6();
long long fuck7();
unsigned long long fuck8();
