# $NetBSD: Makefile,v 1.2 2026/01/27 08:40:50 wiz Exp $

PM_GTK_VER=	3

PKGREVISION= 1
.include "../../www/palemoon/Makefile.common"
.include "../../www/palemoon/hacks.mk"

PKGNAME=	palemoon-gtk3-${PM_VER}

CONFLICTS+=	palemoon-[0-9]*

ALL_ENV+=	MOZ_PKG_SPECIAL=gtk${PM_GTK_VER}

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
