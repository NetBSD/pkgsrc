# $NetBSD: Makefile,v 1.3 2020/09/30 05:34:28 adam Exp $

DISTNAME=	draftjs_exporter-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/draftjs-exporter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/springload/draftjs_exporter
COMMENT=	Library to convert Draft.js raw ContentState to HTML
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.4.1:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.2.0:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE+=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
