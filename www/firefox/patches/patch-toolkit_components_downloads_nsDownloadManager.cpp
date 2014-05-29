$NetBSD: patch-toolkit_components_downloads_nsDownloadManager.cpp,v 1.1 2014/05/29 15:38:19 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- toolkit/components/downloads/nsDownloadManager.cpp.orig	2014-05-06 22:56:29.000000000 +0000
+++ toolkit/components/downloads/nsDownloadManager.cpp
@@ -46,7 +46,7 @@
 #endif
 #endif
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include <CoreFoundation/CoreFoundation.h>
 #endif
 
@@ -1373,7 +1373,7 @@ nsDownloadManager::GetDefaultDownloadsDi
   mBundle->GetStringFromName(MOZ_UTF16("downloadsFolder"),
                              getter_Copies(folderName));
 
-#if defined (XP_MACOSX)
+#if defined (MOZ_WIDGET_COCOA)
   rv = dirService->Get(NS_OSX_DEFAULT_DOWNLOAD_DIR,
                        NS_GET_IID(nsIFile),
                        getter_AddRefs(downloadDir));
@@ -2436,7 +2436,7 @@ nsDownloadManager::Observe(nsISupports *
     nsCOMPtr<nsISupportsPRBool> cancelDownloads =
       do_QueryInterface(aSubject, &rv);
     NS_ENSURE_SUCCESS(rv, rv);
-#ifndef XP_MACOSX
+#ifndef MOZ_WIDGET_COCOA
     ConfirmCancelDownloads(currDownloadCount, cancelDownloads,
                            MOZ_UTF16("quitCancelDownloadsAlertTitle"),
                            MOZ_UTF16("quitCancelDownloadsAlertMsgMultiple"),
@@ -2731,7 +2731,7 @@ nsDownload::SetState(DownloadState aStat
         }
       }
 
-#if defined(XP_WIN) || defined(XP_MACOSX) || defined(MOZ_WIDGET_ANDROID) || defined(MOZ_WIDGET_GTK)
+#if defined(XP_WIN) || defined(MOZ_WIDGET_COCOA) || defined(MOZ_WIDGET_ANDROID) || defined(MOZ_WIDGET_GTK)
       nsCOMPtr<nsIFileURL> fileURL = do_QueryInterface(mTarget);
       nsCOMPtr<nsIFile> file;
       nsAutoString path;
@@ -2780,7 +2780,7 @@ nsDownload::SetState(DownloadState aStat
 #endif
         }
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
         // On OS X, make the downloads stack bounce.
         CFStringRef observedObject = ::CFStringCreateWithCString(kCFAllocatorDefault,
                                                  NS_ConvertUTF16toUTF8(path).get(),
@@ -3363,7 +3363,7 @@ nsDownload::OpenWithApplication()
   if (!prefs || NS_FAILED(prefs->GetBoolPref(PREF_BH_DELETETEMPFILEONEXIT,
                                              &deleteTempFileOnExit))) {
     // No prefservice or no pref set; use default value
-#if !defined(XP_MACOSX)
+#if !defined(MOZ_WIDGET_COCOA)
     // Mac users have been very verbal about temp files being deleted on
     // app exit - they don't like it - but we'll continue to do this on
     // other platforms for now.
