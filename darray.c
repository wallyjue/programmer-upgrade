#include "darray.h"


Ret darray_destory( DArray* thiz)
{
	if( thiz == NULL)
		return RET_FAIL;
		
	thiz->size = 0;
	if( thiz->element == NULL)
	{
		free( thiz->element );
		thiz->element = NULL;
	}
	free( thiz );
	thiz = NULL;
	return RET_OK;
}

DArray* darray_create( DArrayDestoryFunc darray_destroy, void* ctx)
{
	DArray* darray = (DArray*) malloc( sizeof( DArray ));
	darray->size = (size_t)0;
	return darray;
}

Ret darray_append( DArray* thiz, size_t index, void* ctx)
{
	if( thiz == NULL)
		return RET_FAIL;
		
	thiz->element = (DArray*) realloc( thiz->element, thiz->size*sizeof(void*) + index*sizeof(void*));
	thiz->size += index*sizeof(void*);
	if( thiz == NULL )
	{
		return RET_FAIL;
	}
	return RET_OK;
}
