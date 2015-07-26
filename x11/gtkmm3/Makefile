# $NetBSD: Makefile,v 1.14 2015/07/26 23:53:45 wiz Exp $

DISTNAME=	gtkmm-3.16.0
PKGNAME=	${DISTNAME:S/gtkmm/gtkmm3/1}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/3.16/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ Interfaces for GTK+ and GNOME (v3)
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

USE_LANGUAGES=		c c++
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

.include "../../devel/atkmm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.44.0
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/mm-common/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.gtk3+=	gtk3+>=3.16.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
