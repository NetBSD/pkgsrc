# $NetBSD: Makefile,v 1.10 2018/07/14 12:12:33 adam Exp $

DISTNAME=	pylint-django-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/landscapeio/pylint-django
COMMENT=	Pylint plugin to aid Pylint in recognising the Django framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-pylint>=1.8.2:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pylint-plugin-utils>=0.2.1:../../devel/py-pylint-plugin-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # pylint-plugin-utils

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
