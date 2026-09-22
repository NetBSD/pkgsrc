# $NetBSD: Makefile,v 1.9 2026/09/22 20:18:18 ktnb Exp $

DISTNAME=	nativefiledialog-extended-1.4.0
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=btzy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/btzy/nativefiledialog-extended/
COMMENT=	Cross platform native file dialog library with C and C++ bindings
LICENSE=	zlib

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DNFD_WAYLAND=OFF

.include "../../devel/cmake/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
