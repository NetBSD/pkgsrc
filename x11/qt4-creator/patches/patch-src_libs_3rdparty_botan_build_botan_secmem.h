$NetBSD: patch-src_libs_3rdparty_botan_build_botan_secmem.h,v 1.1 2012/11/19 23:13:48 joerg Exp $

--- src/libs/3rdparty/botan/build/botan/secmem.h.orig	2012-11-19 11:01:09.000000000 +0000
+++ src/libs/3rdparty/botan/build/botan/secmem.h
@@ -307,7 +307,7 @@ class MemoryVector : public MemoryRegion
       * @return a reference to *this
       */
       MemoryVector<T>& operator=(const MemoryRegion<T>& in)
-         { if(this != &in) set(in); return (*this); }
+         { if(this != &in) this->set(in); return (*this); }
 
       /**
       * Create a buffer of the specified length.
@@ -323,13 +323,13 @@ class MemoryVector : public MemoryRegion
       * @param n the size of the arry in
       */
       MemoryVector(const T in[], u32bit n)
-         { MemoryRegion<T>::init(false); set(in, n); }
+         { MemoryRegion<T>::init(false); this->set(in, n); }
 
       /**
       * Copy constructor.
       */
       MemoryVector(const MemoryRegion<T>& in)
-         { MemoryRegion<T>::init(false); set(in); }
+         { MemoryRegion<T>::init(false); this->set(in); }
 
       /**
       * Create a buffer whose content is the concatenation of two other
@@ -338,7 +338,7 @@ class MemoryVector : public MemoryRegion
       * @param in2 the contents to be appended to in1
       */
       MemoryVector(const MemoryRegion<T>& in1, const MemoryRegion<T>& in2)
-         { MemoryRegion<T>::init(false); set(in1); append(in2); }
+         { MemoryRegion<T>::init(false); this->set(in1); this->append(in2); }
    };
 
 /**
@@ -359,7 +359,7 @@ class SecureVector : public MemoryRegion
       * @return a reference to *this
       */
       SecureVector<T>& operator=(const MemoryRegion<T>& in)
-         { if(this != &in) set(in); return (*this); }
+         { if(this != &in) this->set(in); return (*this); }
 
       /**
       * Create a buffer of the specified length.
@@ -375,7 +375,7 @@ class SecureVector : public MemoryRegion
       * @param n the size of the array in
       */
       SecureVector(const T in[], u32bit n)
-         { MemoryRegion<T>::init(true); set(in, n); }
+         { MemoryRegion<T>::init(true); this->set(in, n); }
 
       /**
       * Create a buffer with contents specified contents.
@@ -383,7 +383,7 @@ class SecureVector : public MemoryRegion
       * copied into the newly created buffer.
       */
       SecureVector(const MemoryRegion<T>& in)
-         { MemoryRegion<T>::init(true); set(in); }
+         { MemoryRegion<T>::init(true); this->set(in); }
 
       /**
       * Create a buffer whose content is the concatenation of two other
@@ -392,7 +392,7 @@ class SecureVector : public MemoryRegion
       * @param in2 the contents to be appended to in1
       */
       SecureVector(const MemoryRegion<T>& in1, const MemoryRegion<T>& in2)
-         { MemoryRegion<T>::init(true); set(in1); append(in2); }
+         { MemoryRegion<T>::init(true); this->set(in1); this->append(in2); }
    };
 
 /**
@@ -413,7 +413,7 @@ class SecureBuffer : public MemoryRegion
       * @return a reference to *this
       */
       SecureBuffer<T,L>& operator=(const SecureBuffer<T,L>& in)
-         { if(this != &in) set(in); return (*this); }
+         { if(this != &in) this->set(in); return (*this); }
 
       /**
       * Create a buffer of the length L.
@@ -427,10 +427,10 @@ class SecureBuffer : public MemoryRegion
       * @param n the size of the array in
       */
       SecureBuffer(const T in[], u32bit n)
-         { MemoryRegion<T>::init(true, L); copy(in, n); }
+         { MemoryRegion<T>::init(true, L); this->copy(in, n); }
    private:
       SecureBuffer<T, L>& operator=(const MemoryRegion<T>& in)
-         { if(this != &in) set(in); return (*this); }
+         { if(this != &in) this->set(in); return (*this); }
    };
 
 }
