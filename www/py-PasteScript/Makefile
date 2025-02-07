# $NetBSD: Makefile,v 1.11 2025/02/07 15:22:50 adam Exp $

DISTNAME=	pastescript-3.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pastes/PasteS/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PasteScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pasteorg/pastescript
COMMENT=	Pluggable command-line frontend for setting up package file layouts
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/pastes/PasteS/}

DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-paste>=3.0:../../www/py-paste
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} paster paster-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
