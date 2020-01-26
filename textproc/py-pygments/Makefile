# $NetBSD: Makefile,v 1.30 2020/01/26 17:32:17 rillig Exp $

DISTNAME=	Pygments-2.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pygments/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pygments.org/
COMMENT=	Python syntax highlighter
LICENSE=	2-clause-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
# circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_LANGUAGES=		# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pygmentize \
		${DESTDIR}${PREFIX}/bin/pygmentize-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/run.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
