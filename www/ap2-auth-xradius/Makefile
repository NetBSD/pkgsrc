# $NetBSD: Makefile,v 1.6 2009/07/17 18:00:25 adrianp Exp $

DISTNAME=	mod_auth_xradius-0.4.6
PKGNAME=	${APACHE_PKG_PREFIX}-auth-xradius-0.4.6
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_auth_xradius/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.outoforder.cc/projects/apache/mod_auth_xradius/
COMMENT=	Module to allow apache2 authentication against a RADIUS server

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKG_APACHE_ACCEPTED=	apache2 apache22
.include "../../mk/apache.mk"
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.42

CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs

.include "../../mk/bsd.pkg.mk"
