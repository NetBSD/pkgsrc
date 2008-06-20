# $NetBSD: Makefile,v 1.5 2008/06/20 01:09:40 joerg Exp $

DISTNAME=		w9wm-0.4.2
PKGREVISION=		1
CATEGORIES=		plan9 wm
MASTER_SITES=		http://www.grassouille.org/code/w9wm/src/

HOMEPAGE=		http://www.grassouille.org/code/w9wm.en.html
COMMENT=		8 1/2-like Window Manager for X with virtual desktops

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}.orig
USE_IMAKE=		yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
