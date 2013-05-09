$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_wtf_HashSet.h,v 1.1 2013/05/09 14:07:08 joerg Exp $

--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/HashSet.h.orig	2013-05-08 14:26:07.000000000 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/HashSet.h
@@ -49,7 +49,7 @@ namespace WTF {
             HashFunctions, ValueTraits, ValueTraits> HashTableType;
 
     public:
-        typedef HashTableConstIteratorAdapter<HashTableType, ValueType> iterator;
+        typedef HashTableIteratorAdapter<HashTableType, ValueType> iterator;
         typedef HashTableConstIteratorAdapter<HashTableType, ValueType> const_iterator;
 
         void swap(HashSet&);
@@ -58,10 +58,14 @@ namespace WTF {
         int capacity() const;
         bool isEmpty() const;
 
-        iterator begin() const;
-        iterator end() const;
+        iterator begin();
+        iterator end();
 
-        iterator find(const ValueType&) const;
+        const_iterator begin() const;
+        const_iterator end() const;
+
+        iterator find(const ValueType&);
+        const_iterator find(const ValueType&) const;
         bool contains(const ValueType&) const;
 
         // An alternate version of find() that finds the object by hashing and comparing
@@ -69,7 +73,8 @@ namespace WTF {
         // must have the following function members:
         //   static unsigned hash(const T&);
         //   static bool equal(const ValueType&, const T&);
-        template<typename T, typename HashTranslator> iterator find(const T&) const;
+        template<typename T, typename HashTranslator> iterator find(const T&);
+        template<typename T, typename HashTranslator> const_iterator find(const T&) const;
         template<typename T, typename HashTranslator> bool contains(const T&) const;
 
         // The return value is a pair of an interator to the new value's location, 
@@ -134,19 +139,37 @@ namespace WTF {
     }
 
     template<typename T, typename U, typename V>
-    inline typename HashSet<T, U, V>::iterator HashSet<T, U, V>::begin() const
+    inline typename HashSet<T, U, V>::iterator HashSet<T, U, V>::begin()
     {
         return m_impl.begin(); 
     }
 
     template<typename T, typename U, typename V>
-    inline typename HashSet<T, U, V>::iterator HashSet<T, U, V>::end() const
+    inline typename HashSet<T, U, V>::const_iterator HashSet<T, U, V>::begin() const
+    {
+        return m_impl.begin(); 
+    }
+
+    template<typename T, typename U, typename V>
+    inline typename HashSet<T, U, V>::iterator HashSet<T, U, V>::end()
     {
         return m_impl.end(); 
     }
 
     template<typename T, typename U, typename V>
-    inline typename HashSet<T, U, V>::iterator HashSet<T, U, V>::find(const ValueType& value) const
+    inline typename HashSet<T, U, V>::const_iterator HashSet<T, U, V>::end() const
+    {
+        return m_impl.end(); 
+    }
+
+    template<typename T, typename U, typename V>
+    inline typename HashSet<T, U, V>::iterator HashSet<T, U, V>::find(const ValueType& value)
+    {
+        return m_impl.find(value); 
+    }
+
+    template<typename T, typename U, typename V>
+    inline typename HashSet<T, U, V>::const_iterator HashSet<T, U, V>::find(const ValueType& value) const
     {
         return m_impl.find(value); 
     }
@@ -160,10 +183,21 @@ namespace WTF {
     template<typename Value, typename HashFunctions, typename Traits>
     template<typename T, typename HashTranslator>
     typename HashSet<Value, HashFunctions, Traits>::iterator
+    inline HashSet<Value, HashFunctions, Traits>::find(const T& value)
+    {
+        typedef HashSetTranslatorAdapter<ValueType, ValueTraits, T, HashTranslator> Adapter;
+        return m_impl.template find<T, Adapter>(value);
+        
+    }
+
+    template<typename Value, typename HashFunctions, typename Traits>
+    template<typename T, typename HashTranslator>
+    typename HashSet<Value, HashFunctions, Traits>::const_iterator
     inline HashSet<Value, HashFunctions, Traits>::find(const T& value) const
     {
         typedef HashSetTranslatorAdapter<ValueType, ValueTraits, T, HashTranslator> Adapter;
         return m_impl.template find<T, Adapter>(value);
+        
     }
 
     template<typename Value, typename HashFunctions, typename Traits>
