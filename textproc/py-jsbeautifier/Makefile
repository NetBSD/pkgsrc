# $NetBSD: Makefile,v 1.4 2017/12/10 17:25:37 adam Exp $

DISTNAME=	jsbeautifier-1.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsbeautifier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jsbeautifier.org/
COMMENT=	JavaScript unobfuscator and beautifier
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-editorconfig-core>=0.12.0:../../devel/py-editorconfig-core
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} js-beautify js-beautify-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
