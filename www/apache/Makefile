# $NetBSD: Makefile,v 1.10 1998/06/04 19:38:36 tv Exp $
#

DISTNAME=       apache_1.3b7
PKGNAME=        apache-1.3b7
CATEGORIES=	www
MASTER_SITES=   http://www.apache.org/dist/

MAINTAINER=	cjs@netbsd.org

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--compat --prefix=${PREFIX}/http --exec-prefix=${PREFIX} \
		--mandir=${PREFIX}/man --libexecdir=${PREFIX}/lib/apache \
		--sbindir=${PREFIX}/sbin --runtimedir=/var/run \
		--enable-module=most --enable-module=auth_db \
		--disable-module=auth_dbm --with-perl=${PREFIX}/bin/perl

MAN1=	ab.1 apachectl.1 dbmmanage.1 htpasswd.1 htpasswd.1
MAN8=	apxs.8 httpd.8 logresolve.8 rotatelogs.8

# Note that there is NO static compile module hook here.  This is intentional.
# Under Apache 1.3, modules can be compiled to link dynamically to the server
# using the "apxs" program.  See apxs(8).

.include "../../mk/bsd.pkg.mk"

# Define some modules that are often replaced as shared modules that can be
# changed at runtime.  This allows an apxs-compiled .so to be "dropped in"
# without even changing httpd.conf.
# Only those defined here should be in PLIST-mi.shared.

.if !defined(NOPIC)
CONFIGURE_ARGS+=--enable-module=so --enable-shared=include
.endif
