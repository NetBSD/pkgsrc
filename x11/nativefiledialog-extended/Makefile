# $NetBSD: Makefile,v 1.1 2025/01/12 15:17:14 ktnb Exp $

DISTNAME=	nativefiledialog-extended-1.2.1
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

.include "../../devel/cmake/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
