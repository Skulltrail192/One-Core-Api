/*
 * Copyright 2009 Henri Verbeet for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 */

#include <main.h>

#define MAX_GDI_HANDLES  16384
#define FIRST_GDI_HANDLE 32

typedef struct tagBITMAPOBJ
{
     DIBSECTION          dib;
     SIZE                size;   /* For SetBitmapDimension() */
     RGBQUAD            *color_table;  /* DIB color table if <= 8bpp (always 1 << bpp in size) */
} BITMAPOBJ;

const RGBQUAD *get_default_color_table( int bpp )
{
    static const RGBQUAD table_1[2] =
    {
        { 0x00, 0x00, 0x00 }, { 0xff, 0xff, 0xff }
    };
    static const RGBQUAD table_4[16] =
    {
        { 0x00, 0x00, 0x00 }, { 0x00, 0x00, 0x80 }, { 0x00, 0x80, 0x00 }, { 0x00, 0x80, 0x80 },
        { 0x80, 0x00, 0x00 }, { 0x80, 0x00, 0x80 }, { 0x80, 0x80, 0x00 }, { 0x80, 0x80, 0x80 },
        { 0xc0, 0xc0, 0xc0 }, { 0x00, 0x00, 0xff }, { 0x00, 0xff, 0x00 }, { 0x00, 0xff, 0xff },
        { 0xff, 0x00, 0x00 }, { 0xff, 0x00, 0xff }, { 0xff, 0xff, 0x00 }, { 0xff, 0xff, 0xff },
    };
    static const RGBQUAD table_8[256] =
    {
        /* first and last 10 entries are the default system palette entries */
        { 0x00, 0x00, 0x00 }, { 0x00, 0x00, 0x80 }, { 0x00, 0x80, 0x00 }, { 0x00, 0x80, 0x80 },
        { 0x80, 0x00, 0x00 }, { 0x80, 0x00, 0x80 }, { 0x80, 0x80, 0x00 }, { 0xc0, 0xc0, 0xc0 },
        { 0xc0, 0xdc, 0xc0 }, { 0xf0, 0xca, 0xa6 }, { 0x00, 0x20, 0x40 }, { 0x00, 0x20, 0x60 },
        { 0x00, 0x20, 0x80 }, { 0x00, 0x20, 0xa0 }, { 0x00, 0x20, 0xc0 }, { 0x00, 0x20, 0xe0 },
        { 0x00, 0x40, 0x00 }, { 0x00, 0x40, 0x20 }, { 0x00, 0x40, 0x40 }, { 0x00, 0x40, 0x60 },
        { 0x00, 0x40, 0x80 }, { 0x00, 0x40, 0xa0 }, { 0x00, 0x40, 0xc0 }, { 0x00, 0x40, 0xe0 },
        { 0x00, 0x60, 0x00 }, { 0x00, 0x60, 0x20 }, { 0x00, 0x60, 0x40 }, { 0x00, 0x60, 0x60 },
        { 0x00, 0x60, 0x80 }, { 0x00, 0x60, 0xa0 }, { 0x00, 0x60, 0xc0 }, { 0x00, 0x60, 0xe0 },
        { 0x00, 0x80, 0x00 }, { 0x00, 0x80, 0x20 }, { 0x00, 0x80, 0x40 }, { 0x00, 0x80, 0x60 },
        { 0x00, 0x80, 0x80 }, { 0x00, 0x80, 0xa0 }, { 0x00, 0x80, 0xc0 }, { 0x00, 0x80, 0xe0 },
        { 0x00, 0xa0, 0x00 }, { 0x00, 0xa0, 0x20 }, { 0x00, 0xa0, 0x40 }, { 0x00, 0xa0, 0x60 },
        { 0x00, 0xa0, 0x80 }, { 0x00, 0xa0, 0xa0 }, { 0x00, 0xa0, 0xc0 }, { 0x00, 0xa0, 0xe0 },
        { 0x00, 0xc0, 0x00 }, { 0x00, 0xc0, 0x20 }, { 0x00, 0xc0, 0x40 }, { 0x00, 0xc0, 0x60 },
        { 0x00, 0xc0, 0x80 }, { 0x00, 0xc0, 0xa0 }, { 0x00, 0xc0, 0xc0 }, { 0x00, 0xc0, 0xe0 },
        { 0x00, 0xe0, 0x00 }, { 0x00, 0xe0, 0x20 }, { 0x00, 0xe0, 0x40 }, { 0x00, 0xe0, 0x60 },
        { 0x00, 0xe0, 0x80 }, { 0x00, 0xe0, 0xa0 }, { 0x00, 0xe0, 0xc0 }, { 0x00, 0xe0, 0xe0 },
        { 0x40, 0x00, 0x00 }, { 0x40, 0x00, 0x20 }, { 0x40, 0x00, 0x40 }, { 0x40, 0x00, 0x60 },
        { 0x40, 0x00, 0x80 }, { 0x40, 0x00, 0xa0 }, { 0x40, 0x00, 0xc0 }, { 0x40, 0x00, 0xe0 },
        { 0x40, 0x20, 0x00 }, { 0x40, 0x20, 0x20 }, { 0x40, 0x20, 0x40 }, { 0x40, 0x20, 0x60 },
        { 0x40, 0x20, 0x80 }, { 0x40, 0x20, 0xa0 }, { 0x40, 0x20, 0xc0 }, { 0x40, 0x20, 0xe0 },
        { 0x40, 0x40, 0x00 }, { 0x40, 0x40, 0x20 }, { 0x40, 0x40, 0x40 }, { 0x40, 0x40, 0x60 },
        { 0x40, 0x40, 0x80 }, { 0x40, 0x40, 0xa0 }, { 0x40, 0x40, 0xc0 }, { 0x40, 0x40, 0xe0 },
        { 0x40, 0x60, 0x00 }, { 0x40, 0x60, 0x20 }, { 0x40, 0x60, 0x40 }, { 0x40, 0x60, 0x60 },
        { 0x40, 0x60, 0x80 }, { 0x40, 0x60, 0xa0 }, { 0x40, 0x60, 0xc0 }, { 0x40, 0x60, 0xe0 },
        { 0x40, 0x80, 0x00 }, { 0x40, 0x80, 0x20 }, { 0x40, 0x80, 0x40 }, { 0x40, 0x80, 0x60 },
        { 0x40, 0x80, 0x80 }, { 0x40, 0x80, 0xa0 }, { 0x40, 0x80, 0xc0 }, { 0x40, 0x80, 0xe0 },
        { 0x40, 0xa0, 0x00 }, { 0x40, 0xa0, 0x20 }, { 0x40, 0xa0, 0x40 }, { 0x40, 0xa0, 0x60 },
        { 0x40, 0xa0, 0x80 }, { 0x40, 0xa0, 0xa0 }, { 0x40, 0xa0, 0xc0 }, { 0x40, 0xa0, 0xe0 },
        { 0x40, 0xc0, 0x00 }, { 0x40, 0xc0, 0x20 }, { 0x40, 0xc0, 0x40 }, { 0x40, 0xc0, 0x60 },
        { 0x40, 0xc0, 0x80 }, { 0x40, 0xc0, 0xa0 }, { 0x40, 0xc0, 0xc0 }, { 0x40, 0xc0, 0xe0 },
        { 0x40, 0xe0, 0x00 }, { 0x40, 0xe0, 0x20 }, { 0x40, 0xe0, 0x40 }, { 0x40, 0xe0, 0x60 },
        { 0x40, 0xe0, 0x80 }, { 0x40, 0xe0, 0xa0 }, { 0x40, 0xe0, 0xc0 }, { 0x40, 0xe0, 0xe0 },
        { 0x80, 0x00, 0x00 }, { 0x80, 0x00, 0x20 }, { 0x80, 0x00, 0x40 }, { 0x80, 0x00, 0x60 },
        { 0x80, 0x00, 0x80 }, { 0x80, 0x00, 0xa0 }, { 0x80, 0x00, 0xc0 }, { 0x80, 0x00, 0xe0 },
        { 0x80, 0x20, 0x00 }, { 0x80, 0x20, 0x20 }, { 0x80, 0x20, 0x40 }, { 0x80, 0x20, 0x60 },
        { 0x80, 0x20, 0x80 }, { 0x80, 0x20, 0xa0 }, { 0x80, 0x20, 0xc0 }, { 0x80, 0x20, 0xe0 },
        { 0x80, 0x40, 0x00 }, { 0x80, 0x40, 0x20 }, { 0x80, 0x40, 0x40 }, { 0x80, 0x40, 0x60 },
        { 0x80, 0x40, 0x80 }, { 0x80, 0x40, 0xa0 }, { 0x80, 0x40, 0xc0 }, { 0x80, 0x40, 0xe0 },
        { 0x80, 0x60, 0x00 }, { 0x80, 0x60, 0x20 }, { 0x80, 0x60, 0x40 }, { 0x80, 0x60, 0x60 },
        { 0x80, 0x60, 0x80 }, { 0x80, 0x60, 0xa0 }, { 0x80, 0x60, 0xc0 }, { 0x80, 0x60, 0xe0 },
        { 0x80, 0x80, 0x00 }, { 0x80, 0x80, 0x20 }, { 0x80, 0x80, 0x40 }, { 0x80, 0x80, 0x60 },
        { 0x80, 0x80, 0x80 }, { 0x80, 0x80, 0xa0 }, { 0x80, 0x80, 0xc0 }, { 0x80, 0x80, 0xe0 },
        { 0x80, 0xa0, 0x00 }, { 0x80, 0xa0, 0x20 }, { 0x80, 0xa0, 0x40 }, { 0x80, 0xa0, 0x60 },
        { 0x80, 0xa0, 0x80 }, { 0x80, 0xa0, 0xa0 }, { 0x80, 0xa0, 0xc0 }, { 0x80, 0xa0, 0xe0 },
        { 0x80, 0xc0, 0x00 }, { 0x80, 0xc0, 0x20 }, { 0x80, 0xc0, 0x40 }, { 0x80, 0xc0, 0x60 },
        { 0x80, 0xc0, 0x80 }, { 0x80, 0xc0, 0xa0 }, { 0x80, 0xc0, 0xc0 }, { 0x80, 0xc0, 0xe0 },
        { 0x80, 0xe0, 0x00 }, { 0x80, 0xe0, 0x20 }, { 0x80, 0xe0, 0x40 }, { 0x80, 0xe0, 0x60 },
        { 0x80, 0xe0, 0x80 }, { 0x80, 0xe0, 0xa0 }, { 0x80, 0xe0, 0xc0 }, { 0x80, 0xe0, 0xe0 },
        { 0xc0, 0x00, 0x00 }, { 0xc0, 0x00, 0x20 }, { 0xc0, 0x00, 0x40 }, { 0xc0, 0x00, 0x60 },
        { 0xc0, 0x00, 0x80 }, { 0xc0, 0x00, 0xa0 }, { 0xc0, 0x00, 0xc0 }, { 0xc0, 0x00, 0xe0 },
        { 0xc0, 0x20, 0x00 }, { 0xc0, 0x20, 0x20 }, { 0xc0, 0x20, 0x40 }, { 0xc0, 0x20, 0x60 },
        { 0xc0, 0x20, 0x80 }, { 0xc0, 0x20, 0xa0 }, { 0xc0, 0x20, 0xc0 }, { 0xc0, 0x20, 0xe0 },
        { 0xc0, 0x40, 0x00 }, { 0xc0, 0x40, 0x20 }, { 0xc0, 0x40, 0x40 }, { 0xc0, 0x40, 0x60 },
        { 0xc0, 0x40, 0x80 }, { 0xc0, 0x40, 0xa0 }, { 0xc0, 0x40, 0xc0 }, { 0xc0, 0x40, 0xe0 },
        { 0xc0, 0x60, 0x00 }, { 0xc0, 0x60, 0x20 }, { 0xc0, 0x60, 0x40 }, { 0xc0, 0x60, 0x60 },
        { 0xc0, 0x60, 0x80 }, { 0xc0, 0x60, 0xa0 }, { 0xc0, 0x60, 0xc0 }, { 0xc0, 0x60, 0xe0 },
        { 0xc0, 0x80, 0x00 }, { 0xc0, 0x80, 0x20 }, { 0xc0, 0x80, 0x40 }, { 0xc0, 0x80, 0x60 },
        { 0xc0, 0x80, 0x80 }, { 0xc0, 0x80, 0xa0 }, { 0xc0, 0x80, 0xc0 }, { 0xc0, 0x80, 0xe0 },
        { 0xc0, 0xa0, 0x00 }, { 0xc0, 0xa0, 0x20 }, { 0xc0, 0xa0, 0x40 }, { 0xc0, 0xa0, 0x60 },
        { 0xc0, 0xa0, 0x80 }, { 0xc0, 0xa0, 0xa0 }, { 0xc0, 0xa0, 0xc0 }, { 0xc0, 0xa0, 0xe0 },
        { 0xc0, 0xc0, 0x00 }, { 0xc0, 0xc0, 0x20 }, { 0xc0, 0xc0, 0x40 }, { 0xc0, 0xc0, 0x60 },
        { 0xc0, 0xc0, 0x80 }, { 0xc0, 0xc0, 0xa0 }, { 0xf0, 0xfb, 0xff }, { 0xa4, 0xa0, 0xa0 },
        { 0x80, 0x80, 0x80 }, { 0x00, 0x00, 0xff }, { 0x00, 0xff, 0x00 }, { 0x00, 0xff, 0xff },
        { 0xff, 0x00, 0x00 }, { 0xff, 0x00, 0xff }, { 0xff, 0xff, 0x00 }, { 0xff, 0xff, 0xff },
    };

    switch (bpp)
    {
    case 1: return table_1;
    case 4: return table_4;
    case 8: return table_8;
    default: return NULL;
    }
}


