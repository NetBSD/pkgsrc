# $NetBSD: Makefile,v 1.11 2019/05/02 08:35:09 adam Exp $

DISTNAME=	jsbeautifier-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsbeautifier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://beautifier.io/
COMMENT=	JavaScript unobfuscator and beautifier
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-editorconfig-core>=0.12.0:../../devel/py-editorconfig-core
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} js-beautify js-beautify-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
