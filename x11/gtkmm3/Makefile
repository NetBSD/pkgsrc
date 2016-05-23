# $NetBSD: Makefile,v 1.16 2016/05/23 18:02:36 prlw1 Exp $

DISTNAME=	gtkmm-3.20.1
PKGNAME=	${DISTNAME:S/gtkmm/gtkmm3/1}
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ Interfaces for GTK+ and GNOME (v3)
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

USE_LANGUAGES=		c c++
CXXFLAGS+=		-std=c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	gdk/gdkmm.pc.in
PKGCONFIG_OVERRIDE+=	gtk/gtkmm.pc.in

.include "../../mk/bsd.prefs.mk"
PLIST_VARS+=	x11
.if !empty(PKG_BUILD_OPTIONS.gtk3:Mx11)
PLIST.x11=	yes
.endif

BUILDLINK_ABI_DEPENDS.atkmm+=	atkmm>=2.24.2
.include "../../devel/atkmm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.48.0
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.pangomm+=	pangomm>=2.38.2
.include "../../devel/pangomm/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.cairomm+=	cairomm>=1.12.0
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.gtk3+=	gtk3+>=3.20.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