NTSTATUS 
APIENTRY 
D3DKMTCloseAdapter(
  _In_ D3DKMT_CLOSEADAPTER *pData
)
{
	if(!pData->hAdapter)
	{
		return STATUS_INVALID_HANDLE;
	}
	pData->hAdapter = NULL;
	return STATUS_SUCCESS;
}


// NTSTATUS 
// APIENTRY
// D3DKMTCreateDCFromMemory(
   // IN OUT D3DKMT_CREATEDCFROMMEMORY *pData
// )
// {
    // const struct d3dddi_format_info
    // {
        // D3DDDIFORMAT format;
        // unsigned int bit_count;
        // DWORD compression;
        // unsigned int palette_size;
        // DWORD mask_r, mask_g, mask_b;
    // } *format = NULL;
    // BITMAPOBJ *bmp = NULL;
    // HBITMAP bitmap;
    // unsigned int i;
    // HDC dc;

    // static const struct d3dddi_format_info format_info[] =
    // {
        // { D3DDDIFMT_R8G8B8,   24, BI_RGB,       0,   0x00000000, 0x00000000, 0x00000000 },
        // { D3DDDIFMT_A8R8G8B8, 32, BI_RGB,       0,   0x00000000, 0x00000000, 0x00000000 },
        // { D3DDDIFMT_X8R8G8B8, 32, BI_RGB,       0,   0x00000000, 0x00000000, 0x00000000 },
        // { D3DDDIFMT_R5G6B5,   16, BI_BITFIELDS, 0,   0x0000f800, 0x000007e0, 0x0000001f },
        // { D3DDDIFMT_X1R5G5B5, 16, BI_BITFIELDS, 0,   0x00007c00, 0x000003e0, 0x0000001f },
        // { D3DDDIFMT_A1R5G5B5, 16, BI_BITFIELDS, 0,   0x00007c00, 0x000003e0, 0x0000001f },
        // { D3DDDIFMT_P8,       8,  BI_RGB,       256, 0x00000000, 0x00000000, 0x00000000 },
    // };

    // if (!pData) return STATUS_INVALID_PARAMETER;

    // if (!pData->pMemory) return STATUS_INVALID_PARAMETER;

    // for (i = 0; i < sizeof(format_info) / sizeof(*format_info); ++i)
    // {
        // if (format_info[i].format == pData->Format)
        // {
            // format = &format_info[i];
            // break;
        // }
    // }
    // if (!format) return STATUS_INVALID_PARAMETER;

    // if (pData->Width > (UINT_MAX & ~3) / (format->bit_count / 8) ||
        // !pData->Pitch || !pData->Height || pData->Height > UINT_MAX / pData->Pitch) return STATUS_INVALID_PARAMETER;

    // if (!pData->hDeviceDc || !(dc = CreateCompatibleDC( pData->hDeviceDc ))) return STATUS_INVALID_PARAMETER;

    // if (!(bmp = HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*bmp) ))) goto error;

    // bmp->dib.dsBm.bmWidth      = pData->Width;
    // bmp->dib.dsBm.bmHeight     = pData->Height;
    // bmp->dib.dsBm.bmWidthBytes = pData->Pitch;
    // bmp->dib.dsBm.bmPlanes     = 1;
    // bmp->dib.dsBm.bmBitsPixel  = format->bit_count;
    // bmp->dib.dsBm.bmBits       = pData->pMemory;

    // bmp->dib.dsBmih.biSize         = sizeof(bmp->dib.dsBmih);
    // bmp->dib.dsBmih.biWidth        = pData->Width;
    // bmp->dib.dsBmih.biHeight       = -(LONG)pData->Height;
    // bmp->dib.dsBmih.biPlanes       = 1;
    // bmp->dib.dsBmih.biBitCount     = format->bit_count;
    // bmp->dib.dsBmih.biCompression  = format->compression;
    // bmp->dib.dsBmih.biClrUsed      = format->palette_size;
    // bmp->dib.dsBmih.biClrImportant = format->palette_size;

    // bmp->dib.dsBitfields[0] = format->mask_r;
    // bmp->dib.dsBitfields[1] = format->mask_g;
    // bmp->dib.dsBitfields[2] = format->mask_b;

    // if (format->palette_size)
    // {
        // if (!(bmp->color_table = HeapAlloc( GetProcessHeap(), 0, format->palette_size * sizeof(*bmp->color_table) )))
            // goto error;
        // if (pData->pColorTable)
        // {
            // for (i = 0; i < format->palette_size; ++i)
            // {
                // bmp->color_table[i].rgbRed      = pData->pColorTable[i].peRed;
                // bmp->color_table[i].rgbGreen    = pData->pColorTable[i].peGreen;
                // bmp->color_table[i].rgbBlue     = pData->pColorTable[i].peBlue;
                // bmp->color_table[i].rgbReserved = 0;
            // }
        // }
        // else
        // {
            // memcpy( bmp->color_table, get_default_color_table( format->bit_count ),
                    // format->palette_size * sizeof(*bmp->color_table) );
        // }
    // }	
    // pData->hDc = CreateCompatibleDC(pData->hDeviceDc);
	// bitmap = CreateDIBitmap(pData->hDc, &bmp->dib.dsBmih, CBM_INIT, NULL, &bmp->dib.dsBm, DIB_RGB_COLORS);	
	// pData->hBitmap = bitmap;
    //SelectObject();
	// return STATUS_SUCCESS;
