# $NetBSD: Makefile,v 1.2 2000/07/01 03:40:18 danw Exp $
#

DISTNAME=	rep-gtk-0.11
CATEGORIES=	x11 lang
MASTER_SITES=	ftp://rep-gtk.sourceforge.net/pub/rep-gtk/

MAINTAINER=	danw@netbsd.org
HOMEPAGE=	http://rep-gtk.sourceforge.net/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	librep>=0.11:../../lang/librep
DEPENDS+=	libglade-*:../../devel/libglade
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	gettext-*:../../devel/gettext

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
