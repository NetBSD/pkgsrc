$NetBSD: patch-Source_JavaScriptCore_runtime_Options.cpp,v 1.4 2025/10/25 14:45:27 tsutsui Exp $

- fix build errors on NetBSD/arm where size_t == unsigned long

--- Source/JavaScriptCore/runtime/Options.cpp.orig	2022-06-30 09:49:26.996186500 +0000
+++ Source/JavaScriptCore/runtime/Options.cpp
@@ -89,7 +89,8 @@ std::optional<OptionsStorage::Unsigned> 
     return std::nullopt;
 }
 
-#if CPU(ADDRESS64) || OS(DARWIN)
+#if CPU(ADDRESS64) || OS(DARWIN) || \
+  (defined(__NetBSD__) && (defined(__arm__) || defined(__powerpc__)))
 template<>
 std::optional<OptionsStorage::Size> parse(const char* string)
 {
@@ -98,7 +99,7 @@ std::optional<OptionsStorage::Size> pars
         return value;
     return std::nullopt;
 }
-#endif // CPU(ADDRESS64) || OS(DARWIN)
+#endif // CPU(ADDRESS64) || OS(DARWIN) || (defined(__NetBSD__) && (defined(__arm__) || defined(__powerpc__)))
 
 template<>
 std::optional<OptionsStorage::Double> parse(const char* string)
