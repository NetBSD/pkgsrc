# $NetBSD: Makefile,v 1.44 2023/11/12 13:23:46 wiz Exp $

DISTNAME=	blackbox-0.77
PKGREVISION=	4
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=bbidulock/}
GITHUB_PROJECT=	blackboxwm
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/bbidulock/blackboxwm
COMMENT=	Small and fast X11 window manager
LICENSE=	mit

CONFLICTS=	bsetroot-[0-9]*
CONFLICTS+=	blackbox70-[0-9]*
SUPERSEDES+=	blackbox70-[0-9]*
PREV_PKGPATH=	wm/blackbox70

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

FORCE_CXX_STD=	c++03

REPLACE_SH=	util/bsetbg

CXXFLAGS.Linux+=	-fpermissive
CXXFLAGS.SunOS+=	-fpermissive

BUILDLINK_DEPMETHOD.libXt?=	build

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
