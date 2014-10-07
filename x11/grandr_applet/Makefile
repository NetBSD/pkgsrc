# $NetBSD: Makefile,v 1.49 2014/10/07 16:47:38 adam Exp $
#

DISTNAME=	grandr_applet-0.4
PKGREVISION=	42
CATEGORIES=	x11
MASTER_SITES=	http://dekorte.homeip.net/download/grandr-applet/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dekorte.homeip.net/download/grandr-applet/
COMMENT=	GNOME panel applet for controlling the X RandR extension

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
