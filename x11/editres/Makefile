# $NetBSD: Makefile,v 1.16 2026/04/27 08:34:13 wiz Exp $

DISTNAME=		editres-1.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Dynamic resource editor for libXt applications

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libXaw/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXmu+=	libXmu>=1.3.0
.include "../../x11/libXmu/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXt+=	libXt>=1.0.99.1
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
