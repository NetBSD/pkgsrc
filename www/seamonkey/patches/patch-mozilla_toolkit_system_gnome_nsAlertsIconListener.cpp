$NetBSD: patch-mozilla_toolkit_system_gnome_nsAlertsIconListener.cpp,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/toolkit/system/gnome/nsAlertsIconListener.cpp.orig	2014-12-03 06:23:26.000000000 +0000
+++ mozilla/toolkit/system/gnome/nsAlertsIconListener.cpp
@@ -51,6 +51,21 @@ static void notify_closed_marshal(GClosu
   NS_RELEASE(alert);
 }
 
+static GdkPixbuf*
+GetPixbufFromImgRequest(imgIRequest* aRequest)
+{
+  nsCOMPtr<imgIContainer> image;
+  nsresult rv = aRequest->GetImage(getter_AddRefs(image));
+  if (NS_FAILED(rv)) {
+    return nullptr;
+  }
+
+  nsCOMPtr<nsIImageToPixbuf> imgToPixbuf =
+    do_GetService("@mozilla.org/widget/image-to-gdk-pixbuf;1");
+
+  return imgToPixbuf->ConvertImageToPixbuf(image);
+}
+
 NS_IMPL_ISUPPORTS(nsAlertsIconListener, imgINotificationObserver,
                   nsIObserver, nsISupportsWeakReference)
 
@@ -106,47 +121,45 @@ nsAlertsIconListener::Notify(imgIRequest
 nsresult
 nsAlertsIconListener::OnStopRequest(imgIRequest* aRequest)
 {
+  NS_ASSERTION(mIconRequest == aRequest, "aRequest does not match!");
+
   uint32_t imgStatus = imgIRequest::STATUS_ERROR;
   nsresult rv = aRequest->GetImageStatus(&imgStatus);
   NS_ENSURE_SUCCESS(rv, rv);
   if (imgStatus == imgIRequest::STATUS_ERROR && !mLoadedFrame) {
     // We have an error getting the image. Display the notification with no icon.
     ShowAlert(nullptr);
-  }
 
-  if (mIconRequest) {
+    // Cancel any pending request
     mIconRequest->Cancel(NS_BINDING_ABORTED);
     mIconRequest = nullptr;
   }
+
   return NS_OK;
 }
 
 nsresult
 nsAlertsIconListener::OnStopFrame(imgIRequest* aRequest)
 {
-  if (aRequest != mIconRequest)
-    return NS_ERROR_FAILURE;
+  NS_ASSERTION(mIconRequest == aRequest, "aRequest does not match!");
 
   if (mLoadedFrame)
     return NS_OK; // only use one frame
 
-  nsCOMPtr<imgIContainer> image;
-  nsresult rv = aRequest->GetImage(getter_AddRefs(image));
-  if (NS_FAILED(rv))
-    return rv;
-
-  nsCOMPtr<nsIImageToPixbuf> imgToPixbuf =
-    do_GetService("@mozilla.org/widget/image-to-gdk-pixbuf;1");
-
-  GdkPixbuf* imagePixbuf = imgToPixbuf->ConvertImageToPixbuf(image);
-  if (!imagePixbuf)
-    return NS_ERROR_FAILURE;
+  GdkPixbuf* imagePixbuf = GetPixbufFromImgRequest(aRequest);
+  if (!imagePixbuf) {
+    ShowAlert(nullptr);
+  } else {
+    ShowAlert(imagePixbuf);
+    g_object_unref(imagePixbuf);
+  }
 
-  ShowAlert(imagePixbuf);
+  mLoadedFrame = true;
 
-  g_object_unref(imagePixbuf);
+  // Cancel any pending request (multipart image loading/decoding for instance)
+  mIconRequest->Cancel(NS_BINDING_ABORTED);
+  mIconRequest = nullptr;
 
-  mLoadedFrame = true;
   return NS_OK;
 }
 
@@ -180,6 +193,9 @@ nsAlertsIconListener::ShowAlert(GdkPixbu
   mClosureHandler = g_signal_connect_closure(mNotification, "closed", closure, FALSE);
   gboolean result = notify_notification_show(mNotification, nullptr);
 
+  if (result && mAlertListener)
+    mAlertListener->Observe(nullptr, "alertshow", mAlertCookie.get());
+
   return result ? NS_OK : NS_ERROR_FAILURE;
 }
 
@@ -201,9 +217,15 @@ nsAlertsIconListener::StartRequest(const
   if (!il)
     return ShowAlert(nullptr);
 
-  return il->LoadImageXPCOM(imageUri, nullptr, nullptr, nullptr, nullptr,
-                            this, nullptr, nsIRequest::LOAD_NORMAL, nullptr,
-                            nullptr, getter_AddRefs(mIconRequest));
+  nsresult rv = il->LoadImageXPCOM(imageUri, nullptr, nullptr, nullptr, nullptr,
+                                   this, nullptr, nsIRequest::LOAD_NORMAL, nullptr,
+                                   0 /* use default */, getter_AddRefs(mIconRequest));
+  if (NS_FAILED(rv))
+    return rv;
+
+  mIconRequest->StartDecoding();
+
+  return NS_OK;
 }
 
 void
