# $NetBSD: Makefile,v 1.15 2026/02/13 09:31:56 adam Exp $

DISTNAME=	cssselect2-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cssselect2/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/Kozea/cssselect2
COMMENT=	CSS selectors for Python ElementTree
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-tinycss2-[0-9]*:../../textproc/py-tinycss2
DEPENDS+=	${PYPKGPREFIX}-webencodings-[0-9]*:../../textproc/py-webencodings

USE_LANGUAGES=	# none

# as of 0.9.0
# 446 passed, 9 xfailed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
