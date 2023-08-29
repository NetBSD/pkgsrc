$NetBSD: patch-sydent_threepid_bind.py,v 1.2 2023/08/29 14:21:18 wiz Exp $


--- sydent/threepid/bind.py.orig
+++ sydent/threepid/bind.py
@@ -30,9 +30,9 @@
 from sydent.threepid import ThreepidAssociation
 
 from OpenSSL import SSL
 from OpenSSL.SSL import VERIFY_NONE
-from StringIO import StringIO
+from io import StringIO
 from twisted.internet import reactor, defer, ssl
 from twisted.names import client, dns
 from twisted.names.error import DNSNameError
 from twisted.web.client import FileBodyProducer, Agent
