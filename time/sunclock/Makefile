# $NetBSD: Makefile,v 1.3 2001/06/11 06:34:53 jlam Exp $
#

DISTNAME=	sunclock-1.4
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	perry@netbsd.org
COMMENT=	Show which portion of the Earth's surface is illuminated by the Sun

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DUSE_PUTENV
.endif

.include "../../mk/bsd.pkg.mk"
