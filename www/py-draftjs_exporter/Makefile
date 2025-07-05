# $NetBSD: Makefile,v 1.10 2025/07/05 11:44:11 wiz Exp $

DISTNAME=	draftjs_exporter-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/draftjs-exporter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/springload/draftjs_exporter
COMMENT=	Library to convert Draft.js raw ContentState to HTML
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# html5lib
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.4.1:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999:../../textproc/py-html5lib
# lxml
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.2.0:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
