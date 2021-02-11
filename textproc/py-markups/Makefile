# $NetBSD: Makefile,v 1.4 2021/02/11 03:31:37 gutteridge Exp $

VERSION=	3.1.0
DISTNAME=	Markups-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markups/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/retext-project/pymarkups
COMMENT=	Python text markup language wrapper module
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-markdown-math-[0-9]*:../../textproc/py-markdown-math
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-textile-[0-9]*:../../textproc/py-textile

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-markdown-math

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
