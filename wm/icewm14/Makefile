# $NetBSD: Makefile,v 1.11 2023/01/29 21:17:59 ryoon Exp $

DISTNAME=	icewm-1.4.2
PKGREVISION=	7
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=bbidulock/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2
EXTRACT_USING=	gtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ice-wm.org/
COMMENT=	Small, fast and light-weight window manager
LICENSE=	gnu-gpl-v2

CONFLICTS+=	icewm-imlib-[0-9]*

FILESDIR=	${.CURDIR}/../../wm/icewm/files

USE_CMAKE=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	msgfmt pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

CMAKE_ARGS.NetBSD+=	-DCMAKE_CXX_FLAGS="-DHAVE_SYSCTL_CP_TIME"

post-extract:
	cp ${FILESDIR}/bsd-daemon.xpm ${WRKSRC}/lib/taskbar

#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
