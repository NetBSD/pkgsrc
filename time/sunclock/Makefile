# $NetBSD: Makefile,v 1.13 2006/12/27 13:37:40 joerg Exp $
#

DISTNAME=	sunclock-1.5
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	perry@NetBSD.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

USE_IMAKE=	yes

CPPFLAGS.SunOS+=	-DUSE_PUTENV

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
