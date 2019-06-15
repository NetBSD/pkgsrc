# $NetBSD: Makefile,v 1.5 2019/06/15 19:04:24 adam Exp $

DISTNAME=	guessit-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guessit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://guessit.readthedocs.io/en/latest/
COMMENT=	Extracts as much information as possible from a video filename
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-babelfish>=0.5.5:../../textproc/py-babelfish
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-rebulk>=0.9.0:../../textproc/py-rebulk
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.7.3:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*: not yet packaged

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} guessit guessit-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
