# $NetBSD: Makefile,v 1.27 2017/02/18 13:09:11 adam Exp $

DISTNAME=	Pygments-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pygments/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pygments.org/
COMMENT=	Python syntax highlighter
LICENSE=	2-clause-bsd

# test dependencies
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
# can't depend on sphinx since sphinx depends on pygments
#BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_LANGUAGES=		# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pygmentize ${DESTDIR}${PREFIX}/bin/pygmentize${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
