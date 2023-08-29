$NetBSD

--- sydent/http/httpsclient.py.orig
+++ sydent/http/httpsclient.py
@@ -16,9 +16,9 @@
 
 import logging
 import json
 
-from StringIO import StringIO
+from io import StringIO
 
 from zope.interface import implementer
 
 import twisted.internet.reactor
@@ -69,5 +69,5 @@
 
     def creatorForNetloc(self, hostname, port):
         return optionsForClientTLS(hostname.decode("ascii"),
                                    trustRoot=self.sydent.sslComponents.trustRoot,
-                                   clientCertificate=self.sydent.sslComponents.myPrivateCertificate)
\ No newline at end of file
+                                   clientCertificate=self.sydent.sslComponents.myPrivateCertificate)
