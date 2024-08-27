# $NetBSD: Makefile,v 1.4 2024/08/27 05:20:53 wiz Exp $

DISTNAME=		xclipboard-1.1.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Manage the X server clipboard
LICENSE=		x11

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

MAKE_FLAGS+=	appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
