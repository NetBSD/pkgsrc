# $NetBSD: Makefile,v 1.8 2022/04/29 13:34:52 wiz Exp $

DISTNAME=	Pallets-Sphinx-Themes-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pallets-Sphinx-Themes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pallets/pallets-sphinx-themes
COMMENT=	Sphinx themes for Pallets and related projects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} < 38
PYTHON_VERSIONED_DEPENDENCIES+=	importlib-metadata
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
