#ifndef MEM_H
#define MEM_H

typedef struct {
	void *mem_ptr;
	unsigned int index;
	unsigned int len;
} mem_t, *mem_t_ptr;

mem_t makeMem(unsigned int);
void *getMemPtr(mem_t_ptr, unsigned int, unsigned int);
void memCpy(mem_t_ptr, void *, unsigned int);
void memCat(mem_t_ptr, void *, unsigned int);
void memSet(mem_t_ptr, char, unsigned int);
void setMemIndex(mem_t_ptr, unsigned int);
unsigned int getMemIndex(mem_t mem);
void destroyMem(mem_t);

#define GET_TYPE_MEM(mem_t_ptr, type, _index)					\
({										\
	(type *)getMemPtr(mem_t_ptr, sizeof(type) * _index, sizeof(type));	\
})

#undef index

#define SET_TYPE_MEM(mem_t_ptr, type, _index, val)				\
do {										\
	*GET_TYPE_MEM(mem_t_ptr, type, _index) = val;				\
	if((mem_t_ptr)->index < sizeof(type) * (_index + 1))			\
		setMemIndex(mem_t_ptr, sizeof(type) * (_index + 1));		\
} while(0)

#endif
