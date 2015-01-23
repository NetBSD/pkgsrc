# $NetBSD: Makefile,v 1.18 2015/01/23 07:07:42 obache Exp $

DISTNAME=	Pygments-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/P/Pygments/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://pygments.org/
COMMENT=	Python syntax highlighter
LICENSE=	2-clause-bsd

USE_LANGUAGES=		#none
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_TARGET=	test
.endif

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pygmentize ${DESTDIR}${PREFIX}/bin/pygmentize${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
