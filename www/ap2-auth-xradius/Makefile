# $NetBSD: Makefile,v 1.9 2014/06/10 15:22:17 joerg Exp $

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

PKG_APACHE_ACCEPTED=	apache22
.include "../../mk/apache.mk"

CONFIGURE_ARGS+=	--with-apxs=${APXS}

.include "../../mk/bsd.pkg.mk"
