# $NetBSD: Makefile,v 1.7 1999/08/28 09:43:15 rh Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/12 16:50:43 vanilla Exp
#

DISTNAME=	Gtk---1.0.0
PKGNAME=	gtk---1.0.0
CATEGORIES=	x11 devel
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/gtk--/ \
		ftp://gd.tuwien.ac.at/graphics/gimp/gtk/gtk--/ \
		ftp://ftp.u-aizu.ac.jp/pub/graphics/tools/gimp/gtk/gtk--/ \
		ftp://ftp.flirble.org/pub/X/gimp/gtk/gtk--/ \
		http://lazy.ton.tut.fi/terop/iki/gtk/ \
		http://gd.tuwien.ac.at/graphics/gimp/gtk/gtk--/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lazy.ton.tut.fi/gtk--/gtk--.html

DEPENDS+=	gtk+-1.2.4:../../x11/gtk
BUILD_DEPENDS+=	gm4:../../devel/m4

USE_LIBTOOL=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gnome

.include "../../mk/bsd.pkg.mk"
