# $NetBSD: Makefile,v 1.3.2.2 2002/06/21 23:05:45 jlam Exp $
#

DISTNAME=	sunclock-1.4
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	perry@netbsd.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

USE_BUILDLINK2=	yes
USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DUSE_PUTENV
.endif

.include "../../mk/bsd.pkg.mk"
