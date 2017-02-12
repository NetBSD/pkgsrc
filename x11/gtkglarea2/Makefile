# $NetBSD: Makefile,v 1.39 2017/02/12 06:24:54 ryoon Exp $

DISTNAME=	gtkglarea-2.0.1
PKGNAME=	${DISTNAME:S/gtkglarea/gtkglarea2/}
PKGREVISION=	20
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkglarea/2.0/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	OpenGL widget for the GTK+2 GUI toolkit
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIG_GUESS_OVERRIDE+=	.auto/config.guess
CONFIG_SUB_OVERRIDE+=	.auto/config.sub

PKGCONFIG_OVERRIDE=	gtkgl-2.0.pc.in

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
