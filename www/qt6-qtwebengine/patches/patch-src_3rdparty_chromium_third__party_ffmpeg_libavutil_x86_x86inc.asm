$NetBSD: patch-src_3rdparty_chromium_third__party_ffmpeg_libavutil_x86_x86inc.asm,v 1.1 2025/12/21 09:38:42 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/ffmpeg/libavutil/x86/x86inc.asm.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/ffmpeg/libavutil/x86/x86inc.asm
@@ -46,6 +46,12 @@
     %endif
 %endif
 
+%if ARCH_X86_64
+    %define _CET_ENDBR endbr64
+%else
+    %define _CET_ENDBR
+%endif
+
 %define WIN64  0
 %define UNIX64 0
 %if ARCH_X86_64
@@ -861,6 +867,7 @@ BRANCH_INSTR jz, je, jnz, jne, jl, jle, 
     %endif
     align function_align
     %2:
+    _CET_ENDBR
     RESET_MM_PERMUTATION        ; needed for x86-64, also makes disassembly somewhat nicer
     %xdefine rstk rsp           ; copy of the original stack pointer, used when greater alignment than the known stack alignment is required
     %assign stack_offset 0      ; stack pointer offset relative to the return address
