# $NetBSD: Makefile,v 1.3 2006/12/27 13:37:41 joerg Exp $

DISTNAME=		w9wm-0.4.2
PKGREVISION=		1
CATEGORIES=		plan9 wm
MASTER_SITES=		http://www.grassouille.org/code/w9wm/src/

MAINTAINER=		rumble@NetBSD.org
HOMEPAGE=		http://www.grassouille.org/code/w9wm.en.html
COMMENT=		8 1/2-like Window Manager for X with virtual desktops

WRKSRC=			${WRKDIR}/${DISTNAME}.orig
USE_IMAKE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
