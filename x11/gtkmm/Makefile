# $NetBSD: Makefile,v 1.21 2004/10/03 00:18:33 tv Exp $
#

DISTNAME=	gtkmm-2.2.12
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/2.2/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to Gtk+ v2

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
USE_PERL5=		YES
USE_X11=		YES
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE=	atk/atkmm-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk/gdkmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glib/glibmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk/gtkmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	pango/pangomm-1.0.pc.in

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
