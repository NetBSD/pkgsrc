# $NetBSD: Makefile,v 1.1.1.1 2003/03/01 14:33:05 jmmv Exp $
#

DISTNAME=	gtkmm-2.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to Gtk+ v2

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	atk/atkmm-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gdk/gdkmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	glib/glibmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk/gtkmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	pango/pangomm-1.0.pc.in

.include "../../devel/libsigc++/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
