# $NetBSD: Makefile,v 1.14 2007/02/15 22:37:06 perry Exp $
#

DISTNAME=	sunclock-1.5
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

USE_IMAKE=	yes

CPPFLAGS.SunOS+=	-DUSE_PUTENV

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
