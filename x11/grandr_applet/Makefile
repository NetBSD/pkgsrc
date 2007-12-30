# $NetBSD: Makefile,v 1.2 2007/12/30 16:29:15 joerg Exp $
#

DISTNAME=	grandr_applet-0.4
CATEGORIES=	x11
MASTER_SITES=	http://dekorte.homeip.net/download/grandr-applet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dekorte.homeip.net/download/grandr-applet/
COMMENT=	gnome-panel front end to the xrandr extension

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt
USE_DIRS+=		xdg-1.1

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
