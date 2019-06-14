# $NetBSD: Makefile,v 1.20 2019/06/14 02:09:03 gutteridge Exp $

VERSION=	0.74
PKGREVISION=	1
DISTNAME=	blackbox-${VERSION}
PKGNAME=	blackbox70-${VERSION}
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=bbidulock/}
GITHUB_PROJECT=	blackboxwm
GITHUB_TAG=	${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bbidulock/blackboxwm
COMMENT=	Small and fast X11 window manager
LICENSE=	mit

CONFLICTS=	bsetroot-[0-9]*
CONFLICTS+=	blackbox-[0-9]*

USE_LANGUAGES=	c c++03
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autopoint gettext-m4 gsed pkg-config
GNU_CONFIGURE=	YES

CXXFLAGS.Linux+=	-fpermissive

CONFIGURE_ARGS+=	--enable-nls

BROKEN_GETTEXT_DETECTION=yes

BUILDLINK_DEPMETHOD.libXt?=	build

pre-configure:
	cd ${WRKSRC}; ${SH} ./autogen.sh

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
