# Generic vector in C

## 📌 **Overview**
### The purpose of this project is mastering dynamic memory allocation and resizing it, pointer arithmetic, macros and using my C skills in a real project.
---

## 🚀 Key features
* **Generic vector**  
 *using `void*` so you can use it with any data type*.
* **push_back and push_front functions.**

* **pop function**.

* **Amortized O(1) complexity in push functions.**    
By doubling the size of the vector while pushing in a full vector.
* **Using memcpy to copy the raw bits**

* **using memmove when the source and destination are the same.**  

* **Using macros to provide an easy syntax for the user** 
**Example:**   
Instead of ```((int*)name.vect)[index]=value;```  
Just write  ```place(V_ptr,int,value);```
---
## 📖 API Reference
* ```c vector v; // defining a vector (you can use a different name it does not have to  be v)```

* ```c vec(type,vect_ptr,capacity); //initializing the vector```  
type: the data type you will use.  
vect_ptr: pointer to the vector.  
capacity: the size of the vector you want to initialize with.


* ```c place(v_ptr,type,value); //like v[0]=1;```  
    * v_ptr: pointer to the vector.  
    * type: the data type you will use.  
    * value: the value you want to place.


* ```c vector_pushback(v_ptr , type , value); //pushing back a value```   
    * v_ptr: pointer to the vector.  
    * type: the data type you will use.  
    * value: the value you want to place. 

* ```vector_pushfront(v_ptr , type , value); //pushing front a value```   
    * v_ptr: pointer to the vector.  
    * type: the data type you will use.  
    * value: the value you want to place.

* ```c pop(position, v_ptr);```
    * position: the place of the element you want to pop.  
    * v_ptr: pointer to the vector.  
---
## ⚙️ Technical concepts.
* **Amortized O(1) complexity :**  
If we just increase the size by one -> $\Sigma_{i=0}^{n} i= n^2/2$ so the compexity will be O(n).  
But, if we double the size -> $\Sigma_{i=0}^{\log_2 n} 2^i= 2n-1$ ≈ 2n so the complexity will be O(1).  
* **void pointer arithmetic :**   
Casting the pointer to char `char*` so the compiler deals with pointer as a char pointer as a result we add by one byte.  
--- 
## 📂 Compilation

Compile using `gcc` or `clang`:

 ```
 gcc vector.c -o vector_test
./vector_test
```
---
Author:  Marwan Hany.  

Preparing for Google SWE Internship 2027.

---
## 🛜 Connect 

[![Github](https://img.shields.io/badge/Github-black?style=for-the-badge&logo=Github&logoColor=ffffff)](https://github.com/maro782)
[![Linkedin](https://img.shields.io/badge/linkedin-blue?style=for-the-badge&logoColor=0077B5)](http://www.linkedin.com/in/marwan-hany-494b503a2) 







 


