#!/usr/pkg/bin/python
#
#	$NetBSD: zope-install.py,v 1.1.1.1 1998/12/12 17:28:23 tsarna Exp $
#	$Endicor$
#
# Copyright (c) 1998 Endicor Technologies, Inc.
# All rights reserved. Written by Ty Sarna <tsarna@endicor.com>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# This will have to do for now...

import sys, os, re, getopt, string

prefix = "/usr/pkg"
cgidir = prefix + "/libexec/cgi-bin"
apconf = prefix + "/etc/httpd/httpd.conf"
zopedir = prefix + "/zope"
zopevar = zopedir + "/var"
zopedata = "/var/zope"

def usage():
    print 'usage: zope-install [-n] [-p perms] [-u user] [-g group] [-d dir] [-c cgidir] instancename'
    print
    print '\t-n\tshow what would be done, but don\'t actually do it'
    print '\t-p\tmanager permissions, in the form'
    print '\t\tusername:plaintextpassword[:domain-restrinction]'
    print '\t\teg: "root:mypass" or "root:mypass:*.mydomain.com'
    print '\t-u\tusername to run as, default to Apache\'s user'
    print '\t-g\tgroupname to run as, default to Apache\'s group'
    print '\t-d\tdirectory for instance, defaults to %s/instancename' % zopedata
    print '\t-d\tdirectory for CGIs, defaults to %s' % cgidir
    
    sys.exit(1)

def exists(f):
    e = 1
    try:
        os.stat(f)
    except:
        e = 0
    return e

def resourcefile(v):
    resource = '''#!%(zopedir)s/pcgi/pcgi-wrapper
PCGI_NAME=Main
PCGI_MODULE_PATH=%(zopedir)s/lib/python/Main.py
PCGI_PUBLISHER=%(zopedir)s/pcgi/pcgi_publisher.py
PCGI_EXE=%(python)s
PCGI_SOCKET_FILE=%(instvar)s/pcgi.soc
PCGI_PID_FILE=%(instvar)s/pcgi.pid
PCGI_ERROR_LOG=%(instvar)s/pcgi.log
PCGI_DISPLAY_ERRORS=1
BOBO_REALM=%(instance)s
BOBO_DEBUG_MODE=1
INSTANCE_HOME=%(dirname)s
''' % v
    
    return resource
    
def GetApachePerms():
    user = group = "?ERROR?"
    
    rx = re.compile("^(User|Group)\\s([^\\s]+)")
    f = open(apconf, "r")
    for l in f.readlines():
        m = rx.match(l)
        if m:
            if m.group(1) == "User":
                user = m.group(2)
            if m.group(1) == "Group":
                group = m.group(2)
    return user, group

def runsys(pretend, cmd):
    if pretend:
        print cmd
    else:
        r = os.system(cmd)
        if r:
            sys.exit(r)
            
def createfile(pretend, fname, contents):
    if pretend:
        print "cat >%(fname)s <__EOF__\n%(contents)s__EOF__" % vars()
    else:
        f = open(fname, "w")
        f.write(contents)
        f.close()
            
if __name__ == "__main__":
    optlist, args = getopt.getopt(sys.argv[1:], 'np:u:g:d:')
    if len(args) != 1:
        usage()

    instance = args[0]
    user, group = GetApachePerms()
    pretend = 0
    seenperms = 0
    perms = "root:password"
    dirname = None
    python = sys.executable

    for (oname, oarg) in optlist:
        if oname == '-n':
            pretend = 1
        elif oname == '-p':
            perms = oarg
            seenperms = 1
        elif oname == '-u':
            user = oarg
        elif oname == '-g':
            group = oarg
        elif oname == '-d':
            dirname = oarg
        elif oname == '-c':
            cgidir = oarg
            
    if not dirname:
        dirname = zopedata + '/' + instance

    instvar = dirname + '/var'
    
    runsys(pretend, "mkdir -p " + instvar)

    if not exists(instvar + "/Data.bbb"):
        runsys(pretend, "cp %(zopevar)s/Data.bbb.in %(instvar)s" % vars())

    runsys(pretend, "chown -R %(user)s.%(group)s %(dirname)s" % vars())
    runsys(pretend, "chmod -R u+rwX,g+rX,g-w,o-rwx %(dirname)s" % vars())

    fname = dirname + "/access"
    if not exists(fname):
        if not seenperms:
            sys.stderr.write("%s: warning: perms not set, dedaulting to %s\n"
                % (sys.argv[0], perms))

        createfile(pretend, fname, perms + '\n')

    runsys(pretend, 
        "chmod 600 %(fname)s; chown %(user)s.%(group)s %(fname)s" % vars())

    fname = cgidir + '/' + instance + ".cgi"
    createfile(pretend, fname, resourcefile(vars()))
    runsys(pretend, 
        "chmod 755 %(fname)s; chown %(user)s.%(group)s %(fname)s" % vars())

    sys.stderr.write("""
now you will need to add lines similar to these to your
Apache srm.conf file to enable access to your instance
via http://yourwebserver/instance/

RewriteEngine on
RewriteCond %%{HTTP:Authorization}  ^(.*)
RewriteRule ^/%(instance)s/(.*) %(cgidir)s/%(instance)s.cgi/$1  [e=HTTP_CGI_AUTHORIZATION:%%1,t=application/x-httpd-cgi,l]
""" % vars())
