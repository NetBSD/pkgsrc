# $NetBSD: Makefile,v 1.8 2019/07/21 22:25:51 wiz Exp $

DISTNAME=	icewm-1.3.8
PKGREVISION=	4
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icewm/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.icewm.org/
COMMENT=	Small, fast and light-weight window manager
#LICENSE=	# TODO: (see mk/license.mk)

CONFLICTS+=	icewm-imlib-[0-9]*

FILESDIR=	${.CURDIR}/../../wm/icewm/files

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++03
USE_TOOLS+=	msgfmt pkg-config

post-extract:
	cp ${FILESDIR}/bsd-daemon.xpm ${WRKSRC}/lib/taskbar

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
