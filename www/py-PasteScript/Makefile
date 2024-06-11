# $NetBSD: Makefile,v 1.9 2024/06/11 19:48:19 adam Exp $

DISTNAME=	PasteScript-3.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PasteScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pasteorg/pastescript
COMMENT=	Pluggable command-line frontend for setting up package file layouts
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-paste>=3.0:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} paster paster-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
