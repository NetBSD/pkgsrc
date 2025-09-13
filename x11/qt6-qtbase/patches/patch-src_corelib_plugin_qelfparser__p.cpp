$NetBSD: patch-src_corelib_plugin_qelfparser__p.cpp,v 1.4 2025/09/13 14:31:53 tsutsui Exp $

- fix incorrect alignment calculation in Qt ELF note parser,
  which can fail on NetBSD/earmv7hf due to a .note.netbsd.march
  section containing 9 byte n_descsz (e.g. "earmv7hf") (PR/59096)

--- src/corelib/plugin/qelfparser_p.cpp.orig	2025-09-12 13:29:40.513080754 +0000
+++ src/corelib/plugin/qelfparser_p.cpp
@@ -619,12 +619,12 @@ static QLibraryScanResult scanProgramHea
             // overflow check: calculate where the next note will be, if it exists
             T::Off next_offset = offset;
             next_offset += sizeof(T::Nhdr);          // can't overflow (we checked above)
-            next_offset += NoteAlignment - 3;        // offset is aligned, this can't overflow
+            next_offset += NoteAlignment - 1;        // offset is aligned, this can't overflow
             if (qAddOverflow<T::Off>(next_offset, n_namesz, &next_offset))
                 break;
             next_offset &= -NoteAlignment;
 
-            next_offset += NoteAlignment - 3;        // offset is aligned, this can't overflow
+            next_offset += NoteAlignment - 1;        // offset is aligned, this can't overflow
             if (qAddOverflow<T::Off>(next_offset, n_descsz, &next_offset))
                 break;
             next_offset &= -NoteAlignment;
