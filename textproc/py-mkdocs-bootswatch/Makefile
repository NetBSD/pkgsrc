# $NetBSD: Makefile,v 1.4 2022/02/05 09:50:42 adam Exp $

DISTNAME=	mkdocs-bootswatch-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mkdocs-bootswatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mkdocs/mkdocs-bootswatch
COMMENT=	Bootswatch themes for MkDocs
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-mkdocs>=1.1:../../textproc/py-mkdocs

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
