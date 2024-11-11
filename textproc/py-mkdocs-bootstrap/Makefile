# $NetBSD: Makefile,v 1.7 2024/11/11 07:29:06 wiz Exp $

DISTNAME=	mkdocs-bootstrap-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mkdocs-bootstrap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mkdocs/mkdocs-bootstrap
COMMENT=	Bootstrap theme for MkDocs
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mkdocs>=1.1:../../textproc/py-mkdocs

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 312

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
