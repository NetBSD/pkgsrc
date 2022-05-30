$NetBSD: patch-src_unix_uilocale.cpp,v 1.1 2022/05/30 16:31:11 adam Exp $

Fix build for non-Linux.

--- src/unix/uilocale.cpp.orig	2022-05-30 15:19:39.798310136 +0000
+++ src/unix/uilocale.cpp
@@ -448,7 +448,7 @@ wxUILocaleImplUnix::GetInfo(wxLocaleInfo
 wxString
 wxUILocaleImplUnix::GetLocalizedName(wxLocaleName name, wxLocaleForm form) const
 {
-#ifdef HAVE_LANGINFO_H
+#if defined(HAVE_LANGINFO_H) && defined(__linux__)
     wxString str;
     switch (name)
     {
