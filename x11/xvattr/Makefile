# $NetBSD: Makefile,v 1.8 2003/07/17 22:57:04 grant Exp $

DISTNAME=	xvattr-1.3
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	veego@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	Modify Xv attributes

USE_BUILDLINK2=		# defined
USE_X11=		# defined
GNU_CONFIGURE=		# defined

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/Xvlib.h)
PKG_FAIL_REASON=	"${PKGNAME} requires libXv.a"
.endif

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
