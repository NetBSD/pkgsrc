# $NetBSD: Makefile,v 1.1.1.1 2000/07/01 04:13:30 danw Exp $
#

DISTNAME=		sawfish-0.28.1
CATEGORIES=		x11 gnome
MASTER_SITES=		ftp://sawmill.sourceforge.net/pub/sawmill/

MAINTAINER=		danw@netbsd.org
HOMEPAGE=		http://sawmill.sourceforge.net/

DEPENDS+=		librep>=0.12:../../lang/librep
DEPENDS+=		rep-gtk-*:../../x11/rep-gtk
DEPENDS+=		imlib>=1.8.2:../../graphics/imlib
DEPENDS+=		control-center-*:../../x11/controlcenter

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

CONFIGURE_FLAGS+=	--with-readline

.include "../../mk/bsd.pkg.mk"
