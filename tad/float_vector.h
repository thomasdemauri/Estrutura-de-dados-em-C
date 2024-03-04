#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H

typedef struct _float_vector FloatVector;

FloatVector *FVcreate(int capacity);
void FVdestroy(FloatVector **vec);
int FVsize(const FloatVector *vec);
int FVcapacity(const FloatVector *vec);
float FVat(const FloatVector *vec, int index);
float FVget(const FloatVector *vec, int index);
void FVappend(FloatVector *vec, float val);
void FVset(const FloatVector *vec, int index, float val);
void FVprint(const FloatVector *vec);

#endif