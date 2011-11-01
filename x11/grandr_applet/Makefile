# $NetBSD: Makefile,v 1.16 2011/11/01 06:02:51 sbd Exp $
#

DISTNAME=	grandr_applet-0.4
PKGREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	http://dekorte.homeip.net/download/grandr-applet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dekorte.homeip.net/download/grandr-applet/
COMMENT=	gnome-panel front end to the xrandr extension

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
