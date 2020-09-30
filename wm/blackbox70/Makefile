# $NetBSD: Makefile,v 1.24 2020/09/30 03:07:25 gutteridge Exp $

VERSION=	0.76
DISTNAME=	blackbox-${VERSION}
PKGNAME=	blackbox70-${VERSION}
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=bbidulock/}
GITHUB_PROJECT=	blackboxwm
GITHUB_RELEASE=	${VERSION}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bbidulock/blackboxwm
COMMENT=	Small and fast X11 window manager
LICENSE=	mit

CONFLICTS=	bsetroot-[0-9]*
CONFLICTS+=	blackbox-[0-9]*

USE_LANGUAGES=	c c++03
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

CXXFLAGS.Linux+=	-fpermissive
CXXFLAGS.SunOS+=	-fpermissive

BUILDLINK_DEPMETHOD.libXt?=	build

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
