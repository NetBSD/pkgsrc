# $NetBSD: Makefile,v 1.8 2026/08/17 18:06:38 wiz Exp $

DISTNAME=	xpr-1.2.1
CATEGORIES=	x11 print
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Formats xwd dump files as output for various types of printers

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
