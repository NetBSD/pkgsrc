# $NetBSD: Makefile,v 1.10 2004/10/03 00:18:40 tv Exp $

DISTNAME=	xvattr-1.3
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	veego@NetBSD.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	Modify Xv attributes

USE_BUILDLINK3=		yes
USE_X11=		# defined
GNU_CONFIGURE=		# defined

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/Xvlib.h)
PKG_FAIL_REASON=	"${PKGNAME} requires libXv.a"
.endif

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