// error:
    // if (bmp) HeapFree( GetProcessHeap(), 0, bmp->color_table );
    // HeapFree( GetProcessHeap(), 0, bmp );
    // DeleteDC( dc );
    // return STATUS_INVALID_PARAMETER;	
    // pData->hDc = NULL;
	// bitmap = CreateDIBitmap(pData->hDc, &bmp->dib.dsBmih, CBM_INIT, NULL, &bmp->dib.dsBm, DIB_RGB_COLORS);	
	// pData->hBitmap = NULL;   
	// return STATUS_SUCCESS;
// }

/***********************************************************************
 *           D3DKMTCreateDCFromMemory    (GDI32.@)
 */
NTSTATUS 
APIENTRY 
D3DKMTCreateDCFromMemory( 
	D3DKMT_CREATEDCFROMMEMORY *desc 
)
{
    const struct d3dddi_format_info
    {
        D3DDDIFORMAT format;
        unsigned int bit_count;
        DWORD compression;
        unsigned int palette_size;
        DWORD mask_r, mask_g, mask_b;
    } *format = NULL;
    BITMAPINFO *bmpInfo = NULL;
    BITMAPV5HEADER *bmpHeader = NULL;
    HBITMAP bitmap;
    unsigned int i;
    HDC dc;

    static const struct d3dddi_format_info format_info[] =
    {
        { D3DDDIFMT_R8G8B8,   24, BI_RGB,       0,   0x00000000, 0x00000000, 0x00000000 },
        { D3DDDIFMT_A8R8G8B8, 32, BI_RGB,       0,   0x00000000, 0x00000000, 0x00000000 },
        { D3DDDIFMT_X8R8G8B8, 32, BI_RGB,       0,   0x00000000, 0x00000000, 0x00000000 },
        { D3DDDIFMT_R5G6B5,   16, BI_BITFIELDS, 0,   0x0000f800, 0x000007e0, 0x0000001f },
        { D3DDDIFMT_X1R5G5B5, 16, BI_BITFIELDS, 0,   0x00007c00, 0x000003e0, 0x0000001f },
        { D3DDDIFMT_A1R5G5B5, 16, BI_BITFIELDS, 0,   0x00007c00, 0x000003e0, 0x0000001f },
        { D3DDDIFMT_A4R4G4B4, 16, BI_BITFIELDS, 0,   0x00000f00, 0x000000f0, 0x0000000f },
        { D3DDDIFMT_X4R4G4B4, 16, BI_BITFIELDS, 0,   0x00000f00, 0x000000f0, 0x0000000f },
        { D3DDDIFMT_P8,       8,  BI_RGB,       256, 0x00000000, 0x00000000, 0x00000000 },
    };

    if (!desc) return STATUS_INVALID_PARAMETER;

    if (!desc->pMemory) return STATUS_INVALID_PARAMETER;

    for (i = 0; i < sizeof(format_info) / sizeof(*format_info); i)
    {
        if (format_info[i].format == desc->Format)
        {
            format = &format_info[i];
            break;
        }
    }
    if (!format) return STATUS_INVALID_PARAMETER;

    if (desc->Width > (UINT_MAX & ~3) / (format->bit_count / 8) ||
        !desc->Pitch || 
		desc->Pitch < (((desc->Width * format->bit_count + 31) >> 3) & ~3) ||
        !desc->Height || desc->Height > UINT_MAX / desc->Pitch) return STATUS_INVALID_PARAMETER;

    if (!desc->hDeviceDc || !(dc = CreateCompatibleDC( desc->hDeviceDc ))) return STATUS_INVALID_PARAMETER;

    if (!(bmpInfo = HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*bmpInfo) + (format->palette_size * sizeof(RGBQUAD)) ))) goto error;
    if (!(bmpHeader = HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*bmpHeader) ))) goto error;
	
    bmpHeader->bV5Size        = sizeof(*bmpHeader);
    bmpHeader->bV5Width       = desc->Width;
    bmpHeader->bV5Height      = desc->Height;
    bmpHeader->bV5SizeImage   = desc->Pitch;
    bmpHeader->bV5Planes      = 1;
    bmpHeader->bV5BitCount    = format->bit_count;
    bmpHeader->bV5Compression = BI_BITFIELDS;
    bmpHeader->bV5RedMask     = format->mask_r;
    bmpHeader->bV5GreenMask   = format->mask_g;
    bmpHeader->bV5BlueMask    = format->mask_b;

    bmpInfo->bmiHeader.biSize         = sizeof(BITMAPINFOHEADER);
    bmpInfo->bmiHeader.biWidth        = desc->Width;
    bmpInfo->bmiHeader.biHeight       = -(LONG)desc->Height;
    bmpInfo->bmiHeader.biPlanes       = 1;
    bmpInfo->bmiHeader.biBitCount     = format->bit_count;
    bmpInfo->bmiHeader.biCompression  = format->compression;
    bmpInfo->bmiHeader.biClrUsed      = format->palette_size;
    bmpInfo->bmiHeader.biClrImportant = format->palette_size;

    if (desc->pColorTable)
    {
        for (i = 0; i < format->palette_size; i)
        {
             bmpInfo->bmiColors[i].rgbRed   = desc->pColorTable[i].peRed;
             bmpInfo->bmiColors[i].rgbGreen = desc->pColorTable[i].peGreen;
             bmpInfo->bmiColors[i].rgbGreen = desc->pColorTable[i].peBlue;
             bmpInfo->bmiColors[i].rgbReserved = 0;
        }
    }

    if (!(bitmap = CreateDIBitmap(dc, (BITMAPINFOHEADER*)bmpHeader, CBM_INIT, desc->pMemory, bmpInfo, DIB_RGB_COLORS))) goto error;

    desc->hDc = dc;
    desc->hBitmap = bitmap;
    SelectObject( dc, bitmap );
    return STATUS_SUCCESS;

