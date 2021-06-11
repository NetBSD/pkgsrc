# $NetBSD: Makefile,v 1.39 2021/06/11 21:30:39 gutteridge Exp $

DISTNAME=	blackbox-0.77
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=bbidulock/}
GITHUB_PROJECT=	blackboxwm
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bbidulock/blackboxwm
COMMENT=	Small and fast X11 window manager
LICENSE=	mit

CONFLICTS=	bsetroot-[0-9]*
CONFLICTS+=	blackbox70-[0-9]*
SUPERSEDES+=	blackbox70-[0-9]*
PREV_PKGPATH=	wm/blackbox70

USE_LANGUAGES=	c c++03
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

REPLACE_SH=	util/bsetbg

CXXFLAGS.Linux+=	-fpermissive
CXXFLAGS.SunOS+=	-fpermissive

BUILDLINK_DEPMETHOD.libXt?=	build

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
