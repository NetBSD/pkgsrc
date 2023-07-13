# $NetBSD: Makefile,v 1.11 2023/07/13 10:03:29 wiz Exp $

DISTNAME=	django-tagging-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=Fantomas42/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Fantomas42/django-tagging/
COMMENT=	Generic tagging application for Django
LICENSE=	mit

GITHUB_PROJECT=	django-tagging
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=		# none

INSTALLATION_DIRS+=	share/doc/py-django-tagging

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} tagging/tests/tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
