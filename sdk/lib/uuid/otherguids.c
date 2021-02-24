

#include <initguid.h>
#include <oleauto.h>

DEFINE_GUID(IID_IDirectPlaySP,               0xc9f6360, 0xcc61, 0x11cf, 0xac, 0xec, 0x0, 0xaa, 0x0, 0x68, 0x86, 0xe3);
DEFINE_GUID(IID_ISFHelper,                   0x1fe68efb,0x1874,0x9812,0x56,0xdc,0x00,0x00,0x00,0x00,0x00,0x00);
DEFINE_GUID(IID_IDPLobbySP,                  0x5a4e5a20,0x2ced,0x11d0,0xa8,0x89,0x00,0xa0,0xc9,0x05,0x43,0x3c);
DEFINE_GUID(IID_IEnumNetConnection,          0xC08956A0,0x1CD3,0x11D1,0xB1,0xC5,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetConnectionManager,       0xC08956A2,0x1CD3,0x11D1,0xB1,0xC5,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetConnectionConnectUi,     0xC08956A3,0x1CD3,0x11D1,0xB1,0xC5,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetConnectionPropertyUi,    0xC08956A4,0x1CD3,0x11D1,0xB1,0xC5,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetLanConnectionUiInfo,     0xC08956A6,0x1CD3,0x11D1,0xB1,0xC5,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_IEnumNetCfgBindingInterface, 0xC0E8AE90,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_IEnumNetCfgBindingPath,      0xC0E8AE91,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_IEnumNetCfgComponent,        0xC0E8AE92,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetCfg,                     0xC0E8AE93,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetCfgBindingInterface,     0xC0E8AE94,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetCfgBindingPath,          0xC0E8AE96,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetCfgClass,                0xC0E8AE97,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetCfgComponent,            0xC0E8AE99,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetCfgClassSetup,           0xC0E8AE9D,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetCfgComponentBindings,    0xC0E8AE9E,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetCfgLock,                 0xC0E8AE9F,0x306E,0x11D1,0xAA,0xCF,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetConnectionPropertyUi2,   0xC08956B9,0x1CD3,0x11D1,0xB1,0xC5,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(IID_INetCfgPnpReconfigCallback,  0x8D84BD35,0xE227,0x11D2,0xB7,0x00,0x00,0xA0,0xC9,0x8A,0x6A,0x85);
DEFINE_GUID(IID_INetCfgComponentPropertyUi,  0x932238E0,0xBEA1,0x11D0,0x92,0x98,0x00,0xC0,0x4f,0xC9,0x9D,0xCF);
DEFINE_GUID(IID_INetCfgComponentControl,     0x932238DF,0xBEA1,0x11D0,0x92,0x98,0x00,0xC0,0x4f,0xC9,0x9D,0xCF);
DEFINE_GUID(FMTID_SummaryInformation,0xF29F85E0,0x4FF9,0x1068,0xAB,0x91,0x08,0x00,0x2B,0x27,0xB3,0xD9);
DEFINE_GUID(FMTID_DocSummaryInformation,0xD5CDD502,0x2E9C,0x101B,0x93,0x97,0x08,0x00,0x2B,0x2C,0xF9,0xAE);
DEFINE_GUID(FMTID_UserDefinedProperties,0xD5CDD505,0x2E9C,0x101B,0x93,0x97,0x08,0x00,0x2B,0x2C,0xF9,0xAE);
DEFINE_GUID(CLSID_InProcFreeMarshaler,    0x0000033a,0x0000,0x0000,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);
DEFINE_GUID(CLSID_TF_ThreadMgr,           0x529a9e6b,0x6587,0x4f23,0xab,0x9e,0x9c,0x7d,0x68,0x3e,0x3c,0x50);
DEFINE_GUID(CLSID_TF_InputProcessorProfiles, 0x33c53a50,0xf456,0x4884,0xb0,0x49,0x85,0xfd,0x64,0x3e,0xcf,0xed);
DEFINE_GUID(CLSID_TF_CategoryMgr,         0xA4B544A1,0x438D,0x4B41,0x93,0x25,0x86,0x95,0x23,0xE2,0xD6,0xC7);
DEFINE_GUID(CLSID_TF_LangBarMgr,          0xebb08c45,0x6c4a,0x4fdc,0xae,0x53,0x4e,0xb8,0xc4,0xc7,0xdb,0x8e);
DEFINE_GUID(CLSID_TF_DisplayAttributeMgr, 0x3ce74de4,0x53d3,0x4d74,0x8b,0x83,0x43,0x1b,0x38,0x28,0xba,0x53);
DEFINE_GUID(GUID_TFCAT_TIP_KEYBOARD,     0x34745c63,0xb2f0,0x4784,0x8b,0x67,0x5e,0x12,0xc8,0x70,0x1a,0x31);
DEFINE_GUID(GUID_TFCAT_TIP_SPEECH,       0xB5A73CD1,0x8355,0x426B,0xA1,0x61,0x25,0x98,0x08,0xF2,0x6B,0x14);
DEFINE_GUID(GUID_TFCAT_TIP_HANDWRITING,  0x246ecb87,0xc2f2,0x4abe,0x90,0x5b,0xc8,0xb3,0x8a,0xdd,0x2c,0x43);
DEFINE_GUID(CLSID_ConnectionManager,      0xBA126AD1,0x2166,0x11D1,0xB1,0xD0,0x0,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(CLSID_CNetCfg,                0x5B035261,0x40F9,0x11D1,0xAA,0xEC,0x00,0x80,0x5F,0xC1,0x27,0x0E);
DEFINE_GUID(GUID_TFCAT_DISPLAYATTRIBUTEPROVIDER,  0x046B8C80,0x1647,0x40F7,0x9B,0x21,0xB9,0x3B,0x81,0xAA,0xBC,0x1B);
DEFINE_GUID(GUID_COMPARTMENT_KEYBOARD_DISABLED,     0x71a5b253,0x1951,0x466b,0x9f,0xbc,0x9c,0x88,0x08,0xfa,0x84,0xf2);
DEFINE_GUID(GUID_COMPARTMENT_KEYBOARD_OPENCLOSE,    0x58273aad,0x01bb,0x4164,0x95,0xc6,0x75,0x5b,0xa0,0xb5,0x16,0x2d);
DEFINE_GUID(GUID_COMPARTMENT_HANDWRITING_OPENCLOSE, 0xf9ae2c6b,0x1866,0x4361,0xaf,0x72,0x7a,0xa3,0x09,0x48,0x89,0x0e);
DEFINE_GUID(GUID_COMPARTMENT_SPEECH_DISABLED,       0x56c5c607,0x0703,0x4e59,0x8e,0x52,0xcb,0xc8,0x4e,0x8b,0xbe,0x35);
DEFINE_GUID(GUID_COMPARTMENT_SPEECH_OPENCLOSE,      0x544d6a63,0xe2e8,0x4752,0xbb,0xd1,0x00,0x09,0x60,0xbc,0xa0,0x83);
DEFINE_GUID(GUID_COMPARTMENT_SPEECH_GLOBALSTATE,    0x2a54fe8e,0x0d08,0x460c,0xa7,0x5d,0x87,0x03,0x5f,0xf4,0x36,0xc5);
DEFINE_GUID(GUID_COMPARTMENT_PERSISTMENUENABLED,    0x575f3783,0x70c8,0x47c8,0xae,0x5d,0x91,0xa0,0x1a,0x1f,0x75,0x92);
DEFINE_GUID(GUID_COMPARTMENT_EMPTYCONTEXT,          0xd7487dbf,0x804e,0x41c5,0x89,0x4d,0xad,0x96,0xfd,0x4e,0xea,0x13);
DEFINE_GUID(GUID_COMPARTMENT_TIPUISTATUS,           0x148ca3ec,0x0366,0x401c,0x8d,0x75,0xed,0x97,0x8d,0x85,0xfb,0xc9);

DEFINE_GUID(IID_IDsObjectPicker, 0x0c87e64e, 0x3b7a, 0x11d2, 0x00b9, 0xe0,0x00,0xc0,0x4f,0xd8,0xdb,0xf7);
DEFINE_GUID(CLSID_DsObjectPicker, 0x17d6ccd8, 0x3b7b, 0x11d2, 0x00b9, 0xe0,0x00,0xc0,0x4f,0xd8,0xdb,0xf7);
DEFINE_GUID(CLSID_StdPicture, 0x0BE35204, 0x8F91, 0x11CE, 0x9D,0xE3, 0x00,0xAA,0x00,0x4B,0xB8,0x51);
DEFINE_GUID(CLSID_StdFont,    0x0BE35203, 0x8F91, 0x11CE, 0x9D,0xE3, 0x00,0xAA,0x00,0x4B,0xB8,0x51);

DEFINE_GUID(SID_VariantConversion, 0x1f101481,0xbccd,0x11d0,0x93,0x36,0x00,0xa0,0xc9,0xd,0xca,0xa9);

DEFINE_GUID(KSDATAFORMAT_SUBTYPE_PCM, 0x00000001, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
DEFINE_GUID(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT, 0x00000003, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
