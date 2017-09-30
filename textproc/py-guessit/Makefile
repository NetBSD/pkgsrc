# $NetBSD: Makefile,v 1.2 2017/09/30 14:13:08 adam Exp $

DISTNAME=	guessit-2.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guessit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://guessit.io/
COMMENT=	Extracts as much information as possible from a video filename
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-babelfish>=0.5.5:../../textproc/py-babelfish
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-rebulk>=0.9.0:../../textproc/py-rebulk
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} guessit guessit${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
