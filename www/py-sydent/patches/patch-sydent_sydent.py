$NetBSD: patch-sydent_sydent.py,v 1.1 2023/08/29 14:15:01 manu Exp $

--- sydent/sydent.py.orig	2017-04-25 17:29:32.000000000 +0200
+++ sydent/sydent.py	2023-08-22 02:03:44.352677913 +0200
@@ -13,40 +13,40 @@
 # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 # See the License for the specific language governing permissions and
 # limitations under the License.
 
-import ConfigParser
+import configparser
 import logging
 import os
 
 import twisted.internet.reactor
 from twisted.python import log
 
-from db.sqlitedb import SqliteDatabase
+from sydent.db.sqlitedb import SqliteDatabase
 
-from http.httpcommon import SslComponents
-from http.httpserver import ClientApiHttpServer, ReplicationHttpsServer
-from http.httpsclient import ReplicationHttpsClient
-from http.servlets.blindlysignstuffservlet import BlindlySignStuffServlet
-from http.servlets.pubkeyservlets import EphemeralPubkeyIsValidServlet, PubkeyIsValidServlet
-from validators.emailvalidator import EmailValidator
-from validators.msisdnvalidator import MsisdnValidator
-
-from sign.ed25519 import SydentEd25519
-
-from http.servlets.emailservlet import EmailRequestCodeServlet, EmailValidateCodeServlet
-from http.servlets.msisdnservlet import MsisdnRequestCodeServlet, MsisdnValidateCodeServlet
-from http.servlets.lookupservlet import LookupServlet
-from http.servlets.bulklookupservlet import BulkLookupServlet
-from http.servlets.pubkeyservlets import Ed25519Servlet
-from http.servlets.threepidbindservlet import ThreePidBindServlet
-from http.servlets.replication import ReplicationPushServlet
-from http.servlets.getvalidated3pidservlet import GetValidated3pidServlet
-from http.servlets.store_invite_servlet import StoreInviteServlet
+from sydent.http.httpcommon import SslComponents
+from sydent.http.httpserver import ClientApiHttpServer, ReplicationHttpsServer
+from sydent.http.httpsclient import ReplicationHttpsClient
+from sydent.http.servlets.blindlysignstuffservlet import BlindlySignStuffServlet
+from sydent.http.servlets.pubkeyservlets import EphemeralPubkeyIsValidServlet, PubkeyIsValidServlet
+from sydent.validators.emailvalidator import EmailValidator
+from sydent.validators.msisdnvalidator import MsisdnValidator
+
+from sydent.sign.ed25519 import SydentEd25519
+
+from sydent.http.servlets.emailservlet import EmailRequestCodeServlet, EmailValidateCodeServlet
+from sydent.http.servlets.msisdnservlet import MsisdnRequestCodeServlet, MsisdnValidateCodeServlet
+from sydent.http.servlets.lookupservlet import LookupServlet
+from sydent.http.servlets.bulklookupservlet import BulkLookupServlet
+from sydent.http.servlets.pubkeyservlets import Ed25519Servlet
+from sydent.http.servlets.threepidbindservlet import ThreePidBindServlet
+from sydent.http.servlets.replication import ReplicationPushServlet
+from sydent.http.servlets.getvalidated3pidservlet import GetValidated3pidServlet
+from sydent.http.servlets.store_invite_servlet import StoreInviteServlet
 
-from threepid.bind import ThreepidBinder
+from sydent.threepid.bind import ThreepidBinder
 
-from replication.pusher import Pusher
+from sydent.replication.pusher import Pusher
 
 logger = logging.getLogger(__name__)
 
 
@@ -60,8 +60,9 @@
         # db
         'db.file': 'sydent.db',
         # http
         'clientapi.http.port': '8090',
+        'clientapi.http.bind_address': '',
         'replication.https.certfile': '',
         'replication.https.cacert': '', # This should only be used for testing
         'replication.https.port': '4434',
         'obey_x_forwarded_for': False,
@@ -143,13 +144,13 @@
 
         self.pusher = Pusher(self)
 
     def parse_config(self):
-        self.cfg = ConfigParser.SafeConfigParser(Sydent.CONFIG_DEFAULTS)
+        self.cfg = configparser.SafeConfigParser(Sydent.CONFIG_DEFAULTS)
         for sect in Sydent.CONFIG_SECTIONS:
             try:
                 self.cfg.add_section(sect)
-            except ConfigParser.DuplicateSectionError:
+            except configparser.DuplicateSectionError:
                 pass
         self.cfg.read("sydent.conf")
 
     def save_config(self):
