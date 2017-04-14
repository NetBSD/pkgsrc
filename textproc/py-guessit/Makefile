# $NetBSD: Makefile,v 1.1 2017/04/14 14:13:18 leot Exp $

DISTNAME=	guessit-2.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=g/guessit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://guessit.io/
COMMENT=	Extracts as much information as possible from a video filename
LICENSE=	gnu-lgpl-v3

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

DEPENDS+=	${PYPKGPREFIX}-babelfish>=0.5.5:../../textproc/py-babelfish
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-rebulk>=0.8.2:../../textproc/py-rebulk

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/guessit ${DESTDIR}${PREFIX}/bin/guessit-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
