$NetBSD: patch-cppcms__boost_cppcms__boost_detail_container__fwd.hpp,v 1.1 2013/07/16 10:12:48 joerg Exp $

--- cppcms_boost/cppcms_boost/detail/container_fwd.hpp.orig	2010-05-14 13:53:44.000000000 +0000
+++ cppcms_boost/cppcms_boost/detail/container_fwd.hpp
@@ -12,12 +12,7 @@
 
 #include <cppcms_boost/config.hpp>
 #include <cppcms_boost/detail/workaround.hpp>
-
-#if ((defined(__GLIBCPP__) || defined(__GLIBCXX__)) && defined(_GLIBCXX_DEBUG)) \
-    || CPPCMS_BOOST_WORKAROUND(__BORLANDC__, > 0x551) \
-    || CPPCMS_BOOST_WORKAROUND(__DMC__, CPPCMS_BOOST_TESTED_AT(0x842)) \
-    || (defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION))
-
+#include <utility>
 #include <deque>
 #include <list>
 #include <vector>
@@ -27,73 +22,4 @@
 #include <string>
 #include <complex>
 
-#else
-
-#include <cstddef>
-
-#if !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION) && \
-        defined(__STL_CONFIG_H)
-
-#define CPPCMS_BOOST_CONTAINER_FWD_BAD_BITSET
-
-#if !defined(__STL_NON_TYPE_TMPL_PARAM_BUG)
-#define CPPCMS_BOOST_CONTAINER_FWD_BAD_DEQUE
-#endif
-
-#endif
-
-#if defined(CPPCMS_BOOST_CONTAINER_FWD_BAD_DEQUE)
-#include <deque>
-#endif
-
-#if defined(CPPCMS_BOOST_CONTAINER_FWD_BAD_BITSET)
-#include <bitset>
-#endif
-
-#if defined(CPPCMS_BOOST_MSVC)
-#pragma warning(push)
-#pragma warning(disable:4099) // struct/class mismatch in fwd declarations
-#endif
-
-namespace std
-{
-    template <class T> class allocator;
-    template <class charT, class traits, class Allocator> class basic_string;
-
-#if CPPCMS_BOOST_WORKAROUND(__GNUC__, < 3) && !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
-    template <class charT> struct string_char_traits;
-#else
-    template <class charT> struct char_traits;
-#endif
-
-    template <class T> class complex;
-}
-
-// gcc 3.4 and greater
-namespace std
-{
-#if !defined(CPPCMS_BOOST_CONTAINER_FWD_BAD_DEQUE)
-    template <class T, class Allocator> class deque;
-#endif
-
-    template <class T, class Allocator> class list;
-    template <class T, class Allocator> class vector;
-    template <class Key, class T, class Compare, class Allocator> class map;
-    template <class Key, class T, class Compare, class Allocator>
-    class multimap;
-    template <class Key, class Compare, class Allocator> class set;
-    template <class Key, class Compare, class Allocator> class multiset;
-
-#if !defined(CPPCMS_BOOST_CONTAINER_FWD_BAD_BITSET)
-    template <size_t N> class bitset;
-#endif
-    template <class T1, class T2> struct pair;
-}
-
-#if defined(CPPCMS_BOOST_MSVC)
-#pragma warning(pop)
-#endif
-
-#endif
-
 #endif
