$NetBSD: patch-toolkit_components_protobuf_src_google_protobuf_arenastring.cc,v 1.1 2022/09/02 15:33:19 ryoon Exp $

* Fix build under NetBSD/i386 9. From protobuf-3.21.5.

--- toolkit/components/protobuf/src/google/protobuf/arenastring.cc.orig	2022-08-19 01:24:42.000000000 +0000
+++ toolkit/components/protobuf/src/google/protobuf/arenastring.cc
@@ -64,8 +64,8 @@ constexpr size_t kNewAlign = alignof(std
 #endif
 constexpr size_t kStringAlign = alignof(std::string);
 
-static_assert((kStringAlign > kNewAlign ? kStringAlign : kNewAlign) >= 8, "");
-static_assert(alignof(ExplicitlyConstructedArenaString) >= 8, "");
+static_assert((kStringAlign > kNewAlign ? kStringAlign : kNewAlign) >= 4, "");
+static_assert(alignof(ExplicitlyConstructedArenaString) >= 4, "");
 
 }  // namespace
 
