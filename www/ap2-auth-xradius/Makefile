# $NetBSD: Makefile,v 1.1.1.1 2006/08/13 17:34:16 adrianp Exp $

DISTNAME=	mod_auth_xradius-0.4.6
PKGNAME=	ap2-auth-xradius-0.4.6
CATEGORIES=	www databases
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_auth_xradius/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.outoforder.cc/projects/apache/mod_auth_xradius/
COMMENT=	Module to allow apache2 authentication against a RADIUS server

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs

BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.42

.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
