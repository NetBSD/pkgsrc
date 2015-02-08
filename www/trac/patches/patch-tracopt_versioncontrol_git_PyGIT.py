$NetBSD: patch-tracopt_versioncontrol_git_PyGIT.py,v 1.3 2015/02/08 16:52:46 gdt Exp $

2015-02-08: upstream says that this is unnecesary >= 1.0.2 because of
http://trac.edgewall.org/changeset/11710
which has since been refactored into a utils file.
Hence it is not in distinfo, and parked here commented out until this is
confirmed.

The git browser can fail if the git log process has already exited when
trac tries to terminate it (resulting in a python exception).

This patch should be applied upstream; Reported to trac-devel@ on
2014-03-11 and on 2015-01-18.

# --- tracopt/versioncontrol/git/PyGIT.py.orig	2013-02-01 00:47:41.000000000 +0000
# +++ tracopt/versioncontrol/git/PyGIT.py
# @@ -913,7 +913,11 @@ class Storage(object):
#                          except ValueError:
#                              break
#              f.close()
# -            terminate(p[0])
# +            # The process may or may not have finished.
# +            try:
# +                terminate(p[0])
# +            except:
# +                pass
#              p[0].wait()
#              p[:] = []
#              while True:
# @@ -930,7 +934,10 @@ class Storage(object):
 
#          if p:
#              p[0].stdout.close()
# -            terminate(p[0])
# +            try:
# +                terminate(p[0])
# +            except:
# +                pass
#              p[0].wait()
 
#      def last_change(self, sha, path, historian=None):
