$NetBSD: patch-sydent_http_httpserver.py,v 1.1 2023/08/29 14:15:01 manu Exp $

--- sydent/http/httpserver.py.orig	2017-04-25 17:29:32.000000000 +0200
+++ sydent/http/httpserver.py	2023-08-22 02:02:39.118761474 +0200
@@ -53,46 +53,47 @@
         ephemeralPubkey = Resource()
 
         pk_ed25519 = self.sydent.servlets.pubkey_ed25519
 
-        root.putChild('_matrix', matrix)
-        matrix.putChild('identity', identity)
-        identity.putChild('api', api)
-        api.putChild('v1', v1)
+        root.putChild(bytes('_matrix', 'utf-8'), matrix)
+        matrix.putChild(bytes('identity', 'utf-8'), identity)
+        identity.putChild(bytes('api', 'utf-8'), api)
+        api.putChild(bytes('v1', 'utf-8'), v1)
 
-        v1.putChild('validate', validate)
-        validate.putChild('email', email)
-        validate.putChild('msisdn', msisdn)
+        v1.putChild(bytes('validate', 'utf-8'), validate)
+        validate.putChild(bytes('email', 'utf-8'), email)
+        validate.putChild(bytes('msisdn', 'utf-8'), msisdn)
 
-        v1.putChild('lookup', lookup)
-        v1.putChild('bulk_lookup', bulk_lookup)
+        v1.putChild(bytes('lookup', 'utf-8'), lookup)
+        v1.putChild(bytes('bulk_lookup', 'utf-8'), bulk_lookup)
 
-        v1.putChild('pubkey', pubkey)
-        pubkey.putChild('isvalid', self.sydent.servlets.pubkeyIsValid)
-        pubkey.putChild('ed25519:0', pk_ed25519)
-        pubkey.putChild('ephemeral', ephemeralPubkey)
-        ephemeralPubkey.putChild('isvalid', self.sydent.servlets.ephemeralPubkeyIsValid)
+        v1.putChild(bytes('pubkey', 'utf-8'), pubkey)
+        pubkey.putChild(bytes('isvalid', 'utf-8'), self.sydent.servlets.pubkeyIsValid)
+        pubkey.putChild(bytes('ed25519:0', 'utf-8'), pk_ed25519)
+        pubkey.putChild(bytes('ephemeral', 'utf-8'), ephemeralPubkey)
+        ephemeralPubkey.putChild(bytes('isvalid', 'utf-8'), self.sydent.servlets.ephemeralPubkeyIsValid)
 
-        v1.putChild('3pid', threepid)
-        threepid.putChild('bind', bind)
-        threepid.putChild('getValidated3pid', getValidated3pid)
+        v1.putChild(bytes('3pid', 'utf-8'), threepid)
+        threepid.putChild(bytes('bind', 'utf-8'), bind)
+        threepid.putChild(bytes('getValidated3pid', 'utf-8'), getValidated3pid)
 
-        email.putChild('requestToken', emailReqCode)
-        email.putChild('submitToken', emailValCode)
+        email.putChild(bytes('requestToken', 'utf-8'), emailReqCode)
+        email.putChild(bytes('submitToken', 'utf-8'), emailValCode)
 
-        msisdn.putChild('requestToken', msisdnReqCode)
-        msisdn.putChild('submitToken', msisdnValCode)
+        msisdn.putChild(bytes('requestToken', 'utf-8'), msisdnReqCode)
+        msisdn.putChild(bytes('submitToken', 'utf-8'), msisdnValCode)
 
-        v1.putChild('store-invite', self.sydent.servlets.storeInviteServlet)
+        v1.putChild(bytes('store-invite', 'utf-8'), self.sydent.servlets.storeInviteServlet)
 
-        v1.putChild('sign-ed25519', self.sydent.servlets.blindlySignStuffServlet)
+        v1.putChild(bytes('sign-ed25519', 'utf-8'), self.sydent.servlets.blindlySignStuffServlet)
 
         self.factory = Site(root)
 
     def setup(self):
         httpPort = int(self.sydent.cfg.get('http', 'clientapi.http.port'))
+        httpListen = str(self.sydent.cfg.get('http', 'clientapi.http.bind_address'))
         logger.info("Starting Client API HTTP server on port %d", httpPort)
-        twisted.internet.reactor.listenTCP(httpPort, self.factory)
+        twisted.internet.reactor.listenTCP(httpPort, self.factory, interface=httpListen)
 
 
 class ReplicationHttpsServer:
     def __init__(self, sydent):
@@ -101,17 +102,17 @@
         root = Resource()
         matrix = Resource()
         identity = Resource()
 
-        root.putChild('_matrix', matrix)
-        matrix.putChild('identity', identity)
+        root.putChild(bytes('_matrix', 'utf-8'), matrix)
+        matrix.putChild(bytes('identity', 'utf-8'), identity)
 
         replicate = Resource()
         replV1 = Resource()
 
-        identity.putChild('replicate', replicate)
-        replicate.putChild('v1', replV1)
-        replV1.putChild('push', self.sydent.servlets.replicationPush)
+        identity.putChild(bytes('replicate', 'utf-8'), replicate)
+        replicate.putChild(bytes('v1', 'utf-8'), replV1)
+        replV1.putChild(bytes('push', 'utf-8'), self.sydent.servlets.replicationPush)
 
         self.factory = Site(root)
 
     def setup(self):
