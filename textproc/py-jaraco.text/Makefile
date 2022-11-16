# $NetBSD: Makefile,v 1.2 2022/11/16 22:55:44 wiz Exp $

DISTNAME=	jaraco.text-3.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.text
COMMENT=	Module for text manipulation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-autocommand-[0-9]*:../../misc/py-autocommand
DEPENDS+=	${PYPKGPREFIX}-jaraco.context>=4.1:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools-[0-9]*:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-inflect-[0-9]*:../../lang/py-inflect
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 38
DEPENDS+=	${PYPKGPREFIX}-importlib-resources-[0-9]*:../../devel/py-importlib-resources
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
