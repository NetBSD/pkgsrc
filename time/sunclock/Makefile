# $NetBSD: Makefile,v 1.8 2004/11/30 21:17:30 perry Exp $
#

DISTNAME=	sunclock-1.5
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	perry@NetBSD.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

USE_BUILDLINK3=	yes
USE_IMAKE=	yes

CPPFLAGS.SunOS=	-DUSE_PUTENV

.include "../../mk/bsd.pkg.mk"
