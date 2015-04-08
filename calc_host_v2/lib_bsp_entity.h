#ifndef _lib_bsp_entity_
#define _lib_bsp_entity_

#include "types.h"

public uint32_t addr_magic;

public uint32_t addr_stack_begin;
public uint32_t addr_stack_end;

public uint32_t addr_code_begin;
public uint32_t addr_code_end;

public uint32_t addr_data_begin;
public uint32_t addr_data_end;

public uint32_t addr_idata_begin;
public uint32_t addr_idata_end;

public uint32_t addr_udata_begin;
public uint32_t addr_udata_end;

public uint32_t addr_irodata_begin;
public uint32_t addr_irodata_end;

//#include "lib_bsp_entity.interface"

#endif

