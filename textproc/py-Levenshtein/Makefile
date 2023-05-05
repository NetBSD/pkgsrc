# $NetBSD: Makefile,v 1.7 2023/05/05 19:32:18 adam Exp $

DISTNAME=	Levenshtein-0.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Levenshtein/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxbachmann/Levenshtein
COMMENT=	Python extension for computing string edit distances
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build>=0.13.0:../../devel/py-scikit-build
DEPENDS+=	${PYPKGPREFIX}-rapidfuzz>=2.3.0:../../textproc/py-rapidfuzz

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
