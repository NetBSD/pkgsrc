# $NetBSD: Makefile,v 1.1 1998/07/24 00:18:03 cjs Exp $
#
#  Notes:
#
#  This package is configured to work with the NetBSD apache-1.3 package
#  And the NetBSD mysql package.
#
#  1. Downloading the distribution from http://ca.php.net/distributions/
#     works with netscape, but not with our FTP client or when done by
#     hand. I've sent a message to webmaster@php.org about this.
#
#  2. The DEPENDS line still needs to be done. I (cjs) am not entirely
#     certain of how to go about this.
#

DISTNAME=       php-3.0.2a
PKGNAME=        php-3.0.2a
CATEGORIES=	www
MASTER_SITES=   http://ca.php.net/distributions/

MAINTAINER=	cjs@netbsd.org

#DEPENDS+=	perl,apache1.3,mysql

CONFIGURE_ARGS+=--with-apxs --with-mysql=/usr/pkg --with-system-regex --enable-track-vars
GNU_CONFIGURE=  YES

.include "../../mk/bsd.pkg.mk"
