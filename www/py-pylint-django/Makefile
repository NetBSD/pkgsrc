# $NetBSD: Makefile,v 1.37 2024/10/22 11:41:48 adam Exp $

DISTNAME=	pylint-django-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pylint-dev/pylint-django
COMMENT=	Pylint plugin to aid Pylint in recognising the Django framework
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-pylint>=3.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pylint-plugin-utils>=0.8:../../devel/py-pylint-plugin-utils

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
