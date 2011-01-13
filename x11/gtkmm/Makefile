# $NetBSD: Makefile,v 1.75 2011/01/13 16:05:00 drochner Exp $

DISTNAME=	gtkmm-2.22.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to Gtk+ v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run pkg-config
GNU_CONFIGURE=		yes

EXTRACT_USING=		bsdtar

PKGCONFIG_OVERRIDE+=	gdk/gdkmm.pc.in
PKGCONFIG_OVERRIDE+=	gtk/gtkmm.pc.in

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.20.1

.include "../../devel/atkmm/buildlink3.mk"
.include "../../devel/pangomm/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
