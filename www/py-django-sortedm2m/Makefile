# $NetBSD: Makefile,v 1.6 2024/11/11 07:29:20 wiz Exp $

DISTNAME=	django-sortedm2m-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sortedm2m/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gregmuellegger/django-sortedm2m
COMMENT=	Drop-in replacement for Django's many to many field
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${RM} ${WRKSRC}/sortedm2m/locale/es/.DS_Store

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
