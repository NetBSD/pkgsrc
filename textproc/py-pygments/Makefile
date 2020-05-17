# $NetBSD: Makefile,v 1.32 2020/05/17 21:38:46 adam Exp $

DISTNAME=	Pygments-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pygments/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pygments.org/
COMMENT=	Python syntax highlighter
LICENSE=	2-clause-bsd

# circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pygmentize pygmentize-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
