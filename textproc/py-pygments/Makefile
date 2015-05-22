# $NetBSD: Makefile,v 1.20 2015/05/22 08:18:01 adam Exp $

DISTNAME=	Pygments-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/P/Pygments/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pygments.org/
COMMENT=	Python syntax highlighter
LICENSE=	2-clause-bsd

USE_LANGUAGES=		# none
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
