$NetBSD: patch-components_sync__bookmarks_bookmark__model__view.cc,v 1.1 2025/11/04 14:55:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync_bookmarks/bookmark_model_view.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ components/sync_bookmarks/bookmark_model_view.cc
@@ -9,7 +9,7 @@
 #include "components/bookmarks/browser/bookmark_model.h"
 #include "components/bookmarks/browser/bookmark_node.h"
 #include "components/bookmarks/common/bookmark_metrics.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/sync_bookmarks/initial_account_bookmark_deduplicator.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -250,7 +250,7 @@ void BookmarkModelViewUsingAccountNodes:
 
 void BookmarkModelViewUsingAccountNodes::
     MaybeRemoveUnderlyingModelDuplicatesUponInitialSync() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   InitialAccountBookmarkDeduplicator initial_account_bookmark_deduplicator(
       underlying_model());
   initial_account_bookmark_deduplicator.Deduplicate();
