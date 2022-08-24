# $NetBSD: Makefile,v 1.12 2022/08/24 09:25:57 wiz Exp $

DISTNAME=	waitress-1.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/waitress/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Pylons/waitress
COMMENT=	Production-quality pure-Python WSGI server
LICENSE=	zpl-2.1

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	coverage:test

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} waitress-serve waitress-serve-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
