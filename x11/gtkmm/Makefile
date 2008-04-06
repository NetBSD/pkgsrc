# $NetBSD: Makefile,v 1.59 2008/04/06 12:13:11 adam Exp $

DISTNAME=	gtkmm-2.12.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to Gtk+ v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-examples

PKGCONFIG_OVERRIDE=	atk/atkmm-1.6.pc.in
PKGCONFIG_OVERRIDE+=	gdk/gdkmm-2.4.pc.in
PKGCONFIG_OVERRIDE+=	gtk/gtkmm-2.4.pc.in
PKGCONFIG_OVERRIDE+=	pango/pangomm-1.4.pc.in

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.12.3
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0

.include "../../devel/glibmm/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
