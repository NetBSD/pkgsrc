$NetBSD: patch-cppcms__boost_cppcms__boost_interprocess_detail_managed__memory__impl.hpp,v 1.1 2013/07/16 10:12:48 joerg Exp $

--- cppcms_boost/cppcms_boost/interprocess/detail/managed_memory_impl.hpp.orig	2010-05-14 13:53:01.000000000 +0000
+++ cppcms_boost/cppcms_boost/interprocess/detail/managed_memory_impl.hpp
@@ -673,7 +673,7 @@ class basic_managed_memory_impl
    template<class T>
    typename allocator<T>::type
       get_allocator()
-   {   return mp_header->get_allocator<T>(); }
+   {   return mp_header-> template get_allocator<T>(); }
 
    //!This is the default deleter to delete types T
    //!from this managed segment.
@@ -688,7 +688,7 @@ class basic_managed_memory_impl
    template<class T>
    typename deleter<T>::type
       get_deleter()
-   {   return mp_header->get_deleter<T>(); }
+   {   return mp_header-> template get_deleter<T>(); }
 
    /// @cond
    //!Tries to find a previous named allocation address. Returns a memory
