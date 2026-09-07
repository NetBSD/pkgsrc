# $NetBSD: Makefile,v 1.10 2026/09/07 08:37:15 adam Exp $

DISTNAME=	xmldiff-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmldiff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Shoobx/xmldiff
COMMENT=	Creates diffs of XML files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.1.0:../../textproc/py-lxml

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	xmldiff xmlpatch

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
