#pragma once

#include "droplet_init.h"

void		init();
void		loop();
void		handle_msg			(ir_msg* msg_struct);

void get_molecules(uint8_t* atoms, uint8_t numAtoms);

uint8_t molecule_count=0;

typedef struct molecule_result_struct{
	int16_t deltaG;	
	uint8_t atoms[12];
	uint8_t numAtoms; 
} molecule_result;

#define MAX_NUM_MOLECULE_RESULTS 20

molecule_result results_storage[MAX_NUM_MOLECULE_RESULTS];
uint8_t num_molecule_results;

int comp_func(molecule_result* a, molecule_result* b);

const uint8_t MOLECULE_LOOKUP[2644] PROGMEM = {
	0x36,0xA,0xD2,0xF8,0x0,0x2,0x8,0x3,0x2,0x48,0x3,0xD4,0x5,0x2,0x48,0x3,0x2,0x7,0x5,0x2,
	0x47,0x3,0xCD,0xFF,0x0,0x5C,0xFF,0x2,0x8,0x3,0x4,0x41,0xB,0x7,0x5,0x81,0xFD,0x0,0x2,0xB,
	0x3,0x4D,0xFB,0x0,0xBD,0xF6,0x2,0x8,0x3,0x23,0x0,0x6,0x41,0x13,0x47,0xB,0x8,0x5,0xE7,0xFC,
	0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x2,0x48,0x3,0x2A,0xF1,0x0,0x2,0x8,0x3,0x11,0x0,0x0,0x2E,
	0x7,0x8,0x1,0x1E,0x47,0xC,0x4B,0x6,0x35,0x3,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x40,
	0x1,0x0,0x2,0x7,0x3,0x48,0xF8,0x0,0x2,0x8,0x3,0x2,0x47,0x3,0xD8,0xFC,0x0,0x7B,0xF9,0x2,
	0x8,0x3,0x8,0xFE,0x6,0x41,0x14,0x47,0xB,0x8,0x5,0x74,0xFF,0x0,0x77,0xF9,0x2,0x8,0x3,0x2,
	0x8,0x5,0xC9,0xF7,0x0,0x4F,0xF4,0x0,0x2,0x8,0x3,0x94,0xFD,0x0,0xF2,0xFE,0x0,0x91,0x0,0x0,
	0xE,0x1,0x26,0x47,0x15,0x9,0x12,0x4B,0xC,0x11,0x9,0x23,0x6,0x35,0x3,0xD8,0xF1,0x0,0x78,0xFA,
	0x2,0x8,0x3,0x69,0xEF,0x0,0x2,0x9,0x3,0xAD,0xF6,0x0,0x46,0xFD,0x0,0x4,0x9,0x6,0x11,0x3,
	0x9A,0xFE,0x0,0x2,0x11,0x3,0x3D,0x3,0x0,0x2,0x35,0x3,0xC,0x41,0x34,0x8,0x22,0x49,0x1A,0x51,
	0x11,0x63,0x9,0x75,0x3,0xDF,0x4,0x0,0x1E,0xE6,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0xAF,0xDE,0x0,
	0x45,0xE9,0x2,0x8,0x3,0x2,0x8,0x5,0x2,0x48,0x3,0x67,0xEE,0x0,0x2,0x9,0x3,0x20,0xF6,0x0,
	0x21,0xFD,0x0,0x4,0x9,0x6,0x11,0x3,0x4,0x49,0xE,0x51,0x5,0xB,0xF0,0x0,0x2,0x9,0x3,0xD0,
	0xFF,0x0,0x2,0x23,0x3,0x4,0x49,0x9,0x63,0x3,0xC,0x41,0x4E,0x7,0x41,0x49,0x38,0x4B,0x2A,0x51,
	0x16,0x63,0x5,0xA1,0x3,0x0,0x2,0x7,0x3,0x2,0x47,0x3,0x10,0xFB,0x0,0x69,0x1,0x2,0x8,0x3,
	0x4,0x41,0xB,0x7,0x5,0x85,0xF9,0x0,0x2,0x8,0x3,0x2,0x47,0x3,0x2C,0xF3,0x0,0x36,0xF9,0x2,
	0x8,0x3,0xC1,0xFE,0x6,0x41,0x16,0x47,0xB,0x8,0x5,0x60,0xFF,0x0,0x8A,0xF8,0x2,0x8,0x3,0xEB,
	0x6,0x2,0x8,0x5,0xB5,0xF7,0x0,0xDC,0xFA,0x0,0xA4,0xFD,0x2,0x8,0x3,0xF4,0xFE,0x0,0xAB,0x0,
	0x0,0xC,0x1,0x27,0x7,0x16,0x9,0x11,0x11,0xB,0x23,0x6,0x35,0x3,0x1C,0x7,0x0,0x2,0x7,0x3,
	0x1D,0x6,0x2,0x47,0x3,0x2,0x7,0x5,0x61,0xF5,0x0,0xCE,0xF0,0x2,0x8,0x3,0x9E,0xFA,0x2,0x8,
	0x5,0x39,0xEA,0x0,0xD6,0xEE,0x2,0x8,0x3,0x2,0x9,0x5,0xB,0xF9,0x0,0xCE,0xFC,0x2,0x8,0x3,
	0x2,0x11,0x5,0x41,0xFF,0x0,0x2,0x23,0x3,0xAC,0x2,0xC,0x41,0x44,0x47,0x2C,0x8,0x21,0x49,0x14,
	0x51,0x9,0x63,0x3,0xF6,0xFF,0x0,0x4,0x3,0x2,0x8,0x3,0xCB,0xE5,0x0,0x2,0x9,0x3,0x3A,0xFB,
	0x2,0x49,0x3,0x4A,0xE8,0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x8D,0xF0,0x0,0xE7,0xF7,0x2,0x8,0x3,
	0xCE,0xED,0x0,0x2,0x9,0x3,0x2F,0xF5,0x0,0x79,0xFC,0x0,0x4,0x9,0x6,0x11,0x3,0xA3,0x1,0x6,
	0x8,0x16,0x49,0xE,0x51,0x5,0x27,0x3,0x0,0xC,0x1,0x50,0x7,0x3E,0x9,0x33,0x4B,0x28,0x11,0xC,
	0x23,0x3,0xAE,0xE4,0x0,0x2,0x8,0x3,0x7E,0xF8,0x2,0x48,0x3,0x1D,0xFE,0x2,0x8,0x5,0x2B,0xE1,
	0x0,0x2,0x8,0x3,0xCA,0xDF,0x0,0x4,0x47,0x6,0x9,0x3,0x11,0xF4,0x2,0x49,0x5,0x2,0x9,0x5,
	0xB6,0xE5,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0xE1,0xF0,0x0,0x54,0xFA,0x2,0x8,0x3,0x9B,0xF6,0x0,
	0x4B,0xFC,0x0,0x4,0x9,0x6,0x11,0x3,0xFD,0x0,0x4,0x8,0x10,0x51,0x5,0x4,0x49,0x1D,0x11,0x7,
	0x6,0x0,0x0,0x2,0x23,0x3,0x2,0x63,0x3,0x2,0x63,0x3,0x3A,0x8,0xA,0x41,0x67,0x8,0x4F,0x49,
	0x37,0x51,0x11,0x63,0x3,0x78,0xDA,0x0,0x2,0x8,0x3,0xA8,0xD0,0x0,0xF1,0xD7,0x2,0x8,0x3,0x2,
	0x9,0x5,0x4,0x48,0xE,0x49,0x3,0x2,0x49,0x5,0x2,0x49,0x3,0xB9,0xDE,0x0,0x2,0x9,0x3,0x2A,
	0xF4,0x2,0x49,0x3,0x2,0x9,0x5,0x61,0xE7,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0x17,0xF1,0x0,0x2C,
	0xF8,0x2,0x8,0x3,0xE6,0xFC,0x0,0x2,0x11,0x3,0x6A,0x0,0x4,0x8,0xB,0x51,0x3,0x4,0x49,0x18,
	0x11,0x7,0x4,0x49,0x26,0x51,0x5,0x47,0xE7,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,
	0x51,0x3,0x8,0x1,0x6E,0x49,0x48,0x51,0x14,0x63,0x3,0xD8,0x3,0x0,0x2,0x7,0x3,0x2,0x47,0x3,
	0x8E,0xFB,0x0,0xDD,0x3,0x2,0x8,0x3,0x4,0x41,0xB,0x7,0x5,0x5F,0xFB,0x0,0x2,0x8,0x3,0x2,
	0x47,0x3,0x4E,0xED,0x0,0xBC,0xF3,0x2,0x8,0x3,0x7A,0xF9,0x2,0x8,0x5,0xD,0xFF,0x6,0x41,0x1B,
	0x47,0x10,0x8,0x5,0x32,0xFF,0x0,0xEA,0xF9,0x2,0x8,0x3,0x2B,0x5,0x2,0x8,0x5,0x6C,0xF2,0x0,
	0x15,0xF8,0x2,0x8,0x3,0xDB,0xFD,0x2,0x8,0x5,0xB3,0xFE,0x0,0xD1,0x0,0x0,0xA,0x1,0x29,0x7,
	0x18,0x11,0xB,0x23,0x6,0x35,0x3,0xED,0x6,0x0,0x2,0x7,0x3,0x2,0x47,0x3,0x2,0x47,0x3,0x2,
	0x47,0x3,0x2,0x47,0x3,0x6E,0xF2,0x0,0x57,0xF4,0x2,0x8,0x3,0x18,0xFD,0x2,0x8,0x5,0x3,0xF7,
	0x0,0x79,0xFC,0x2,0x8,0x3,0x2,0x11,0x5,0x14,0x4,0x8,0x41,0x35,0x47,0x1B,0x8,0x10,0x51,0x3,
	0x99,0xFC,0x0,0x85,0x3,0x2,0x8,0x3,0x5C,0xF1,0x0,0x42,0xFE,0x2,0x8,0x3,0xB3,0xFB,0x0,0x2,
	0x11,0x3,0xA1,0x1,0x4,0x8,0xB,0x51,0x3,0x6,0x1,0x28,0x7,0x1A,0x11,0x7,0xC4,0xE3,0x0,0x68,
	0xED,0x2,0x8,0x3,0x8F,0xF3,0x2,0x8,0x5,0xAF,0xFD,0x2,0x8,0x5,0x6D,0x0,0x0,0x2,0x11,0x3,
	0xD8,0x7,0x6,0x41,0x1F,0x8,0xB,0x51,0x3,0xD9,0x0,0x0,0x41,0x7,0x2,0x8,0x3,0x10,0xD2,0x0,
	0xDD,0xED,0x2,0x8,0x3,0x2,0x9,0x5,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x86,0x6,0x0,
	0x8,0x1,0x28,0x7,0x1C,0x49,0x6,0x11,0x3,0x9F,0x9,0x0,0x2,0x7,0x3,0xFA,0xCE,0x0,0x2,0x9,
	0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x6,0x41,0x21,0x47,0x15,0x49,0x3,
	0x6,0xC8,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,
	0x3,0x4,0x41,0x1C,0x49,0x3,0x33,0xFB,0x0,0x59,0xFF,0x2,0x8,0x3,0xF2,0x6,0x0,0x42,0x4,0x2,
	0x8,0x3,0xDE,0xFD,0x0,0xE4,0xFE,0x0,0xC,0x1,0x0,0xA,0x1,0x16,0x7,0xE,0x11,0x9,0x23,0x6,
	0x35,0x3,0x53,0xED,0x0,0xE2,0xF4,0x2,0x8,0x3,0xBA,0xFC,0x2,0x8,0x5,0xB9,0xF8,0x0,0x9C,0xFC,
	0x2,0x8,0x3,0x2,0x11,0x5,0x62,0x4,0x6,0x41,0x23,0x8,0x10,0x51,0x3,0xC,0xFE,0x0,0xC8,0x3,
	0x2,0x8,0x3,0xF1,0xF1,0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x6,0x1,0x1A,0x7,0xE,0x51,0x3,0xA6,
	0xDD,0x0,0x27,0xE5,0x2,0x8,0x3,0xA2,0xEB,0x2,0x8,0x5,0xA1,0xF5,0x2,0x8,0x5,0x28,0xFE,0x2,
	0x8,0x5,0x2F,0x0,0x0,0x2,0x11,0x3,0xC2,0x7,0x6,0x41,0x24,0x8,0xB,0x51,0x3,0xF6,0xB,0x0,
	0x2,0x7,0x3,0x15,0xF5,0x0,0xE6,0x1,0x2,0x8,0x3,0xC,0x8,0x4,0x47,0xB,0x8,0x5,0x5E,0x4,
	0x0,0x6,0x1,0x21,0x7,0xA,0x11,0x3,0xC4,0x8,0x0,0x2,0x7,0x3,0x60,0xE7,0x0,0x78,0xED,0x2,
	0x8,0x3,0x47,0xFA,0x2,0x8,0x5,0x0,0x0,0x2,0x8,0x5,0xF4,0xB,0x6,0x41,0x1F,0x47,0x15,0x8,
	0x5,0x28,0xC4,0x0,0x2,0x8,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,
	0x49,0x3,0x2,0x49,0x3,0x4,0x1,0x21,0x49,0x3,0x10,0xD,0x0,0x2,0x7,0x3,0x30,0xF1,0x0,0x2,
	0x8,0x3,0x2,0x48,0x3,0x6,0x41,0x14,0x47,0xC,0x48,0x3,0x6C,0xBC,0x0,0x2,0x8,0x3,0x2,0x48,
	0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x4,
	0x41,0x22,0x49,0x3,0x6D,0x1,0x0,0xEE,0x3,0x0,0x4,0x1,0x6,0x7,0x3,0x26,0xF5,0x0,0xF8,0xFB,
	0x2,0x8,0x3,0x3E,0x4,0x4,0x41,0xD,0x8,0x5,0x2E,0xF7,0x0,0x2,0x8,0x3,0xE0,0x6,0x2,0x48,
	0x3,0x4,0x1,0x12,0x7,0x5,0x6C,0x8,0x0,0x2,0x7,0x3,0x38,0xF1,0x0,0xFB,0xF9,0x2,0x8,0x3,
	0x2,0x8,0x5,0xCE,0x6,0x6,0x41,0x16,0x47,0xE,0x48,0x3,0x18,0x7,0x0,0x4,0x1,0xC,0x7,0x3,
	0x47,0xF0,0x0,0x5A,0xFB,0x2,0x8,0x3,0x2,0x8,0x5,0x4,0x41,0x10,0x48,0x3,0x2,0x41,0x5,0x2,
	0x41,0x3,0x2,0x41,0x3,0xBD,0xFE,0x0,0xFE,0x6,0x2,0x8,0x3,0xB1,0x6,0x0,0x4,0x1,0x8,0x7,
	0x3,0x4C,0xC,0x0,0x2,0x7,0x3,0x2B,0xF1,0x0,0x7C,0xF7,0x2,0x8,0x3,0x8,0xFE,0x2,0x8,0x5,
	0x92,0x4,0x0,0x2,0x7,0x3,0xDC,0x4,0x8,0x41,0x1E,0x47,0x16,0x8,0xB,0x51,0x3,0x96,0x5,0x0,
	0x2,0x8,0x3,0x2,0x48,0x3,0x1B,0xFD,0x0,0xE0,0xFC,0x0,0xAA,0x3,0x0,0x2,0x7,0x3,0x9D,0x3,
	0x4,0x8,0x9,0x51,0x3,0xEC,0x4,0x0,0x10,0x7,0x0,0xC,0x1,0x2D,0x47,0x1C,0x9,0x19,0x11,0xD,
	0x23,0x6,0x35,0x3,0xEE,0xA,0x0,0x2,0x7,0x3,0xB2,0xFC,0x0,0x2,0x8,0x3,0x7C,0x4,0x0,0x2,
	0x8,0x3,0x2,0x48,0x3,0x52,0x2,0x0,0x4,0x47,0x6,0x11,0x3,0x13,0x5,0x0,0x2,0x23,0x3,0xA,
	0x41,0x30,0x47,0x20,0x48,0x1A,0x51,0xB,0x63,0x3,0x8E,0x3,0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x60,
	0x1,0x0,0x4,0x47,0x6,0x11,0x3,0x2,0x51,0x5,0x4,0x41,0x1F,0x51,0x3,0x2,0x41,0x5,0x2,0x41,
	0x3,0x72,0x4,0x0,0x9C,0x3,0x0,0xF7,0x4,0x0,0x6,0x1,0x9,0x11,0x6,0x23,0x3,0xCF,0xF9,0x0,
	0x41,0x0,0x2,0x8,0x3,0xF6,0x1,0x0,0x2,0x11,0x3,0x6,0x41,0x15,0x8,0xB,0x51,0x3,0x57,0x1,
	0x0,0x53,0x9,0x2,0x8,0x3,0xC8,0xEB,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0x3F,0xF6,0x0,0x8F,0xFD,
	0x2,0x8,0x3,0x4C,0x2,0x0,0x2,0x11,0x3,0x4,0x8,0xB,0x51,0x3,0x8,0x41,0x2B,0x7,0x21,0x49,
	0x16,0x51,0x5,0xFE,0xEA,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0xAE,0xFC,0x0,0x2,0x8,0x3,0x4,0x49,
	0x9,0x51,0x3,0x4,0x41,0x1D,0x51,0x5,0xAF,0x0,0x0,0x2,0x8,0x3,0xB0,0xE9,0x0,0x2,0x9,0x3,
	0x2,0x49,0x3,0x4,0x47,0xC,0x49,0x3,0x2,0x51,0x5,0x4,0x41,0x1C,0x51,0x3,0x2,0x41,0x5,0x2,
	0x41,0x3,0x95,0xD,0x0,0x2,0x1,0x3,0x18,0xF3,0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x4,0x41,0xC,
	0x48,0x3,0x2,0x41,0x5,0x2,0x41,0x3,0x2,0x41,0x3,0x2,0x41,0x3,0x4,0x41,0x23,0x46,0x3,0x94,
	0xDD,0x0,0x2,0x1,0x3,0x7D,0xDD,0x0,0x4,0x48,0x6,0x9,0x3,0x2,0x49,0x5,0x2,0x49,0x3,0x2,
	0x49,0x3,0x2,0x49,0x3,0xA0,0xFF,0x0,0x2,0x11,0x3,0x2,0x51,0x3,0x2,0x51,0x3,0x2,0x51,0x3,
	0x2,0x51,0x3,0x8,0x41,0xE1,0x46,0x31,0x49,0x15,0x51,0x3,0xF5,0xFD,0x0,0x2,0x11,0x3,0x2,0x51,
	0x3,0x2,0x51,0x3,0x2,0x51,0x3,0x2,0x51,0x3,0x7,0xC1,0xAC,0x1,0x46,0x1B,0x51,0x3,0x72,0xBB,
	0x0,0xA4,0xB1,0x0,0x2,0x9,0x3,0x5A,0xC9,0x4,0x8,0x9,0x49,0x3,0x2,0x9,0x7,0x36,0xDE,0x2,
	0x49,0x3,0x2,0x9,0x5,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x1E,0xD4,0x0,
	0x2,0x9,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x83,0x0,0x0,0x2,0x11,
	0x3,0x2,0x51,0x3,0x2,0x51,0x3,0x4,0x49,0xF,0x51,0x3,0x2,0x51,0x5,0x9,0xC1,0x68,0x2,0x46,
	0x55,0x49,0x29,0x51,0x3,0x7E,0xC8,0x0,0x1E,0xBF,0x0,0x2,0x9,0x3,0x7E,0xD7,0x4,0x8,0x9,0x49,
	0x3,0x2,0x9,0x7,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x7E,0xD2,0x0,0x2,
	0x9,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x51,0x3,
	0x9,0xC1,0xBF,0x3,0x46,0x41,0x49,0x1B,0x51,0x3,0xA0,0xB,0x0,0x2,0x7,0x3,0xC8,0xCE,0x0,0x2,
	0x9,0x3,0xA4,0xE7,0x2,0x49,0x3,0x2,0x9,0x5,0x2,0x49,0x3,0x2,0x49,0x3,0x4C,0xD7,0x0,0x2,
	0x9,0x3,0x88,0xEB,0x2,0x49,0x3,0x2,0x9,0x5,0x2,0x49,0x3,0x6B,0xDF,0x0,0x2,0x9,0x3,0x2,
	0x49,0x3,0x2,0x49,0x3,0xB9,0xE4,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0x8A,0xF8,0x0,0x1A,0xF6,0x0,
	0x52,0xFD,0x0,0x4,0x9,0x6,0x11,0x3,0x84,0x0,0x4,0x8,0xE,0x51,0x5,0x4,0x49,0x18,0x11,0x7,
	0x4,0x49,0x26,0x51,0x5,0x4,0x49,0x37,0x51,0x5,0xE4,0xEE,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0x9D,
	0xE3,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x2,0x49,0x3,0x4,0x49,0x12,0x63,0x3,0xD,
	0xC1,0x89,0x5,0x46,0x8B,0x47,0x7E,0x49,0x6A,0x51,0x22,0x63,0x5,0xDC,0xFC,0x0,0x2,0xB,0x3,0x99,
	0xF0,0x0,0xA5,0xFA,0x2,0x8,0x3,0xA7,0xE7,0x0,0xB8,0xDD,0x0,0xB1,0xE9,0x0,0x4,0x9,0x6,0x35,
	0x3,0x4,0x8,0xE,0x49,0x5,0x2,0x49,0x5,0xF,0xD7,0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x2,0x48,
	0x3,0x2,0x4B,0x3,0x1D,0x5,0x0,0xEF,0xE5,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0x1,0xF8,0x0,0x51,
	0xEE,0x0,0x2,0x9,0x3,0x42,0xF6,0x0,0xB8,0xFD,0x0,0x4,0x9,0x6,0x11,0x3,0x6,0x8,0x14,0x49,
	0xE,0x51,0x5,0x6,0x7,0x27,0x49,0x1E,0x51,0x7,0xAE,0xE7,0x0,0x2,0x9,0x3,0x2,0x49,0x3,0xE,
	0xF0,0x0,0x2,0x9,0x3,0x2A,0xFF,0x0,0x2,0x11,0x3,0x4,0x49,0x9,0x51,0x3,0x50,0xF1,0x0,0x2,
	0x9,0x3,0x2,0x49,0x3,0x6,0x49,0x1D,0x51,0xE,0x63,0x3,0x0,0x0,0x11,0xC1,0xE6,0x7,0x46,0x99,
	0x47,0x88,0x8,0x82,0x49,0x6A,0x4B,0x5B,0x51,0x31,0x63,0x7,0x9D,0x4,0x0,0xD2,0x3,0x2,0x8,0x3,
	0x74,0x5,0x2,0x8,0x5,0x2,0x8,0x5,0x11,0x4,0x2,0x48,0x3,0x0,0x0,0x2,0x8,0x5,0x1,0x2,
	0x0,0x61,0x3,0x2,0x8,0x3,0xAA,0xF1,0x0,0xE2,0xF4,0x2,0x8,0x3,0x2,0x8,0x5,0x2,0x48,0x3,
	0xAE,0x10,0x6,0x7,0x1B,0x8,0x13,0x4B,0x3,0x5F,0x6,0x0,0x0,0x0,0x2,0x8,0x3,0xDB,0x7,0x2,
	0x8,0x5,0x3E,0xF5,0x0,0xFF,0xFD,0x0,0x2,0x8,0x3,0x76,0xFC,0x0,0x1E,0x3,0x0,0x2,0x7,0x3,
	0x2,0x47,0x3,0x4,0x7,0xC,0x49,0x3,0x0,0x0,0x2,0x49,0x5,0xB5,0xEA,0x0,0x40,0x1,0x8,0x1,
	0x22,0x47,0x1C,0x9,0x8,0xB,0x3,0x6C,0xEE,0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x0,0x0,0x2,0x4B,
	0x3,0x89,0xFC,0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x2,0x48,0x3,0x10,0xF8,0x2,0x48,0x3,0x2,0x7,
	0x5,0x2,0x41,0x3,0x2,0x41,0x3,0x61,0xFF,0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x2,0x48,0x3,0x47,
	0xFC,0x4,0x41,0xF,0x48,0x3,0x95,0x2,0x0,0x2,0x8,0x3,0xB3,0x4,0x0,0x2,0x8,0x3,0xE2,0x1,
	0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x50,0xFB,0x0,0x2,0x9,0x3,0x4,0x48,0x9,0x49,0x3,0xC1,0xF5,
	0x0,0x2,0x8,0x3,0x2,0x48,0x3,0x0,0xF1,0x2,0x48,0x3,0xAA,0xB,0x0,0x2,0x7,0x3,0x0,0x0,
	0x2,0x51,0x3,0xD0,0x2,0xC,0x1,0x40,0x47,0x36,0x48,0x30,0x49,0x1E,0xB,0x10,0x11,0x5,0xEB,0xFD,
	0x0,0x5B,0xF2,0x0,0x0,0x0,0x0,0x55,0x2,0x6,0x1,0x9,0xB,0x6,0x23,0x3,0x78,0xF5,0x0,0xE2,
	0xF4,0x0,0x0,0x0,0x0,0x10,0x2,0x6,0x3,0x9,0xB,0x6,0x35,0x3,0x1D,0x81,0xE7,0x9,0x82,0xDC,
	0x9,0x83,0xD9,0x9,0x84,0xD6,0x9,0x86,0x2E,0x1,0x7,0xEA,0x8,0xD9,0x9,0xB2,0xB,0x9E,0x11,0x33,
	0x23,0x1B,0x35,0x9
};