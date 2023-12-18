$NetBSD: patch-gfx_thebes_gfxFont.cpp,v 1.2 2023/12/18 09:31:44 abs Exp $

Add an explicit template instantiation to make it work
with newer gcc (older gcc did not create specialized inline
clones).

--- gfx/thebes/gfxFont.cpp.orig	2017-04-11 02:13:08.000000000 +0000
+++ gfx/thebes/gfxFont.cpp
@@ -2614,6 +2614,18 @@ gfxFont::GetShapedWord(DrawTarget *aDraw
     return sw;
 }
 
+template
+gfxShapedWord*
+gfxFont::GetShapedWord(DrawTarget *aDrawTarget,
+                       const uint8_t *aText,
+                       uint32_t    aLength,
+                       uint32_t    aHash,
+                       Script      aRunScript,
+                       bool        aVertical,
+                       int32_t     aAppUnitsPerDevUnit,
+                       uint32_t    aFlags,
+                       gfxTextPerfMetrics *aTextPerf GFX_MAYBE_UNUSED);
+
 bool
 gfxFont::CacheHashEntry::KeyEquals(const KeyTypePointer aKey) const
 {
