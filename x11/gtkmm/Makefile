# $NetBSD: Makefile,v 1.13 2003/12/13 00:45:26 wiz Exp $
#

DISTNAME=	gtkmm-2.2.8
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to Gtk+ v2

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_PERL5=		YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/atk/atkmm-1.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gdk/gdkmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/glib/glibmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gtk/gtkmm-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pango/pangomm-1.0.pc.in

.include "../../devel/libsigc++/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
