#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define vector_pushback(v_ptr , type , value) \
    do{\
    type temp =value;  \
    push_back(v_ptr,&temp);\
    }while (0) 
# define vector_pushfront(v_ptr , type , value) \
do{\
type temp =value;  \
push_front(v_ptr,&temp);\
}while (0)
#define vec(typ,vect_ptr,capacity)\
    do{\
    int bytes =sizeof(typ);\
    (vect_ptr)->size= capacity;\
    (vect_ptr)->num=0;\
    (vect_ptr)->vect=NULL;\
    (vect_ptr)->type=bytes;\
    (vect_ptr)->vect=dynamic_array(vect_ptr);\
}while(0)
#define place(name,index,type,value) \
    do{\
        ((type *)name.vect)[index]=value;\
      }while(0)
typedef struct  {  // struct for vecto defining
    int size; // size of the vector
    int num; // number of relements in the vector
    void *vect; // vector pointer pointing to the base address
    int type;
}vector;

void* dynamic_array(vector *v) { // vector intialization
    v->vect= malloc(v->size * v->type); // reserving a memory for the vector
    v->num=v->size;  //updating the number of elements in the vector
    return v->vect; // returning the base adress of the vector
}
void push_back(vector*v,void * value) { // push_back function 
    if (v->size==v->num) { // checks if I need to double the size of the vector
         void* newarr=malloc(2 * v->size * v->type); //doubling the size by reserving a new block of memory
        memcpy(newarr,v->vect,v->num * v->type); // copying the values in the old vect to the new one 
        memcpy((char*)newarr+(v->num * v->type),value, v->type); //pushing back the new value

        v->size*=2; //updating the size of the vect
        void *temp=v->vect; //making a temp pointer
        v->vect=newarr; 
        free(temp); // free the the old block of memory 
        v->num++; // updating the number of the elements of the array
    }
    else { // if I don not need to increase the size 
        memcpy((char *)v->vect+(v->num*v->type),value, v->type); //just add the value 
        v->num++; 
    }

}
void push_front(vector*v,void * value) { // push_front function
    if (v->size==v->num) {// checks if I need to double the size of the vector
        void* newarr=malloc(2 * v->size * v->type);//doubling the size by reserving a new block of memory
        memcpy(newarr,value, v->type);// pushing front the value
        memcpy((char*)newarr+v->type,v->vect, v->num*v->type);// copying the values in the old vect to the new one but shifting it by one
        v->num++;
        v->size*=2;
        void *temp=v->vect;
        v->vect=newarr;
        free(temp);
    }
    else { // if I do not need to double the size
        void * temp=v->vect; // holder for me to not miss up
        memmove((char*)temp+v->type,v->vect, v->num*v->type);//shifting all the values by one
        memcpy(temp,value, v->type); // pushing front the value
        v->num++;
    }

}
void pop(int position, vector*v) { // pop function
    void *temp=v->vect;
    int take = v->num-position;
    memmove((char*)temp+((position-1)*v->type),((char*)v->vect+(position * v->type)),v->type * take);//popping by shifting
    v->num--;
}
int main(void) {
    int size =2;
    vector v;
    vec(float,&v,2);
    place(v,0,float,10.5); // like v[0]=10.5 in c++
    place(v,1,float,20.5);
   vector_pushback(&v,float,20.3); // (ptr to the vector , data type , value)
   vector_pushback(&v,float,70.7);
   vector_pushfront(&v,float,80.9);
     pop(2,&v);//(postion,ptr to the vector)
     pop(1,&v);
    for(int i=0;i<v.num;i++) {
        printf("%.2f ",((float*)v.vect)[i]);
    }
    free(v.vect);
    return 0;
}