error:
    if (bmpInfo)  HeapFree( GetProcessHeap(), 0, bmpInfo );
    if (bmpHeader) HeapFree( GetProcessHeap(), 0, bmpHeader );

    DeleteDC( dc );
    return STATUS_INVALID_PARAMETER;
}

NTSTATUS 
APIENTRY 
D3DKMTDestroyDCFromMemory( 
 	_In_ const D3DKMT_DESTROYDCFROMMEMORY *desc )
{
    if (!desc) return STATUS_INVALID_PARAMETER;

    if (GetObjectType( desc->hDc ) != OBJ_MEMDC ||
        GetObjectType( desc->hBitmap ) != OBJ_BITMAP) return STATUS_INVALID_PARAMETER;
    DeleteObject( desc->hBitmap );
    DeleteDC( desc->hDc );

    return STATUS_SUCCESS;
}

NTSTATUS 
APIENTRY 
D3DKMTCheckMonitorPowerState(
  _In_ const D3DKMT_CHECKMONITORPOWERSTATE *pData
)
{
	HMONITOR mon;
	BOOL state;
	mon = MonitorFromWindow( NULL,MONITOR_DEFAULTTONULL );	
	GetDevicePowerState(mon, &state);
	if(state){
		return STATUS_SUCCESS;
	}else{
		return STATUS_INVALID_PARAMETER;
	}		
}

/******************************************************************************
 *		D3DKMTOpenAdapterFromHdc [GDI32.@]
 */
NTSTATUS 
WINAPI 
D3DKMTOpenAdapterFromHdc( void *pData )
{
    return STATUS_NO_MEMORY;
}

/******************************************************************************
 *		D3DKMTEscape [GDI32.@]
 */
NTSTATUS 
WINAPI 
D3DKMTEscape( const void *pData )
{
    return STATUS_NO_MEMORY;
}