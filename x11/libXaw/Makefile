# $NetBSD: Makefile,v 1.20 2022/11/09 13:14:20 joerg Exp $

DISTNAME=		libXaw-1.0.14
PKGREVISION=		1
CATEGORIES=		x11 graphics
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Athena Widgets Library from modular Xorg X11

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xaw6.pc.in
PKGCONFIG_OVERRIDE+=	xaw7.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
