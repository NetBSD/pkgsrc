# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:19 wiz Exp $
#

DISTNAME=	sunclock-1.4
CATEGORIES=	x11 time
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	perry@netbsd.org

USE_IMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=-DUSE_PUTENV
.endif

.include "../../mk/bsd.pkg.mk"
