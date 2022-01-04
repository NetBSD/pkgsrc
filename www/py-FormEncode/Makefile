# $NetBSD: Makefile,v 1.7 2022/01/04 20:55:14 wiz Exp $

DISTNAME=	FormEncode-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/FormEncode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://formencode.org/
COMMENT=	HTML form validation, generation, and conversion package
LICENSE=	python-software-foundation

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm_git_archive-[0-9]*:../../devel/py-setuptools_scm_git_archive
TEST_DEPENDS+=	${PYPKGPREFIX}-country-[0-9]*:../../geography/py-country
TEST_DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-country

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

INSTALLATION_DIRS+=	share/doc/${PYPKGPREFIX}-FormEncode

post-install:
	${MV} ${DESTDIR}${PREFIX}/LICENSE.txt ${DESTDIR}${PREFIX}/share/doc/${PYPKGPREFIX}-FormEncode

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
