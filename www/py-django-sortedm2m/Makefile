# $NetBSD: Makefile,v 1.5 2023/12/02 09:01:10 adam Exp $

DISTNAME=	django-sortedm2m-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sortedm2m/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gregmuellegger/django-sortedm2m
COMMENT=	Drop-in replacement for Django's many to many field
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${RM} ${WRKSRC}/sortedm2m/locale/es/.DS_Store

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
