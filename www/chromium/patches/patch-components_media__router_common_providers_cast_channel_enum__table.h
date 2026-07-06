$NetBSD: patch-components_media__router_common_providers_cast_channel_enum__table.h,v 1.22 2026/07/06 13:06:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/media_router/common/providers/cast/channel/enum_table.h.orig	2026-06-23 23:37:18.000000000 +0000
+++ components/media_router/common/providers/cast/channel/enum_table.h
@@ -364,7 +364,12 @@ class EnumTable {
 
  private:
 #ifdef ARCH_CPU_64_BITS
+#ifdef __cpp_lib_hardware_interference_size
   alignas(std::hardware_destructive_interference_size)
+#else
+  static constexpr std::size_t hardware_destructive_interference_size = 64;
+  alignas(hardware_destructive_interference_size)
+#endif
 #endif
       // Constructed from an std::initializer_list pointing at static read only
       // data.
