# $NetBSD: Makefile,v 1.3 2013/02/11 08:59:57 wiz Exp $
#

DISTNAME=		xkbutils-1.0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Small utilities utilizing the X11 XKeyboard (XKB) extension

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
