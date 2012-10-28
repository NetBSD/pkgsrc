# $NetBSD: Makefile,v 1.8 2012/10/28 06:30:07 asau Exp $

DISTNAME=	mod_auth_xradius-0.4.6
PKGNAME=	${APACHE_PKG_PREFIX}-auth-xradius-0.4.6
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_auth_xradius/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.outoforder.cc/projects/apache/mod_auth_xradius/
COMMENT=	Module to allow apache2 authentication against a RADIUS server

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKG_APACHE_ACCEPTED=	apache2 apache22
.include "../../mk/apache.mk"
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.42

CONFIGURE_ARGS+=	--with-apxs=${APXS}

.include "../../mk/bsd.pkg.mk"
