# $NetBSD: Makefile,v 1.16 1998/08/20 15:17:30 tsarna Exp $
#

DISTNAME=       apache_1.3.1
PKGNAME=        apache-1.3.1
CATEGORIES=	www
MASTER_SITES=   http://www.apache.org/dist/

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.apache.org/

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--compat --prefix=${PREFIX}/http --exec-prefix=${PREFIX} \
		--mandir=${PREFIX}/man --libexecdir=${PREFIX}/lib/apache \
		--sbindir=${PREFIX}/sbin --runtimedir=/var/run \
		--enable-module=most --enable-module=auth_db \
		--disable-module=auth_dbm --with-perl=${PREFIX}/bin/perl

# Note that there is NO static compile module hook here.  This is intentional.
# Under Apache 1.3, modules can be compiled to link dynamically to the server
# using the "apxs" program.  See apxs(8).

# Create dummy files because there's no way (that I can see --cjs)
# to make an empty directory with pkg_add.
post-install:
	touch ${PREFIX}/http/logs/.keep_me
	touch ${PREFIX}/http/proxy/.keep_me

.include "../../mk/bsd.pkg.mk"

# Define some modules that are often replaced as shared modules that can be
# changed at runtime.  This allows an apxs-compiled .so to be "dropped in"
# without even changing httpd.conf.
# Only those defined here should be in PLIST-mi.shared.

.if !defined(NOPIC)
CONFIGURE_ARGS+=--enable-module=so --enable-shared=include
.endif
