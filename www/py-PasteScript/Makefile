# $NetBSD: Makefile,v 1.12 2025/03/08 13:00:47 wiz Exp $

DISTNAME=	pastescript-3.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pastes/PasteS/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PasteScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pasteorg/pastescript
COMMENT=	Pluggable command-line frontend for setting up package file layouts
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-paste>=3.0:../../www/py-paste

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} paster paster-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
