# $NetBSD: Makefile,v 1.4 2018/03/07 11:57:46 wiz Exp $

DISTNAME=		xkbutils-1.0.4
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Small utilities utilizing the X11 XKeyboard (XKB) extension

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
