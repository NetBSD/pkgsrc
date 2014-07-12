# $NetBSD: Makefile,v 1.11 2014/07/12 12:03:42 obache Exp $
#

DISTNAME=		xkbcomp-1.2.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XKBD keymap compiler

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	xkbcomp.pc.in

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
BUILDLINK_API_DEPENDS.xproto+=	xproto>=7.0.17
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
