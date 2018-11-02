#include <stdio.h>
#include<stdlib.h>
//记录数据的描述，整型数据，字符型数据
typedef struct _recort
{
    const char* name;
    int int_value;
    const char* string_value;
}record_t;
//记录数据组的个数和大小
typedef struct _rector_array
{
    unsigned int size;
    record_t rector[0];
}rector_array_t;

rector_array_t* rector_array_inti(int num)
{
    rector_array_t* array;
    array = (rector_array_t*)malloc(sizeof(rector_array_t)+sizeof(record_t)*num);
    array->size = num;
    return array;
}
int main(void)
{
    rector_array_t *array         = rector_array_inti(3);
    array->rector[0].name         = "AAA";
    array->rector[0].int_value    = 111;
    array->rector[0].string_value = "array first";

    array->rector[1].name         = "BBB";
    array->rector[1].int_value    = 222;
    array->rector[1].string_value = "array second";

    array->rector[2].name         = "CCC";
    array->rector[2].int_value    = 333;
    array->rector[2].string_value = "array third";

    unsigned int i;
    for(i = 0 ; i < array->size ; i++ ){
        printf ("[%d]name[%s]  int_value[%d]  string_value[%s]\n",i,
              array->rector[i].name,array->rector[i].int_value,array->rector[i].string_value);
    }

    free(array);
    return 0;
}

