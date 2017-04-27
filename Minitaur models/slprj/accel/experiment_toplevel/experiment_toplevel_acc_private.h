#include "__cf_experiment_toplevel.h"
#ifndef RTW_HEADER_experiment_toplevel_acc_private_h_
#define RTW_HEADER_experiment_toplevel_acc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "experiment_toplevel_acc.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
extern void rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( const real_T u0 [ 9 ] , const
real_T u1 [ 3 ] , real_T y [ 3 ] ) ; extern real_T look1_binlxpw ( real_T u0
, const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) ; void
d0eofad4fk ( hlfsonbzsi * localB , myg1st0tfa * localP ) ; void gwv3tbs0q4 (
SimStruct * const S ) ; void cgmwjmky2g ( hlfsonbzsi * localB , myg1st0tfa *
localP , ow3ethn5h3 * localZCSV ) ; void evsykqyxrn ( SimStruct * const S ) ;
void nrfrkljgb4 ( SimStruct * const S , real_T chxostfn3v , real_T epia03xohm
, real_T bvmrffpfg4 , real_T adkmtoocbb , const real_T eqqp1dxh4a [ 9 ] ,
real_T ntta2xxji3 , real_T irkyxhxp3z , real_T fnb4qdzo5g , real_T dyqnbc15wz
, real_T jzlwdgmswb [ 3 ] , real_T ky31l4kzsq [ 3 ] , real_T mrs4nhqz2s [ 3 ]
, real_T * i2du5vl0nm , real_T * jzryxoczpg , real_T * mcgmnfscww ,
hlfsonbzsi * localB , hshpypz4ol * localDW , myg1st0tfa * localP ) ; void
nrfrkljgb4TID2 ( hlfsonbzsi * localB , myg1st0tfa * localP ) ;
#endif
