# $NetBSD: Makefile,v 1.4 2002/09/23 23:15:14 jlam Exp $

DISTNAME=	xvattr-1.3
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	veego@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	Modify Xv attributes

USE_BUILDLINK2=		# defined
USE_X11=		# defined
GNU_CONFIGURE=		# defined

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/Xvlib.h)
IGNORE=			"${PKGNAME} requires libXv.a."
.endif

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
