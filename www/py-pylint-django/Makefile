# $NetBSD: Makefile,v 1.36 2023/10/28 19:57:25 wiz Exp $

DISTNAME=	pylint_django-2.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/landscapeio/pylint-django
COMMENT=	Pylint plugin to aid Pylint in recognising the Django framework
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-pylint>=2.0.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pylint-plugin-utils>=0.8:../../devel/py-pylint-plugin-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
