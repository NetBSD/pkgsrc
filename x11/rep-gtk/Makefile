# $NetBSD: Makefile,v 1.4 2000/08/07 15:51:37 danw Exp $
#

DISTNAME=	rep-gtk-0.13a
CATEGORIES=	x11 lang
MASTER_SITES=	ftp://rep-gtk.sourceforge.net/pub/rep-gtk/

MAINTAINER=	danw@netbsd.org
HOMEPAGE=	http://rep-gtk.sourceforge.net/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	librep>=0.12:../../lang/librep
DEPENDS+=	libglade-*:../../devel/libglade
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=	gdk-pixbuf-*:../../graphics/gdk-pixbuf

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
