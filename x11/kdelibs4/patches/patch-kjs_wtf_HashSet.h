$NetBSD: patch-kjs_wtf_HashSet.h,v 1.1 2012/04/19 21:10:59 joerg Exp $

--- kjs/wtf/HashSet.h.orig	2012-04-19 16:21:41.000000000 +0000
+++ kjs/wtf/HashSet.h
@@ -181,7 +181,7 @@ namespace WTF {
     inline HashSet<Value, HashFunctions, Traits>::find(const T& value)
     {
         typedef HashSetTranslatorAdapter<ValueType, ValueTraits, T, Translator> Adapter;
-        return m_impl.find<T, Adapter>(value);
+        return m_impl.template find<T, Adapter>(value);
     }
 
     template<typename Value, typename HashFunctions, typename Traits>
@@ -190,7 +190,7 @@ namespace WTF {
     inline HashSet<Value, HashFunctions, Traits>::find(const T& value) const
     {
         typedef HashSetTranslatorAdapter<ValueType, ValueTraits, T, Translator> Adapter;
-        return m_impl.find<T, Adapter>(value);
+        return m_impl.template find<T, Adapter>(value);
     }
 
     template<typename Value, typename HashFunctions, typename Traits>
@@ -198,7 +198,7 @@ namespace WTF {
     inline bool HashSet<Value, HashFunctions, Traits>::contains(const T& value) const
     {
         typedef HashSetTranslatorAdapter<ValueType, ValueTraits, T, Translator> Adapter;
-        return m_impl.contains<T, Adapter>(value);
+        return m_impl.template contains<T, Adapter>(value);
     }
 
     template<typename T, typename U, typename V>
