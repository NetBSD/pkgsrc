# $NetBSD: Makefile,v 1.8 2023/11/12 13:24:07 wiz Exp $

DISTNAME=	gtkmm-4.2.0
PKGNAME=	${DISTNAME:S/gtkmm/gtkmm4/1}
PKGREVISION=	6
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ Interfaces for GTK+ and GNOME (v4)
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS+=		perl pkg-config
PKGCONFIG_OVERRIDE+=	gtk/gtkmm.pc.in

BUILDLINK_API_DEPENDS.gtk4+=	gtk4>=4.2
.include "../../x11/gtk4/buildlink3.mk"
.include "../../devel/glibmm2.68/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/pangomm2.48/buildlink3.mk"
.include "../../graphics/cairomm1.16/buildlink3.mk"
BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.35.5
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
