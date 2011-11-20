$NetBSD: patch-kioslave_http_http.cpp,v 1.1 2011/11/20 02:08:10 markd Exp $

don't interpret html tags. KDE Security Advisory 20111003-1

commit 90607b28d21fefc43657ca08b889bdb174c31fab
Author: David Faure <faure@kde.org>
Date:   Wed Sep 28 17:26:47 2011 +0200

    Use HTML escaping on texts that come from the website
    
    Interestingly enough, this is yet another use case for moving Qt::escape
    to QtCore, which I made a merge request for.
    (cherry picked from commit 86622e4db182f4b914169f72ebd1e66d708e9f87)

diff --git a/kioslave/http/http.cpp b/kioslave/http/http.cpp
index 33f4cb1..6447a02 100644
--- kioslave/http/http.cpp
+++ kioslave/http/http.cpp
@@ -99,6 +99,27 @@
 //authentication handlers
 #include "httpauthentication.cpp"
 
+// KDE5 TODO (QT5) : use QString::htmlEscape or whatever https://qt.gitorious.org/qt/qtbase/merge_requests/56
+// ends up with.
+static QString htmlEscape(const QString &plain)
+{
+    QString rich;
+    rich.reserve(int(plain.length() * 1.1));
+        for (int i = 0; i < plain.length(); ++i) {
+        if (plain.at(i) == QLatin1Char('<'))
+            rich += QLatin1String("&lt;");
+        else if (plain.at(i) == QLatin1Char('>'))
+            rich += QLatin1String("&gt;");
+        else if (plain.at(i) == QLatin1Char('&'))
+            rich += QLatin1String("&amp;");
+        else if (plain.at(i) == QLatin1Char('"'))
+            rich += QLatin1String("&quot;");
+        else
+            rich += plain.at(i);
+    }
+    rich.squeeze();
+    return rich;
+}
 
 // see filenameFromUrl(): a sha1 hash is 160 bits
 static const int s_hashedUrlBits = 160;   // this number should always be divisible by eight
@@ -3410,7 +3431,7 @@ endParsing:
                                 authinfo.url = reqUrl;
                                 authinfo.keepPassword = true;
                                 authinfo.comment = i18n("<b>%1</b> at <b>%2</b>",
-                                                        authinfo.realmValue, authinfo.url.host());
+                                                        htmlEscape(authinfo.realmValue), authinfo.url.host());
 
                                 if (!openPasswordDialog(authinfo, errorMsg)) {
                                     if (sendErrorPageNotification()) {
@@ -5122,7 +5143,7 @@ void HTTPProtocol::proxyAuthenticationForSocket(const QNetworkProxy &proxy, QAut
                            "to access any sites.");
         info.keepPassword = true;
         info.commentLabel = i18n("Proxy:");
-        info.comment = i18n("<b>%1</b> at <b>%2</b>", info.realmValue, m_request.proxyUrl.host());
+        info.comment = i18n("<b>%1</b> at <b>%2</b>", htmlEscape(info.realmValue), m_request.proxyUrl.host());
         const bool dataEntered = openPasswordDialog(info, i18n("Proxy Authentication Failed."));
         if (!dataEntered) {
             kDebug(7103) << "looks like the user canceled proxy authentication.";
