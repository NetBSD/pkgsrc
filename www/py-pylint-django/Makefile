# $NetBSD: Makefile,v 1.24 2020/04/18 07:32:24 adam Exp $

DISTNAME=	pylint-django-2.0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/landscapeio/pylint-django
COMMENT=	Pylint plugin to aid Pylint in recognising the Django framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-pylint>=2.0.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pylint-plugin-utils>=0.5:../../devel/py-pylint-plugin-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
