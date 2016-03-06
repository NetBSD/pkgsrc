# $NetBSD: Makefile,v 1.8 2016/03/06 14:46:42 adam Exp $

DISTNAME=	django-tagging-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-tagging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Fantomas42/django-tagging/
COMMENT=	Generic tagging application for Django
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=		# none

INSTALLATION_DIRS+=	share/doc/py-django-tagging

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} tagging/tests/tests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
