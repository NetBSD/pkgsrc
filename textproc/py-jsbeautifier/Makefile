# $NetBSD: Makefile,v 1.26 2025/03/12 14:17:36 adam Exp $

DISTNAME=	jsbeautifier-1.15.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsbeautifier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://beautifier.io/
COMMENT=	JavaScript unobfuscator and beautifier
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-editorconfig-core>=0.12.2:../../devel/py-editorconfig-core
DEPENDS+=	${PYPKGPREFIX}-six>=1.13.0:../../lang/py-six

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} js-beautify js-beautify-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
