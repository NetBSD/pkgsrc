# $NetBSD: Makefile,v 1.6 2003/07/17 22:55:06 grant Exp $
#

DISTNAME=	sunclock-1.4
PKGREVISION=	1
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	perry@NetBSD.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

USE_BUILDLINK2=	yes
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DUSE_PUTENV
.endif

.include "../../mk/bsd.pkg.mk"
