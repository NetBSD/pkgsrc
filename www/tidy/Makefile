# $NetBSD: Makefile,v 1.51 2017/06/14 07:37:30 adam Exp $

DISTNAME=	tidy-html5-5.4.0
PKGNAME=	${DISTNAME:S/-html5//}
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=htacg/}
GITHUB_PROJECT=	tidy-html5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.html-tidy.org/
COMMENT=	Fixes and tidies up HTML files
LICENSE=	mit

GCC_REQD=	4.4

# for man page
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_LANGUAGES=	c c++

USE_CMAKE=	yes
CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PKGMANDIR}/man1
CMAKE_ARGS+=	-DINCLUDE_INSTALL_DIR:PATH=include/tidy

.include "../../mk/bsd.pkg.mk"
