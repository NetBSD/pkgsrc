# $NetBSD: Makefile,v 1.2 2002/08/14 02:14:16 dmcmahill Exp $

DISTNAME=	xvattr-1.3
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	veego@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	Modify Xv attributes

GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	YES

.if !exists(${X11BASE}/include/X11/extensions/Xvlib.h)
# you need Xv which isn't there in older X installs
NOT_FOR_PLATFORM=	*-*-*
.endif

.include "../../mk/x11.buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
