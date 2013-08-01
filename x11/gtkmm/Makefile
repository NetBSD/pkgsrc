# $NetBSD: Makefile,v 1.97 2013/08/01 08:24:50 adam Exp $

DISTNAME=	gtkmm-2.24.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to Gtk+ v2
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run pkg-config
GNU_CONFIGURE=		yes

EXTRACT_USING=		bsdtar

PKGCONFIG_OVERRIDE+=	gdk/gdkmm.pc.in
PKGCONFIG_OVERRIDE+=	gtk/gtkmm.pc.in

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.24.0

.include "../../devel/atkmm/buildlink3.mk"
BUILDLINK_API_DEPENDS.pangomm+= pangomm>=2.28.0
.include "../../devel/pangomm/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
