# $NetBSD: Makefile,v 1.59 2024/08/25 06:19:18 wiz Exp $

DISTNAME=	tidy-html5-5.8.0
PKGNAME=	${DISTNAME:S/-html5//}
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=htacg/}
GITHUB_PROJECT=	tidy-html5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.html-tidy.org/
COMMENT=	Fixes and tidies up HTML files
LICENSE=	mit

# for man page
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	tidy.pc.cmake.in

GCC_REQD+=	4.4

CMAKE_CONFIGURE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PKGMANDIR}/man1
CMAKE_CONFIGURE_ARGS+=	-DINCLUDE_INSTALL_DIR:PATH=include/tidy

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
