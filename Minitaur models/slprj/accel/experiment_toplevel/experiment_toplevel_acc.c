#include "__cf_experiment_toplevel.h"
#include <math.h>
#include "experiment_toplevel_acc.h"
#include "experiment_toplevel_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
real_T look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table
[ ] , uint32_T maxIndex ) { real_T frac ; uint32_T iRght ; uint32_T iLeft ;
uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [
0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) {
bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght -
iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft =
bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) /
( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ;
frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex -
1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] ) * frac + table [
iLeft ] ; } void rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( const real_T u0 [ 9 ] ,
const real_T u1 [ 3 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ; int32_T r1 ;
int32_T r2 ; int32_T r3 ; real_T maxval ; real_T a21 ; int32_T rtemp ; memcpy
( & A [ 0 ] , & u0 [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 1 ; r2 = 2 ; r3 =
3 ; maxval = muDoubleScalarAbs ( u0 [ 0 ] ) ; a21 = muDoubleScalarAbs ( u0 [
1 ] ) ; if ( a21 > maxval ) { maxval = a21 ; r1 = 2 ; r2 = 1 ; } if (
muDoubleScalarAbs ( u0 [ 2 ] ) > maxval ) { r1 = 3 ; r2 = 2 ; r3 = 1 ; } A [
r2 - 1 ] = u0 [ r2 - 1 ] / u0 [ r1 - 1 ] ; A [ r3 - 1 ] /= A [ r1 - 1 ] ; A [
r2 + 2 ] -= A [ r2 - 1 ] * A [ r1 + 2 ] ; A [ r3 + 2 ] -= A [ r3 - 1 ] * A [
r1 + 2 ] ; A [ r2 + 5 ] -= A [ r2 - 1 ] * A [ r1 + 5 ] ; A [ r3 + 5 ] -= A [
r3 - 1 ] * A [ r1 + 5 ] ; if ( muDoubleScalarAbs ( A [ r3 + 2 ] ) >
muDoubleScalarAbs ( A [ r2 + 2 ] ) ) { rtemp = r2 ; r2 = r3 ; r3 = rtemp ; }
A [ r3 + 2 ] /= A [ r2 + 2 ] ; A [ r3 + 5 ] -= A [ r3 + 2 ] * A [ r2 + 5 ] ;
maxval = u1 [ r2 - 1 ] - u1 [ r1 - 1 ] * A [ r2 - 1 ] ; a21 = ( ( u1 [ r3 - 1
] - u1 [ r1 - 1 ] * A [ r3 - 1 ] ) - A [ r3 + 2 ] * maxval ) / A [ r3 + 5 ] ;
maxval -= A [ r2 + 5 ] * a21 ; maxval /= A [ r2 + 2 ] ; y [ 0 ] = ( ( u1 [ r1
- 1 ] - A [ r1 + 5 ] * a21 ) - A [ r1 + 2 ] * maxval ) / A [ r1 - 1 ] ; y [ 1
] = maxval ; y [ 2 ] = a21 ; } void d0eofad4fk ( hlfsonbzsi * localB ,
myg1st0tfa * localP ) { localB -> lbahd1zvro = localP -> P_0 ; localB ->
a1uff23gp2 = localP -> P_0 ; localB -> biw0uvoced = localP -> P_0 ; localB ->
hum5y5u3fc = localP -> P_0 ; localB -> oa2veixczc = localP -> P_0 ; localB ->
fevfwm0ave [ 0 ] = localP -> P_0 ; localB -> fevfwm0ave [ 1 ] = localP -> P_0
; localB -> fevfwm0ave [ 2 ] = localP -> P_0 ; } void gwv3tbs0q4 ( SimStruct
* const S ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } } void evsykqyxrn ( SimStruct * const S ) {
ssSetSolverNeedsReset ( S ) ; } void cgmwjmky2g ( hlfsonbzsi * localB ,
myg1st0tfa * localP , ow3ethn5h3 * localZCSV ) { localZCSV -> gqijqi0as0 =
localB -> dvtdaeeego - localP -> P_2 ; localZCSV -> pgawnr5bji = localB ->
dvtdaeeego - localP -> P_3 ; } void nrfrkljgb4 ( SimStruct * const S , real_T
chxostfn3v , real_T epia03xohm , real_T bvmrffpfg4 , real_T adkmtoocbb ,
const real_T eqqp1dxh4a [ 9 ] , real_T ntta2xxji3 , real_T irkyxhxp3z ,
real_T fnb4qdzo5g , real_T dyqnbc15wz , real_T jzlwdgmswb [ 3 ] , real_T
ky31l4kzsq [ 3 ] , real_T mrs4nhqz2s [ 3 ] , real_T * i2du5vl0nm , real_T *
jzryxoczpg , real_T * mcgmnfscww , hlfsonbzsi * localB , hshpypz4ol * localDW
, myg1st0tfa * localP ) { real_T fdcr1puwgy ; real_T tmp [ 3 ] ; localB ->
h4xx3divl5 = muDoubleScalarAbs ( bvmrffpfg4 ) ; localB -> dvtdaeeego = localB
-> jpwsuldxpm - localB -> h4xx3divl5 ; if ( ssIsMajorTimeStep ( S ) ) { if (
localB -> dvtdaeeego > localP -> P_3 ) { localDW -> dvgrgfd4iz = 1 ; } else
if ( localB -> dvtdaeeego >= localP -> P_2 ) { localDW -> dvgrgfd4iz = 0 ; }
else { localDW -> dvgrgfd4iz = - 1 ; } } if ( localDW -> dvgrgfd4iz == 1 ) {
localB -> lbahd1zvro = localB -> dvtdaeeego - localP -> P_3 ; } else if (
localDW -> dvgrgfd4iz == - 1 ) { localB -> lbahd1zvro = localB -> dvtdaeeego
- localP -> P_2 ; } else { localB -> lbahd1zvro = 0.0 ; } localB ->
f1d5gr31em = muDoubleScalarSign ( bvmrffpfg4 ) ; localB -> htvudeaf4j =
localB -> f1d5gr31em * adkmtoocbb ; localB -> a1uff23gp2 = localP -> P_4 *
localB -> htvudeaf4j ; localB -> h3fxjwhngj = muDoubleScalarSign ( adkmtoocbb
) ; localB -> d3zqcbfhsg = localP -> P_6 * localB -> lbahd1zvro ; localB ->
biw0uvoced = localB -> f1d5gr31em * localB -> d3zqcbfhsg ; localB ->
kzwgwi4rbq = muDoubleScalarSign ( localB -> lbahd1zvro ) ; localB ->
lkxalcb02x = muDoubleScalarAbs ( localB -> kzwgwi4rbq ) ; if ( localB ->
a1uff23gp2 > localP -> P_7 ) { localB -> mm4u0rp1ek = localP -> P_7 ; } else
if ( localB -> a1uff23gp2 < localP -> P_8 ) { localB -> mm4u0rp1ek = localP
-> P_8 ; } else { localB -> mm4u0rp1ek = localB -> a1uff23gp2 ; } localB ->
eyos5wplhu = localP -> P_9 * localB -> mm4u0rp1ek ; localB -> g1lpwvslhe =
localB -> lkxalcb02x * localB -> eyos5wplhu ; localB -> hum5y5u3fc = localB
-> g1lpwvslhe * localB -> h3fxjwhngj ; localB -> oa2veixczc = localB ->
biw0uvoced + localB -> hum5y5u3fc ; localB -> j03iyamj2v [ 0 ] = localB ->
fi5hb5fnoo ; localB -> j03iyamj2v [ 1 ] = localB -> fi5hb5fnoo ; localB ->
j03iyamj2v [ 2 ] = localB -> oa2veixczc ; localB -> lktbawe2i4 [ 0 ] = localP
-> P_10 * localB -> j03iyamj2v [ 0 ] ; localB -> lktbawe2i4 [ 1 ] = localP ->
P_10 * localB -> j03iyamj2v [ 1 ] ; localB -> lktbawe2i4 [ 2 ] = localP ->
P_10 * localB -> j03iyamj2v [ 2 ] ; localB -> lylh0ueotr = ntta2xxji3 *
localB -> axnygjbm1i ; localB -> mxeqk2h4r0 = localB -> f1d5gr31em *
dyqnbc15wz ; localB -> pnbwlwvs1k = localB -> lylh0ueotr + localB ->
mxeqk2h4r0 ; localB -> jezudxuai2 = localB -> axnygjbm1i * irkyxhxp3z ;
localB -> l4ormgbvbu = fnb4qdzo5g * localB -> f1d5gr31em ; localB ->
iosma031z4 = localB -> l4ormgbvbu - localB -> jezudxuai2 ; localB ->
hbvmnzgs5o = localB -> pnbwlwvs1k * localB -> pnbwlwvs1k + localB ->
iosma031z4 * localB -> iosma031z4 ; if ( ssIsMajorTimeStep ( S ) ) { if (
localDW -> b23hhumil3 != 0 ) { ssSetSolverNeedsReset ( S ) ; localDW ->
b23hhumil3 = 0 ; } fdcr1puwgy = muDoubleScalarSqrt ( localB -> hbvmnzgs5o ) ;
} else { if ( localB -> hbvmnzgs5o < 0.0 ) { fdcr1puwgy = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( localB -> hbvmnzgs5o ) ) ; } else {
fdcr1puwgy = muDoubleScalarSqrt ( localB -> hbvmnzgs5o ) ; } if ( localB ->
hbvmnzgs5o < 0.0 ) { localDW -> b23hhumil3 = 1 ; } } fdcr1puwgy =
look1_binlxpw ( fdcr1puwgy , localP -> P_13 , localP -> P_12 , 5U ) ; localB
-> fju2mpcpjb = fdcr1puwgy * localB -> lktbawe2i4 [ 2 ] ; localB ->
cyhtdelmps = localP -> P_14 * localB -> fju2mpcpjb ; fdcr1puwgy =
muDoubleScalarAtan2 ( localB -> pnbwlwvs1k , localB -> iosma031z4 ) ; localB
-> bogyzjzz0k = localB -> cyhtdelmps * muDoubleScalarCos ( fdcr1puwgy ) ;
localB -> iqexhzc0fx = localB -> cyhtdelmps * muDoubleScalarSin ( fdcr1puwgy
) ; localB -> n3cj3cerja [ 0 ] = localB -> bogyzjzz0k ; localB -> n3cj3cerja
[ 1 ] = localB -> iqexhzc0fx ; localB -> n3cj3cerja [ 2 ] = localB ->
pecf2q3wr3 ; localB -> fevfwm0ave [ 0 ] = localP -> P_16 * localB ->
n3cj3cerja [ 0 ] ; localB -> mxsrdv1yjt [ 0 ] = localB -> lktbawe2i4 [ 0 ] +
localB -> fevfwm0ave [ 0 ] ; localB -> fevfwm0ave [ 1 ] = localP -> P_16 *
localB -> n3cj3cerja [ 1 ] ; localB -> mxsrdv1yjt [ 1 ] = localB ->
lktbawe2i4 [ 1 ] + localB -> fevfwm0ave [ 1 ] ; localB -> fevfwm0ave [ 2 ] =
localP -> P_16 * localB -> n3cj3cerja [ 2 ] ; localB -> mxsrdv1yjt [ 2 ] =
localB -> lktbawe2i4 [ 2 ] + localB -> fevfwm0ave [ 2 ] ; mrs4nhqz2s [ 0 ] =
localB -> mxsrdv1yjt [ 0 ] ; mrs4nhqz2s [ 1 ] = localB -> mxsrdv1yjt [ 1 ] ;
mrs4nhqz2s [ 2 ] = localB -> mxsrdv1yjt [ 2 ] ; localB -> f5drcezmua =
epia03xohm * localB -> mxsrdv1yjt [ 2 ] ; localB -> ctesau4egp = bvmrffpfg4 *
localB -> mxsrdv1yjt [ 1 ] ; localB -> jwgqklbaxp = bvmrffpfg4 * localB ->
mxsrdv1yjt [ 0 ] ; localB -> fcbdgcat3f = chxostfn3v * localB -> mxsrdv1yjt [
2 ] ; localB -> jxtppeynye = chxostfn3v * localB -> mxsrdv1yjt [ 1 ] ; localB
-> gzub3l1dbk = epia03xohm * localB -> mxsrdv1yjt [ 0 ] ; * i2du5vl0nm =
localB -> f5drcezmua - localB -> ctesau4egp ; * jzryxoczpg = localB ->
jwgqklbaxp - localB -> fcbdgcat3f ; * mcgmnfscww = localB -> jxtppeynye -
localB -> gzub3l1dbk ; localB -> byslff42wm [ 0 ] = localB -> peprhw2hww [ 0
] * localB -> f1d5gr31em ; localB -> byslff42wm [ 1 ] = localB -> peprhw2hww
[ 1 ] * localB -> f1d5gr31em ; localB -> byslff42wm [ 2 ] = localB ->
peprhw2hww [ 2 ] * localB -> f1d5gr31em ; localB -> in3jcdtztv = localB ->
byslff42wm [ 1 ] * localB -> pecf2q3wr3 ; localB -> lagvtdiabl = localB ->
byslff42wm [ 2 ] * localB -> iqexhzc0fx ; localB -> assu43dcua = localB ->
byslff42wm [ 2 ] * localB -> bogyzjzz0k ; localB -> fxz0y23c04 = localB ->
byslff42wm [ 0 ] * localB -> pecf2q3wr3 ; localB -> m1kul545a5 = localB ->
byslff42wm [ 0 ] * localB -> iqexhzc0fx ; localB -> d4w2zsz2zn = localB ->
byslff42wm [ 1 ] * localB -> bogyzjzz0k ; localB -> dozb1quqjp = localB ->
in3jcdtztv - localB -> lagvtdiabl ; localB -> bwu4mh2wve = localB ->
assu43dcua - localB -> fxz0y23c04 ; localB -> pk0ju2zi2g = localB ->
m1kul545a5 - localB -> d4w2zsz2zn ; rt_mldivide_U1d3x3_U2d3_Yd3x1_snf (
eqqp1dxh4a , localB -> n3cj3cerja , localB -> esoauhe4wd ) ; localB ->
aag2gs1ep5 [ 0 ] = localB -> dozb1quqjp ; localB -> aag2gs1ep5 [ 1 ] = localB
-> bwu4mh2wve ; localB -> aag2gs1ep5 [ 2 ] = localB -> pk0ju2zi2g ;
rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( eqqp1dxh4a , localB -> aag2gs1ep5 , tmp )
; ky31l4kzsq [ 0 ] = tmp [ 0 ] ; ky31l4kzsq [ 1 ] = tmp [ 1 ] ; ky31l4kzsq [
2 ] = tmp [ 2 ] ; rt_mldivide_U1d3x3_U2d3_Yd3x1_snf ( eqqp1dxh4a , localB ->
j03iyamj2v , localB -> n5qfg5t1l3 ) ; jzlwdgmswb [ 0 ] = localB -> n5qfg5t1l3
[ 0 ] + localB -> esoauhe4wd [ 0 ] ; jzlwdgmswb [ 1 ] = localB -> n5qfg5t1l3
[ 1 ] + localB -> esoauhe4wd [ 1 ] ; jzlwdgmswb [ 2 ] = localB -> n5qfg5t1l3
[ 2 ] + localB -> esoauhe4wd [ 2 ] ; } void nrfrkljgb4TID2 ( hlfsonbzsi *
localB , myg1st0tfa * localP ) { localB -> jpwsuldxpm = localP -> P_1 ;
localB -> fi5hb5fnoo = localP -> P_5 ; localB -> axnygjbm1i = localP -> P_11
; localB -> pecf2q3wr3 = localP -> P_15 ; localB -> peprhw2hww [ 0 ] = localP
-> P_17 [ 0 ] ; localB -> peprhw2hww [ 1 ] = localP -> P_17 [ 1 ] ; localB ->
peprhw2hww [ 2 ] = localP -> P_17 [ 2 ] ; } void cqs2zicbj4 ( SimStruct *
const S ) { } static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T
jvs5i4w5ye ; real_T iw24a5fhro [ 4 ] ; real_T amuqdujtnk ; real_T grepr3faim
; real_T mpgvgtjuc3 ; real_T dzju20iykt ; real_T asuc3ovo0p ; real_T
geamegmthb ; real_T ojmyu3yj4i ; real_T eqsip0abas ; real_T hkapiozpds ;
real_T ecuu4mmu22 ; real_T ega5zbm5sp ; real_T bdnicddmcs ; real_T ixvimtbepc
; real_T hesuxowbif ; real_T pfdhed5jbr ; real_T ljolgva0g0 ; int8_T
rtPrevAction ; int8_T rtAction ; boolean_T bhdoohci1d ; int8_T fytpxckdu1 ;
boolean_T k1j10hrmp1 ; int8_T aj0oydudzg ; boolean_T h5ywwldble ; int8_T
nxwxeu4gdx ; boolean_T aqyocmx4fn ; int8_T bmj2qwivwl ; boolean_T prctt2ewb5
; int8_T fx1shjs25a ; boolean_T em3luynxhv ; int8_T oit4ht2aqi ; boolean_T
atxky2vcsj ; int8_T j4cvrxmjnb ; boolean_T aar4d3t5v3 ; int8_T c2ifbtm5rr ;
int32_T tmp ; gjw3c2hq0n * _rtB ; pn00hmq1oq * _rtP ; fzug05v1yn * _rtX ;
ey1cddduxp * _rtDW ; _rtDW = ( ( ey1cddduxp * ) ssGetRootDWork ( S ) ) ; _rtX
= ( ( fzug05v1yn * ) ssGetContStates ( S ) ) ; _rtP = ( ( pn00hmq1oq * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( gjw3c2hq0n * ) _ssGetModelBlockIO ( S ) )
; jvs5i4w5ye = ssGetT ( S ) ; _rtB -> ofqzqqa0se [ 0 ] = _rtB -> jtidsw4hp3 [
0 ] + jvs5i4w5ye ; _rtB -> eylpkrhcz5 [ 0 ] = muDoubleScalarMod ( _rtB ->
ofqzqqa0se [ 0 ] , _rtB -> pvre3w420d ) / _rtB -> pvre3w420d ; _rtB ->
iwrclgpyo1 [ 0 ] = _rtP -> P_11 * _rtB -> eylpkrhcz5 [ 0 ] ; _rtB ->
ii2qqwpe3c [ 0 ] = _rtP -> P_12 * muDoubleScalarSin ( _rtB -> iwrclgpyo1 [ 0
] ) ; _rtB -> o1q4woo5f2 [ 0 ] = _rtB -> ii2qqwpe3c [ 0 ] * _rtB ->
efldjtmkbv ; _rtB -> iwm5tf2dwe [ 0 ] = muDoubleScalarCos ( _rtB ->
iwrclgpyo1 [ 0 ] ) * _rtB -> fjfnwwgrbe ; _rtB -> lzhl3d50ah [ 0 ] = _rtB ->
iwm5tf2dwe [ 0 ] + _rtB -> fmygpllf40 ; _rtB -> jhnjspziwz [ 0 ] = _rtB ->
kur2lpov1n - muDoubleScalarAtan2 ( _rtB -> o1q4woo5f2 [ 0 ] , _rtB ->
lzhl3d50ah [ 0 ] ) ; _rtB -> ieqqz35o4c [ 0 ] = _rtB -> lzhl3d50ah [ 0 ] *
_rtB -> lzhl3d50ah [ 0 ] + _rtB -> o1q4woo5f2 [ 0 ] * _rtB -> o1q4woo5f2 [ 0
] ; _rtB -> ofqzqqa0se [ 1 ] = _rtB -> jtidsw4hp3 [ 1 ] + jvs5i4w5ye ; _rtB
-> eylpkrhcz5 [ 1 ] = muDoubleScalarMod ( _rtB -> ofqzqqa0se [ 1 ] , _rtB ->
pvre3w420d ) / _rtB -> pvre3w420d ; _rtB -> iwrclgpyo1 [ 1 ] = _rtP -> P_11 *
_rtB -> eylpkrhcz5 [ 1 ] ; _rtB -> ii2qqwpe3c [ 1 ] = _rtP -> P_12 *
muDoubleScalarSin ( _rtB -> iwrclgpyo1 [ 1 ] ) ; _rtB -> o1q4woo5f2 [ 1 ] =
_rtB -> ii2qqwpe3c [ 1 ] * _rtB -> efldjtmkbv ; _rtB -> iwm5tf2dwe [ 1 ] =
muDoubleScalarCos ( _rtB -> iwrclgpyo1 [ 1 ] ) * _rtB -> fjfnwwgrbe ; _rtB ->
lzhl3d50ah [ 1 ] = _rtB -> iwm5tf2dwe [ 1 ] + _rtB -> fmygpllf40 ; _rtB ->
jhnjspziwz [ 1 ] = _rtB -> kur2lpov1n - muDoubleScalarAtan2 ( _rtB ->
o1q4woo5f2 [ 1 ] , _rtB -> lzhl3d50ah [ 1 ] ) ; _rtB -> ieqqz35o4c [ 1 ] =
_rtB -> lzhl3d50ah [ 1 ] * _rtB -> lzhl3d50ah [ 1 ] + _rtB -> o1q4woo5f2 [ 1
] * _rtB -> o1q4woo5f2 [ 1 ] ; _rtB -> ofqzqqa0se [ 2 ] = _rtB -> jtidsw4hp3
[ 2 ] + jvs5i4w5ye ; _rtB -> eylpkrhcz5 [ 2 ] = muDoubleScalarMod ( _rtB ->
ofqzqqa0se [ 2 ] , _rtB -> pvre3w420d ) / _rtB -> pvre3w420d ; _rtB ->
iwrclgpyo1 [ 2 ] = _rtP -> P_11 * _rtB -> eylpkrhcz5 [ 2 ] ; _rtB ->
ii2qqwpe3c [ 2 ] = _rtP -> P_12 * muDoubleScalarSin ( _rtB -> iwrclgpyo1 [ 2
] ) ; _rtB -> o1q4woo5f2 [ 2 ] = _rtB -> ii2qqwpe3c [ 2 ] * _rtB ->
efldjtmkbv ; _rtB -> iwm5tf2dwe [ 2 ] = muDoubleScalarCos ( _rtB ->
iwrclgpyo1 [ 2 ] ) * _rtB -> fjfnwwgrbe ; _rtB -> lzhl3d50ah [ 2 ] = _rtB ->
iwm5tf2dwe [ 2 ] + _rtB -> fmygpllf40 ; _rtB -> jhnjspziwz [ 2 ] = _rtB ->
kur2lpov1n - muDoubleScalarAtan2 ( _rtB -> o1q4woo5f2 [ 2 ] , _rtB ->
lzhl3d50ah [ 2 ] ) ; _rtB -> ieqqz35o4c [ 2 ] = _rtB -> lzhl3d50ah [ 2 ] *
_rtB -> lzhl3d50ah [ 2 ] + _rtB -> o1q4woo5f2 [ 2 ] * _rtB -> o1q4woo5f2 [ 2
] ; _rtB -> ofqzqqa0se [ 3 ] = _rtB -> jtidsw4hp3 [ 3 ] + jvs5i4w5ye ; _rtB
-> eylpkrhcz5 [ 3 ] = muDoubleScalarMod ( _rtB -> ofqzqqa0se [ 3 ] , _rtB ->
pvre3w420d ) / _rtB -> pvre3w420d ; _rtB -> iwrclgpyo1 [ 3 ] = _rtP -> P_11 *
_rtB -> eylpkrhcz5 [ 3 ] ; _rtB -> ii2qqwpe3c [ 3 ] = _rtP -> P_12 *
muDoubleScalarSin ( _rtB -> iwrclgpyo1 [ 3 ] ) ; _rtB -> o1q4woo5f2 [ 3 ] =
_rtB -> ii2qqwpe3c [ 3 ] * _rtB -> efldjtmkbv ; _rtB -> iwm5tf2dwe [ 3 ] =
muDoubleScalarCos ( _rtB -> iwrclgpyo1 [ 3 ] ) * _rtB -> fjfnwwgrbe ; _rtB ->
lzhl3d50ah [ 3 ] = _rtB -> iwm5tf2dwe [ 3 ] + _rtB -> fmygpllf40 ; _rtB ->
jhnjspziwz [ 3 ] = _rtB -> kur2lpov1n - muDoubleScalarAtan2 ( _rtB ->
o1q4woo5f2 [ 3 ] , _rtB -> lzhl3d50ah [ 3 ] ) ; _rtB -> ieqqz35o4c [ 3 ] =
_rtB -> lzhl3d50ah [ 3 ] * _rtB -> lzhl3d50ah [ 3 ] + _rtB -> o1q4woo5f2 [ 3
] * _rtB -> o1q4woo5f2 [ 3 ] ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtDW ->
n4owsftki3 != 0 ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> n4owsftki3 = 0 ; }
_rtB -> f2v5uxp2kf [ 0 ] = muDoubleScalarSqrt ( _rtB -> ieqqz35o4c [ 0 ] ) ;
_rtB -> f2v5uxp2kf [ 1 ] = muDoubleScalarSqrt ( _rtB -> ieqqz35o4c [ 1 ] ) ;
_rtB -> f2v5uxp2kf [ 2 ] = muDoubleScalarSqrt ( _rtB -> ieqqz35o4c [ 2 ] ) ;
_rtB -> f2v5uxp2kf [ 3 ] = muDoubleScalarSqrt ( _rtB -> ieqqz35o4c [ 3 ] ) ;
} else { if ( _rtB -> ieqqz35o4c [ 0 ] < 0.0 ) { _rtB -> f2v5uxp2kf [ 0 ] = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB -> ieqqz35o4c [ 0 ] ) ) ; }
else { _rtB -> f2v5uxp2kf [ 0 ] = muDoubleScalarSqrt ( _rtB -> ieqqz35o4c [ 0
] ) ; } if ( _rtB -> ieqqz35o4c [ 0 ] < 0.0 ) { _rtDW -> n4owsftki3 = 1 ; }
if ( _rtB -> ieqqz35o4c [ 1 ] < 0.0 ) { _rtB -> f2v5uxp2kf [ 1 ] = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB -> ieqqz35o4c [ 1 ] ) ) ; }
else { _rtB -> f2v5uxp2kf [ 1 ] = muDoubleScalarSqrt ( _rtB -> ieqqz35o4c [ 1
] ) ; } if ( _rtB -> ieqqz35o4c [ 1 ] < 0.0 ) { _rtDW -> n4owsftki3 = 1 ; }
if ( _rtB -> ieqqz35o4c [ 2 ] < 0.0 ) { _rtB -> f2v5uxp2kf [ 2 ] = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB -> ieqqz35o4c [ 2 ] ) ) ; }
else { _rtB -> f2v5uxp2kf [ 2 ] = muDoubleScalarSqrt ( _rtB -> ieqqz35o4c [ 2
] ) ; } if ( _rtB -> ieqqz35o4c [ 2 ] < 0.0 ) { _rtDW -> n4owsftki3 = 1 ; }
if ( _rtB -> ieqqz35o4c [ 3 ] < 0.0 ) { _rtB -> f2v5uxp2kf [ 3 ] = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB -> ieqqz35o4c [ 3 ] ) ) ; }
else { _rtB -> f2v5uxp2kf [ 3 ] = muDoubleScalarSqrt ( _rtB -> ieqqz35o4c [ 3
] ) ; } if ( _rtB -> ieqqz35o4c [ 3 ] < 0.0 ) { _rtDW -> n4owsftki3 = 1 ; } }
ssCallAccelRunBlock ( S , 28 , 32 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 28 , 33 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
iyieymotem = _rtB -> g2oxeuzo0r [ 12 ] - _rtB -> ppq2nljpur ; _rtB ->
a4x4yk4wkw = _rtB -> g2oxeuzo0r [ 14 ] - _rtB -> bjbsexztnp ; _rtB ->
lb4n1nxfht [ 0 ] = _rtB -> iyieymotem ; _rtB -> lb4n1nxfht [ 1 ] = _rtB ->
a4x4yk4wkw ; ssCallAccelRunBlock ( S , 9 , 1 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 11 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> bkxp04saya
[ 0 ] = _rtB -> jhnjspziwz [ 0 ] - _rtB -> fdrhl5x0jl [ 0 ] ; _rtB ->
bkxp04saya [ 1 ] = _rtB -> f2v5uxp2kf [ 0 ] - _rtB -> fdrhl5x0jl [ 1 ] ; _rtB
-> dk5kj1yocg = _rtB -> bkxp04saya [ 0 ] / _rtB -> fdrhl5x0jl [ 1 ] ; _rtB ->
f4y5ezrltg = _rtP -> P_20 * _rtB -> dk5kj1yocg ; _rtB -> kwidjj0i1z = _rtX ->
cxeojb1daj ; _rtB -> jtdzi4yth5 = _rtP -> P_22 * _rtB -> dk5kj1yocg ; _rtB ->
p3luu21sk4 = _rtX -> jpnzccegos ; _rtB -> aobtkp50cz = _rtB -> jtdzi4yth5 -
_rtB -> p3luu21sk4 ; _rtB -> ob0cpd1sjr = _rtP -> P_24 * _rtB -> aobtkp50cz ;
_rtB -> fzuymbvivo = ( _rtB -> f4y5ezrltg + _rtB -> kwidjj0i1z ) + _rtB ->
ob0cpd1sjr ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> bbzmveq00t = _rtB ->
fzuymbvivo >= _rtP -> P_25 ? 1 : _rtB -> fzuymbvivo > _rtP -> P_26 ? 0 : - 1
; } _rtB -> ke1o1od2nj = _rtDW -> bbzmveq00t == 1 ? _rtP -> P_25 : _rtDW ->
bbzmveq00t == - 1 ? _rtP -> P_26 : _rtB -> fzuymbvivo ; _rtB -> pt5fmy3hmn =
_rtP -> P_27 * _rtB -> bkxp04saya [ 1 ] ; _rtB -> getjjx42p5 = _rtX ->
hbzjezrxaa ; _rtB -> g2qyjyrfqu = _rtP -> P_29 * _rtB -> bkxp04saya [ 1 ] ;
_rtB -> aepr0ozi51 = _rtX -> plrlq1n4lb ; _rtB -> omegeqihoh = _rtB ->
g2qyjyrfqu - _rtB -> aepr0ozi51 ; _rtB -> b3thtgmkcq = _rtP -> P_31 * _rtB ->
omegeqihoh ; _rtB -> pyb2whaz1q = ( _rtB -> pt5fmy3hmn + _rtB -> getjjx42p5 )
+ _rtB -> b3thtgmkcq ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> cdxep2a1zz =
_rtB -> pyb2whaz1q >= _rtP -> P_32 ? 1 : _rtB -> pyb2whaz1q > _rtP -> P_33 ?
0 : - 1 ; } _rtB -> i33tjky33b = _rtDW -> cdxep2a1zz == 1 ? _rtP -> P_32 :
_rtDW -> cdxep2a1zz == - 1 ? _rtP -> P_33 : _rtB -> pyb2whaz1q ; _rtB ->
pgqyjbrf1n [ 0 ] = _rtB -> ke1o1od2nj ; _rtB -> pgqyjbrf1n [ 1 ] = _rtB ->
i33tjky33b ; ssCallAccelRunBlock ( S , 10 , 1 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> oavxtosfyf = 0.0 ; _rtB -> oavxtosfyf += _rtP -> P_34 * _rtB -> gv4gzbi0bf
[ 0 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> dcge5imozy = ( _rtB -> oavxtosfyf > _rtB -> d45j2mfj2n ) ; _rtDW ->
oyeucpfj52 = ( _rtB -> oavxtosfyf < _rtB -> kuyzofz0c1 ) ; } _rtB ->
hagdbbdqlm = _rtDW -> dcge5imozy ; _rtB -> k0u1kmzzuq = _rtDW -> oyeucpfj52 ;
} if ( _rtB -> hagdbbdqlm ) { _rtB -> mgodjl5ant = _rtB -> d45j2mfj2n ; }
else { if ( _rtB -> k0u1kmzzuq ) { _rtB -> ffdkuhu2sz = _rtB -> kuyzofz0c1 ;
} else { _rtB -> ffdkuhu2sz = _rtB -> oavxtosfyf ; } _rtB -> mgodjl5ant =
_rtB -> ffdkuhu2sz ; } amuqdujtnk = _rtP -> P_36 * _rtB -> mgodjl5ant ;
amuqdujtnk = amuqdujtnk * amuqdujtnk * _rtP -> P_37 ; grepr3faim = _rtB ->
g2oxeuzo0r [ 13 ] * _rtB -> mgodjl5ant ; _rtB -> ftg3bfo40p = 0.0 ; _rtB ->
ftg3bfo40p += _rtP -> P_39 * _rtB -> gv4gzbi0bf [ 1 ] ; if ( ssIsSampleHit (
S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> mdar5hxfui = ( _rtB
-> ftg3bfo40p > _rtB -> jq3apgk4nj ) ; _rtDW -> kvgq5benja = ( _rtB ->
ftg3bfo40p < _rtB -> mwoc4aem5x ) ; } _rtB -> njjt02j5xt = _rtDW ->
mdar5hxfui ; _rtB -> kunooz3ag5 = _rtDW -> kvgq5benja ; } if ( _rtB ->
njjt02j5xt ) { _rtB -> nmf044e53q = _rtB -> jq3apgk4nj ; } else { if ( _rtB
-> kunooz3ag5 ) { _rtB -> kb0lqdprhr = _rtB -> mwoc4aem5x ; } else { _rtB ->
kb0lqdprhr = _rtB -> ftg3bfo40p ; } _rtB -> nmf044e53q = _rtB -> kb0lqdprhr ;
} mpgvgtjuc3 = _rtP -> P_41 * _rtB -> nmf044e53q ; mpgvgtjuc3 = mpgvgtjuc3 *
mpgvgtjuc3 * _rtP -> P_42 ; dzju20iykt = _rtB -> g2oxeuzo0r [ 15 ] * _rtB ->
nmf044e53q ; _rtB -> ahy2dz0qqz = _rtB -> g2oxeuzo0r [ 16 ] - _rtB ->
orkduffjmn ; _rtB -> gbpy2vf1yb = _rtB -> g2oxeuzo0r [ 18 ] - _rtB ->
hirmalog3p ; _rtB -> bkawd4amun [ 0 ] = _rtB -> ahy2dz0qqz ; _rtB ->
bkawd4amun [ 1 ] = _rtB -> gbpy2vf1yb ; ssCallAccelRunBlock ( S , 0 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> e01mzhagag [ 0 ] = _rtB -> jhnjspziwz [ 1 ] - _rtB -> gbhifmgi2i
[ 0 ] ; _rtB -> e01mzhagag [ 1 ] = _rtB -> f2v5uxp2kf [ 1 ] - _rtB ->
gbhifmgi2i [ 1 ] ; _rtB -> jgygd4vgjf = _rtB -> e01mzhagag [ 0 ] / _rtB ->
gbhifmgi2i [ 1 ] ; _rtB -> ha3korcge1 = _rtP -> P_48 * _rtB -> jgygd4vgjf ;
_rtB -> jdwbtyg4ry = _rtX -> f0j1nzn33x ; _rtB -> h10ykxjggh = _rtP -> P_50 *
_rtB -> jgygd4vgjf ; _rtB -> pkcbv2t0zs = _rtX -> nip4ajifhe ; _rtB ->
h3rhyw55w1 = _rtB -> h10ykxjggh - _rtB -> pkcbv2t0zs ; _rtB -> hkmuzcm3fa =
_rtP -> P_52 * _rtB -> h3rhyw55w1 ; _rtB -> kqi21egmuf = ( _rtB -> ha3korcge1
+ _rtB -> jdwbtyg4ry ) + _rtB -> hkmuzcm3fa ; if ( ssIsMajorTimeStep ( S ) )
{ _rtDW -> hzsgeujya2 = _rtB -> kqi21egmuf >= _rtP -> P_53 ? 1 : _rtB ->
kqi21egmuf > _rtP -> P_54 ? 0 : - 1 ; } _rtB -> p0olrfw053 = _rtDW ->
hzsgeujya2 == 1 ? _rtP -> P_53 : _rtDW -> hzsgeujya2 == - 1 ? _rtP -> P_54 :
_rtB -> kqi21egmuf ; _rtB -> op22qdefcp = _rtP -> P_55 * _rtB -> e01mzhagag [
1 ] ; _rtB -> dlyqa5rssu = _rtX -> oru0egare2 ; _rtB -> j2gvb2douf = _rtP ->
P_57 * _rtB -> e01mzhagag [ 1 ] ; _rtB -> g1dmq1d012 = _rtX -> gxrnom4kvs ;
_rtB -> n2vo3skpnu = _rtB -> j2gvb2douf - _rtB -> g1dmq1d012 ; _rtB ->
g4s3hdi1ku = _rtP -> P_59 * _rtB -> n2vo3skpnu ; _rtB -> hqnpewltuj = ( _rtB
-> op22qdefcp + _rtB -> dlyqa5rssu ) + _rtB -> g4s3hdi1ku ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> coon22buvj = _rtB -> hqnpewltuj >= _rtP
-> P_60 ? 1 : _rtB -> hqnpewltuj > _rtP -> P_61 ? 0 : - 1 ; } _rtB ->
dm3r03kwni = _rtDW -> coon22buvj == 1 ? _rtP -> P_60 : _rtDW -> coon22buvj ==
- 1 ? _rtP -> P_61 : _rtB -> hqnpewltuj ; _rtB -> nckxqwc2kp [ 0 ] = _rtB ->
p0olrfw053 ; _rtB -> nckxqwc2kp [ 1 ] = _rtB -> dm3r03kwni ;
ssCallAccelRunBlock ( S , 1 , 1 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> im3cdxu1xy
= 0.0 ; _rtB -> im3cdxu1xy += _rtP -> P_62 * _rtB -> o4tm4bqawj [ 0 ] ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
i4b420jbyi = ( _rtB -> im3cdxu1xy > _rtB -> bfhgfrbwvh ) ; _rtDW ->
lqrzaatwkx = ( _rtB -> im3cdxu1xy < _rtB -> fnmwtzhcqo ) ; } _rtB ->
ixnkngqvv1 = _rtDW -> i4b420jbyi ; _rtB -> ad1qsobstp = _rtDW -> lqrzaatwkx ;
} if ( _rtB -> ixnkngqvv1 ) { _rtB -> n1fw4qveod = _rtB -> bfhgfrbwvh ; }
else { if ( _rtB -> ad1qsobstp ) { _rtB -> f1miwtqeqk = _rtB -> fnmwtzhcqo ;
} else { _rtB -> f1miwtqeqk = _rtB -> im3cdxu1xy ; } _rtB -> n1fw4qveod =
_rtB -> f1miwtqeqk ; } asuc3ovo0p = _rtP -> P_64 * _rtB -> n1fw4qveod ;
asuc3ovo0p = asuc3ovo0p * asuc3ovo0p * _rtP -> P_65 ; geamegmthb = _rtB ->
g2oxeuzo0r [ 17 ] * _rtB -> n1fw4qveod ; _rtB -> pb1dz3kkx0 = 0.0 ; _rtB ->
pb1dz3kkx0 += _rtP -> P_67 * _rtB -> o4tm4bqawj [ 1 ] ; if ( ssIsSampleHit (
S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> boxrvoralg = ( _rtB
-> pb1dz3kkx0 > _rtB -> egg4byp5sm ) ; _rtDW -> ohrspvz1c5 = ( _rtB ->
pb1dz3kkx0 < _rtB -> n0kkxtxeuq ) ; } _rtB -> duqyfca1di = _rtDW ->
boxrvoralg ; _rtB -> ke0k43w3of = _rtDW -> ohrspvz1c5 ; } if ( _rtB ->
duqyfca1di ) { _rtB -> ahovkcndla = _rtB -> egg4byp5sm ; } else { if ( _rtB
-> ke0k43w3of ) { _rtB -> kmx0knio2h = _rtB -> n0kkxtxeuq ; } else { _rtB ->
kmx0knio2h = _rtB -> pb1dz3kkx0 ; } _rtB -> ahovkcndla = _rtB -> kmx0knio2h ;
} ojmyu3yj4i = _rtP -> P_69 * _rtB -> ahovkcndla ; ojmyu3yj4i = ojmyu3yj4i *
ojmyu3yj4i * _rtP -> P_70 ; eqsip0abas = _rtB -> g2oxeuzo0r [ 19 ] * _rtB ->
ahovkcndla ; _rtB -> mlbtulv2ez = _rtB -> g2oxeuzo0r [ 20 ] - _rtB ->
dolfcdt54b ; _rtB -> axte3clpuh = _rtB -> g2oxeuzo0r [ 22 ] - _rtB ->
cnyirpvnk1 ; _rtB -> kqyhwlcpfu [ 0 ] = _rtB -> mlbtulv2ez ; _rtB ->
kqyhwlcpfu [ 1 ] = _rtB -> axte3clpuh ; ssCallAccelRunBlock ( S , 3 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 5 , 0 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> npavplmseb [ 0 ] = _rtB -> jhnjspziwz [ 2 ] - _rtB -> iq2rbbroq1
[ 0 ] ; _rtB -> npavplmseb [ 1 ] = _rtB -> f2v5uxp2kf [ 2 ] - _rtB ->
iq2rbbroq1 [ 1 ] ; _rtB -> mq2bvv1fib = _rtB -> npavplmseb [ 0 ] / _rtB ->
iq2rbbroq1 [ 1 ] ; _rtB -> iagcwtdnth = _rtP -> P_76 * _rtB -> mq2bvv1fib ;
_rtB -> ax1s5djwhh = _rtX -> fl3smsk2pa ; _rtB -> oo2ot1jog1 = _rtP -> P_78 *
_rtB -> mq2bvv1fib ; _rtB -> au4srwkjym = _rtX -> gygufh40me ; _rtB ->
mbkacjp2ci = _rtB -> oo2ot1jog1 - _rtB -> au4srwkjym ; _rtB -> o0pn3e5klc =
_rtP -> P_80 * _rtB -> mbkacjp2ci ; _rtB -> m4nk3qn5jz = ( _rtB -> iagcwtdnth
+ _rtB -> ax1s5djwhh ) + _rtB -> o0pn3e5klc ; if ( ssIsMajorTimeStep ( S ) )
{ _rtDW -> f3ewaily5n = _rtB -> m4nk3qn5jz >= _rtP -> P_81 ? 1 : _rtB ->
m4nk3qn5jz > _rtP -> P_82 ? 0 : - 1 ; } _rtB -> fuvhub1udj = _rtDW ->
f3ewaily5n == 1 ? _rtP -> P_81 : _rtDW -> f3ewaily5n == - 1 ? _rtP -> P_82 :
_rtB -> m4nk3qn5jz ; _rtB -> j03ik1fb55 = _rtP -> P_83 * _rtB -> npavplmseb [
1 ] ; _rtB -> b402wiv3lw = _rtX -> eovqkkvnpx ; _rtB -> nz0mvja3db = _rtP ->
P_85 * _rtB -> npavplmseb [ 1 ] ; _rtB -> mmlpc0sjeh = _rtX -> jzergwlee4 ;
_rtB -> isea5ttru2 = _rtB -> nz0mvja3db - _rtB -> mmlpc0sjeh ; _rtB ->
awcjdb2df1 = _rtP -> P_87 * _rtB -> isea5ttru2 ; _rtB -> osksjb1cuc = ( _rtB
-> j03ik1fb55 + _rtB -> b402wiv3lw ) + _rtB -> awcjdb2df1 ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> mwnwghgqzy = _rtB -> osksjb1cuc >= _rtP
-> P_88 ? 1 : _rtB -> osksjb1cuc > _rtP -> P_89 ? 0 : - 1 ; } _rtB ->
j52r1bz0kf = _rtDW -> mwnwghgqzy == 1 ? _rtP -> P_88 : _rtDW -> mwnwghgqzy ==
- 1 ? _rtP -> P_89 : _rtB -> osksjb1cuc ; _rtB -> i2ocokex3b [ 0 ] = _rtB ->
fuvhub1udj ; _rtB -> i2ocokex3b [ 1 ] = _rtB -> j52r1bz0kf ;
ssCallAccelRunBlock ( S , 4 , 1 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> fqdvqq43ng
= 0.0 ; _rtB -> fqdvqq43ng += _rtP -> P_90 * _rtB -> ijheqgwykq [ 0 ] ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
kcsvna1w3k = ( _rtB -> fqdvqq43ng > _rtB -> bufkv32hnh ) ; _rtDW ->
b5cudn00n2 = ( _rtB -> fqdvqq43ng < _rtB -> hnkdyd2esb ) ; } _rtB ->
f1oirqllee = _rtDW -> kcsvna1w3k ; _rtB -> dd3gxvdzui = _rtDW -> b5cudn00n2 ;
} if ( _rtB -> f1oirqllee ) { _rtB -> jpo5nxw1ap = _rtB -> bufkv32hnh ; }
else { if ( _rtB -> dd3gxvdzui ) { _rtB -> pit0cx01gw = _rtB -> hnkdyd2esb ;
} else { _rtB -> pit0cx01gw = _rtB -> fqdvqq43ng ; } _rtB -> jpo5nxw1ap =
_rtB -> pit0cx01gw ; } hkapiozpds = _rtP -> P_92 * _rtB -> jpo5nxw1ap ;
hkapiozpds = hkapiozpds * hkapiozpds * _rtP -> P_93 ; ecuu4mmu22 = _rtB ->
g2oxeuzo0r [ 21 ] * _rtB -> jpo5nxw1ap ; _rtB -> io01e0xual = 0.0 ; _rtB ->
io01e0xual += _rtP -> P_95 * _rtB -> ijheqgwykq [ 1 ] ; if ( ssIsSampleHit (
S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> gnwobkp00f = ( _rtB
-> io01e0xual > _rtB -> c5awvfjfsl ) ; _rtDW -> fovvfprobq = ( _rtB ->
io01e0xual < _rtB -> atspuwrc12 ) ; } _rtB -> itroinojky = _rtDW ->
gnwobkp00f ; _rtB -> gyed24vkjd = _rtDW -> fovvfprobq ; } if ( _rtB ->
itroinojky ) { _rtB -> aa3lzm1qoo = _rtB -> c5awvfjfsl ; } else { if ( _rtB
-> gyed24vkjd ) { _rtB -> fkecm2myk5 = _rtB -> atspuwrc12 ; } else { _rtB ->
fkecm2myk5 = _rtB -> io01e0xual ; } _rtB -> aa3lzm1qoo = _rtB -> fkecm2myk5 ;
} ega5zbm5sp = _rtP -> P_97 * _rtB -> aa3lzm1qoo ; ega5zbm5sp = ega5zbm5sp *
ega5zbm5sp * _rtP -> P_98 ; bdnicddmcs = _rtB -> g2oxeuzo0r [ 23 ] * _rtB ->
aa3lzm1qoo ; _rtB -> ffwwzbyrkw = _rtB -> g2oxeuzo0r [ 24 ] - _rtB ->
e3yp4epods ; _rtB -> kctyiybzdq = _rtB -> g2oxeuzo0r [ 26 ] - _rtB ->
eqvwsfe21z ; _rtB -> hnogjmnp1i [ 0 ] = _rtB -> ffwwzbyrkw ; _rtB ->
hnogjmnp1i [ 1 ] = _rtB -> kctyiybzdq ; ssCallAccelRunBlock ( S , 6 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 8 , 0 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> jsldrpofzn [ 0 ] = _rtB -> jhnjspziwz [ 3 ] - _rtB -> l0kklialbo
[ 0 ] ; _rtB -> jsldrpofzn [ 1 ] = _rtB -> f2v5uxp2kf [ 3 ] - _rtB ->
l0kklialbo [ 1 ] ; _rtB -> bm2z2jstbd = _rtB -> jsldrpofzn [ 0 ] / _rtB ->
l0kklialbo [ 1 ] ; _rtB -> oelwsrn20m = _rtP -> P_104 * _rtB -> bm2z2jstbd ;
_rtB -> o5j5vbjuec = _rtX -> d2r23v0g05 ; _rtB -> foyiuctooc = _rtP -> P_106
* _rtB -> bm2z2jstbd ; _rtB -> n0ghuazspr = _rtX -> gd5kx0ir3u ; _rtB ->
f4w14odsny = _rtB -> foyiuctooc - _rtB -> n0ghuazspr ; _rtB -> fhrn1ot0cf =
_rtP -> P_108 * _rtB -> f4w14odsny ; _rtB -> f04zp5o0lg = ( _rtB ->
oelwsrn20m + _rtB -> o5j5vbjuec ) + _rtB -> fhrn1ot0cf ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> ozxdwj14pv = _rtB -> f04zp5o0lg >= _rtP
-> P_109 ? 1 : _rtB -> f04zp5o0lg > _rtP -> P_110 ? 0 : - 1 ; } _rtB ->
hvqi2gk2ic = _rtDW -> ozxdwj14pv == 1 ? _rtP -> P_109 : _rtDW -> ozxdwj14pv
== - 1 ? _rtP -> P_110 : _rtB -> f04zp5o0lg ; _rtB -> bz1hdrphts = _rtP ->
P_111 * _rtB -> jsldrpofzn [ 1 ] ; _rtB -> iwvrgl3vyz = _rtX -> jk2n0iiuzk ;
_rtB -> bo0yu5ufyh = _rtP -> P_113 * _rtB -> jsldrpofzn [ 1 ] ; _rtB ->
apxjxpktqt = _rtX -> ohlowbif4o ; _rtB -> mpsx4iyzxj = _rtB -> bo0yu5ufyh -
_rtB -> apxjxpktqt ; _rtB -> eycuxcgy4u = _rtP -> P_115 * _rtB -> mpsx4iyzxj
; _rtB -> iqxqfzwt1t = ( _rtB -> bz1hdrphts + _rtB -> iwvrgl3vyz ) + _rtB ->
eycuxcgy4u ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> omqdqbwjxe = _rtB ->
iqxqfzwt1t >= _rtP -> P_116 ? 1 : _rtB -> iqxqfzwt1t > _rtP -> P_117 ? 0 : -
1 ; } _rtB -> kgewalmsl5 = _rtDW -> omqdqbwjxe == 1 ? _rtP -> P_116 : _rtDW
-> omqdqbwjxe == - 1 ? _rtP -> P_117 : _rtB -> iqxqfzwt1t ; _rtB ->
lkqgp0hbcb [ 0 ] = _rtB -> hvqi2gk2ic ; _rtB -> lkqgp0hbcb [ 1 ] = _rtB ->
kgewalmsl5 ; ssCallAccelRunBlock ( S , 7 , 1 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> gumk4r3kva = 0.0 ; _rtB -> gumk4r3kva += _rtP -> P_118 * _rtB ->
aaxznq02ab [ 0 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> eoar2rg2on = ( _rtB -> gumk4r3kva > _rtB
-> fcmom4rlro ) ; _rtDW -> dxtwktjgiq = ( _rtB -> gumk4r3kva < _rtB ->
gc2ovlipnf ) ; } _rtB -> ovzrm41a3x = _rtDW -> eoar2rg2on ; _rtB ->
c2krcpk0s4 = _rtDW -> dxtwktjgiq ; } if ( _rtB -> ovzrm41a3x ) { _rtB ->
cxyjcf5uqw = _rtB -> fcmom4rlro ; } else { if ( _rtB -> c2krcpk0s4 ) { _rtB
-> eidbg5wig3 = _rtB -> gc2ovlipnf ; } else { _rtB -> eidbg5wig3 = _rtB ->
gumk4r3kva ; } _rtB -> cxyjcf5uqw = _rtB -> eidbg5wig3 ; } ixvimtbepc = _rtP
-> P_120 * _rtB -> cxyjcf5uqw ; hesuxowbif = _rtB -> g2oxeuzo0r [ 25 ] * _rtB
-> cxyjcf5uqw ; _rtB -> p3h0g0snlv = 0.0 ; _rtB -> p3h0g0snlv += _rtP ->
P_123 * _rtB -> aaxznq02ab [ 1 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> csejsrw1rx = ( _rtB -> p3h0g0snlv > _rtB
-> ayo13uo1wa ) ; _rtDW -> h4fg3imnwa = ( _rtB -> p3h0g0snlv < _rtB ->
la1abbljvx ) ; } _rtB -> hm4jz2hzgd = _rtDW -> csejsrw1rx ; _rtB ->
arfzbse42k = _rtDW -> h4fg3imnwa ; } if ( _rtB -> hm4jz2hzgd ) { _rtB ->
n42cgxjwpd = _rtB -> ayo13uo1wa ; } else { if ( _rtB -> arfzbse42k ) { _rtB
-> ohakj0eiqt = _rtB -> la1abbljvx ; } else { _rtB -> ohakj0eiqt = _rtB ->
p3h0g0snlv ; } _rtB -> n42cgxjwpd = _rtB -> ohakj0eiqt ; } pfdhed5jbr = _rtP
-> P_125 * _rtB -> n42cgxjwpd ; ljolgva0g0 = _rtB -> g2oxeuzo0r [ 27 ] * _rtB
-> n42cgxjwpd ; _rtB -> jayblgu4eu [ 0 ] = amuqdujtnk + grepr3faim ; _rtB ->
jayblgu4eu [ 1 ] = mpgvgtjuc3 + dzju20iykt ; _rtB -> jayblgu4eu [ 2 ] =
asuc3ovo0p + geamegmthb ; _rtB -> jayblgu4eu [ 3 ] = ojmyu3yj4i + eqsip0abas
; _rtB -> jayblgu4eu [ 4 ] = hkapiozpds + ecuu4mmu22 ; _rtB -> jayblgu4eu [ 5
] = ega5zbm5sp + bdnicddmcs ; _rtB -> jayblgu4eu [ 6 ] = ixvimtbepc *
ixvimtbepc * _rtP -> P_121 + hesuxowbif ; _rtB -> jayblgu4eu [ 7 ] =
pfdhed5jbr * pfdhed5jbr * _rtP -> P_126 + ljolgva0g0 ; ssCallAccelRunBlock (
S , 28 , 238 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> jayblgu4eu [ 0 ] = grepr3faim
; _rtB -> jayblgu4eu [ 1 ] = dzju20iykt ; _rtB -> jayblgu4eu [ 2 ] =
geamegmthb ; _rtB -> jayblgu4eu [ 3 ] = eqsip0abas ; _rtB -> jayblgu4eu [ 4 ]
= ecuu4mmu22 ; _rtB -> jayblgu4eu [ 5 ] = bdnicddmcs ; _rtB -> jayblgu4eu [ 6
] = hesuxowbif ; _rtB -> jayblgu4eu [ 7 ] = ljolgva0g0 ; ssCallAccelRunBlock
( S , 28 , 240 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> jxklyhvaee = ( (
muDoubleScalarAbs ( _rtP -> P_127 * _rtB -> g2oxeuzo0r [ 45 ] ) < _rtB ->
mdt5f1k4na ) && ( muDoubleScalarAbs ( _rtP -> P_129 * _rtB -> g2oxeuzo0r [ 46
] ) < _rtB -> ix4zqj34sb ) ) ; rtPrevAction = _rtDW -> juc3cooyqb ; if (
ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T ) ! ( _rtB -> jxklyhvaee >
0.0 ) ; _rtDW -> juc3cooyqb = rtAction ; } else { rtAction = _rtDW ->
juc3cooyqb ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : evsykqyxrn ( S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ;
break ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) {
gwv3tbs0q4 ( S ) ; } nrfrkljgb4 ( S , _rtB -> g2oxeuzo0r [ 45 ] , _rtB ->
g2oxeuzo0r [ 46 ] , _rtB -> g2oxeuzo0r [ 47 ] , _rtB -> g2oxeuzo0r [ 50 ] , &
_rtB -> g2oxeuzo0r [ 34 ] , _rtB -> g2oxeuzo0r [ 43 ] , _rtB -> g2oxeuzo0r [
44 ] , _rtB -> g2oxeuzo0r [ 48 ] , _rtB -> g2oxeuzo0r [ 49 ] , & _rtB ->
f3yexps0ss [ 0 ] , & _rtB -> f3yexps0ss [ 3 ] , & _rtB -> f3yexps0ss [ 6 ] ,
& _rtB -> f3yexps0ss [ 9 ] , & _rtB -> f3yexps0ss [ 10 ] , & _rtB ->
f3yexps0ss [ 11 ] , & _rtB -> nrfrkljgb41 , & _rtDW -> nrfrkljgb41 , (
myg1st0tfa * ) & _rtP -> nrfrkljgb41 ) ; if ( ssIsMajorTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> nrfrkljgb41 . et1cogum3m ) ; } break ; case 1 : if (
rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S
) ) { ssSetSolverNeedsReset ( S ) ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> f3yexps0ss [ 0 ] , & _rtP -> P_0 [ 0 ] , 12U * sizeof (
real_T ) ) ; } if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
ld1ggeu4ct ) ; } break ; } _rtB -> mh5bayccp0 [ 0 ] = _rtB -> jxklyhvaee *
_rtB -> nrfrkljgb41 . oa2veixczc ; _rtB -> mh5bayccp0 [ 1 ] = _rtB ->
jxklyhvaee * _rtB -> nrfrkljgb41 . fevfwm0ave [ 0 ] ; _rtB -> mh5bayccp0 [ 2
] = _rtB -> jxklyhvaee * _rtB -> nrfrkljgb41 . fevfwm0ave [ 1 ] ; _rtB ->
mh5bayccp0 [ 3 ] = _rtB -> jxklyhvaee * _rtB -> nrfrkljgb41 . fevfwm0ave [ 2
] ; _rtB -> mh5bayccp0 [ 4 ] = _rtB -> jxklyhvaee * _rtB -> nrfrkljgb41 .
lbahd1zvro ; _rtB -> mh5bayccp0 [ 5 ] = _rtB -> jxklyhvaee * _rtB ->
nrfrkljgb41 . a1uff23gp2 ; _rtB -> mh5bayccp0 [ 6 ] = _rtB -> jxklyhvaee *
_rtB -> nrfrkljgb41 . biw0uvoced ; _rtB -> mh5bayccp0 [ 7 ] = _rtB ->
jxklyhvaee * _rtB -> nrfrkljgb41 . hum5y5u3fc ; _rtB -> dlomiozwtn = ( (
muDoubleScalarAbs ( _rtP -> P_131 * _rtB -> g2oxeuzo0r [ 62 ] ) < _rtB ->
gdklmxkw3o ) && ( muDoubleScalarAbs ( _rtP -> P_133 * _rtB -> g2oxeuzo0r [ 63
] ) < _rtB -> ivt01jokr5 ) ) ; rtPrevAction = _rtDW -> air5odkdn1 ; if (
ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T ) ! ( _rtB -> dlomiozwtn >
0.0 ) ; _rtDW -> air5odkdn1 = rtAction ; } else { rtAction = _rtDW ->
air5odkdn1 ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : evsykqyxrn ( S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ;
break ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) {
gwv3tbs0q4 ( S ) ; } nrfrkljgb4 ( S , _rtB -> g2oxeuzo0r [ 62 ] , _rtB ->
g2oxeuzo0r [ 63 ] , _rtB -> g2oxeuzo0r [ 64 ] , _rtB -> g2oxeuzo0r [ 67 ] , &
_rtB -> g2oxeuzo0r [ 51 ] , _rtB -> g2oxeuzo0r [ 60 ] , _rtB -> g2oxeuzo0r [
61 ] , _rtB -> g2oxeuzo0r [ 65 ] , _rtB -> g2oxeuzo0r [ 66 ] , & _rtB ->
dz1mvkujq5 [ 0 ] , & _rtB -> dz1mvkujq5 [ 3 ] , & _rtB -> dz1mvkujq5 [ 6 ] ,
& _rtB -> dz1mvkujq5 [ 9 ] , & _rtB -> dz1mvkujq5 [ 10 ] , & _rtB ->
dz1mvkujq5 [ 11 ] , & _rtB -> gdzkcxszzw , & _rtDW -> gdzkcxszzw , (
myg1st0tfa * ) & _rtP -> gdzkcxszzw ) ; if ( ssIsMajorTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> gdzkcxszzw . et1cogum3m ) ; } break ; case 1 : if (
rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S
) ) { ssSetSolverNeedsReset ( S ) ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> dz1mvkujq5 [ 0 ] , & _rtP -> P_1 [ 0 ] , 12U * sizeof (
real_T ) ) ; } if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
ilj3eptqgd ) ; } break ; } _rtB -> chmogmkvly [ 0 ] = _rtB -> dlomiozwtn *
_rtB -> gdzkcxszzw . oa2veixczc ; _rtB -> chmogmkvly [ 1 ] = _rtB ->
dlomiozwtn * _rtB -> gdzkcxszzw . fevfwm0ave [ 0 ] ; _rtB -> chmogmkvly [ 2 ]
= _rtB -> dlomiozwtn * _rtB -> gdzkcxszzw . fevfwm0ave [ 1 ] ; _rtB ->
chmogmkvly [ 3 ] = _rtB -> dlomiozwtn * _rtB -> gdzkcxszzw . fevfwm0ave [ 2 ]
; _rtB -> chmogmkvly [ 4 ] = _rtB -> dlomiozwtn * _rtB -> gdzkcxszzw .
lbahd1zvro ; _rtB -> chmogmkvly [ 5 ] = _rtB -> dlomiozwtn * _rtB ->
gdzkcxszzw . a1uff23gp2 ; _rtB -> chmogmkvly [ 6 ] = _rtB -> dlomiozwtn *
_rtB -> gdzkcxszzw . biw0uvoced ; _rtB -> chmogmkvly [ 7 ] = _rtB ->
dlomiozwtn * _rtB -> gdzkcxszzw . hum5y5u3fc ; _rtB -> m2ub1bsc1t = ( (
muDoubleScalarAbs ( _rtP -> P_135 * _rtB -> g2oxeuzo0r [ 79 ] ) < _rtB ->
irmq23w5il ) && ( muDoubleScalarAbs ( _rtP -> P_137 * _rtB -> g2oxeuzo0r [ 80
] ) < _rtB -> m0efayzcxy ) ) ; rtPrevAction = _rtDW -> nclypgegew ; if (
ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T ) ! ( _rtB -> m2ub1bsc1t >
0.0 ) ; _rtDW -> nclypgegew = rtAction ; } else { rtAction = _rtDW ->
nclypgegew ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : evsykqyxrn ( S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ;
break ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) {
gwv3tbs0q4 ( S ) ; } nrfrkljgb4 ( S , _rtB -> g2oxeuzo0r [ 79 ] , _rtB ->
g2oxeuzo0r [ 80 ] , _rtB -> g2oxeuzo0r [ 81 ] , _rtB -> g2oxeuzo0r [ 84 ] , &
_rtB -> g2oxeuzo0r [ 68 ] , _rtB -> g2oxeuzo0r [ 77 ] , _rtB -> g2oxeuzo0r [
78 ] , _rtB -> g2oxeuzo0r [ 82 ] , _rtB -> g2oxeuzo0r [ 83 ] , & _rtB ->
hwk3cn3whe [ 0 ] , & _rtB -> hwk3cn3whe [ 3 ] , & _rtB -> hwk3cn3whe [ 6 ] ,
& _rtB -> hwk3cn3whe [ 9 ] , & _rtB -> hwk3cn3whe [ 10 ] , & _rtB ->
hwk3cn3whe [ 11 ] , & _rtB -> fpj3f1xutu , & _rtDW -> fpj3f1xutu , (
myg1st0tfa * ) & _rtP -> fpj3f1xutu ) ; if ( ssIsMajorTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> fpj3f1xutu . et1cogum3m ) ; } break ; case 1 : if (
rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S
) ) { ssSetSolverNeedsReset ( S ) ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> hwk3cn3whe [ 0 ] , & _rtP -> P_2 [ 0 ] , 12U * sizeof (
real_T ) ) ; } if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
obktkswbn1 ) ; } break ; } _rtB -> gvgcuwwh1h [ 0 ] = _rtB -> m2ub1bsc1t *
_rtB -> fpj3f1xutu . oa2veixczc ; _rtB -> gvgcuwwh1h [ 1 ] = _rtB ->
m2ub1bsc1t * _rtB -> fpj3f1xutu . fevfwm0ave [ 0 ] ; _rtB -> gvgcuwwh1h [ 2 ]
= _rtB -> m2ub1bsc1t * _rtB -> fpj3f1xutu . fevfwm0ave [ 1 ] ; _rtB ->
gvgcuwwh1h [ 3 ] = _rtB -> m2ub1bsc1t * _rtB -> fpj3f1xutu . fevfwm0ave [ 2 ]
; _rtB -> gvgcuwwh1h [ 4 ] = _rtB -> m2ub1bsc1t * _rtB -> fpj3f1xutu .
lbahd1zvro ; _rtB -> gvgcuwwh1h [ 5 ] = _rtB -> m2ub1bsc1t * _rtB ->
fpj3f1xutu . a1uff23gp2 ; _rtB -> gvgcuwwh1h [ 6 ] = _rtB -> m2ub1bsc1t *
_rtB -> fpj3f1xutu . biw0uvoced ; _rtB -> gvgcuwwh1h [ 7 ] = _rtB ->
m2ub1bsc1t * _rtB -> fpj3f1xutu . hum5y5u3fc ; _rtB -> jt2c0fz5cf = ( (
muDoubleScalarAbs ( _rtP -> P_139 * _rtB -> g2oxeuzo0r [ 96 ] ) < _rtB ->
l4gv1h4w24 ) && ( muDoubleScalarAbs ( _rtP -> P_141 * _rtB -> g2oxeuzo0r [ 97
] ) < _rtB -> kayx5icfrq ) ) ; rtPrevAction = _rtDW -> iczwe02roz ; if (
ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T ) ! ( _rtB -> jt2c0fz5cf >
0.0 ) ; _rtDW -> iczwe02roz = rtAction ; } else { rtAction = _rtDW ->
iczwe02roz ; } if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) {
case 0 : evsykqyxrn ( S ) ; break ; case 1 : ssSetSolverNeedsReset ( S ) ;
break ; } } switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) {
gwv3tbs0q4 ( S ) ; } nrfrkljgb4 ( S , _rtB -> g2oxeuzo0r [ 96 ] , _rtB ->
g2oxeuzo0r [ 97 ] , _rtB -> g2oxeuzo0r [ 98 ] , _rtB -> g2oxeuzo0r [ 101 ] ,
& _rtB -> g2oxeuzo0r [ 85 ] , _rtB -> g2oxeuzo0r [ 94 ] , _rtB -> g2oxeuzo0r
[ 95 ] , _rtB -> g2oxeuzo0r [ 99 ] , _rtB -> g2oxeuzo0r [ 100 ] , & _rtB ->
c2smzgk22s [ 0 ] , & _rtB -> c2smzgk22s [ 3 ] , & _rtB -> c2smzgk22s [ 6 ] ,
& _rtB -> c2smzgk22s [ 9 ] , & _rtB -> c2smzgk22s [ 10 ] , & _rtB ->
c2smzgk22s [ 11 ] , & _rtB -> fwourmp1ch , & _rtDW -> fwourmp1ch , (
myg1st0tfa * ) & _rtP -> fwourmp1ch ) ; if ( ssIsMajorTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> fwourmp1ch . et1cogum3m ) ; } break ; case 1 : if (
rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart ( S
) ) { ssSetSolverNeedsReset ( S ) ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
memcpy ( & _rtB -> c2smzgk22s [ 0 ] , & _rtP -> P_3 [ 0 ] , 12U * sizeof (
real_T ) ) ; } if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
eim4ekbp5t ) ; } break ; } _rtB -> iiumtm4y4u [ 0 ] = _rtB -> jt2c0fz5cf *
_rtB -> fwourmp1ch . oa2veixczc ; _rtB -> iiumtm4y4u [ 1 ] = _rtB ->
jt2c0fz5cf * _rtB -> fwourmp1ch . fevfwm0ave [ 0 ] ; _rtB -> iiumtm4y4u [ 2 ]
= _rtB -> jt2c0fz5cf * _rtB -> fwourmp1ch . fevfwm0ave [ 1 ] ; _rtB ->
iiumtm4y4u [ 3 ] = _rtB -> jt2c0fz5cf * _rtB -> fwourmp1ch . fevfwm0ave [ 2 ]
; _rtB -> iiumtm4y4u [ 4 ] = _rtB -> jt2c0fz5cf * _rtB -> fwourmp1ch .
lbahd1zvro ; _rtB -> iiumtm4y4u [ 5 ] = _rtB -> jt2c0fz5cf * _rtB ->
fwourmp1ch . a1uff23gp2 ; _rtB -> iiumtm4y4u [ 6 ] = _rtB -> jt2c0fz5cf *
_rtB -> fwourmp1ch . biw0uvoced ; _rtB -> iiumtm4y4u [ 7 ] = _rtB ->
jt2c0fz5cf * _rtB -> fwourmp1ch . hum5y5u3fc ; if ( ssIsSampleHit ( S , 1 , 0
) ) { iw24a5fhro [ 0 ] = _rtB -> mh5bayccp0 [ 0 ] ; iw24a5fhro [ 1 ] = _rtB
-> chmogmkvly [ 0 ] ; iw24a5fhro [ 2 ] = _rtB -> gvgcuwwh1h [ 0 ] ;
iw24a5fhro [ 3 ] = _rtB -> iiumtm4y4u [ 0 ] ; { if ( _rtDW -> aub1oi20ec .
AQHandles ) { sdiWriteSignal ( _rtDW -> aub1oi20ec . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( void * ) & iw24a5fhro [ 0 ] ) ; } } } _rtB ->
lxfit3mg4t [ 0 ] = _rtB -> mh5bayccp0 [ 0 ] ; _rtB -> lxfit3mg4t [ 1 ] = _rtB
-> chmogmkvly [ 0 ] ; _rtB -> lxfit3mg4t [ 2 ] = _rtB -> gvgcuwwh1h [ 0 ] ;
_rtB -> lxfit3mg4t [ 3 ] = _rtB -> iiumtm4y4u [ 0 ] ; ssCallAccelRunBlock ( S
, 28 , 300 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 28 , 301 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { iw24a5fhro [ 0 ]
= _rtB -> mh5bayccp0 [ 2 ] ; iw24a5fhro [ 1 ] = _rtB -> chmogmkvly [ 2 ] ;
iw24a5fhro [ 2 ] = _rtB -> gvgcuwwh1h [ 2 ] ; iw24a5fhro [ 3 ] = _rtB ->
iiumtm4y4u [ 2 ] ; { if ( _rtDW -> ca0ieglkxf . AQHandles ) { sdiWriteSignal
( _rtDW -> ca0ieglkxf . AQHandles , ssGetTaskTime ( S , 1 ) , ( void * ) &
iw24a5fhro [ 0 ] ) ; } } } _rtB -> lxfit3mg4t [ 0 ] = _rtB -> mh5bayccp0 [ 2
] ; _rtB -> lxfit3mg4t [ 1 ] = _rtB -> chmogmkvly [ 2 ] ; _rtB -> lxfit3mg4t
[ 2 ] = _rtB -> gvgcuwwh1h [ 2 ] ; _rtB -> lxfit3mg4t [ 3 ] = _rtB ->
iiumtm4y4u [ 2 ] ; ssCallAccelRunBlock ( S , 28 , 305 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 28 , 306 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { { if ( _rtDW -> fw23bj3wur . AQHandles ) {
sdiWriteSignal ( _rtDW -> fw23bj3wur . AQHandles , ssGetTaskTime ( S , 1 ) ,
( void * ) & _rtB -> g2oxeuzo0r [ 28 ] ) ; } } } ssCallAccelRunBlock ( S , 28
, 308 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 28 , 309 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> ko23keii2h = ( _rtB -> g2oxeuzo0r [ 30 ] <
0.5 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) && ( _rtB -> ko23keii2h != 0.0 ) ) {
ssSetStopRequested ( S , 1 ) ; } _rtB -> a4kablj5zf = ( _rtB -> g2oxeuzo0r [
30 ] > 1.1 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) && ( _rtB -> a4kablj5zf !=
0.0 ) ) { ssSetStopRequested ( S , 1 ) ; } ssCallAccelRunBlock ( S , 28 , 323
, SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 28 , 324 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 28 , 325 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> pmhifjwn2o = _rtP -> P_143 * _rtB ->
kqi21egmuf ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB -> kqi21egmuf > _rtP
-> P_145 ) { _rtDW -> grwtmqz0wm = 1 ; } else if ( _rtB -> kqi21egmuf >= _rtP
-> P_144 ) { _rtDW -> grwtmqz0wm = 0 ; } else { _rtDW -> grwtmqz0wm = - 1 ; }
} if ( _rtDW -> grwtmqz0wm == 1 ) { _rtB -> blsuevmlcn = _rtB -> kqi21egmuf -
_rtP -> P_145 ; } else if ( _rtDW -> grwtmqz0wm == - 1 ) { _rtB -> blsuevmlcn
= _rtB -> kqi21egmuf - _rtP -> P_144 ; } else { _rtB -> blsuevmlcn = 0.0 ; }
_rtB -> h0oizzq4os = _rtP -> P_146 * _rtB -> jgygd4vgjf ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> d4be5a0b23 = (
_rtB -> pmhifjwn2o != _rtB -> blsuevmlcn ) ; } bhdoohci1d = _rtDW ->
d4be5a0b23 ; if ( _rtB -> blsuevmlcn > 0.0 ) { _rtDW -> bhrsd3gntt = 1 ; }
else if ( _rtB -> blsuevmlcn < 0.0 ) { _rtDW -> bhrsd3gntt = - 1 ; } else {
_rtDW -> bhrsd3gntt = 0 ; } tmp = _rtDW -> bhrsd3gntt ; if ( _rtDW ->
bhrsd3gntt > 127 ) { tmp = 127 ; } else { if ( _rtDW -> bhrsd3gntt < - 128 )
{ tmp = - 128 ; } } fytpxckdu1 = ( int8_T ) tmp ; if ( _rtB -> h0oizzq4os >
0.0 ) { _rtDW -> at1533irpq = 1 ; } else if ( _rtB -> h0oizzq4os < 0.0 ) {
_rtDW -> at1533irpq = - 1 ; } else { _rtDW -> at1533irpq = 0 ; } _rtB ->
cknc5won5n = ( bhdoohci1d && ( fytpxckdu1 == ( int8_T ) _rtDW -> at1533irpq )
) ; _rtB -> pmhqycf4dm = _rtDW -> ajz0u54jsm ; } if ( _rtB -> pmhqycf4dm ) {
_rtB -> c0je32umso = 0.0 ; } else { _rtB -> c0je32umso = _rtB -> h0oizzq4os ;
} _rtB -> ljfg0mbcvv = _rtP -> P_148 * _rtB -> hqnpewltuj ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtB -> hqnpewltuj > _rtP -> P_150 ) { _rtDW
-> jfeuldmax0 = 1 ; } else if ( _rtB -> hqnpewltuj >= _rtP -> P_149 ) { _rtDW
-> jfeuldmax0 = 0 ; } else { _rtDW -> jfeuldmax0 = - 1 ; } } if ( _rtDW ->
jfeuldmax0 == 1 ) { _rtB -> dmt0x5ciax = _rtB -> hqnpewltuj - _rtP -> P_150 ;
} else if ( _rtDW -> jfeuldmax0 == - 1 ) { _rtB -> dmt0x5ciax = _rtB ->
hqnpewltuj - _rtP -> P_149 ; } else { _rtB -> dmt0x5ciax = 0.0 ; } _rtB ->
oewy2hp03d = _rtP -> P_151 * _rtB -> e01mzhagag [ 1 ] ; if ( ssIsSampleHit (
S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> n50kvxiuw0 = ( _rtB
-> ljfg0mbcvv != _rtB -> dmt0x5ciax ) ; } k1j10hrmp1 = _rtDW -> n50kvxiuw0 ;
if ( _rtB -> dmt0x5ciax > 0.0 ) { _rtDW -> is14ye2vfo = 1 ; } else if ( _rtB
-> dmt0x5ciax < 0.0 ) { _rtDW -> is14ye2vfo = - 1 ; } else { _rtDW ->
is14ye2vfo = 0 ; } tmp = _rtDW -> is14ye2vfo ; if ( _rtDW -> is14ye2vfo > 127
) { tmp = 127 ; } else { if ( _rtDW -> is14ye2vfo < - 128 ) { tmp = - 128 ; }
} aj0oydudzg = ( int8_T ) tmp ; if ( _rtB -> oewy2hp03d > 0.0 ) { _rtDW ->
dohpzh3s4t = 1 ; } else if ( _rtB -> oewy2hp03d < 0.0 ) { _rtDW -> dohpzh3s4t
= - 1 ; } else { _rtDW -> dohpzh3s4t = 0 ; } _rtB -> chweuqwv45 = (
k1j10hrmp1 && ( aj0oydudzg == ( int8_T ) _rtDW -> dohpzh3s4t ) ) ; _rtB ->
mc0202u5fd = _rtDW -> ebzl2ofgoe ; } if ( _rtB -> mc0202u5fd ) { _rtB ->
h105ogxueu = 0.0 ; } else { _rtB -> h105ogxueu = _rtB -> oewy2hp03d ; }
ssCallAccelRunBlock ( S , 28 , 352 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 28 , 353 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 28 , 354 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
npunsrv4vt = _rtP -> P_153 * _rtB -> m4nk3qn5jz ; if ( ssIsMajorTimeStep ( S
) ) { if ( _rtB -> m4nk3qn5jz > _rtP -> P_155 ) { _rtDW -> okmk4eudw4 = 1 ; }
else if ( _rtB -> m4nk3qn5jz >= _rtP -> P_154 ) { _rtDW -> okmk4eudw4 = 0 ; }
else { _rtDW -> okmk4eudw4 = - 1 ; } } if ( _rtDW -> okmk4eudw4 == 1 ) { _rtB
-> cwdv4kxqla = _rtB -> m4nk3qn5jz - _rtP -> P_155 ; } else if ( _rtDW ->
okmk4eudw4 == - 1 ) { _rtB -> cwdv4kxqla = _rtB -> m4nk3qn5jz - _rtP -> P_154
; } else { _rtB -> cwdv4kxqla = 0.0 ; } _rtB -> m0sbzxsqet = _rtP -> P_156 *
_rtB -> mq2bvv1fib ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> luj0y4uur5 = ( _rtB -> npunsrv4vt !=
_rtB -> cwdv4kxqla ) ; } h5ywwldble = _rtDW -> luj0y4uur5 ; if ( _rtB ->
cwdv4kxqla > 0.0 ) { _rtDW -> exz4lrhvpb = 1 ; } else if ( _rtB -> cwdv4kxqla
< 0.0 ) { _rtDW -> exz4lrhvpb = - 1 ; } else { _rtDW -> exz4lrhvpb = 0 ; }
tmp = _rtDW -> exz4lrhvpb ; if ( _rtDW -> exz4lrhvpb > 127 ) { tmp = 127 ; }
else { if ( _rtDW -> exz4lrhvpb < - 128 ) { tmp = - 128 ; } } nxwxeu4gdx = (
int8_T ) tmp ; if ( _rtB -> m0sbzxsqet > 0.0 ) { _rtDW -> fdirchlazg = 1 ; }
else if ( _rtB -> m0sbzxsqet < 0.0 ) { _rtDW -> fdirchlazg = - 1 ; } else {
_rtDW -> fdirchlazg = 0 ; } _rtB -> g3yiuxbunj = ( h5ywwldble && ( nxwxeu4gdx
== ( int8_T ) _rtDW -> fdirchlazg ) ) ; _rtB -> f5vxtu0wks = _rtDW ->
lezbx3zwvh ; } if ( _rtB -> f5vxtu0wks ) { _rtB -> jqibdnglg4 = 0.0 ; } else
{ _rtB -> jqibdnglg4 = _rtB -> m0sbzxsqet ; } _rtB -> e4bet41oob = _rtP ->
P_158 * _rtB -> osksjb1cuc ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB ->
osksjb1cuc > _rtP -> P_160 ) { _rtDW -> bpzrdeg2la = 1 ; } else if ( _rtB ->
osksjb1cuc >= _rtP -> P_159 ) { _rtDW -> bpzrdeg2la = 0 ; } else { _rtDW ->
bpzrdeg2la = - 1 ; } } if ( _rtDW -> bpzrdeg2la == 1 ) { _rtB -> cotooafzk4 =
_rtB -> osksjb1cuc - _rtP -> P_160 ; } else if ( _rtDW -> bpzrdeg2la == - 1 )
{ _rtB -> cotooafzk4 = _rtB -> osksjb1cuc - _rtP -> P_159 ; } else { _rtB ->
cotooafzk4 = 0.0 ; } _rtB -> bjuskw14gm = _rtP -> P_161 * _rtB -> npavplmseb
[ 1 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> gxn4epbxov = ( _rtB -> e4bet41oob != _rtB -> cotooafzk4 ) ; }
aqyocmx4fn = _rtDW -> gxn4epbxov ; if ( _rtB -> cotooafzk4 > 0.0 ) { _rtDW ->
nu5jq1u4eo = 1 ; } else if ( _rtB -> cotooafzk4 < 0.0 ) { _rtDW -> nu5jq1u4eo
= - 1 ; } else { _rtDW -> nu5jq1u4eo = 0 ; } tmp = _rtDW -> nu5jq1u4eo ; if (
_rtDW -> nu5jq1u4eo > 127 ) { tmp = 127 ; } else { if ( _rtDW -> nu5jq1u4eo <
- 128 ) { tmp = - 128 ; } } bmj2qwivwl = ( int8_T ) tmp ; if ( _rtB ->
bjuskw14gm > 0.0 ) { _rtDW -> oollz50owm = 1 ; } else if ( _rtB -> bjuskw14gm
< 0.0 ) { _rtDW -> oollz50owm = - 1 ; } else { _rtDW -> oollz50owm = 0 ; }
_rtB -> enfkjlu4o2 = ( aqyocmx4fn && ( bmj2qwivwl == ( int8_T ) _rtDW ->
oollz50owm ) ) ; _rtB -> nqeq3wc0od = _rtDW -> dze3loidd5 ; } if ( _rtB ->
nqeq3wc0od ) { _rtB -> f1sryrcxt4 = 0.0 ; } else { _rtB -> f1sryrcxt4 = _rtB
-> bjuskw14gm ; } ssCallAccelRunBlock ( S , 28 , 381 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 28 , 382 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 28 , 383 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
i1vxjab5q2 = _rtP -> P_163 * _rtB -> f04zp5o0lg ; if ( ssIsMajorTimeStep ( S
) ) { if ( _rtB -> f04zp5o0lg > _rtP -> P_165 ) { _rtDW -> aprxbajbou = 1 ; }
else if ( _rtB -> f04zp5o0lg >= _rtP -> P_164 ) { _rtDW -> aprxbajbou = 0 ; }
else { _rtDW -> aprxbajbou = - 1 ; } } if ( _rtDW -> aprxbajbou == 1 ) { _rtB
-> b5rwap1dnf = _rtB -> f04zp5o0lg - _rtP -> P_165 ; } else if ( _rtDW ->
aprxbajbou == - 1 ) { _rtB -> b5rwap1dnf = _rtB -> f04zp5o0lg - _rtP -> P_164
; } else { _rtB -> b5rwap1dnf = 0.0 ; } _rtB -> objuqcchzk = _rtP -> P_166 *
_rtB -> bm2z2jstbd ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> c1mbcu4lwp = ( _rtB -> i1vxjab5q2 !=
_rtB -> b5rwap1dnf ) ; } prctt2ewb5 = _rtDW -> c1mbcu4lwp ; if ( _rtB ->
b5rwap1dnf > 0.0 ) { _rtDW -> johr34i1r2 = 1 ; } else if ( _rtB -> b5rwap1dnf
< 0.0 ) { _rtDW -> johr34i1r2 = - 1 ; } else { _rtDW -> johr34i1r2 = 0 ; }
tmp = _rtDW -> johr34i1r2 ; if ( _rtDW -> johr34i1r2 > 127 ) { tmp = 127 ; }
else { if ( _rtDW -> johr34i1r2 < - 128 ) { tmp = - 128 ; } } fx1shjs25a = (
int8_T ) tmp ; if ( _rtB -> objuqcchzk > 0.0 ) { _rtDW -> asvdo2jane = 1 ; }
else if ( _rtB -> objuqcchzk < 0.0 ) { _rtDW -> asvdo2jane = - 1 ; } else {
_rtDW -> asvdo2jane = 0 ; } _rtB -> pbw1ootozw = ( prctt2ewb5 && ( fx1shjs25a
== ( int8_T ) _rtDW -> asvdo2jane ) ) ; _rtB -> jxn5uc0yp4 = _rtDW ->
me5mg5rwwa ; } if ( _rtB -> jxn5uc0yp4 ) { _rtB -> m4hod2sssc = 0.0 ; } else
{ _rtB -> m4hod2sssc = _rtB -> objuqcchzk ; } _rtB -> nkxbwokvpb = _rtP ->
P_168 * _rtB -> iqxqfzwt1t ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB ->
iqxqfzwt1t > _rtP -> P_170 ) { _rtDW -> cl0n2gqxt1 = 1 ; } else if ( _rtB ->
iqxqfzwt1t >= _rtP -> P_169 ) { _rtDW -> cl0n2gqxt1 = 0 ; } else { _rtDW ->
cl0n2gqxt1 = - 1 ; } } if ( _rtDW -> cl0n2gqxt1 == 1 ) { _rtB -> dlbqkeuixo =
_rtB -> iqxqfzwt1t - _rtP -> P_170 ; } else if ( _rtDW -> cl0n2gqxt1 == - 1 )
{ _rtB -> dlbqkeuixo = _rtB -> iqxqfzwt1t - _rtP -> P_169 ; } else { _rtB ->
dlbqkeuixo = 0.0 ; } _rtB -> lzmaxcpr13 = _rtP -> P_171 * _rtB -> jsldrpofzn
[ 1 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> frox2wk5yh = ( _rtB -> nkxbwokvpb != _rtB -> dlbqkeuixo ) ; }
em3luynxhv = _rtDW -> frox2wk5yh ; if ( _rtB -> dlbqkeuixo > 0.0 ) { _rtDW ->
ajsouqlijh = 1 ; } else if ( _rtB -> dlbqkeuixo < 0.0 ) { _rtDW -> ajsouqlijh
= - 1 ; } else { _rtDW -> ajsouqlijh = 0 ; } tmp = _rtDW -> ajsouqlijh ; if (
_rtDW -> ajsouqlijh > 127 ) { tmp = 127 ; } else { if ( _rtDW -> ajsouqlijh <
- 128 ) { tmp = - 128 ; } } oit4ht2aqi = ( int8_T ) tmp ; if ( _rtB ->
lzmaxcpr13 > 0.0 ) { _rtDW -> n2kvek13hp = 1 ; } else if ( _rtB -> lzmaxcpr13
< 0.0 ) { _rtDW -> n2kvek13hp = - 1 ; } else { _rtDW -> n2kvek13hp = 0 ; }
_rtB -> cguvi3wh3u = ( em3luynxhv && ( oit4ht2aqi == ( int8_T ) _rtDW ->
n2kvek13hp ) ) ; _rtB -> jgkd5ny3tu = _rtDW -> jyaxtcifce ; } if ( _rtB ->
jgkd5ny3tu ) { _rtB -> ozk0ymxppc = 0.0 ; } else { _rtB -> ozk0ymxppc = _rtB
-> lzmaxcpr13 ; } ssCallAccelRunBlock ( S , 28 , 410 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 28 , 411 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 28 , 412 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
jr2f1yqfth = _rtP -> P_173 * _rtB -> fzuymbvivo ; if ( ssIsMajorTimeStep ( S
) ) { if ( _rtB -> fzuymbvivo > _rtP -> P_175 ) { _rtDW -> irfyp5iv1i = 1 ; }
else if ( _rtB -> fzuymbvivo >= _rtP -> P_174 ) { _rtDW -> irfyp5iv1i = 0 ; }
else { _rtDW -> irfyp5iv1i = - 1 ; } } if ( _rtDW -> irfyp5iv1i == 1 ) { _rtB
-> cnifyxtjkl = _rtB -> fzuymbvivo - _rtP -> P_175 ; } else if ( _rtDW ->
irfyp5iv1i == - 1 ) { _rtB -> cnifyxtjkl = _rtB -> fzuymbvivo - _rtP -> P_174
; } else { _rtB -> cnifyxtjkl = 0.0 ; } _rtB -> cngdrskut4 = _rtP -> P_176 *
_rtB -> dk5kj1yocg ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> nasgp5ufoz = ( _rtB -> jr2f1yqfth !=
_rtB -> cnifyxtjkl ) ; } atxky2vcsj = _rtDW -> nasgp5ufoz ; if ( _rtB ->
cnifyxtjkl > 0.0 ) { _rtDW -> b5uhfcemh3 = 1 ; } else if ( _rtB -> cnifyxtjkl
< 0.0 ) { _rtDW -> b5uhfcemh3 = - 1 ; } else { _rtDW -> b5uhfcemh3 = 0 ; }
tmp = _rtDW -> b5uhfcemh3 ; if ( _rtDW -> b5uhfcemh3 > 127 ) { tmp = 127 ; }
else { if ( _rtDW -> b5uhfcemh3 < - 128 ) { tmp = - 128 ; } } j4cvrxmjnb = (
int8_T ) tmp ; if ( _rtB -> cngdrskut4 > 0.0 ) { _rtDW -> dqmnvxyd3m = 1 ; }
else if ( _rtB -> cngdrskut4 < 0.0 ) { _rtDW -> dqmnvxyd3m = - 1 ; } else {
_rtDW -> dqmnvxyd3m = 0 ; } _rtB -> pkjgnxh5jz = ( atxky2vcsj && ( j4cvrxmjnb
== ( int8_T ) _rtDW -> dqmnvxyd3m ) ) ; _rtB -> hv0rrqiiib = _rtDW ->
jxpey1i4yn ; } if ( _rtB -> hv0rrqiiib ) { _rtB -> grsge4ey2c = 0.0 ; } else
{ _rtB -> grsge4ey2c = _rtB -> cngdrskut4 ; } _rtB -> csckzaxojd = _rtP ->
P_178 * _rtB -> pyb2whaz1q ; if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB ->
pyb2whaz1q > _rtP -> P_180 ) { _rtDW -> lzhmcr5iqk = 1 ; } else if ( _rtB ->
pyb2whaz1q >= _rtP -> P_179 ) { _rtDW -> lzhmcr5iqk = 0 ; } else { _rtDW ->
lzhmcr5iqk = - 1 ; } } if ( _rtDW -> lzhmcr5iqk == 1 ) { _rtB -> csp31kbg3k =
_rtB -> pyb2whaz1q - _rtP -> P_180 ; } else if ( _rtDW -> lzhmcr5iqk == - 1 )
{ _rtB -> csp31kbg3k = _rtB -> pyb2whaz1q - _rtP -> P_179 ; } else { _rtB ->
csp31kbg3k = 0.0 ; } _rtB -> ll0xvtqlfe = _rtP -> P_181 * _rtB -> bkxp04saya
[ 1 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> hkelelukjc = ( _rtB -> csckzaxojd != _rtB -> csp31kbg3k ) ; }
aar4d3t5v3 = _rtDW -> hkelelukjc ; if ( _rtB -> csp31kbg3k > 0.0 ) { _rtDW ->
bwqg5oulf0 = 1 ; } else if ( _rtB -> csp31kbg3k < 0.0 ) { _rtDW -> bwqg5oulf0
= - 1 ; } else { _rtDW -> bwqg5oulf0 = 0 ; } tmp = _rtDW -> bwqg5oulf0 ; if (
_rtDW -> bwqg5oulf0 > 127 ) { tmp = 127 ; } else { if ( _rtDW -> bwqg5oulf0 <
- 128 ) { tmp = - 128 ; } } c2ifbtm5rr = ( int8_T ) tmp ; if ( _rtB ->
ll0xvtqlfe > 0.0 ) { _rtDW -> fwranrqztx = 1 ; } else if ( _rtB -> ll0xvtqlfe
< 0.0 ) { _rtDW -> fwranrqztx = - 1 ; } else { _rtDW -> fwranrqztx = 0 ; }
_rtB -> csgo3gnqyq = ( aar4d3t5v3 && ( c2ifbtm5rr == ( int8_T ) _rtDW ->
fwranrqztx ) ) ; _rtB -> aifo2efvxa = _rtDW -> ivhrjyrewc ; } if ( _rtB ->
aifo2efvxa ) { _rtB -> hcyjnnhovz = 0.0 ; } else { _rtB -> hcyjnnhovz = _rtB
-> ll0xvtqlfe ; } _rtB -> b3kon1ysc3 = _rtX -> p0to41lsks ; _rtB ->
mkx145gx4i = _rtP -> P_184 * _rtB -> b3kon1ysc3 ; _rtB -> hxt4qqum02 [ 0 ] =
_rtB -> mkx145gx4i ; _rtB -> hxt4qqum02 [ 1 ] = 0.0 ; _rtB -> hxt4qqum02 [ 2
] = 0.0 ; _rtB -> hxt4qqum02 [ 3 ] = 0.0 ; _rtB -> nnwsquqvoc = _rtX ->
i0eikwwksw ; _rtB -> axc2grjhf3 = _rtP -> P_186 * _rtB -> nnwsquqvoc ; _rtB
-> jktjv3bde5 [ 0 ] = _rtB -> axc2grjhf3 ; _rtB -> jktjv3bde5 [ 1 ] = 0.0 ;
_rtB -> jktjv3bde5 [ 2 ] = 0.0 ; _rtB -> jktjv3bde5 [ 3 ] = 0.0 ; _rtB ->
p2xxn2gv2e = 0.0 ; _rtB -> p2xxn2gv2e += 0.006 * _rtB -> hxt4qqum02 [ 0 ] ;
_rtB -> p2xxn2gv2e += 0.006 * _rtB -> jktjv3bde5 [ 0 ] ; _rtB -> metqrwcpdj [
0 ] = _rtB -> p2xxn2gv2e ; _rtB -> metqrwcpdj [ 1 ] = 0.0 ; _rtB ->
metqrwcpdj [ 2 ] = 0.0 ; _rtB -> metqrwcpdj [ 3 ] = 0.0 ; _rtB -> gln3by4dvn
= _rtX -> jsywnquoot ; _rtB -> i1ie0n4hxn = _rtP -> P_188 * _rtB ->
gln3by4dvn ; _rtB -> prdup54iy0 [ 0 ] = _rtB -> i1ie0n4hxn ; _rtB ->
prdup54iy0 [ 1 ] = 0.0 ; _rtB -> prdup54iy0 [ 2 ] = 0.0 ; _rtB -> prdup54iy0
[ 3 ] = 0.0 ; _rtB -> po11h4ki1w = _rtX -> mytqqyhqjs ; _rtB -> dlt1hiy53u =
_rtP -> P_190 * _rtB -> po11h4ki1w ; _rtB -> m1nkfitelf [ 0 ] = _rtB ->
dlt1hiy53u ; _rtB -> m1nkfitelf [ 1 ] = 0.0 ; _rtB -> m1nkfitelf [ 2 ] = 0.0
; _rtB -> m1nkfitelf [ 3 ] = 0.0 ; _rtB -> myp4o4c3yb = 0.0 ; _rtB ->
myp4o4c3yb += 0.006 * _rtB -> prdup54iy0 [ 0 ] ; _rtB -> myp4o4c3yb += 0.006
* _rtB -> m1nkfitelf [ 0 ] ; _rtB -> dv3jchvo5s [ 0 ] = _rtB -> myp4o4c3yb ;
_rtB -> dv3jchvo5s [ 1 ] = 0.0 ; _rtB -> dv3jchvo5s [ 2 ] = 0.0 ; _rtB ->
dv3jchvo5s [ 3 ] = 0.0 ; _rtB -> c1fhgdgph1 = _rtX -> lfw4k0qpar ; _rtB ->
p3svxaeu2v = _rtP -> P_192 * _rtB -> c1fhgdgph1 ; _rtB -> fdgrx1tnox [ 0 ] =
_rtB -> p3svxaeu2v ; _rtB -> fdgrx1tnox [ 1 ] = 0.0 ; _rtB -> fdgrx1tnox [ 2
] = 0.0 ; _rtB -> fdgrx1tnox [ 3 ] = 0.0 ; _rtB -> ecmekl2ztp = _rtX ->
db4tnlyipx ; _rtB -> pqrezee1ex = _rtP -> P_194 * _rtB -> ecmekl2ztp ; _rtB
-> e4fkogy5hr [ 0 ] = _rtB -> pqrezee1ex ; _rtB -> e4fkogy5hr [ 1 ] = 0.0 ;
_rtB -> e4fkogy5hr [ 2 ] = 0.0 ; _rtB -> e4fkogy5hr [ 3 ] = 0.0 ; _rtB ->
m0urjkmrjb = 0.0 ; _rtB -> m0urjkmrjb += 0.006 * _rtB -> fdgrx1tnox [ 0 ] ;
_rtB -> m0urjkmrjb += 0.006 * _rtB -> e4fkogy5hr [ 0 ] ; _rtB -> nuxexihwle [
0 ] = _rtB -> m0urjkmrjb ; _rtB -> nuxexihwle [ 1 ] = 0.0 ; _rtB ->
nuxexihwle [ 2 ] = 0.0 ; _rtB -> nuxexihwle [ 3 ] = 0.0 ; _rtB -> ni1ub1whbe
= _rtX -> p2jdm4a0dt ; _rtB -> idx0f0tpft = _rtP -> P_196 * _rtB ->
ni1ub1whbe ; _rtB -> namq10acwr [ 0 ] = _rtB -> idx0f0tpft ; _rtB ->
namq10acwr [ 1 ] = 0.0 ; _rtB -> namq10acwr [ 2 ] = 0.0 ; _rtB -> namq10acwr
[ 3 ] = 0.0 ; _rtB -> bykhzjpkhu = _rtX -> dyocza0fhh ; _rtB -> boig44tbgk =
_rtP -> P_198 * _rtB -> bykhzjpkhu ; _rtB -> gmms3ojzcm [ 0 ] = _rtB ->
boig44tbgk ; _rtB -> gmms3ojzcm [ 1 ] = 0.0 ; _rtB -> gmms3ojzcm [ 2 ] = 0.0
; _rtB -> gmms3ojzcm [ 3 ] = 0.0 ; _rtB -> imwdedxldq = 0.0 ; _rtB ->
imwdedxldq += 0.006 * _rtB -> namq10acwr [ 0 ] ; _rtB -> imwdedxldq += 0.006
* _rtB -> gmms3ojzcm [ 0 ] ; _rtB -> cv5jr1pg4l [ 0 ] = _rtB -> imwdedxldq ;
_rtB -> cv5jr1pg4l [ 1 ] = 0.0 ; _rtB -> cv5jr1pg4l [ 2 ] = 0.0 ; _rtB ->
cv5jr1pg4l [ 3 ] = 0.0 ; _rtB -> lo0h0uwdy2 = _rtX -> ojez0qcspo ; _rtB ->
ki01gqo503 = _rtP -> P_200 * _rtB -> lo0h0uwdy2 ; _rtB -> b02nxzrtst [ 0 ] =
_rtB -> ki01gqo503 ; _rtB -> b02nxzrtst [ 1 ] = 0.0 ; _rtB -> b02nxzrtst [ 2
] = 0.0 ; _rtB -> b02nxzrtst [ 3 ] = 0.0 ; _rtB -> ddy15ma2vh = _rtX ->
m1bdar3z5x ; _rtB -> at1ccozb5c = _rtP -> P_202 * _rtB -> ddy15ma2vh ; _rtB
-> n2zcbd3c2w [ 0 ] = _rtB -> at1ccozb5c ; _rtB -> n2zcbd3c2w [ 1 ] = 0.0 ;
_rtB -> n2zcbd3c2w [ 2 ] = 0.0 ; _rtB -> n2zcbd3c2w [ 3 ] = 0.0 ; _rtB ->
jyiorqknrn = 0.0 ; _rtB -> jyiorqknrn += 0.006 * _rtB -> b02nxzrtst [ 0 ] ;
_rtB -> jyiorqknrn += 0.006 * _rtB -> n2zcbd3c2w [ 0 ] ; _rtB -> oxe3d2rrnd [
0 ] = _rtB -> jyiorqknrn ; _rtB -> oxe3d2rrnd [ 1 ] = 0.0 ; _rtB ->
oxe3d2rrnd [ 2 ] = 0.0 ; _rtB -> oxe3d2rrnd [ 3 ] = 0.0 ; _rtB -> hzao3v02wk
= _rtX -> eyft05yr34 ; _rtB -> il53rgtmz5 = _rtP -> P_204 * _rtB ->
hzao3v02wk ; _rtB -> bnsyuc3a5n [ 0 ] = _rtB -> il53rgtmz5 ; _rtB ->
bnsyuc3a5n [ 1 ] = 0.0 ; _rtB -> bnsyuc3a5n [ 2 ] = 0.0 ; _rtB -> bnsyuc3a5n
[ 3 ] = 0.0 ; _rtB -> mgktk0wnrw = _rtX -> e5wvrueztz ; _rtB -> oplrad3nny =
_rtP -> P_206 * _rtB -> mgktk0wnrw ; _rtB -> mttdook1q4 [ 0 ] = _rtB ->
oplrad3nny ; _rtB -> mttdook1q4 [ 1 ] = 0.0 ; _rtB -> mttdook1q4 [ 2 ] = 0.0
; _rtB -> mttdook1q4 [ 3 ] = 0.0 ; _rtB -> ia5soextlo = 0.0 ; _rtB ->
ia5soextlo += 0.006 * _rtB -> bnsyuc3a5n [ 0 ] ; _rtB -> ia5soextlo += 0.006
* _rtB -> mttdook1q4 [ 0 ] ; _rtB -> nqvkckfsd3 [ 0 ] = _rtB -> ia5soextlo ;
_rtB -> nqvkckfsd3 [ 1 ] = 0.0 ; _rtB -> nqvkckfsd3 [ 2 ] = 0.0 ; _rtB ->
nqvkckfsd3 [ 3 ] = 0.0 ; _rtB -> omhws2aayu = _rtX -> aro51uuwra ; _rtB ->
dpbtrt2nal = _rtP -> P_208 * _rtB -> omhws2aayu ; _rtB -> n5zr5a3kth [ 0 ] =
_rtB -> dpbtrt2nal ; _rtB -> n5zr5a3kth [ 1 ] = 0.0 ; _rtB -> n5zr5a3kth [ 2
] = 0.0 ; _rtB -> n5zr5a3kth [ 3 ] = 0.0 ; _rtB -> dqizl1yob4 = _rtX ->
fuwg5kqaqs ; _rtB -> md54yy2bxt = _rtP -> P_210 * _rtB -> dqizl1yob4 ; _rtB
-> opx51mais1 [ 0 ] = _rtB -> md54yy2bxt ; _rtB -> opx51mais1 [ 1 ] = 0.0 ;
_rtB -> opx51mais1 [ 2 ] = 0.0 ; _rtB -> opx51mais1 [ 3 ] = 0.0 ; _rtB ->
icpvfxfd1x = 0.0 ; _rtB -> icpvfxfd1x += 0.006 * _rtB -> n5zr5a3kth [ 0 ] ;
_rtB -> icpvfxfd1x += 0.006 * _rtB -> opx51mais1 [ 0 ] ; _rtB -> aac2t3bvho [
0 ] = _rtB -> icpvfxfd1x ; _rtB -> aac2t3bvho [ 1 ] = 0.0 ; _rtB ->
aac2t3bvho [ 2 ] = 0.0 ; _rtB -> aac2t3bvho [ 3 ] = 0.0 ; _rtB -> fuxife2xx5
= _rtX -> nztqpvbjju ; _rtB -> jc005m52ez = _rtP -> P_212 * _rtB ->
fuxife2xx5 ; _rtB -> bcw2eigzt0 [ 0 ] = _rtB -> jc005m52ez ; _rtB ->
bcw2eigzt0 [ 1 ] = 0.0 ; _rtB -> bcw2eigzt0 [ 2 ] = 0.0 ; _rtB -> bcw2eigzt0
[ 3 ] = 0.0 ; _rtB -> clsrhj4qiv = _rtX -> de34fxevj1 ; _rtB -> czgnjzn4ns =
_rtP -> P_214 * _rtB -> clsrhj4qiv ; _rtB -> ipxsjx42qn [ 0 ] = _rtB ->
czgnjzn4ns ; _rtB -> ipxsjx42qn [ 1 ] = 0.0 ; _rtB -> ipxsjx42qn [ 2 ] = 0.0
; _rtB -> ipxsjx42qn [ 3 ] = 0.0 ; _rtB -> d5uyuq42j1 = 0.0 ; _rtB ->
d5uyuq42j1 += 0.006 * _rtB -> bcw2eigzt0 [ 0 ] ; _rtB -> d5uyuq42j1 += 0.006
* _rtB -> ipxsjx42qn [ 0 ] ; _rtB -> cecxogiwgl [ 0 ] = _rtB -> d5uyuq42j1 ;
_rtB -> cecxogiwgl [ 1 ] = 0.0 ; _rtB -> cecxogiwgl [ 2 ] = 0.0 ; _rtB ->
cecxogiwgl [ 3 ] = 0.0 ; _rtB -> kef1hnvs2l = _rtX -> owpbcveeep ; _rtB ->
mhjx3knsi4 = _rtP -> P_216 * _rtB -> kef1hnvs2l ; _rtB -> a0r5a3bvod [ 0 ] =
_rtB -> mhjx3knsi4 ; _rtB -> a0r5a3bvod [ 1 ] = 0.0 ; _rtB -> a0r5a3bvod [ 2
] = 0.0 ; _rtB -> a0r5a3bvod [ 3 ] = 0.0 ; _rtB -> jzgf4aluky = _rtX ->
oiv3wlpiv1 ; _rtB -> dg4rqec1ay = _rtP -> P_218 * _rtB -> jzgf4aluky ; _rtB
-> p3b53wrxdh [ 0 ] = _rtB -> dg4rqec1ay ; _rtB -> p3b53wrxdh [ 1 ] = 0.0 ;
_rtB -> p3b53wrxdh [ 2 ] = 0.0 ; _rtB -> p3b53wrxdh [ 3 ] = 0.0 ; _rtB ->
iqkvu0gyga = 0.0 ; _rtB -> iqkvu0gyga += 0.006 * _rtB -> a0r5a3bvod [ 0 ] ;
_rtB -> iqkvu0gyga += 0.006 * _rtB -> p3b53wrxdh [ 0 ] ; _rtB -> c2mpewtcl1 [
0 ] = _rtB -> iqkvu0gyga ; _rtB -> c2mpewtcl1 [ 1 ] = 0.0 ; _rtB ->
c2mpewtcl1 [ 2 ] = 0.0 ; _rtB -> c2mpewtcl1 [ 3 ] = 0.0 ; _rtB -> nr23jllqn4
= _rtX -> f3t0nd3kjl ; _rtB -> d1l5gz5lej = _rtP -> P_220 * _rtB ->
nr23jllqn4 ; _rtB -> beuvvjj5ft [ 0 ] = _rtB -> d1l5gz5lej ; _rtB ->
beuvvjj5ft [ 1 ] = 0.0 ; _rtB -> beuvvjj5ft [ 2 ] = 0.0 ; _rtB -> beuvvjj5ft
[ 3 ] = 0.0 ; _rtB -> fpvdwxrinb = _rtX -> jl4hyit2py ; _rtB -> d3h353cnhv =
_rtP -> P_222 * _rtB -> fpvdwxrinb ; _rtB -> oppx1misqo [ 0 ] = _rtB ->
d3h353cnhv ; _rtB -> oppx1misqo [ 1 ] = 0.0 ; _rtB -> oppx1misqo [ 2 ] = 0.0
; _rtB -> oppx1misqo [ 3 ] = 0.0 ; _rtB -> dikrksah3p = 0.0 ; _rtB ->
dikrksah3p += 0.006 * _rtB -> beuvvjj5ft [ 0 ] ; _rtB -> dikrksah3p += 0.006
* _rtB -> oppx1misqo [ 0 ] ; _rtB -> iuiunel0yh [ 0 ] = _rtB -> dikrksah3p ;
_rtB -> iuiunel0yh [ 1 ] = 0.0 ; _rtB -> iuiunel0yh [ 2 ] = 0.0 ; _rtB ->
iuiunel0yh [ 3 ] = 0.0 ; _rtB -> nvxucltzxk = _rtX -> ldmzoudxil ; _rtB ->
kezumfw412 = _rtP -> P_224 * _rtB -> nvxucltzxk ; _rtB -> pt0d4wbvuu [ 0 ] =
_rtB -> kezumfw412 ; _rtB -> pt0d4wbvuu [ 1 ] = 0.0 ; _rtB -> pt0d4wbvuu [ 2
] = 0.0 ; _rtB -> pt0d4wbvuu [ 3 ] = 0.0 ; _rtB -> anenzo4x2p = _rtX ->
hzzjfqiowf ; _rtB -> gnbrdas2cf = _rtP -> P_226 * _rtB -> anenzo4x2p ; _rtB
-> hibdbxf0hd [ 0 ] = _rtB -> gnbrdas2cf ; _rtB -> hibdbxf0hd [ 1 ] = 0.0 ;
_rtB -> hibdbxf0hd [ 2 ] = 0.0 ; _rtB -> hibdbxf0hd [ 3 ] = 0.0 ; _rtB ->
nnxiamjgm4 = 0.0 ; _rtB -> nnxiamjgm4 += 0.006 * _rtB -> pt0d4wbvuu [ 0 ] ;
_rtB -> nnxiamjgm4 += 0.006 * _rtB -> hibdbxf0hd [ 0 ] ; _rtB -> hq1eqyc3wk [
0 ] = _rtB -> nnxiamjgm4 ; _rtB -> hq1eqyc3wk [ 1 ] = 0.0 ; _rtB ->
hq1eqyc3wk [ 2 ] = 0.0 ; _rtB -> hq1eqyc3wk [ 3 ] = 0.0 ; _rtB -> frsa1g4kga
= _rtX -> cnzg1rfsdu ; _rtB -> ls43quiney = _rtP -> P_228 * _rtB ->
frsa1g4kga ; _rtB -> cyzsesle1l [ 0 ] = _rtB -> ls43quiney ; _rtB ->
cyzsesle1l [ 1 ] = 0.0 ; _rtB -> cyzsesle1l [ 2 ] = 0.0 ; _rtB -> cyzsesle1l
[ 3 ] = 0.0 ; _rtB -> dngvidhaiv = _rtX -> kk0suzgb3o ; _rtB -> gvvlnifink =
_rtP -> P_230 * _rtB -> dngvidhaiv ; _rtB -> j4haqe4lyv [ 0 ] = _rtB ->
gvvlnifink ; _rtB -> j4haqe4lyv [ 1 ] = 0.0 ; _rtB -> j4haqe4lyv [ 2 ] = 0.0
; _rtB -> j4haqe4lyv [ 3 ] = 0.0 ; _rtB -> m3b4pwljr4 = 0.0 ; _rtB ->
m3b4pwljr4 += 0.006 * _rtB -> cyzsesle1l [ 0 ] ; _rtB -> m3b4pwljr4 += 0.006
* _rtB -> j4haqe4lyv [ 0 ] ; _rtB -> beqns5abe5 [ 0 ] = _rtB -> m3b4pwljr4 ;
_rtB -> beqns5abe5 [ 1 ] = 0.0 ; _rtB -> beqns5abe5 [ 2 ] = 0.0 ; _rtB ->
beqns5abe5 [ 3 ] = 0.0 ; _rtB -> gfhx1tvpmz [ 0 ] = _rtB -> mgodjl5ant ; _rtB
-> gfhx1tvpmz [ 1 ] = 0.0 ; _rtB -> gfhx1tvpmz [ 2 ] = 0.0 ; _rtB ->
gfhx1tvpmz [ 3 ] = 0.0 ; _rtB -> hxi5hahkrp [ 0 ] = _rtB -> nmf044e53q ; _rtB
-> hxi5hahkrp [ 1 ] = 0.0 ; _rtB -> hxi5hahkrp [ 2 ] = 0.0 ; _rtB ->
hxi5hahkrp [ 3 ] = 0.0 ; _rtB -> mxavdaw1wj [ 0 ] = _rtB -> n1fw4qveod ; _rtB
-> mxavdaw1wj [ 1 ] = 0.0 ; _rtB -> mxavdaw1wj [ 2 ] = 0.0 ; _rtB ->
mxavdaw1wj [ 3 ] = 0.0 ; _rtB -> kmk0asqpl4 [ 0 ] = _rtB -> ahovkcndla ; _rtB
-> kmk0asqpl4 [ 1 ] = 0.0 ; _rtB -> kmk0asqpl4 [ 2 ] = 0.0 ; _rtB ->
kmk0asqpl4 [ 3 ] = 0.0 ; _rtB -> mycwcesmef [ 0 ] = _rtB -> jpo5nxw1ap ; _rtB
-> mycwcesmef [ 1 ] = 0.0 ; _rtB -> mycwcesmef [ 2 ] = 0.0 ; _rtB ->
mycwcesmef [ 3 ] = 0.0 ; _rtB -> a0c32qnvrq [ 0 ] = _rtB -> aa3lzm1qoo ; _rtB
-> a0c32qnvrq [ 1 ] = 0.0 ; _rtB -> a0c32qnvrq [ 2 ] = 0.0 ; _rtB ->
a0c32qnvrq [ 3 ] = 0.0 ; _rtB -> pjefn4hlzl [ 0 ] = _rtB -> cxyjcf5uqw ; _rtB
-> pjefn4hlzl [ 1 ] = 0.0 ; _rtB -> pjefn4hlzl [ 2 ] = 0.0 ; _rtB ->
pjefn4hlzl [ 3 ] = 0.0 ; _rtB -> noglugs02p [ 0 ] = _rtB -> n42cgxjwpd ; _rtB
-> noglugs02p [ 1 ] = 0.0 ; _rtB -> noglugs02p [ 2 ] = 0.0 ; _rtB ->
noglugs02p [ 3 ] = 0.0 ; _rtB -> cjilh0rs5i [ 0 ] = _rtB -> f3yexps0ss [ 6 ]
; _rtB -> cjilh0rs5i [ 1 ] = 0.0 ; _rtB -> cjilh0rs5i [ 2 ] = 0.0 ; _rtB ->
cjilh0rs5i [ 3 ] = 0.0 ; _rtB -> bv2ipmoxr1 [ 0 ] = _rtB -> f3yexps0ss [ 7 ]
; _rtB -> bv2ipmoxr1 [ 1 ] = 0.0 ; _rtB -> bv2ipmoxr1 [ 2 ] = 0.0 ; _rtB ->
bv2ipmoxr1 [ 3 ] = 0.0 ; _rtB -> ifnszbh34e [ 0 ] = _rtB -> f3yexps0ss [ 8 ]
; _rtB -> ifnszbh34e [ 1 ] = 0.0 ; _rtB -> ifnszbh34e [ 2 ] = 0.0 ; _rtB ->
ifnszbh34e [ 3 ] = 0.0 ; _rtB -> byia45qyuw [ 0 ] = _rtB -> f3yexps0ss [ 9 ]
; _rtB -> byia45qyuw [ 1 ] = 0.0 ; _rtB -> byia45qyuw [ 2 ] = 0.0 ; _rtB ->
byia45qyuw [ 3 ] = 0.0 ; _rtB -> ksgjd1skt4 [ 0 ] = _rtB -> f3yexps0ss [ 10 ]
; _rtB -> ksgjd1skt4 [ 1 ] = 0.0 ; _rtB -> ksgjd1skt4 [ 2 ] = 0.0 ; _rtB ->
ksgjd1skt4 [ 3 ] = 0.0 ; _rtB -> krs50zmp2u [ 0 ] = _rtB -> f3yexps0ss [ 11 ]
; _rtB -> krs50zmp2u [ 1 ] = 0.0 ; _rtB -> krs50zmp2u [ 2 ] = 0.0 ; _rtB ->
krs50zmp2u [ 3 ] = 0.0 ; _rtB -> dvuv0v2ukg [ 0 ] = _rtB -> f3yexps0ss [ 0 ]
; _rtB -> dvuv0v2ukg [ 1 ] = 0.0 ; _rtB -> dvuv0v2ukg [ 2 ] = 0.0 ; _rtB ->
dvuv0v2ukg [ 3 ] = 0.0 ; _rtB -> pqakztvdrf [ 0 ] = _rtB -> f3yexps0ss [ 1 ]
; _rtB -> pqakztvdrf [ 1 ] = 0.0 ; _rtB -> pqakztvdrf [ 2 ] = 0.0 ; _rtB ->
pqakztvdrf [ 3 ] = 0.0 ; _rtB -> ndvmjhzmax [ 0 ] = _rtB -> f3yexps0ss [ 2 ]
; _rtB -> ndvmjhzmax [ 1 ] = 0.0 ; _rtB -> ndvmjhzmax [ 2 ] = 0.0 ; _rtB ->
ndvmjhzmax [ 3 ] = 0.0 ; _rtB -> kuinsnuoqq [ 0 ] = _rtB -> f3yexps0ss [ 3 ]
; _rtB -> kuinsnuoqq [ 1 ] = 0.0 ; _rtB -> kuinsnuoqq [ 2 ] = 0.0 ; _rtB ->
kuinsnuoqq [ 3 ] = 0.0 ; _rtB -> h2nvaoyuvf [ 0 ] = _rtB -> f3yexps0ss [ 4 ]
; _rtB -> h2nvaoyuvf [ 1 ] = 0.0 ; _rtB -> h2nvaoyuvf [ 2 ] = 0.0 ; _rtB ->
h2nvaoyuvf [ 3 ] = 0.0 ; _rtB -> lfzmxbotcc [ 0 ] = _rtB -> f3yexps0ss [ 5 ]
; _rtB -> lfzmxbotcc [ 1 ] = 0.0 ; _rtB -> lfzmxbotcc [ 2 ] = 0.0 ; _rtB ->
lfzmxbotcc [ 3 ] = 0.0 ; _rtB -> hlqw14swmy [ 0 ] = _rtB -> dz1mvkujq5 [ 6 ]
; _rtB -> hlqw14swmy [ 1 ] = 0.0 ; _rtB -> hlqw14swmy [ 2 ] = 0.0 ; _rtB ->
hlqw14swmy [ 3 ] = 0.0 ; _rtB -> mqwqhraieb [ 0 ] = _rtB -> dz1mvkujq5 [ 7 ]
; _rtB -> mqwqhraieb [ 1 ] = 0.0 ; _rtB -> mqwqhraieb [ 2 ] = 0.0 ; _rtB ->
mqwqhraieb [ 3 ] = 0.0 ; _rtB -> m5tcam5rpt [ 0 ] = _rtB -> dz1mvkujq5 [ 8 ]
; _rtB -> m5tcam5rpt [ 1 ] = 0.0 ; _rtB -> m5tcam5rpt [ 2 ] = 0.0 ; _rtB ->
m5tcam5rpt [ 3 ] = 0.0 ; _rtB -> oqtschb2io [ 0 ] = _rtB -> dz1mvkujq5 [ 9 ]
; _rtB -> oqtschb2io [ 1 ] = 0.0 ; _rtB -> oqtschb2io [ 2 ] = 0.0 ; _rtB ->
oqtschb2io [ 3 ] = 0.0 ; _rtB -> o5jum1mimy [ 0 ] = _rtB -> dz1mvkujq5 [ 10 ]
; _rtB -> o5jum1mimy [ 1 ] = 0.0 ; _rtB -> o5jum1mimy [ 2 ] = 0.0 ; _rtB ->
o5jum1mimy [ 3 ] = 0.0 ; _rtB -> o3xwfgp0pm [ 0 ] = _rtB -> dz1mvkujq5 [ 11 ]
; _rtB -> o3xwfgp0pm [ 1 ] = 0.0 ; _rtB -> o3xwfgp0pm [ 2 ] = 0.0 ; _rtB ->
o3xwfgp0pm [ 3 ] = 0.0 ; _rtB -> lyyw3lrfjk [ 0 ] = _rtB -> dz1mvkujq5 [ 0 ]
; _rtB -> lyyw3lrfjk [ 1 ] = 0.0 ; _rtB -> lyyw3lrfjk [ 2 ] = 0.0 ; _rtB ->
lyyw3lrfjk [ 3 ] = 0.0 ; _rtB -> j3h135bwox [ 0 ] = _rtB -> dz1mvkujq5 [ 1 ]
; _rtB -> j3h135bwox [ 1 ] = 0.0 ; _rtB -> j3h135bwox [ 2 ] = 0.0 ; _rtB ->
j3h135bwox [ 3 ] = 0.0 ; _rtB -> bydrccalwo [ 0 ] = _rtB -> dz1mvkujq5 [ 2 ]
; _rtB -> bydrccalwo [ 1 ] = 0.0 ; _rtB -> bydrccalwo [ 2 ] = 0.0 ; _rtB ->
bydrccalwo [ 3 ] = 0.0 ; _rtB -> dc1d1gpzok [ 0 ] = _rtB -> dz1mvkujq5 [ 3 ]
; _rtB -> dc1d1gpzok [ 1 ] = 0.0 ; _rtB -> dc1d1gpzok [ 2 ] = 0.0 ; _rtB ->
dc1d1gpzok [ 3 ] = 0.0 ; _rtB -> m2mpa0at2b [ 0 ] = _rtB -> dz1mvkujq5 [ 4 ]
; _rtB -> m2mpa0at2b [ 1 ] = 0.0 ; _rtB -> m2mpa0at2b [ 2 ] = 0.0 ; _rtB ->
m2mpa0at2b [ 3 ] = 0.0 ; _rtB -> n513otpgxb [ 0 ] = _rtB -> dz1mvkujq5 [ 5 ]
; _rtB -> n513otpgxb [ 1 ] = 0.0 ; _rtB -> n513otpgxb [ 2 ] = 0.0 ; _rtB ->
n513otpgxb [ 3 ] = 0.0 ; _rtB -> gj3v3qkaho [ 0 ] = _rtB -> hwk3cn3whe [ 6 ]
; _rtB -> gj3v3qkaho [ 1 ] = 0.0 ; _rtB -> gj3v3qkaho [ 2 ] = 0.0 ; _rtB ->
gj3v3qkaho [ 3 ] = 0.0 ; _rtB -> n1rm0vqpor [ 0 ] = _rtB -> hwk3cn3whe [ 7 ]
; _rtB -> n1rm0vqpor [ 1 ] = 0.0 ; _rtB -> n1rm0vqpor [ 2 ] = 0.0 ; _rtB ->
n1rm0vqpor [ 3 ] = 0.0 ; _rtB -> jiyy12ehqz [ 0 ] = _rtB -> hwk3cn3whe [ 8 ]
; _rtB -> jiyy12ehqz [ 1 ] = 0.0 ; _rtB -> jiyy12ehqz [ 2 ] = 0.0 ; _rtB ->
jiyy12ehqz [ 3 ] = 0.0 ; _rtB -> j3hfxlsdrr [ 0 ] = _rtB -> hwk3cn3whe [ 9 ]
; _rtB -> j3hfxlsdrr [ 1 ] = 0.0 ; _rtB -> j3hfxlsdrr [ 2 ] = 0.0 ; _rtB ->
j3hfxlsdrr [ 3 ] = 0.0 ; _rtB -> m2ljup3bgz [ 0 ] = _rtB -> hwk3cn3whe [ 10 ]
; _rtB -> m2ljup3bgz [ 1 ] = 0.0 ; _rtB -> m2ljup3bgz [ 2 ] = 0.0 ; _rtB ->
m2ljup3bgz [ 3 ] = 0.0 ; _rtB -> chweq21nlr [ 0 ] = _rtB -> hwk3cn3whe [ 11 ]
; _rtB -> chweq21nlr [ 1 ] = 0.0 ; _rtB -> chweq21nlr [ 2 ] = 0.0 ; _rtB ->
chweq21nlr [ 3 ] = 0.0 ; _rtB -> l05f10gu3g [ 0 ] = _rtB -> hwk3cn3whe [ 0 ]
; _rtB -> l05f10gu3g [ 1 ] = 0.0 ; _rtB -> l05f10gu3g [ 2 ] = 0.0 ; _rtB ->
l05f10gu3g [ 3 ] = 0.0 ; _rtB -> ltgaipmh2k [ 0 ] = _rtB -> hwk3cn3whe [ 1 ]
; _rtB -> ltgaipmh2k [ 1 ] = 0.0 ; _rtB -> ltgaipmh2k [ 2 ] = 0.0 ; _rtB ->
ltgaipmh2k [ 3 ] = 0.0 ; _rtB -> of4y4jf1z1 [ 0 ] = _rtB -> hwk3cn3whe [ 2 ]
; _rtB -> of4y4jf1z1 [ 1 ] = 0.0 ; _rtB -> of4y4jf1z1 [ 2 ] = 0.0 ; _rtB ->
of4y4jf1z1 [ 3 ] = 0.0 ; _rtB -> ln2buu3xpo [ 0 ] = _rtB -> hwk3cn3whe [ 3 ]
; _rtB -> ln2buu3xpo [ 1 ] = 0.0 ; _rtB -> ln2buu3xpo [ 2 ] = 0.0 ; _rtB ->
ln2buu3xpo [ 3 ] = 0.0 ; _rtB -> ketudizo11 [ 0 ] = _rtB -> hwk3cn3whe [ 4 ]
; _rtB -> ketudizo11 [ 1 ] = 0.0 ; _rtB -> ketudizo11 [ 2 ] = 0.0 ; _rtB ->
ketudizo11 [ 3 ] = 0.0 ; _rtB -> mjx04j04eu [ 0 ] = _rtB -> hwk3cn3whe [ 5 ]
; _rtB -> mjx04j04eu [ 1 ] = 0.0 ; _rtB -> mjx04j04eu [ 2 ] = 0.0 ; _rtB ->
mjx04j04eu [ 3 ] = 0.0 ; _rtB -> niqchkvs4x [ 0 ] = _rtB -> c2smzgk22s [ 6 ]
; _rtB -> niqchkvs4x [ 1 ] = 0.0 ; _rtB -> niqchkvs4x [ 2 ] = 0.0 ; _rtB ->
niqchkvs4x [ 3 ] = 0.0 ; _rtB -> lbjtgw2yrd [ 0 ] = _rtB -> c2smzgk22s [ 7 ]
; _rtB -> lbjtgw2yrd [ 1 ] = 0.0 ; _rtB -> lbjtgw2yrd [ 2 ] = 0.0 ; _rtB ->
lbjtgw2yrd [ 3 ] = 0.0 ; _rtB -> jpd1cuvjnn [ 0 ] = _rtB -> c2smzgk22s [ 8 ]
; _rtB -> jpd1cuvjnn [ 1 ] = 0.0 ; _rtB -> jpd1cuvjnn [ 2 ] = 0.0 ; _rtB ->
jpd1cuvjnn [ 3 ] = 0.0 ; _rtB -> armsnj32gx [ 0 ] = _rtB -> c2smzgk22s [ 9 ]
; _rtB -> armsnj32gx [ 1 ] = 0.0 ; _rtB -> armsnj32gx [ 2 ] = 0.0 ; _rtB ->
armsnj32gx [ 3 ] = 0.0 ; _rtB -> dhbmcl1epp [ 0 ] = _rtB -> c2smzgk22s [ 10 ]
; _rtB -> dhbmcl1epp [ 1 ] = 0.0 ; _rtB -> dhbmcl1epp [ 2 ] = 0.0 ; _rtB ->
dhbmcl1epp [ 3 ] = 0.0 ; _rtB -> iemqnqtuua [ 0 ] = _rtB -> c2smzgk22s [ 11 ]
; _rtB -> iemqnqtuua [ 1 ] = 0.0 ; _rtB -> iemqnqtuua [ 2 ] = 0.0 ; _rtB ->
iemqnqtuua [ 3 ] = 0.0 ; _rtB -> bpkwhacgl1 [ 0 ] = _rtB -> c2smzgk22s [ 0 ]
; _rtB -> bpkwhacgl1 [ 1 ] = 0.0 ; _rtB -> bpkwhacgl1 [ 2 ] = 0.0 ; _rtB ->
bpkwhacgl1 [ 3 ] = 0.0 ; _rtB -> gzg3wk2exx [ 0 ] = _rtB -> c2smzgk22s [ 1 ]
; _rtB -> gzg3wk2exx [ 1 ] = 0.0 ; _rtB -> gzg3wk2exx [ 2 ] = 0.0 ; _rtB ->
gzg3wk2exx [ 3 ] = 0.0 ; _rtB -> nbdj42k2ha [ 0 ] = _rtB -> c2smzgk22s [ 2 ]
; _rtB -> nbdj42k2ha [ 1 ] = 0.0 ; _rtB -> nbdj42k2ha [ 2 ] = 0.0 ; _rtB ->
nbdj42k2ha [ 3 ] = 0.0 ; _rtB -> etnklo3xeu [ 0 ] = _rtB -> c2smzgk22s [ 3 ]
; _rtB -> etnklo3xeu [ 1 ] = 0.0 ; _rtB -> etnklo3xeu [ 2 ] = 0.0 ; _rtB ->
etnklo3xeu [ 3 ] = 0.0 ; _rtB -> exnpl2vipa [ 0 ] = _rtB -> c2smzgk22s [ 4 ]
; _rtB -> exnpl2vipa [ 1 ] = 0.0 ; _rtB -> exnpl2vipa [ 2 ] = 0.0 ; _rtB ->
exnpl2vipa [ 3 ] = 0.0 ; _rtB -> ptvtrxsi5q [ 0 ] = _rtB -> c2smzgk22s [ 5 ]
; _rtB -> ptvtrxsi5q [ 1 ] = 0.0 ; _rtB -> ptvtrxsi5q [ 2 ] = 0.0 ; _rtB ->
ptvtrxsi5q [ 3 ] = 0.0 ; ssCallAccelRunBlock ( S , 28 , 1208 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> cntuqzo3vd [ 0 ] = _rtP -> P_235 [ 0 ] * _rtB
-> g21hdmkrr4 [ 3 ] ; _rtB -> hjzr0cxaqc [ 0 ] = _rtP -> P_240 [ 0 ] * _rtB
-> g21hdmkrr4 [ 3 ] ; _rtB -> bsyv1whpl4 [ 0 ] = _rtP -> P_245 [ 0 ] * _rtB
-> g21hdmkrr4 [ 0 ] ; _rtB -> ikcislor0a [ 0 ] = _rtP -> P_250 [ 0 ] * _rtB
-> g21hdmkrr4 [ 0 ] ; _rtB -> nzcavrodol [ 0 ] = _rtP -> P_255 [ 0 ] * _rtB
-> g21hdmkrr4 [ 6 ] ; _rtB -> fouglpsfww [ 0 ] = _rtP -> P_260 [ 0 ] * _rtB
-> g21hdmkrr4 [ 6 ] ; _rtB -> dkvpgm1oad [ 0 ] = _rtP -> P_265 [ 0 ] * _rtB
-> g21hdmkrr4 [ 12 ] ; _rtB -> opxhqvqyor [ 0 ] = _rtP -> P_270 [ 0 ] * _rtB
-> g21hdmkrr4 [ 12 ] ; _rtB -> jnno0w0220 [ 0 ] = _rtP -> P_275 [ 0 ] * _rtB
-> g21hdmkrr4 [ 9 ] ; _rtB -> pnbf0vtgka [ 0 ] = _rtP -> P_280 [ 0 ] * _rtB
-> g21hdmkrr4 [ 9 ] ; _rtB -> ca4hrb2qsy [ 0 ] = _rtP -> P_285 [ 0 ] * _rtB
-> g21hdmkrr4 [ 15 ] ; _rtB -> m0kzlfyh24 [ 0 ] = _rtP -> P_290 [ 0 ] * _rtB
-> g21hdmkrr4 [ 15 ] ; _rtB -> n3qrel0jnu [ 0 ] = _rtP -> P_295 [ 0 ] * _rtB
-> g21hdmkrr4 [ 24 ] ; _rtB -> fmicrbfhw1 [ 0 ] = _rtP -> P_300 [ 0 ] * _rtB
-> g21hdmkrr4 [ 24 ] ; _rtB -> ktlrrfvmep [ 0 ] = _rtP -> P_305 [ 0 ] * _rtB
-> g21hdmkrr4 [ 21 ] ; _rtB -> nsenlpaboq [ 0 ] = _rtP -> P_310 [ 0 ] * _rtB
-> g21hdmkrr4 [ 21 ] ; _rtB -> ivxdeqxdzk [ 0 ] = _rtP -> P_315 [ 0 ] * _rtB
-> g21hdmkrr4 [ 18 ] ; _rtB -> bj3vpgupnm [ 0 ] = _rtP -> P_320 [ 0 ] * _rtB
-> g21hdmkrr4 [ 18 ] ; _rtB -> gem1quhrsv [ 0 ] = _rtP -> P_325 [ 0 ] * _rtB
-> g21hdmkrr4 [ 33 ] ; _rtB -> jwbihckpai [ 0 ] = _rtP -> P_330 [ 0 ] * _rtB
-> g21hdmkrr4 [ 33 ] ; _rtB -> hvmx0wjzyv [ 0 ] = _rtP -> P_335 [ 0 ] * _rtB
-> g21hdmkrr4 [ 30 ] ; _rtB -> fxyrsyyqve [ 0 ] = _rtP -> P_340 [ 0 ] * _rtB
-> g21hdmkrr4 [ 30 ] ; _rtB -> j54ugs5ekq [ 0 ] = _rtP -> P_345 [ 0 ] * _rtB
-> g21hdmkrr4 [ 27 ] ; _rtB -> j3cei1tshw [ 0 ] = _rtP -> P_350 [ 0 ] * _rtB
-> g21hdmkrr4 [ 27 ] ; _rtB -> cntuqzo3vd [ 1 ] = _rtP -> P_235 [ 1 ] * _rtB
-> g21hdmkrr4 [ 4 ] ; _rtB -> hjzr0cxaqc [ 1 ] = _rtP -> P_240 [ 1 ] * _rtB
-> g21hdmkrr4 [ 4 ] ; _rtB -> bsyv1whpl4 [ 1 ] = _rtP -> P_245 [ 1 ] * _rtB
-> g21hdmkrr4 [ 1 ] ; _rtB -> ikcislor0a [ 1 ] = _rtP -> P_250 [ 1 ] * _rtB
-> g21hdmkrr4 [ 1 ] ; _rtB -> nzcavrodol [ 1 ] = _rtP -> P_255 [ 1 ] * _rtB
-> g21hdmkrr4 [ 7 ] ; _rtB -> fouglpsfww [ 1 ] = _rtP -> P_260 [ 1 ] * _rtB
-> g21hdmkrr4 [ 7 ] ; _rtB -> dkvpgm1oad [ 1 ] = _rtP -> P_265 [ 1 ] * _rtB
-> g21hdmkrr4 [ 13 ] ; _rtB -> opxhqvqyor [ 1 ] = _rtP -> P_270 [ 1 ] * _rtB
-> g21hdmkrr4 [ 13 ] ; _rtB -> jnno0w0220 [ 1 ] = _rtP -> P_275 [ 1 ] * _rtB
-> g21hdmkrr4 [ 10 ] ; _rtB -> pnbf0vtgka [ 1 ] = _rtP -> P_280 [ 1 ] * _rtB
-> g21hdmkrr4 [ 10 ] ; _rtB -> ca4hrb2qsy [ 1 ] = _rtP -> P_285 [ 1 ] * _rtB
-> g21hdmkrr4 [ 16 ] ; _rtB -> m0kzlfyh24 [ 1 ] = _rtP -> P_290 [ 1 ] * _rtB
-> g21hdmkrr4 [ 16 ] ; _rtB -> n3qrel0jnu [ 1 ] = _rtP -> P_295 [ 1 ] * _rtB
-> g21hdmkrr4 [ 25 ] ; _rtB -> fmicrbfhw1 [ 1 ] = _rtP -> P_300 [ 1 ] * _rtB
-> g21hdmkrr4 [ 25 ] ; _rtB -> ktlrrfvmep [ 1 ] = _rtP -> P_305 [ 1 ] * _rtB
-> g21hdmkrr4 [ 22 ] ; _rtB -> nsenlpaboq [ 1 ] = _rtP -> P_310 [ 1 ] * _rtB
-> g21hdmkrr4 [ 22 ] ; _rtB -> ivxdeqxdzk [ 1 ] = _rtP -> P_315 [ 1 ] * _rtB
-> g21hdmkrr4 [ 19 ] ; _rtB -> bj3vpgupnm [ 1 ] = _rtP -> P_320 [ 1 ] * _rtB
-> g21hdmkrr4 [ 19 ] ; _rtB -> gem1quhrsv [ 1 ] = _rtP -> P_325 [ 1 ] * _rtB
-> g21hdmkrr4 [ 34 ] ; _rtB -> jwbihckpai [ 1 ] = _rtP -> P_330 [ 1 ] * _rtB
-> g21hdmkrr4 [ 34 ] ; _rtB -> hvmx0wjzyv [ 1 ] = _rtP -> P_335 [ 1 ] * _rtB
-> g21hdmkrr4 [ 31 ] ; _rtB -> fxyrsyyqve [ 1 ] = _rtP -> P_340 [ 1 ] * _rtB
-> g21hdmkrr4 [ 31 ] ; _rtB -> j54ugs5ekq [ 1 ] = _rtP -> P_345 [ 1 ] * _rtB
-> g21hdmkrr4 [ 28 ] ; _rtB -> j3cei1tshw [ 1 ] = _rtP -> P_350 [ 1 ] * _rtB
-> g21hdmkrr4 [ 28 ] ; _rtB -> cntuqzo3vd [ 2 ] = _rtP -> P_235 [ 2 ] * _rtB
-> g21hdmkrr4 [ 5 ] ; _rtB -> hjzr0cxaqc [ 2 ] = _rtP -> P_240 [ 2 ] * _rtB
-> g21hdmkrr4 [ 5 ] ; _rtB -> bsyv1whpl4 [ 2 ] = _rtP -> P_245 [ 2 ] * _rtB
-> g21hdmkrr4 [ 2 ] ; _rtB -> ikcislor0a [ 2 ] = _rtP -> P_250 [ 2 ] * _rtB
-> g21hdmkrr4 [ 2 ] ; _rtB -> nzcavrodol [ 2 ] = _rtP -> P_255 [ 2 ] * _rtB
-> g21hdmkrr4 [ 8 ] ; _rtB -> fouglpsfww [ 2 ] = _rtP -> P_260 [ 2 ] * _rtB
-> g21hdmkrr4 [ 8 ] ; _rtB -> dkvpgm1oad [ 2 ] = _rtP -> P_265 [ 2 ] * _rtB
-> g21hdmkrr4 [ 14 ] ; _rtB -> opxhqvqyor [ 2 ] = _rtP -> P_270 [ 2 ] * _rtB
-> g21hdmkrr4 [ 14 ] ; _rtB -> jnno0w0220 [ 2 ] = _rtP -> P_275 [ 2 ] * _rtB
-> g21hdmkrr4 [ 11 ] ; _rtB -> pnbf0vtgka [ 2 ] = _rtP -> P_280 [ 2 ] * _rtB
-> g21hdmkrr4 [ 11 ] ; _rtB -> ca4hrb2qsy [ 2 ] = _rtP -> P_285 [ 2 ] * _rtB
-> g21hdmkrr4 [ 17 ] ; _rtB -> m0kzlfyh24 [ 2 ] = _rtP -> P_290 [ 2 ] * _rtB
-> g21hdmkrr4 [ 17 ] ; _rtB -> n3qrel0jnu [ 2 ] = _rtP -> P_295 [ 2 ] * _rtB
-> g21hdmkrr4 [ 26 ] ; _rtB -> fmicrbfhw1 [ 2 ] = _rtP -> P_300 [ 2 ] * _rtB
-> g21hdmkrr4 [ 26 ] ; _rtB -> ktlrrfvmep [ 2 ] = _rtP -> P_305 [ 2 ] * _rtB
-> g21hdmkrr4 [ 23 ] ; _rtB -> nsenlpaboq [ 2 ] = _rtP -> P_310 [ 2 ] * _rtB
-> g21hdmkrr4 [ 23 ] ; _rtB -> ivxdeqxdzk [ 2 ] = _rtP -> P_315 [ 2 ] * _rtB
-> g21hdmkrr4 [ 20 ] ; _rtB -> bj3vpgupnm [ 2 ] = _rtP -> P_320 [ 2 ] * _rtB
-> g21hdmkrr4 [ 20 ] ; _rtB -> gem1quhrsv [ 2 ] = _rtP -> P_325 [ 2 ] * _rtB
-> g21hdmkrr4 [ 35 ] ; _rtB -> jwbihckpai [ 2 ] = _rtP -> P_330 [ 2 ] * _rtB
-> g21hdmkrr4 [ 35 ] ; _rtB -> hvmx0wjzyv [ 2 ] = _rtP -> P_335 [ 2 ] * _rtB
-> g21hdmkrr4 [ 32 ] ; _rtB -> fxyrsyyqve [ 2 ] = _rtP -> P_340 [ 2 ] * _rtB
-> g21hdmkrr4 [ 32 ] ; _rtB -> j54ugs5ekq [ 2 ] = _rtP -> P_345 [ 2 ] * _rtB
-> g21hdmkrr4 [ 29 ] ; _rtB -> j3cei1tshw [ 2 ] = _rtP -> P_350 [ 2 ] * _rtB
-> g21hdmkrr4 [ 29 ] ; _rtB -> abg52ogrim = muDoubleScalarAbs ( _rtB ->
cntuqzo3vd [ 0 ] ) ; _rtB -> m2vjnesdbb = _rtP -> P_236 * _rtB -> abg52ogrim
; _rtB -> opq2nuky5x [ 0 ] = _rtB -> g2oxeuzo0r [ 1 ] ; _rtB -> opq2nuky5x [
1 ] = 0.0 ; _rtB -> opq2nuky5x [ 2 ] = 0.0 ; _rtB -> opq2nuky5x [ 3 ] = 0.0 ;
_rtB -> l1m4oazw22 = 0.0 ; _rtB -> l1m4oazw22 += 0.003 * _rtB -> opq2nuky5x [
0 ] ; amuqdujtnk = look1_binlxpw ( _rtB -> l1m4oazw22 , _rtP -> P_238 , _rtP
-> P_237 , 5U ) ; _rtB -> atja23mpoc = amuqdujtnk * _rtB -> m2vjnesdbb ; _rtB
-> ger44vmp4l = _rtP -> P_239 * _rtB -> atja23mpoc ; _rtB -> gewzhyqjwd =
_rtB -> ger44vmp4l - _rtB -> i1ie0n4hxn ; _rtB -> mcd1pvc0do =
muDoubleScalarAbs ( _rtB -> hjzr0cxaqc [ 1 ] ) ; _rtB -> dwacorz5dt = _rtP ->
P_241 * _rtB -> mcd1pvc0do ; amuqdujtnk = look1_binlxpw ( _rtB -> l1m4oazw22
, _rtP -> P_243 , _rtP -> P_242 , 5U ) ; _rtB -> kcscyj0nqw = amuqdujtnk *
_rtB -> dwacorz5dt ; _rtB -> hlxq1dffyi = _rtP -> P_244 * _rtB -> kcscyj0nqw
; _rtB -> mfeyqgzomt = _rtB -> hlxq1dffyi - _rtB -> dlt1hiy53u ; _rtB ->
oas00x3txh = muDoubleScalarAbs ( _rtB -> bsyv1whpl4 [ 0 ] ) ; _rtB ->
ldhkvxfi3w = _rtP -> P_246 * _rtB -> oas00x3txh ; _rtB -> f4mbmrtwuj [ 0 ] =
_rtB -> g2oxeuzo0r [ 0 ] ; _rtB -> f4mbmrtwuj [ 1 ] = 0.0 ; _rtB ->
f4mbmrtwuj [ 2 ] = 0.0 ; _rtB -> f4mbmrtwuj [ 3 ] = 0.0 ; _rtB -> dclymcsudp
= 0.0 ; _rtB -> dclymcsudp += 0.003 * _rtB -> f4mbmrtwuj [ 0 ] ; amuqdujtnk =
look1_binlxpw ( _rtB -> dclymcsudp , _rtP -> P_248 , _rtP -> P_247 , 5U ) ;
_rtB -> pswdz4cnr4 = amuqdujtnk * _rtB -> ldhkvxfi3w ; _rtB -> hpfpmessgi =
_rtP -> P_249 * _rtB -> pswdz4cnr4 ; _rtB -> e1ikoxoxdp = _rtB -> hpfpmessgi
- _rtB -> mkx145gx4i ; _rtB -> gldw0gzyve = muDoubleScalarAbs ( _rtB ->
ikcislor0a [ 1 ] ) ; _rtB -> p2u3tz0eld = _rtP -> P_251 * _rtB -> gldw0gzyve
; amuqdujtnk = look1_binlxpw ( _rtB -> dclymcsudp , _rtP -> P_253 , _rtP ->
P_252 , 5U ) ; _rtB -> g3se3ju3hs = amuqdujtnk * _rtB -> p2u3tz0eld ; _rtB ->
hzzqnytoxy = _rtP -> P_254 * _rtB -> g3se3ju3hs ; _rtB -> mod3qkcthn = _rtB
-> hzzqnytoxy - _rtB -> axc2grjhf3 ; _rtB -> pgjk42w2dv = muDoubleScalarAbs (
_rtB -> nzcavrodol [ 0 ] ) ; _rtB -> f1t3tsmws2 = _rtP -> P_256 * _rtB ->
pgjk42w2dv ; _rtB -> pwjppiwrcx [ 0 ] = _rtB -> g2oxeuzo0r [ 2 ] ; _rtB ->
pwjppiwrcx [ 1 ] = 0.0 ; _rtB -> pwjppiwrcx [ 2 ] = 0.0 ; _rtB -> pwjppiwrcx
[ 3 ] = 0.0 ; _rtB -> dmn1y0yth0 = 0.0 ; _rtB -> dmn1y0yth0 += 0.003 * _rtB
-> pwjppiwrcx [ 0 ] ; amuqdujtnk = look1_binlxpw ( _rtB -> dmn1y0yth0 , _rtP
-> P_258 , _rtP -> P_257 , 5U ) ; _rtB -> jbk4et2pfo = amuqdujtnk * _rtB ->
f1t3tsmws2 ; _rtB -> i55rn132rb = _rtP -> P_259 * _rtB -> jbk4et2pfo ; _rtB
-> efnalmv2pp = _rtB -> i55rn132rb - _rtB -> p3svxaeu2v ; _rtB -> mbidbztnur
= muDoubleScalarAbs ( _rtB -> fouglpsfww [ 1 ] ) ; _rtB -> c4zt1ttmzi = _rtP
-> P_261 * _rtB -> mbidbztnur ; amuqdujtnk = look1_binlxpw ( _rtB ->
dmn1y0yth0 , _rtP -> P_263 , _rtP -> P_262 , 5U ) ; _rtB -> aatxaclxkz =
amuqdujtnk * _rtB -> c4zt1ttmzi ; _rtB -> ikiajba0ne = _rtP -> P_264 * _rtB
-> aatxaclxkz ; _rtB -> nzxy4jfqpl = _rtB -> ikiajba0ne - _rtB -> pqrezee1ex
; _rtB -> cfdwxxtes0 = muDoubleScalarAbs ( _rtB -> dkvpgm1oad [ 0 ] ) ; _rtB
-> ijgcdvs3rk = _rtP -> P_266 * _rtB -> cfdwxxtes0 ; _rtB -> ey4tpkjzfc [ 0 ]
= _rtB -> g2oxeuzo0r [ 4 ] ; _rtB -> ey4tpkjzfc [ 1 ] = 0.0 ; _rtB ->
ey4tpkjzfc [ 2 ] = 0.0 ; _rtB -> ey4tpkjzfc [ 3 ] = 0.0 ; _rtB -> ma0mp5z342
= 0.0 ; _rtB -> ma0mp5z342 += 0.003 * _rtB -> ey4tpkjzfc [ 0 ] ; amuqdujtnk =
look1_binlxpw ( _rtB -> ma0mp5z342 , _rtP -> P_268 , _rtP -> P_267 , 5U ) ;
_rtB -> omssgnh0rr = amuqdujtnk * _rtB -> ijgcdvs3rk ; _rtB -> kdj15r54aj =
_rtP -> P_269 * _rtB -> omssgnh0rr ; _rtB -> op3ubj0wen = _rtB -> kdj15r54aj
- _rtB -> ki01gqo503 ; _rtB -> af2kua5vcz = muDoubleScalarAbs ( _rtB ->
opxhqvqyor [ 1 ] ) ; _rtB -> aibobscsql = _rtP -> P_271 * _rtB -> af2kua5vcz
; amuqdujtnk = look1_binlxpw ( _rtB -> ma0mp5z342 , _rtP -> P_273 , _rtP ->
P_272 , 5U ) ; _rtB -> nkhzfaepz2 = amuqdujtnk * _rtB -> aibobscsql ; _rtB ->
djnuaqhg02 = _rtP -> P_274 * _rtB -> nkhzfaepz2 ; _rtB -> f4j3nkpany = _rtB
-> djnuaqhg02 - _rtB -> at1ccozb5c ; _rtB -> hi5qag5bvh = muDoubleScalarAbs (
_rtB -> jnno0w0220 [ 0 ] ) ; _rtB -> alezjuzglx = _rtP -> P_276 * _rtB ->
hi5qag5bvh ; _rtB -> cttot5ojcm [ 0 ] = _rtB -> g2oxeuzo0r [ 3 ] ; _rtB ->
cttot5ojcm [ 1 ] = 0.0 ; _rtB -> cttot5ojcm [ 2 ] = 0.0 ; _rtB -> cttot5ojcm
[ 3 ] = 0.0 ; _rtB -> m3vdvfr2bp = 0.0 ; _rtB -> m3vdvfr2bp += 0.003 * _rtB
-> cttot5ojcm [ 0 ] ; amuqdujtnk = look1_binlxpw ( _rtB -> m3vdvfr2bp , _rtP
-> P_278 , _rtP -> P_277 , 5U ) ; _rtB -> p4xjyuea5v = amuqdujtnk * _rtB ->
alezjuzglx ; _rtB -> d5rdbfk113 = _rtP -> P_279 * _rtB -> p4xjyuea5v ; _rtB
-> f1kobq02bv = _rtB -> d5rdbfk113 - _rtB -> idx0f0tpft ; _rtB -> fj3veufa0g
= muDoubleScalarAbs ( _rtB -> pnbf0vtgka [ 1 ] ) ; _rtB -> h5omfgpxv2 = _rtP
-> P_281 * _rtB -> fj3veufa0g ; amuqdujtnk = look1_binlxpw ( _rtB ->
m3vdvfr2bp , _rtP -> P_283 , _rtP -> P_282 , 5U ) ; _rtB -> fu1v0uyjzl =
amuqdujtnk * _rtB -> h5omfgpxv2 ; _rtB -> cvo2znjhbw = _rtP -> P_284 * _rtB
-> fu1v0uyjzl ; _rtB -> kvfwjfwswe = _rtB -> cvo2znjhbw - _rtB -> boig44tbgk
; _rtB -> bku1vl5n5n = muDoubleScalarAbs ( _rtB -> ca4hrb2qsy [ 0 ] ) ; _rtB
-> d3mgabhzio = _rtP -> P_286 * _rtB -> bku1vl5n5n ; _rtB -> jozts53nuj [ 0 ]
= _rtB -> g2oxeuzo0r [ 5 ] ; _rtB -> jozts53nuj [ 1 ] = 0.0 ; _rtB ->
jozts53nuj [ 2 ] = 0.0 ; _rtB -> jozts53nuj [ 3 ] = 0.0 ; _rtB -> hq3akg4o1k
= 0.0 ; _rtB -> hq3akg4o1k += 0.003 * _rtB -> jozts53nuj [ 0 ] ; amuqdujtnk =
look1_binlxpw ( _rtB -> hq3akg4o1k , _rtP -> P_288 , _rtP -> P_287 , 5U ) ;
_rtB -> imcmp3xhov = amuqdujtnk * _rtB -> d3mgabhzio ; _rtB -> jqicicp5et =
_rtP -> P_289 * _rtB -> imcmp3xhov ; _rtB -> oozc1jejkz = _rtB -> jqicicp5et
- _rtB -> il53rgtmz5 ; _rtB -> lovbs5b4hl = muDoubleScalarAbs ( _rtB ->
m0kzlfyh24 [ 1 ] ) ; _rtB -> eqcrsva2e1 = _rtP -> P_291 * _rtB -> lovbs5b4hl
; amuqdujtnk = look1_binlxpw ( _rtB -> hq3akg4o1k , _rtP -> P_293 , _rtP ->
P_292 , 5U ) ; _rtB -> e2qzktglvy = amuqdujtnk * _rtB -> eqcrsva2e1 ; _rtB ->
fo2ppjeko4 = _rtP -> P_294 * _rtB -> e2qzktglvy ; _rtB -> gt1eqvfhtd = _rtB
-> fo2ppjeko4 - _rtB -> oplrad3nny ; _rtB -> hicwwdkhgj = muDoubleScalarAbs (
_rtB -> n3qrel0jnu [ 0 ] ) ; _rtB -> kavf1lzwfz = _rtP -> P_296 * _rtB ->
hicwwdkhgj ; _rtB -> gmrxxd5xb4 [ 0 ] = _rtB -> g2oxeuzo0r [ 8 ] ; _rtB ->
gmrxxd5xb4 [ 1 ] = 0.0 ; _rtB -> gmrxxd5xb4 [ 2 ] = 0.0 ; _rtB -> gmrxxd5xb4
[ 3 ] = 0.0 ; _rtB -> fc3ux1eken = 0.0 ; _rtB -> fc3ux1eken += 0.003 * _rtB
-> gmrxxd5xb4 [ 0 ] ; amuqdujtnk = look1_binlxpw ( _rtB -> fc3ux1eken , _rtP
-> P_298 , _rtP -> P_297 , 5U ) ; _rtB -> nbc40ikrjf = amuqdujtnk * _rtB ->
kavf1lzwfz ; _rtB -> euqjqgj00e = _rtP -> P_299 * _rtB -> nbc40ikrjf ; _rtB
-> bldcxkbarf = _rtB -> euqjqgj00e - _rtB -> mhjx3knsi4 ; _rtB -> bnq5inecw4
= muDoubleScalarAbs ( _rtB -> fmicrbfhw1 [ 1 ] ) ; _rtB -> lo4oxwzvlt = _rtP
-> P_301 * _rtB -> bnq5inecw4 ; amuqdujtnk = look1_binlxpw ( _rtB ->
fc3ux1eken , _rtP -> P_303 , _rtP -> P_302 , 5U ) ; _rtB -> gbjnq0q1ig =
amuqdujtnk * _rtB -> lo4oxwzvlt ; _rtB -> dpayp2tllo = _rtP -> P_304 * _rtB
-> gbjnq0q1ig ; _rtB -> jquof1hx34 = _rtB -> dpayp2tllo - _rtB -> dg4rqec1ay
; _rtB -> hwnzufv1yw = muDoubleScalarAbs ( _rtB -> ktlrrfvmep [ 0 ] ) ; _rtB
-> lvesnbdpnr = _rtP -> P_306 * _rtB -> hwnzufv1yw ; _rtB -> p41pwpmzoi [ 0 ]
= _rtB -> g2oxeuzo0r [ 7 ] ; _rtB -> p41pwpmzoi [ 1 ] = 0.0 ; _rtB ->
p41pwpmzoi [ 2 ] = 0.0 ; _rtB -> p41pwpmzoi [ 3 ] = 0.0 ; _rtB -> pfynpydaqw
= 0.0 ; _rtB -> pfynpydaqw += 0.003 * _rtB -> p41pwpmzoi [ 0 ] ; amuqdujtnk =
look1_binlxpw ( _rtB -> pfynpydaqw , _rtP -> P_308 , _rtP -> P_307 , 5U ) ;
_rtB -> l44gjoznxk = amuqdujtnk * _rtB -> lvesnbdpnr ; _rtB -> e34iwrchmn =
_rtP -> P_309 * _rtB -> l44gjoznxk ; _rtB -> nivwyjtwme = _rtB -> e34iwrchmn
- _rtB -> jc005m52ez ; _rtB -> eeilt2p5po = muDoubleScalarAbs ( _rtB ->
nsenlpaboq [ 1 ] ) ; _rtB -> jl11rjx2vz = _rtP -> P_311 * _rtB -> eeilt2p5po
; amuqdujtnk = look1_binlxpw ( _rtB -> pfynpydaqw , _rtP -> P_313 , _rtP ->
P_312 , 5U ) ; _rtB -> nprcebcjk1 = amuqdujtnk * _rtB -> jl11rjx2vz ; _rtB ->
kgaw1d40qa = _rtP -> P_314 * _rtB -> nprcebcjk1 ; _rtB -> pvxakq0t4v = _rtB
-> kgaw1d40qa - _rtB -> czgnjzn4ns ; _rtB -> ozxzai1oad = muDoubleScalarAbs (
_rtB -> ivxdeqxdzk [ 0 ] ) ; _rtB -> hyeqeb4qhl = _rtP -> P_316 * _rtB ->
ozxzai1oad ; _rtB -> nehv1yt0l2 [ 0 ] = _rtB -> g2oxeuzo0r [ 6 ] ; _rtB ->
nehv1yt0l2 [ 1 ] = 0.0 ; _rtB -> nehv1yt0l2 [ 2 ] = 0.0 ; _rtB -> nehv1yt0l2
[ 3 ] = 0.0 ; _rtB -> aswxiv3vbp = 0.0 ; _rtB -> aswxiv3vbp += 0.003 * _rtB
-> nehv1yt0l2 [ 0 ] ; amuqdujtnk = look1_binlxpw ( _rtB -> aswxiv3vbp , _rtP
-> P_318 , _rtP -> P_317 , 5U ) ; _rtB -> n2fj1ffgqs = amuqdujtnk * _rtB ->
hyeqeb4qhl ; _rtB -> f5lpcq3slg = _rtP -> P_319 * _rtB -> n2fj1ffgqs ; _rtB
-> gxisbqwjr1 = _rtB -> f5lpcq3slg - _rtB -> dpbtrt2nal ; _rtB -> hwjj2vstxi
= muDoubleScalarAbs ( _rtB -> bj3vpgupnm [ 1 ] ) ; _rtB -> mlxl3hxxmf = _rtP
-> P_321 * _rtB -> hwjj2vstxi ; amuqdujtnk = look1_binlxpw ( _rtB ->
aswxiv3vbp , _rtP -> P_323 , _rtP -> P_322 , 5U ) ; _rtB -> nh3r5ol23u =
amuqdujtnk * _rtB -> mlxl3hxxmf ; _rtB -> hxnbrmcymm = _rtP -> P_324 * _rtB
-> nh3r5ol23u ; _rtB -> eianhzvqtl = _rtB -> hxnbrmcymm - _rtB -> md54yy2bxt
; _rtB -> ic0ftpap2o = muDoubleScalarAbs ( _rtB -> gem1quhrsv [ 0 ] ) ; _rtB
-> j35vympk3d = _rtP -> P_326 * _rtB -> ic0ftpap2o ; _rtB -> nfzcxtl0vw [ 0 ]
= _rtB -> g2oxeuzo0r [ 11 ] ; _rtB -> nfzcxtl0vw [ 1 ] = 0.0 ; _rtB ->
nfzcxtl0vw [ 2 ] = 0.0 ; _rtB -> nfzcxtl0vw [ 3 ] = 0.0 ; _rtB -> lkzd21dwhr
= 0.0 ; _rtB -> lkzd21dwhr += 0.003 * _rtB -> nfzcxtl0vw [ 0 ] ; amuqdujtnk =
look1_binlxpw ( _rtB -> lkzd21dwhr , _rtP -> P_328 , _rtP -> P_327 , 5U ) ;
_rtB -> ei5zt4frqt = amuqdujtnk * _rtB -> j35vympk3d ; _rtB -> o0zt5qw2hx =
_rtP -> P_329 * _rtB -> ei5zt4frqt ; _rtB -> jb4llouefe = _rtB -> o0zt5qw2hx
- _rtB -> ls43quiney ; _rtB -> p4u0r0ncc2 = muDoubleScalarAbs ( _rtB ->
jwbihckpai [ 1 ] ) ; _rtB -> hmf1uh3uxf = _rtP -> P_331 * _rtB -> p4u0r0ncc2
; amuqdujtnk = look1_binlxpw ( _rtB -> lkzd21dwhr , _rtP -> P_333 , _rtP ->
P_332 , 5U ) ; _rtB -> aquriuqykl = amuqdujtnk * _rtB -> hmf1uh3uxf ; _rtB ->
kp0phrsoed = _rtP -> P_334 * _rtB -> aquriuqykl ; _rtB -> p4er4kkq1i = _rtB
-> kp0phrsoed - _rtB -> gvvlnifink ; _rtB -> f2cif3m3jm = muDoubleScalarAbs (
_rtB -> hvmx0wjzyv [ 0 ] ) ; _rtB -> nppdqp1shn = _rtP -> P_336 * _rtB ->
f2cif3m3jm ; _rtB -> i5i5q5eu3k [ 0 ] = _rtB -> g2oxeuzo0r [ 10 ] ; _rtB ->
i5i5q5eu3k [ 1 ] = 0.0 ; _rtB -> i5i5q5eu3k [ 2 ] = 0.0 ; _rtB -> i5i5q5eu3k
[ 3 ] = 0.0 ; _rtB -> a55t01ixd0 = 0.0 ; _rtB -> a55t01ixd0 += 0.003 * _rtB
-> i5i5q5eu3k [ 0 ] ; amuqdujtnk = look1_binlxpw ( _rtB -> a55t01ixd0 , _rtP
-> P_338 , _rtP -> P_337 , 5U ) ; _rtB -> nnkmtvrezw = amuqdujtnk * _rtB ->
nppdqp1shn ; _rtB -> pv1quhmm0k = _rtP -> P_339 * _rtB -> nnkmtvrezw ; _rtB
-> izcrjfdstr = _rtB -> pv1quhmm0k - _rtB -> kezumfw412 ; _rtB -> ito4fxledm
= muDoubleScalarAbs ( _rtB -> fxyrsyyqve [ 1 ] ) ; _rtB -> c3d2ifjdzv = _rtP
-> P_341 * _rtB -> ito4fxledm ; amuqdujtnk = look1_binlxpw ( _rtB ->
a55t01ixd0 , _rtP -> P_343 , _rtP -> P_342 , 5U ) ; _rtB -> ctksjbxnbn =
amuqdujtnk * _rtB -> c3d2ifjdzv ; _rtB -> em1o0f0sgl = _rtP -> P_344 * _rtB
-> ctksjbxnbn ; _rtB -> ltc3x4g13l = _rtB -> em1o0f0sgl - _rtB -> gnbrdas2cf
; _rtB -> mf4eqo3cuu = muDoubleScalarAbs ( _rtB -> j54ugs5ekq [ 0 ] ) ; _rtB
-> fmtva25tai = _rtP -> P_346 * _rtB -> mf4eqo3cuu ; _rtB -> cwfbgrb1lb [ 0 ]
= _rtB -> g2oxeuzo0r [ 9 ] ; _rtB -> cwfbgrb1lb [ 1 ] = 0.0 ; _rtB ->
cwfbgrb1lb [ 2 ] = 0.0 ; _rtB -> cwfbgrb1lb [ 3 ] = 0.0 ; _rtB -> izdk3w1ntt
= 0.0 ; _rtB -> izdk3w1ntt += 0.003 * _rtB -> cwfbgrb1lb [ 0 ] ; amuqdujtnk =
look1_binlxpw ( _rtB -> izdk3w1ntt , _rtP -> P_348 , _rtP -> P_347 , 5U ) ;
_rtB -> gl5ax5ksbf = amuqdujtnk * _rtB -> fmtva25tai ; _rtB -> exnwy1qztm =
_rtP -> P_349 * _rtB -> gl5ax5ksbf ; _rtB -> oggqgxb44y = _rtB -> exnwy1qztm
- _rtB -> d1l5gz5lej ; _rtB -> akum0qycrf = muDoubleScalarAbs ( _rtB ->
j3cei1tshw [ 1 ] ) ; _rtB -> blyhkkqjf5 = _rtP -> P_351 * _rtB -> akum0qycrf
; amuqdujtnk = look1_binlxpw ( _rtB -> izdk3w1ntt , _rtP -> P_353 , _rtP ->
P_352 , 5U ) ; _rtB -> ol2li3bfqs = amuqdujtnk * _rtB -> blyhkkqjf5 ; _rtB ->
fl4ar5ptgo = _rtP -> P_354 * _rtB -> ol2li3bfqs ; _rtB -> kkjiwqmguk = _rtB
-> fl4ar5ptgo - _rtB -> d3h353cnhv ; ssCallAccelRunBlock ( S , 28 , 2037 ,
SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID2 ( SimStruct * S , int_T tid ) { boolean_T e3boklgumq ;
gjw3c2hq0n * _rtB ; pn00hmq1oq * _rtP ; ey1cddduxp * _rtDW ; _rtDW = ( (
ey1cddduxp * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( pn00hmq1oq * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( gjw3c2hq0n * ) _ssGetModelBlockIO ( S ) )
; _rtB -> d45j2mfj2n = _rtP -> P_4 ; _rtB -> kur2lpov1n = _rtP -> P_5 ;
e3boklgumq = ! ( _rtP -> P_8 != 0.0 ) ; _rtB -> pvre3w420d = _rtP -> P_10 ;
_rtB -> at1eq4ul45 [ 0 ] = _rtP -> P_6 * _rtP -> P_7 [ 0 ] + ( real_T )
e3boklgumq * _rtP -> P_9 [ 0 ] ; _rtB -> jtidsw4hp3 [ 0 ] = _rtB ->
at1eq4ul45 [ 0 ] * _rtB -> pvre3w420d ; _rtB -> at1eq4ul45 [ 1 ] = _rtP ->
P_6 * _rtP -> P_7 [ 1 ] + ( real_T ) e3boklgumq * _rtP -> P_9 [ 1 ] ; _rtB ->
jtidsw4hp3 [ 1 ] = _rtB -> at1eq4ul45 [ 1 ] * _rtB -> pvre3w420d ; _rtB ->
at1eq4ul45 [ 2 ] = _rtP -> P_6 * _rtP -> P_7 [ 2 ] + ( real_T ) e3boklgumq *
_rtP -> P_9 [ 2 ] ; _rtB -> jtidsw4hp3 [ 2 ] = _rtB -> at1eq4ul45 [ 2 ] *
_rtB -> pvre3w420d ; _rtB -> at1eq4ul45 [ 3 ] = _rtP -> P_6 * _rtP -> P_7 [ 3
] + ( real_T ) e3boklgumq * _rtP -> P_9 [ 3 ] ; _rtB -> jtidsw4hp3 [ 3 ] =
_rtB -> at1eq4ul45 [ 3 ] * _rtB -> pvre3w420d ; _rtB -> efldjtmkbv = _rtP ->
P_13 ; _rtB -> fjfnwwgrbe = _rtP -> P_14 ; _rtB -> fmygpllf40 = _rtP -> P_15
; _rtB -> ppq2nljpur = _rtP -> P_16 ; _rtB -> bjbsexztnp = _rtP -> P_17 ;
_rtB -> db4uypitar = _rtP -> P_18 ; _rtB -> a2y34gtzzo = _rtP -> P_19 ; _rtB
-> kuyzofz0c1 = _rtP -> P_35 ; _rtB -> jq3apgk4nj = _rtP -> P_38 ; _rtB ->
mwoc4aem5x = _rtP -> P_40 ; _rtB -> bfhgfrbwvh = _rtP -> P_43 ; _rtB ->
orkduffjmn = _rtP -> P_44 ; _rtB -> hirmalog3p = _rtP -> P_45 ; _rtB ->
arvmgpp1yj = _rtP -> P_46 ; _rtB -> f3xnpmeb2m = _rtP -> P_47 ; _rtB ->
fnmwtzhcqo = _rtP -> P_63 ; _rtB -> egg4byp5sm = _rtP -> P_66 ; _rtB ->
n0kkxtxeuq = _rtP -> P_68 ; _rtB -> bufkv32hnh = _rtP -> P_71 ; _rtB ->
dolfcdt54b = _rtP -> P_72 ; _rtB -> cnyirpvnk1 = _rtP -> P_73 ; _rtB ->
aqcilldke0 = _rtP -> P_74 ; _rtB -> ckju5mwkuz = _rtP -> P_75 ; _rtB ->
hnkdyd2esb = _rtP -> P_91 ; _rtB -> c5awvfjfsl = _rtP -> P_94 ; _rtB ->
atspuwrc12 = _rtP -> P_96 ; _rtB -> fcmom4rlro = _rtP -> P_99 ; _rtB ->
e3yp4epods = _rtP -> P_100 ; _rtB -> eqvwsfe21z = _rtP -> P_101 ; _rtB ->
bpuxsd5efj = _rtP -> P_102 ; _rtB -> afoqmpcxo2 = _rtP -> P_103 ; _rtB ->
gc2ovlipnf = _rtP -> P_119 ; _rtB -> ayo13uo1wa = _rtP -> P_122 ; _rtB ->
la1abbljvx = _rtP -> P_124 ; _rtB -> mdt5f1k4na = _rtP -> P_128 ; _rtB ->
ix4zqj34sb = _rtP -> P_130 ; nrfrkljgb4TID2 ( & _rtB -> nrfrkljgb41 , (
myg1st0tfa * ) & _rtP -> nrfrkljgb41 ) ; _rtB -> gdklmxkw3o = _rtP -> P_132 ;
_rtB -> ivt01jokr5 = _rtP -> P_134 ; nrfrkljgb4TID2 ( & _rtB -> gdzkcxszzw ,
( myg1st0tfa * ) & _rtP -> gdzkcxszzw ) ; _rtB -> irmq23w5il = _rtP -> P_136
; _rtB -> m0efayzcxy = _rtP -> P_138 ; nrfrkljgb4TID2 ( & _rtB -> fpj3f1xutu
, ( myg1st0tfa * ) & _rtP -> fpj3f1xutu ) ; _rtB -> l4gv1h4w24 = _rtP ->
P_140 ; _rtB -> kayx5icfrq = _rtP -> P_142 ; nrfrkljgb4TID2 ( & _rtB ->
fwourmp1ch , ( myg1st0tfa * ) & _rtP -> fwourmp1ch ) ; ssCallAccelRunBlock (
S , 28 , 439 , SS_CALL_MDL_OUTPUTS ) ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { gjw3c2hq0n * _rtB ;
ey1cddduxp * _rtDW ; _rtDW = ( ( ey1cddduxp * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( gjw3c2hq0n * ) _ssGetModelBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtDW -> ajz0u54jsm = _rtB -> cknc5won5n ; _rtDW -> ebzl2ofgoe =
_rtB -> chweuqwv45 ; _rtDW -> lezbx3zwvh = _rtB -> g3yiuxbunj ; _rtDW ->
dze3loidd5 = _rtB -> enfkjlu4o2 ; _rtDW -> me5mg5rwwa = _rtB -> pbw1ootozw ;
_rtDW -> jyaxtcifce = _rtB -> cguvi3wh3u ; _rtDW -> jxpey1i4yn = _rtB ->
pkjgnxh5jz ; _rtDW -> ivhrjyrewc = _rtB -> csgo3gnqyq ; } UNUSED_PARAMETER (
tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID2 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { gjw3c2hq0n * _rtB ; o3klbcogo3
* _rtXdot ; _rtXdot = ( ( o3klbcogo3 * ) ssGetdX ( S ) ) ; _rtB = ( (
gjw3c2hq0n * ) _ssGetModelBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 28 , 32
, SS_CALL_MDL_DERIVATIVES ) ; _rtXdot -> cxeojb1daj = _rtB -> grsge4ey2c ;
_rtXdot -> jpnzccegos = _rtB -> ob0cpd1sjr ; _rtXdot -> hbzjezrxaa = _rtB ->
hcyjnnhovz ; _rtXdot -> plrlq1n4lb = _rtB -> b3thtgmkcq ; _rtXdot ->
f0j1nzn33x = _rtB -> c0je32umso ; _rtXdot -> nip4ajifhe = _rtB -> hkmuzcm3fa
; _rtXdot -> oru0egare2 = _rtB -> h105ogxueu ; _rtXdot -> gxrnom4kvs = _rtB
-> g4s3hdi1ku ; _rtXdot -> fl3smsk2pa = _rtB -> jqibdnglg4 ; _rtXdot ->
gygufh40me = _rtB -> o0pn3e5klc ; _rtXdot -> eovqkkvnpx = _rtB -> f1sryrcxt4
; _rtXdot -> jzergwlee4 = _rtB -> awcjdb2df1 ; _rtXdot -> d2r23v0g05 = _rtB
-> m4hod2sssc ; _rtXdot -> gd5kx0ir3u = _rtB -> fhrn1ot0cf ; _rtXdot ->
jk2n0iiuzk = _rtB -> ozk0ymxppc ; _rtXdot -> ohlowbif4o = _rtB -> eycuxcgy4u
; _rtXdot -> p0to41lsks = _rtB -> e1ikoxoxdp ; _rtXdot -> i0eikwwksw = _rtB
-> mod3qkcthn ; _rtXdot -> jsywnquoot = _rtB -> gewzhyqjwd ; _rtXdot ->
mytqqyhqjs = _rtB -> mfeyqgzomt ; _rtXdot -> lfw4k0qpar = _rtB -> efnalmv2pp
; _rtXdot -> db4tnlyipx = _rtB -> nzxy4jfqpl ; _rtXdot -> p2jdm4a0dt = _rtB
-> f1kobq02bv ; _rtXdot -> dyocza0fhh = _rtB -> kvfwjfwswe ; _rtXdot ->
ojez0qcspo = _rtB -> op3ubj0wen ; _rtXdot -> m1bdar3z5x = _rtB -> f4j3nkpany
; _rtXdot -> eyft05yr34 = _rtB -> oozc1jejkz ; _rtXdot -> e5wvrueztz = _rtB
-> gt1eqvfhtd ; _rtXdot -> aro51uuwra = _rtB -> gxisbqwjr1 ; _rtXdot ->
fuwg5kqaqs = _rtB -> eianhzvqtl ; _rtXdot -> nztqpvbjju = _rtB -> nivwyjtwme
; _rtXdot -> de34fxevj1 = _rtB -> pvxakq0t4v ; _rtXdot -> owpbcveeep = _rtB
-> bldcxkbarf ; _rtXdot -> oiv3wlpiv1 = _rtB -> jquof1hx34 ; _rtXdot ->
f3t0nd3kjl = _rtB -> oggqgxb44y ; _rtXdot -> jl4hyit2py = _rtB -> kkjiwqmguk
; _rtXdot -> ldmzoudxil = _rtB -> izcrjfdstr ; _rtXdot -> hzzjfqiowf = _rtB
-> ltc3x4g13l ; _rtXdot -> cnzg1rfsdu = _rtB -> jb4llouefe ; _rtXdot ->
kk0suzgb3o = _rtB -> p4er4kkq1i ; }
#define MDL_PROJECTION
static void mdlProjection ( SimStruct * S ) { ssCallAccelRunBlock ( S , 28 ,
32 , SS_CALL_MDL_PROJECTION ) ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { gjw3c2hq0n * _rtB ;
pn00hmq1oq * _rtP ; gvg0eycvzd * _rtZCSV ; ey1cddduxp * _rtDW ; _rtDW = ( (
ey1cddduxp * ) ssGetRootDWork ( S ) ) ; _rtZCSV = ( ( gvg0eycvzd * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( ( pn00hmq1oq * ) ssGetModelRtp (
S ) ) ; _rtB = ( ( gjw3c2hq0n * ) _ssGetModelBlockIO ( S ) ) ; _rtZCSV ->
orcgm15ppr = _rtB -> fzuymbvivo - _rtP -> P_25 ; _rtZCSV -> hocitb4k5o = _rtB
-> fzuymbvivo - _rtP -> P_26 ; _rtZCSV -> jpibqacxxc = _rtB -> pyb2whaz1q -
_rtP -> P_32 ; _rtZCSV -> h43hgwikx3 = _rtB -> pyb2whaz1q - _rtP -> P_33 ;
_rtZCSV -> afxkxog2xm = _rtB -> oavxtosfyf - _rtB -> d45j2mfj2n ; _rtZCSV ->
jsndm0hjbh = _rtB -> oavxtosfyf - _rtB -> kuyzofz0c1 ; _rtZCSV -> asc5l0mnju
= _rtB -> ftg3bfo40p - _rtB -> jq3apgk4nj ; _rtZCSV -> p0mtxoa5xp = _rtB ->
ftg3bfo40p - _rtB -> mwoc4aem5x ; _rtZCSV -> m3anvrngsy = _rtB -> kqi21egmuf
- _rtP -> P_53 ; _rtZCSV -> k3wa4o0dxk = _rtB -> kqi21egmuf - _rtP -> P_54 ;
_rtZCSV -> kq0bc5dem2 = _rtB -> hqnpewltuj - _rtP -> P_60 ; _rtZCSV ->
djj2vhnyos = _rtB -> hqnpewltuj - _rtP -> P_61 ; _rtZCSV -> dr3fcrt5nm = _rtB
-> im3cdxu1xy - _rtB -> bfhgfrbwvh ; _rtZCSV -> jd0untccg0 = _rtB ->
im3cdxu1xy - _rtB -> fnmwtzhcqo ; _rtZCSV -> b3kfm03xxf = _rtB -> pb1dz3kkx0
- _rtB -> egg4byp5sm ; _rtZCSV -> hhb53j3qjl = _rtB -> pb1dz3kkx0 - _rtB ->
n0kkxtxeuq ; _rtZCSV -> ipcibgjl5f = _rtB -> m4nk3qn5jz - _rtP -> P_81 ;
_rtZCSV -> fknulzynms = _rtB -> m4nk3qn5jz - _rtP -> P_82 ; _rtZCSV ->
g50iamo05m = _rtB -> osksjb1cuc - _rtP -> P_88 ; _rtZCSV -> ol35qhhn4i = _rtB
-> osksjb1cuc - _rtP -> P_89 ; _rtZCSV -> lt1gvmr2cx = _rtB -> fqdvqq43ng -
_rtB -> bufkv32hnh ; _rtZCSV -> pnjkjpmdss = _rtB -> fqdvqq43ng - _rtB ->
hnkdyd2esb ; _rtZCSV -> ieo4fqypob = _rtB -> io01e0xual - _rtB -> c5awvfjfsl
; _rtZCSV -> oqdcjseghx = _rtB -> io01e0xual - _rtB -> atspuwrc12 ; _rtZCSV
-> mtb5pkawkr = _rtB -> f04zp5o0lg - _rtP -> P_109 ; _rtZCSV -> lkxwf0r1kc =
_rtB -> f04zp5o0lg - _rtP -> P_110 ; _rtZCSV -> htkbyo2zk2 = _rtB ->
iqxqfzwt1t - _rtP -> P_116 ; _rtZCSV -> mqsonpqr5o = _rtB -> iqxqfzwt1t -
_rtP -> P_117 ; _rtZCSV -> blx2gu5y0c = _rtB -> gumk4r3kva - _rtB ->
fcmom4rlro ; _rtZCSV -> niisubzizv = _rtB -> gumk4r3kva - _rtB -> gc2ovlipnf
; _rtZCSV -> gyloeqa4gg = _rtB -> p3h0g0snlv - _rtB -> ayo13uo1wa ; _rtZCSV
-> meehffcia0 = _rtB -> p3h0g0snlv - _rtB -> la1abbljvx ; _rtZCSV ->
enl5layjfv = 0.0 ; if ( _rtB -> jxklyhvaee > 0.0 ) { _rtZCSV -> enl5layjfv =
1.0 ; } { real_T * zcsv = & ( ( ( gvg0eycvzd * ) ssGetSolverZcSignalVector (
S ) ) -> nrfrkljgb41 . gqijqi0as0 ) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ )
{ zcsv [ i ] = 0.0 ; } } if ( _rtDW -> juc3cooyqb == 0 ) { cgmwjmky2g ( &
_rtB -> nrfrkljgb41 , ( myg1st0tfa * ) & _rtP -> nrfrkljgb41 , & _rtZCSV ->
nrfrkljgb41 ) ; } _rtZCSV -> ny252wij03 = 0.0 ; if ( _rtB -> dlomiozwtn > 0.0
) { _rtZCSV -> ny252wij03 = 1.0 ; } { real_T * zcsv = & ( ( ( gvg0eycvzd * )
ssGetSolverZcSignalVector ( S ) ) -> gdzkcxszzw . gqijqi0as0 ) ; int_T i ;
for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i ] = 0.0 ; } } if ( _rtDW ->
air5odkdn1 == 0 ) { cgmwjmky2g ( & _rtB -> gdzkcxszzw , ( myg1st0tfa * ) &
_rtP -> gdzkcxszzw , & _rtZCSV -> gdzkcxszzw ) ; } _rtZCSV -> mxtkjolcq4 =
0.0 ; if ( _rtB -> m2ub1bsc1t > 0.0 ) { _rtZCSV -> mxtkjolcq4 = 1.0 ; } {
real_T * zcsv = & ( ( ( gvg0eycvzd * ) ssGetSolverZcSignalVector ( S ) ) ->
fpj3f1xutu . gqijqi0as0 ) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i
] = 0.0 ; } } if ( _rtDW -> nclypgegew == 0 ) { cgmwjmky2g ( & _rtB ->
fpj3f1xutu , ( myg1st0tfa * ) & _rtP -> fpj3f1xutu , & _rtZCSV -> fpj3f1xutu
) ; } _rtZCSV -> nuozwemw0j = 0.0 ; if ( _rtB -> jt2c0fz5cf > 0.0 ) { _rtZCSV
-> nuozwemw0j = 1.0 ; } { real_T * zcsv = & ( ( ( gvg0eycvzd * )
ssGetSolverZcSignalVector ( S ) ) -> fwourmp1ch . gqijqi0as0 ) ; int_T i ;
for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i ] = 0.0 ; } } if ( _rtDW ->
iczwe02roz == 0 ) { cgmwjmky2g ( & _rtB -> fwourmp1ch , ( myg1st0tfa * ) &
_rtP -> fwourmp1ch , & _rtZCSV -> fwourmp1ch ) ; } _rtZCSV -> kwyx05uol4 =
_rtB -> kqi21egmuf - _rtP -> P_144 ; _rtZCSV -> mqdeqznjyy = _rtB ->
kqi21egmuf - _rtP -> P_145 ; _rtZCSV -> hlnef0l4zk = _rtB -> pmhifjwn2o -
_rtB -> blsuevmlcn ; _rtZCSV -> iwviivxrqt = _rtB -> blsuevmlcn ; _rtZCSV ->
het5negazg = _rtB -> h0oizzq4os ; _rtZCSV -> eyy5sqvz0l = _rtB -> hqnpewltuj
- _rtP -> P_149 ; _rtZCSV -> otg24bf2b5 = _rtB -> hqnpewltuj - _rtP -> P_150
; _rtZCSV -> hslbxntrai = _rtB -> ljfg0mbcvv - _rtB -> dmt0x5ciax ; _rtZCSV
-> ah35e2hcou = _rtB -> dmt0x5ciax ; _rtZCSV -> lkvipxtmn1 = _rtB ->
oewy2hp03d ; _rtZCSV -> dl4us3lewv = _rtB -> m4nk3qn5jz - _rtP -> P_154 ;
_rtZCSV -> fswd4jj2dj = _rtB -> m4nk3qn5jz - _rtP -> P_155 ; _rtZCSV ->
mcvoiumywz = _rtB -> npunsrv4vt - _rtB -> cwdv4kxqla ; _rtZCSV -> gpnujt51nx
= _rtB -> cwdv4kxqla ; _rtZCSV -> lxldpd3fjf = _rtB -> m0sbzxsqet ; _rtZCSV
-> ciatjjievn = _rtB -> osksjb1cuc - _rtP -> P_159 ; _rtZCSV -> ezumiwg4uh =
_rtB -> osksjb1cuc - _rtP -> P_160 ; _rtZCSV -> kkghraxnth = _rtB ->
e4bet41oob - _rtB -> cotooafzk4 ; _rtZCSV -> cakl1dcpbk = _rtB -> cotooafzk4
; _rtZCSV -> n01rpkloin = _rtB -> bjuskw14gm ; _rtZCSV -> hts41lyaa3 = _rtB
-> f04zp5o0lg - _rtP -> P_164 ; _rtZCSV -> lis1qlx3qd = _rtB -> f04zp5o0lg -
_rtP -> P_165 ; _rtZCSV -> nyasku0pmq = _rtB -> i1vxjab5q2 - _rtB ->
b5rwap1dnf ; _rtZCSV -> axgo5ye3u2 = _rtB -> b5rwap1dnf ; _rtZCSV ->
j1hcsckcrd = _rtB -> objuqcchzk ; _rtZCSV -> mbvhpdvmla = _rtB -> iqxqfzwt1t
- _rtP -> P_169 ; _rtZCSV -> l4v0yty2kw = _rtB -> iqxqfzwt1t - _rtP -> P_170
; _rtZCSV -> njt3sdkvxu = _rtB -> nkxbwokvpb - _rtB -> dlbqkeuixo ; _rtZCSV
-> l50cfdjcjc = _rtB -> dlbqkeuixo ; _rtZCSV -> icyqapwkid = _rtB ->
lzmaxcpr13 ; _rtZCSV -> mifqfhjkxi = _rtB -> fzuymbvivo - _rtP -> P_174 ;
_rtZCSV -> fjzn0x2p5f = _rtB -> fzuymbvivo - _rtP -> P_175 ; _rtZCSV ->
mqnbcejyqn = _rtB -> jr2f1yqfth - _rtB -> cnifyxtjkl ; _rtZCSV -> fltkhbyah3
= _rtB -> cnifyxtjkl ; _rtZCSV -> cyxzs1iskf = _rtB -> cngdrskut4 ; _rtZCSV
-> etdla2x0a5 = _rtB -> pyb2whaz1q - _rtP -> P_179 ; _rtZCSV -> hb32szvibj =
_rtB -> pyb2whaz1q - _rtP -> P_180 ; _rtZCSV -> cn3qjj5zzd = _rtB ->
csckzaxojd - _rtB -> csp31kbg3k ; _rtZCSV -> b5gvih2nbd = _rtB -> csp31kbg3k
; _rtZCSV -> nrjlbmpwrz = _rtB -> ll0xvtqlfe ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 3838690734U
) ; ssSetChecksumVal ( S , 1 , 2147005916U ) ; ssSetChecksumVal ( S , 2 ,
4133738319U ) ; ssSetChecksumVal ( S , 3 , 3287262100U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.7" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( ey1cddduxp ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( gjw3c2hq0n ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
pn00hmq1oq ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & ktqfipxpsj ) ; _ssSetConstBlockIO ( S , & lxqhjkwgjl ) ; rt_InitInfAndNaN
( sizeof ( real_T ) ) ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_25 =
rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_26 = rtMinusInf ; ( (
pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_32 = rtInf ; ( ( pn00hmq1oq * )
ssGetModelRtp ( S ) ) -> P_33 = rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp
( S ) ) -> P_53 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_54 =
rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_60 = rtInf ; ( (
pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_61 = rtMinusInf ; ( ( pn00hmq1oq *
) ssGetModelRtp ( S ) ) -> P_81 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp (
S ) ) -> P_82 = rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_88
= rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_89 = rtMinusInf ; ( (
pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_109 = rtInf ; ( ( pn00hmq1oq * )
ssGetModelRtp ( S ) ) -> P_110 = rtMinusInf ; ( ( pn00hmq1oq * )
ssGetModelRtp ( S ) ) -> P_116 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S
) ) -> P_117 = rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_144
= rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_145 = rtInf ; (
( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_149 = rtMinusInf ; ( ( pn00hmq1oq
* ) ssGetModelRtp ( S ) ) -> P_150 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp
( S ) ) -> P_154 = rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) ->
P_155 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_159 =
rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_160 = rtInf ; ( (
pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_164 = rtMinusInf ; ( ( pn00hmq1oq *
) ssGetModelRtp ( S ) ) -> P_165 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp (
S ) ) -> P_169 = rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) ->
P_170 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_174 =
rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_175 = rtInf ; ( (
pn00hmq1oq * ) ssGetModelRtp ( S ) ) -> P_179 = rtMinusInf ; ( ( pn00hmq1oq *
) ssGetModelRtp ( S ) ) -> P_180 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp (
S ) ) -> fwourmp1ch . P_2 = rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S
) ) -> fwourmp1ch . P_7 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) ->
fpj3f1xutu . P_2 = rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) ->
fpj3f1xutu . P_7 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) ->
gdzkcxszzw . P_2 = rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) ->
gdzkcxszzw . P_7 = rtInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) ->
nrfrkljgb41 . P_2 = rtMinusInf ; ( ( pn00hmq1oq * ) ssGetModelRtp ( S ) ) ->
nrfrkljgb41 . P_7 = rtInf ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { { SimStruct * childS ; SysOutputFcn * callSysFcns ; childS
= ssGetSFunction ( S , 0 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 1 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 2 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 3 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 4 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 5 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 6 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 7 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 8 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 9 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 10 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 11 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; }
slAccRegPrmChangeFcn ( S , mdlOutputsTID2 ) ; } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
