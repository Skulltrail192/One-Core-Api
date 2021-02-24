#include <asm.inc>

.code
.align 4

MACRO(DEFINE_ALIAS, alias, alias2, origstring)
PUBLIC alias
.weakref alias2, origstring
alias:
    jmp alias2
ENDM

#define DEFINE_ALIAS(alias, orig) DEFINE_ALIAS alias, __wrap_ ## alias, #orig

DEFINE_ALIAS(__ZN8CHString16AllocBeforeWriteEi, ?AllocBeforeWrite@CHString@@IAEXH@Z)
DEFINE_ALIAS(__ZN8CHString11AllocBufferEi, ?AllocBuffer@CHString@@IAEXH@Z)
DEFINE_ALIAS(__ZNK8CHString9AllocCopyERS_iii, ?AllocCopy@CHString@@IBEXAAV1@HHH@Z)
DEFINE_ALIAS(__ZNK8CHString14AllocSysStringEv, ?AllocSysString@CHString@@QBEPAGXZ)
DEFINE_ALIAS(__ZN8CHString10AssignCopyEiPKw, ?AssignCopy@CHString@@IAEXHPBG@Z)
DEFINE_ALIAS(__ZN8CHStringC1ERKS_, ??0CHString@@QAE@ABV0@@Z)
DEFINE_ALIAS(__ZN8CHStringC1EPKc, ??0CHString@@QAE@PBD@Z)
DEFINE_ALIAS(__ZN8CHStringC1EPKh, ??0CHString@@QAE@PBE@Z)
DEFINE_ALIAS(__ZN8CHStringC1EPKw, ??0CHString@@QAE@PBG@Z)
DEFINE_ALIAS(__ZN8CHStringC1EPKwi, ??0CHString@@QAE@PBGH@Z)
DEFINE_ALIAS(__ZN8CHStringC1Ewi, ??0CHString@@QAE@GH@Z)
DEFINE_ALIAS(__ZN8CHStringC1Ev, ??0CHString@@QAE@XZ)
DEFINE_ALIAS(__ZN8CHStringC2Ev, ??0CHString@@QAE@XZ) // CHString::CHString(void)
DEFINE_ALIAS(__ZNK8CHString7CollateEPKw, ?Collate@CHString@@QBEHPBG@Z)
DEFINE_ALIAS(__ZNK8CHString7CompareEPKw, ?Compare@CHString@@QBEHPBG@Z)
DEFINE_ALIAS(__ZNK8CHString13CompareNoCaseEPKw, ?CompareNoCase@CHString@@QBEHPBG@Z)
DEFINE_ALIAS(__ZN8CHString10ConcatCopyEiPKwiS1_, ?ConcatCopy@CHString@@IAEXHPBGH0@Z)
DEFINE_ALIAS(__ZN8CHString13ConcatInPlaceEiPKw, ?ConcatInPlace@CHString@@IAEXHPBG@Z)
DEFINE_ALIAS(__ZN8CHString15CopyBeforeWriteEv, ?CopyBeforeWrite@CHString@@IAEXXZ)
DEFINE_ALIAS(__ZN8CHString5EmptyEv, ?Empty@CHString@@QAEXXZ)
DEFINE_ALIAS(__ZNK8CHString4FindEPKw, ?Find@CHString@@QBEHPBG@Z)
DEFINE_ALIAS(__ZNK8CHString4FindEw, ?Find@CHString@@QBEHG@Z)
DEFINE_ALIAS(__ZNK8CHString9FindOneOfEPKw, ?FindOneOf@CHString@@QBEHPBG@Z)
DEFINE_ALIAS(__ZN8CHString6FormatEjz, ?Format@CHString@@QAAXIZZ)
DEFINE_ALIAS(__ZN8CHString6FormatEPKwz, ?Format@CHString@@QAAXPBGZZ)
DEFINE_ALIAS(__ZN8CHString14FormatMessageWEjz, ?FormatMessageW@CHString@@QAAXIZZ)
DEFINE_ALIAS(__ZN8CHString14FormatMessageWEPKwz, ?FormatMessageW@CHString@@QAAXPBGZZ)
DEFINE_ALIAS(__ZN8CHString7FormatVEPKwPc, ?FormatV@CHString@@QAEXPBGPAD@Z)
DEFINE_ALIAS(__ZN8CHString9FreeExtraEv, ?FreeExtra@CHString@@QAEXXZ)
DEFINE_ALIAS(__ZNK8CHString14GetAllocLengthEv, ?GetAllocLength@CHString@@QBEHXZ)
DEFINE_ALIAS(__ZNK8CHString5GetAtEi, ?GetAt@CHString@@QBEGH@Z)
DEFINE_ALIAS(__ZN8CHString9GetBufferEi, ?GetBuffer@CHString@@QAEPAGH@Z)
DEFINE_ALIAS(__ZN8CHString18GetBufferSetLengthEi, ?GetBufferSetLength@CHString@@QAEPAGH@Z)
DEFINE_ALIAS(__ZNK8CHString7GetDataEv, ?GetData@CHString@@IBEPAUCHStringData@@XZ)
DEFINE_ALIAS(__ZNK8CHString9GetLengthEv, ?GetLength@CHString@@QBEHXZ)
DEFINE_ALIAS(__ZN8CHString4InitEv, ?Init@CHString@@IAEXXZ)
DEFINE_ALIAS(__ZNK8CHString7IsEmptyEv, ?IsEmpty@CHString@@QBEHXZ)
DEFINE_ALIAS(__ZNK8CHString4LeftEi, ?Left@CHString@@QBE?AV1@H@Z)
DEFINE_ALIAS(__ZN8CHString11LoadStringWEj, ?LoadStringW@CHString@@QAEHI@Z)
DEFINE_ALIAS(__ZN8CHString11LoadStringWEjPwj, ?LoadStringW@CHString@@IAEHIPAGI@Z)
DEFINE_ALIAS(__ZN8CHString10LockBufferEv, ?LockBuffer@CHString@@QAEPAGXZ)
DEFINE_ALIAS(__ZN8CHString9MakeLowerEv, ?MakeLower@CHString@@QAEXXZ)
DEFINE_ALIAS(__ZN8CHString11MakeReverseEv, ?MakeReverse@CHString@@QAEXXZ)
DEFINE_ALIAS(__ZN8CHString9MakeUpperEv, ?MakeUpper@CHString@@QAEXXZ)
DEFINE_ALIAS(__ZNK8CHString3MidEi, ?Mid@CHString@@QBE?AV1@H@Z)
DEFINE_ALIAS(__ZNK8CHString3MidEii, ?Mid@CHString@@QBE?AV1@HH@Z)
DEFINE_ALIAS(__ZN8CHString7ReleaseEP12CHStringData@4, ?Release@CHString@@KGXPAUCHStringData@@@Z)
DEFINE_ALIAS(__ZN8CHString7ReleaseEv, ?Release@CHString@@IAEXXZ)
DEFINE_ALIAS(__ZN8CHString13ReleaseBufferEi, ?ReleaseBuffer@CHString@@QAEXH@Z)
DEFINE_ALIAS(__ZNK8CHString11ReverseFindEw, ?ReverseFind@CHString@@QBEHG@Z)
DEFINE_ALIAS(__ZNK8CHString5RightEi, ?Right@CHString@@QBE?AV1@H@Z)
DEFINE_ALIAS(__ZN8CHString10SafeStrlenEPKw@4, ?SafeStrlen@CHString@@KGHPBG@Z)
DEFINE_ALIAS(__ZN8CHString5SetAtEiw, ?SetAt@CHString@@QAEXHG@Z)
DEFINE_ALIAS(__ZNK8CHString13SpanExcludingEPKw, ?SpanExcluding@CHString@@QBE?AV1@PBG@Z)
DEFINE_ALIAS(__ZNK8CHString13SpanIncludingEPKw, ?SpanIncluding@CHString@@QBE?AV1@PBG@Z)
DEFINE_ALIAS(__ZN8CHString8TrimLeftEv, ?TrimLeft@CHString@@QAEXXZ)
DEFINE_ALIAS(__ZN8CHString9TrimRightEv, ?TrimRight@CHString@@QAEXXZ)
DEFINE_ALIAS(__ZN8CHString12UnlockBufferEv, ?UnlockBuffer@CHString@@QAEXXZ)
DEFINE_ALIAS(__ZNK8CHStringcvPKwEv, ??BCHString@@QBEPBGXZ)
DEFINE_ALIAS(__ZN8CHStringpLERKS_, ??YCHString@@QAEABV0@ABV0@@Z)
DEFINE_ALIAS(__ZN8CHStringpLEc, ??YCHString@@QAEABV0@D@Z)
DEFINE_ALIAS(__ZN8CHStringpLEPKw, ??YCHString@@QAEABV0@PBG@Z)
DEFINE_ALIAS(__ZN8CHStringpLEw, ??YCHString@@QAEABV0@G@Z)
DEFINE_ALIAS(__ZN8CHStringaSEPS_, ??4CHString@@QAEABV0@PAV0@@Z)
DEFINE_ALIAS(__ZN8CHStringaSERKS_, ??4CHString@@QAEABV0@ABV0@@Z)
DEFINE_ALIAS(__ZN8CHStringaSEPKc, ??4CHString@@QAEABV0@PBD@Z)
DEFINE_ALIAS(__ZN8CHStringaSEc, ??4CHString@@QAEABV0@D@Z)
DEFINE_ALIAS(__ZN8CHStringaSEPKh, ??4CHString@@QAEABV0@PBE@Z)
DEFINE_ALIAS(__ZN8CHStringaSEPKw, ??4CHString@@QAEABV0@PBG@Z)
DEFINE_ALIAS(__ZN8CHStringaSEw, ??4CHString@@QAEABV0@G@Z)
DEFINE_ALIAS(__ZNK8CHStringixEi, ??ACHString@@QBEGH@Z)
DEFINE_ALIAS(__ZN8CHStringD1Ev, ??1CHString@@QAE@XZ) // CHString::~CHString() complete object destructor
DEFINE_ALIAS(__ZN8CHStringD2Ev, ??1CHString@@QAE@XZ) // CHString::~CHString() base object destructor
DEFINE_ALIAS(__ZplwRK8CHString, ??H@YG?AVCHString@@GABV0@@Z)
DEFINE_ALIAS(__ZplRK8CHStringw, ??H@YG?AVCHString@@ABV0@G@Z)
DEFINE_ALIAS(__ZplRK8CHStringPKw, ??H@YG?AVCHString@@ABV0@PBG@Z)
DEFINE_ALIAS(__ZplPKwRK8CHString, ??H@YG?AVCHString@@PBGABV0@@Z)
DEFINE_ALIAS(__ZplRK8CHStringS1_, ??H@YG?AVCHString@@ABV0@0@Z)
DEFINE_ALIAS(__ZN8Provider5FlushEv, ?Flush@Provider@@MAEXXZ)
DEFINE_ALIAS(__ZN8Provider21ValidateDeletionFlagsEl, ?ValidateDeletionFlags@Provider@@MAEJJ@Z)
DEFINE_ALIAS(__ZN8Provider19ValidateMethodFlagsEl, ?ValidateMethodFlags@Provider@@MAEJJ@Z)
DEFINE_ALIAS(__ZN8Provider18ValidateQueryFlagsEl, ?ValidateQueryFlags@Provider@@MAEJJ@Z)

END
