# $NetBSD: Makefile,v 1.13 2025/04/14 19:31:54 adam Exp $

DISTNAME=	pastescript-3.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pastes/PasteS/}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PasteScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pasteorg/pastescript
COMMENT=	Pluggable command-line frontend for setting up package file layouts
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-paste>=3.0:../../www/py-paste

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} paster paster-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
