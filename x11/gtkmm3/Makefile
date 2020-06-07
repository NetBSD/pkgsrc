# $NetBSD: Makefile,v 1.41 2020/06/07 18:09:13 rillig Exp $

DISTNAME=	gtkmm-3.24.2
PKGNAME=	${DISTNAME:S/gtkmm/gtkmm3/1}
PKGREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	C++ Interfaces for GTK+ and GNOME (v3)
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

USE_LANGUAGES=		c c++11
GCC_REQD+=		4.9
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	gdk/gdkmm.pc.in
PKGCONFIG_OVERRIDE+=	gtk/gtkmm.pc.in
TEST_TARGET=		check

BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22.0
.include "../../x11/gtk3/buildlink3.mk"

PLIST_VARS+=	x11
.if ${PKG_BUILD_OPTIONS.gtk3:Mx11}
PLIST.x11=	yes
.endif

BUILDLINK_API_DEPENDS.atkmm+=	atkmm>=2.24.2
.include "../../devel/atkmm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.49.1
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
BUILDLINK_API_DEPENDS.pangomm+=	pangomm>=2.38.2
.include "../../devel/pangomm/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairomm+=	cairomm>=1.12.0
.include "../../graphics/cairomm/buildlink3.mk"
BUILDLINK_API_DEPENDS.gdk-pixbuf2+=	gdk-pixbuf2>=2.35.5
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
