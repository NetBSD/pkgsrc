# $NetBSD: Makefile,v 1.5 2005/04/11 21:48:08 tv Exp $

DISTNAME=	gtkmm-2.4.8
PKGNAME=	gtkmm24-2.4.8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkmm/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gtkmm.org/
COMMENT=	C++ interface to Gtk+ v2

USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PERL5=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	atk/atkmm-1.6.pc.in
PKGCONFIG_OVERRIDE+=	gdk/gdkmm-2.4.pc.in
PKGCONFIG_OVERRIDE+=	gtk/gtkmm-2.4.pc.in
PKGCONFIG_OVERRIDE+=	pango/pangomm-1.4.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glibmm24/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
