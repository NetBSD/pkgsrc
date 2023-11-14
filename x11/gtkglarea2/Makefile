# $NetBSD: Makefile,v 1.54 2023/11/14 14:03:11 wiz Exp $

DISTNAME=	gtkglarea-2.1.0
PKGNAME=	${DISTNAME:S/gtkglarea/gtkglarea2/}
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkglarea/2.1/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	OpenGL widget for the GTK+2 GUI toolkit
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIG_GUESS_OVERRIDE+=	.auto/config.guess
CONFIG_SUB_OVERRIDE+=	.auto/config.sub

PKGCONFIG_OVERRIDE=	gtkgl-2.0.pc.in

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
