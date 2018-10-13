# $NetBSD: Makefile,v 1.54 2018/10/13 11:14:38 leot Exp $

DISTNAME=	tidy-html5-5.6.0
PKGNAME=	${DISTNAME:S/-html5//}
PKGREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=htacg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.html-tidy.org/
COMMENT=	Fixes and tidies up HTML files
LICENSE=	mit

GITHUB_PROJECT=	tidy-html5

# for man page
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	tidy.pc.cmake.in

GCC_REQD+=	4.4

CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PKGMANDIR}/man1
CMAKE_ARGS+=	-DINCLUDE_INSTALL_DIR:PATH=include/tidy

.include "../../mk/bsd.pkg.mk"
