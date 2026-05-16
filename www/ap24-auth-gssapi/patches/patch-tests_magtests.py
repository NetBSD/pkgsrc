$NetBSD: patch-tests_magtests.py,v 1.1 2026/05/16 03:47:29 riastradh Exp $

1. Handle Heimdal.

2. Provide a way to give paths to LD_PRELOAD libraries; NetBSD
  ld.elf_so requires this and does not search relative to rpath or
  LD_LIBRARY_PATH.

3. Set Heimdal krb5.conf parameters for KDC database.

4. Set Heimdal pidfile directory and support Heimdal KDC creation.

5. Support Heimdal kadmin setup.

6. Let the environment provide the Apache module directory.

6. Create a simple mime.types to avoid reliance on any external one.

7. Let the environment provide the Apache executable.

8-9. Use a temporary directory (typically under /tmp with a short path)
   to avoid overlong socket paths in pkgsrc workdirs.

9. Fail if any test file didn't exist.  (The distribution tarball is
   missing t_file_check.py, but the tests wrongly passed without it.)

--- tests/magtests.py.orig	2020-11-30 18:30:59.759815268 +0000
+++ tests/magtests.py
@@ -30,6 +30,9 @@ def parse_args():
     return vars(parser.parse_args())
 
 
+HEIMDAL = os.getenv('KRB5_TYPE', None) == 'heimdal'
+
+
 WRAP_HOSTNAME = "kdc.mag.dev"
 WRAP_ALIASNAME = "alias.mag.dev"
 WRAP_FAILNAME = "fail.mag.dev"
@@ -67,7 +70,9 @@ def setup_wrappers(base):
         f.write('maguser3:x:3:3:maguser3:/maguser3:/bin/sh')
         f.write('timeoutusr:x:4:4:timeoutusr:/timeoutusr:/bin/sh')
 
