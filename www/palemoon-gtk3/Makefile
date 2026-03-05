# $NetBSD: Makefile,v 1.3 2026/03/05 14:03:01 nia Exp $

PM_GTK_VER=	3

.include "../../www/palemoon/Makefile.common"
.include "../../www/palemoon/hacks.mk"

PKGNAME=	palemoon-gtk3-${PM_VER}

CONFLICTS+=	palemoon-[0-9]*

ALL_ENV+=	MOZ_PKG_SPECIAL=gtk${PM_GTK_VER}

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
