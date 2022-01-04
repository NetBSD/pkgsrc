# $NetBSD: Makefile,v 1.2 2022/01/04 20:55:38 wiz Exp $

DISTNAME=	webdav-1.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
#MASTER_SITES=	${MASTER_SITE_PYPI:=w/webdav/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=kamikaze/}
GITHUB_PROJECT=	webdav
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kamikaze/webdav
COMMENT=	WebDAV client library
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-hamcrest-[0-9]*:../../devel/py-hamcrest
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

# bug in 1.1.7
EGG_NAME=	webdav-1.1.6

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
