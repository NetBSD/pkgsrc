# $NetBSD: Makefile,v 1.17 2012/10/08 13:04:29 asau Exp $
#

DISTNAME=	sunclock-1.5
PKGREVISION=	2
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

USE_IMAKE=	yes

CPPFLAGS.SunOS+=	-DUSE_PUTENV

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
