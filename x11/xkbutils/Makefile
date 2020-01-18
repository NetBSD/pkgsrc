# $NetBSD: Makefile,v 1.5 2020/01/18 23:36:09 rillig Exp $

DISTNAME=		xkbutils-1.0.4
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Small utilities utilizing the X11 XKeyboard (XKB) extension

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
