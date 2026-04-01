# $NetBSD: Makefile,v 1.4 2026/04/01 11:53:16 adam Exp $

DISTNAME=	mkdocs_get_deps-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mkdocs-get-deps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mkdocs/get-deps
COMMENT=	MkDocs extension that lists all dependencies
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-mergedeep>=1.3.4:../../devel/py-mergedeep
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.2.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} mkdocs-get-deps mkdocs-get-deps-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
