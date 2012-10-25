# $NetBSD: Makefile,v 1.12 2012/10/25 06:56:51 asau Exp $
#

DISTNAME=	Pygments-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/P/Pygments/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://pygments.org/
COMMENT=	Python syntax highlighter
LICENSE=	2-clause-bsd

USE_LANGUAGES=		#none

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_TARGET=	test
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
