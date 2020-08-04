# $NetBSD: Makefile,v 1.1 2020/08/04 00:31:23 joerg Exp $

DISTNAME=	django-phnumber-field-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=stefanfoulis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/stefanfoulis/django-phonenumber-field
COMMENT=	Django library for managing phone numbers
LICENSE=	mit

GITHUB_PROJECT=	django-phonenumber-field
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-django>=1.11.3:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=7.0.2:../../textproc/py-phonenumbers
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=		# none

do-test:
	cd ${WRKSRC} && ${PREFIX}/bin/coverage-${PYVERSSUFFIX} run -m django test --settings=tests.settings

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
