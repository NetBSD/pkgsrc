# $NetBSD: Makefile,v 1.19 2004/04/02 12:33:22 adam Exp $
#

DISTNAME=	gtkmm-2.2.10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

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
