# $NetBSD: Makefile,v 1.1.1.1 1999/12/17 14:56:28 mellon Exp $
#

DISTNAME=       rep-gtk-0.7
CATEGORIES=	x11 devel
MASTER_SITES=   ftp://rep-gtk.sourceforge.net/pub/rep-gtk/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://rep-gtk.sourceforge.net/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	librep-*:../../devel/librep
DEPENDS+=	imlib-*:../../graphics/imlib

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
