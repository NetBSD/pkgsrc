#!/usr/pkg/bin/python
#
#	$NetBSD: zope-shutdown.py,v 1.1 1999/07/02 12:55:33 tsarna Exp $
#
# Copyright (c) 1999 Endicor Technologies, Inc.
# All rights reserved. Written by Ty Sarna <tsarna@endicor.com>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. The name of the author may not be used to endorse or promote products
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


import sys, os, string, urllib #, re, getopt

zopedata = "/var/zope"

def getstr(fn, dflt):
    try:
        f = open(fn, 'r')
        s = string.strip(f.read())
        f.close()
    except:
        s = dflt
    return s
    
for instance in os.listdir(zopedata):
    os.chdir(os.path.join(zopedata, instance))
    access = ""
    try:
        f = open(os.path.join('var', 'pcgi.pid'), 'r')
        pid = int(f.read())
        f.close()
        os.kill(pid, 0)
        url = getstr('access', '')
        if url:
            url = url + '@'
        url = 'http://' + url + getstr('host', 'localhost')
        url = url +'/' + instance + '/Control_Panel/manage_shutdown'
        u = urllib.urlopen(url)
        u.read()
        u.close()
        sys.stdout.write(' ' + instance)
    except:
        sys.stdout.write(' (' + instance + ')')