-    wenv = {'LD_PRELOAD': 'libsocket_wrapper.so libnss_wrapper.so',
+    ld_preload_prefix = os.getenv('LD_PRELOAD_PREFIX', '')
+    wenv = {'LD_PRELOAD': '%slibsocket_wrapper.so %slibnss_wrapper.so' %
+            (ld_preload_prefix, ld_preload_prefix),
             'SOCKET_WRAPPER_DIR': wrapdir,
             'SOCKET_WRAPPER_DEFAULT_IFACE': '9',
             'WRAP_PROXY_PORT': WRAP_PROXY_PORT,
@@ -111,6 +116,12 @@ KRB5_CONF_TEMPLATE = '''
   {TESTREALM} = {{
     database_name = {KDCDIR}/{KDC_DBNAME}
   }}
+
+[kdc]
+ database = {{
+  dbname = {KDCDIR}/{KDC_DBNAME}
+  acl_file = {KDCDIR}/kadmind.acl
+ }}
 '''
 KDC_CONF_TEMPLATE = '''
 [kdcdefaults]
@@ -326,29 +337,60 @@ def setup_kdc(testdir, wrapenv):
         'KRB5_CONFIG': krb5conf,
         'KRB5_KDC_PROFILE': kdcconf,
         'KRB5_TRACE': os.path.join(testdir, 'krbtrace.log'),
+        'HEIM_PIDFILE_DIR': os.path.join(testdir, ''),
     })
 
     logfile = open(testlog, 'a')
-    ksetup = subprocess.Popen(["kdb5_util", "create", "-W", "-s",
-                               "-r", TESTREALM, "-P", KDC_PASSWORD],
-                              stdout=logfile, stderr=logfile,
-                              env=kdcenv, preexec_fn=os.setsid)
-    ksetup.wait()
-    if ksetup.returncode != 0:
-        raise ValueError('KDC Setup failed')
 
-    setup_test_certs(testdir, kdcenv, logfile)
+    if HEIMDAL:
+        ksetup = subprocess.Popen(['kadmin', '-c', krb5conf, '-l',
+                                   'init',
+                                   '--realm-max-ticket-life=unlimited',
+                                   '--realm-max-renewable-life=unlimited',
+                                   TESTREALM],
+                                  stdin=subprocess.DEVNULL,
+                                  stdout=logfile, stderr=logfile,
+                                  env=kdcenv, preexec_fn=os.setsid)
+        ksetup.wait()
+        if ksetup.returncode != 0:
+            raise ValueError('KDC setup failed logfile=%r' % (logfile,))
+
+        setup_test_certs(testdir, kdcenv, logfile)
+
+        kdcproc = subprocess.Popen(['kdc',
+                                    '--config-file=' + kdcconf,
+                                    '--addresses=' + WRAP_IPADDR],
+                                   stdout=logfile, stderr=logfile,
+                                   env=kdcenv, preexec_fn=os.setsid)
+
+    else:
+        ksetup = subprocess.Popen(["kdb5_util", "create", "-W", "-s",
+                                   "-r", TESTREALM, "-P", KDC_PASSWORD],
+                                  stdout=logfile, stderr=logfile,
+                                  env=kdcenv, preexec_fn=os.setsid)
+        ksetup.wait()
+        if ksetup.returncode != 0:
+            raise ValueError('KDC Setup failed logfile=%r' % (logfile,))
+
+        setup_test_certs(testdir, kdcenv, logfile)
+
+        kdcproc = subprocess.Popen(['krb5kdc', '-n'],
+                                   stdout=logfile, stderr=logfile,
+                                   env=kdcenv, preexec_fn=os.setsid)
 
-    kdcproc = subprocess.Popen(['krb5kdc', '-n'],
-                               stdout=logfile, stderr=logfile,
-                               env=kdcenv, preexec_fn=os.setsid)
     return kdcproc, kdcenv
 
 
 def kadmin_local(cmd, env, logfile):
-    ksetup = subprocess.Popen(["kadmin.local", "-q", cmd],
-                              stdout=logfile, stderr=logfile,
-                              env=env, preexec_fn=os.setsid)
+    if HEIMDAL:
+        ksetup = subprocess.Popen(["sh", "-c", "exec kadmin -l %s" % (cmd,)],
+                                  stdin=subprocess.DEVNULL,
+                                  stdout=logfile, stderr=logfile,
+                                  env=env, preexec_fn=os.setsid)
+    else:
+        ksetup = subprocess.Popen(["kadmin.local", "-q", cmd],
+                                  stdout=logfile, stderr=logfile,
+                                  env=env, preexec_fn=os.setsid)
     ksetup.wait()
     if ksetup.returncode != 0:
         raise ValueError('Kadmin local [%s] failed' % cmd)
@@ -369,31 +411,53 @@ def setup_keys(tesdir, env):
     logfile = open(testlog, 'a')
 
     svc_name = "HTTP/%s" % WRAP_HOSTNAME
-    cmd = "addprinc -randkey -e %s %s" % (KEY_TYPE, svc_name)
+    if HEIMDAL:
+        cmd = "add --random-key --use-defaults %s" % (svc_name,)
+    else:
+        cmd = "addprinc -randkey -e %s %s" % (KEY_TYPE, svc_name)
     kadmin_local(cmd, env, logfile)
 
     svc_keytab = os.path.join(testdir, SVC_KTNAME)
-    cmd = "ktadd -k %s -e %s %s" % (svc_keytab, KEY_TYPE, svc_name)
+    if HEIMDAL:
+        cmd = "ext_keytab --keytab=%s %s" % (svc_keytab, svc_name)
+    else:
+        cmd = "ktadd -k %s -e %s %s" % (svc_keytab, KEY_TYPE, svc_name)
     kadmin_local(cmd, env, logfile)
 
-    cmd = "addprinc -pw %s -e %s %s" % (USR_PWD, KEY_TYPE, USR_NAME)
+    if HEIMDAL:
+        cmd = "add --password=%s --use-defaults %s" % (USR_PWD, USR_NAME)
+    else:
+        cmd = "addprinc -pw %s -e %s %s" % (USR_PWD, KEY_TYPE, USR_NAME)
     kadmin_local(cmd, env, logfile)
 
-    cmd = "addprinc -pw %s -e %s %s" % (USR_PWD_2, KEY_TYPE, USR_NAME_2)
+    if HEIMDAL:
+        cmd = "add --password=%s --use-defaults %s" % (USR_PWD_2, USR_NAME_2)
+    else:
+        cmd = "addprinc -pw %s -e %s %s" % (USR_PWD_2, KEY_TYPE, USR_NAME_2)
     kadmin_local(cmd, env, logfile)
 
-    cmd = "addprinc -pw %s -e %s %s" % (USR_PWD, KEY_TYPE, USR_NAME_4)
+    if HEIMDAL:
+        cmd = "add --password=%s --use-defaults %s" % (USR_PWD, USR_NAME_4)
+    else:
+        cmd = "addprinc -pw %s -e %s %s" % (USR_PWD, KEY_TYPE, USR_NAME_4)
     kadmin_local(cmd, env, logfile)
 
     # alias for multinamed hosts testing
     alias_name = "HTTP/%s" % WRAP_ALIASNAME
-    cmd = "addprinc -randkey -e %s %s" % (KEY_TYPE, alias_name)
+    if HEIMDAL:
+        cmd = "add --random-key --use-defaults %s" % (alias_name,)
+    else:
+        cmd = "addprinc -randkey -e %s %s" % (KEY_TYPE, alias_name)
     kadmin_local(cmd, env, logfile)
-    cmd = "ktadd -k %s -e %s %s" % (svc_keytab, KEY_TYPE, alias_name)
+    if HEIMDAL:
+        cmd = "ext_keytab --keytab=%s %s" % (svc_keytab, alias_name)
+    else:
+        cmd = "ktadd -k %s -e %s %s" % (svc_keytab, KEY_TYPE, alias_name)
     kadmin_local(cmd, env, logfile)
 
-    cmd = "addprinc -nokey -e %s %s" % (KEY_TYPE, USR_NAME_3)
-    kadmin_local(cmd, env, logfile)
+    if not HEIMDAL:             # XXX HEIMDAL PKINIT
+        cmd = "addprinc -nokey -e %s %s" % (KEY_TYPE, USR_NAME_3)
+        kadmin_local(cmd, env, logfile)
 
     keys_env = env.copy()
     keys_env.update({
@@ -413,16 +477,16 @@ def setup_http(testdir, so_dir, wrapenv)
     httpdstdlog = os.path.join(testdir, 'httpd.stdlog')
 
     distro = "Fedora"
-    moddir = "/etc/httpd/modules"
-    if not os.path.exists(moddir):
-        distro = "Debian"
-        moddir = "/usr/lib/apache2/modules"
+    moddir = os.getenv('APACHE_MODULE_DIR')
     if not os.path.exists(moddir):
         raise ValueError("Could not find Apache module directory!")
     os.symlink(moddir, os.path.join(httpdir, 'modules'))
 
     shutil.copy('%s/mod_auth_gssapi.so' % so_dir, httpdir)
 
+    with open(os.path.join(httpdir, 'mime.types'), 'w') as f:
+        f.write('text/html\thtml\n')
+
     with open('tests/httpd.conf') as f:
         text = f.read().format(HTTPROOT=httpdir,
                                HTTPNAME=WRAP_HOSTNAME,
@@ -444,6 +508,7 @@ def setup_http(testdir, so_dir, wrapenv)
     })
 
     httpd = "httpd" if distro == "Fedora" else "apache2"
+    httpd = os.getenv('APACHE_HTTPD', httpd)
     log = open(httpdstdlog, 'a')
     httpproc = subprocess.Popen([httpd, '-DFOREGROUND', '-f', config],
                                 stdout=log, stderr=log,
@@ -790,6 +855,7 @@ def http_restart(testdir, so_dir, testen
     })
 
     httpd = "httpd" if os.path.exists("/etc/httpd/modules") else "apache2"
+    httpd = os.getenv('APACHE_HTTPD', httpd)
     config = os.path.join(testdir, 'httpd', 'httpd.conf')
     log = open(os.path.join(testdir, 'httpd.stdlog'), 'a')
     httpproc = subprocess.Popen([httpd, '-DFOREGROUND', '-f', config],
@@ -845,6 +911,11 @@ if __name__ == '__main__':
     errs = -1
 
     try:
+      import tempfile
+      with tempfile.TemporaryDirectory(prefix='mod_auth_gssapi.') as tempdir:
+       otestdir = testdir
+       testdir = tempdir
+       try:
         # prepare environment for tests
         wrapenv = apply_venv(setup_wrappers(testdir))
 
@@ -920,9 +991,14 @@ if __name__ == '__main__':
             errs += test_basic_auth_timeout(testdir, timeenv, logfile)
         except NotImplementedError:
             sys.stderr.write('BASIC Timeout Behavior: SKIPPED\n')
+       finally:
+        shutil.rmtree(os.path.join(tempdir, 'wrapdir'))
+        shutil.copytree(tempdir, otestdir, symlinks=True, dirs_exist_ok=True)
+        testdir = otestdir
 
     except Exception:
         traceback.print_exc()
+        errs += 1
     finally:
         for name in processes:
             logfile.write("Killing %s\n" % name)
