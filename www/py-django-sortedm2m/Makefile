# $NetBSD: Makefile,v 1.4 2023/07/13 10:03:29 wiz Exp $

DISTNAME=	django-sortedm2m-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-sortedm2m/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gregmuellegger/django-sortedm2m
COMMENT=	Drop-in replacement for Django's many to many field
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${RM} ${WRKSRC}/sortedm2m/locale/es/.DS_Store

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
