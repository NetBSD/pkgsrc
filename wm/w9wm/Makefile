# $NetBSD: Makefile,v 1.7 2012/10/23 10:24:15 wiz Exp $

DISTNAME=		w9wm-0.4.2
PKGREVISION=		1
CATEGORIES=		plan9 wm
MASTER_SITES=		http://www.grassouille.org/code/w9wm/src/

HOMEPAGE=		http://www.grassouille.org/code/w9wm.en.html
COMMENT=		8 1/2-like Window Manager for X with virtual desktops

WRKSRC=			${WRKDIR}/${DISTNAME}.orig
USE_IMAKE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
