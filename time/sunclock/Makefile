# $NetBSD: Makefile,v 1.11 2005/12/05 20:51:09 rillig Exp $
#

DISTNAME=	sunclock-1.5
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	perry@NetBSD.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

USE_IMAKE=	yes

CPPFLAGS.SunOS+=	-DUSE_PUTENV

.include "../../mk/bsd.pkg.mk"
