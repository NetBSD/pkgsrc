# $NetBSD: Makefile,v 1.5 2022/04/29 23:14:02 wiz Exp $

DISTNAME=	robobrowser-0.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=r/robobrowser/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://robobrowser.readthedocs.io/
COMMENT=	Your friendly neighborhood web scraper
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.3.2:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-requests>=2.6.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-werkzeug>=1.0.0:../../www/py-werkzeug

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
