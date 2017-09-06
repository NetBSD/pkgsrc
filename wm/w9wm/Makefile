# $NetBSD: Makefile,v 1.8 2017/09/06 10:40:34 wiz Exp $

DISTNAME=		w9wm-0.4.2
PKGREVISION=		1
CATEGORIES=		plan9 wm
MASTER_SITES=		http://www.grassouille.org/code/w9wm/src/

#HOMEPAGE=		http://www.grassouille.org/code/w9wm.en.html
COMMENT=		8 1/2-like Window Manager for X with virtual desktops

WRKSRC=			${WRKDIR}/${DISTNAME}.orig
USE_IMAKE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
