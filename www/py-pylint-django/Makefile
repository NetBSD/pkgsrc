# $NetBSD: Makefile,v 1.3 2018/01/31 12:03:47 adam Exp $

DISTNAME=	pylint-django-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-django/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/landscapeio/pylint-django
COMMENT=	Pylint plugin to aid Pylint in recognising the Django framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-pylint>=1.8:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pylint-plugin-utils>=0.2.1:../../devel/py-pylint-plugin-utils

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
