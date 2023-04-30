# $NetBSD: Makefile,v 1.7 2023/04/30 18:53:39 wiz Exp $

DISTNAME=	PasteScript-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PasteScript/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://pythonpaste.org/script/
COMMENT=	Pluggable command-line frontend for setting up package file layouts
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
DEPENDS+=	${PYPKGPREFIX}-paste-[0-9]*:../../www/py-paste

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
