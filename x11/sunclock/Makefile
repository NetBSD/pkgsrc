# $NetBSD: Makefile,v 1.8 1999/12/21 11:52:42 agc Exp $
#

DISTNAME=	sunclock-1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	perry@netbsd.org

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=-DUSE_PUTENV
.endif

.include "../../mk/bsd.pkg.mk"
