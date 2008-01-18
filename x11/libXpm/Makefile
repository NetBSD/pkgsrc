# $NetBSD: Makefile,v 1.5 2008/01/18 15:36:34 joerg Exp $
#

DISTNAME=		libXpm-3.5.7
CATEGORIES=		graphics x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X PixMap Library from modular Xorg X11

CONFLICTS+=		xpm-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config xgettext
PKGCONFIG_OVERRIDE+=	xpm.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
