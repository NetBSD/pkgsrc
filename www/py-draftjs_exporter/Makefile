# $NetBSD: Makefile,v 1.2 2020/08/27 12:24:17 joerg Exp $

DISTNAME=	draftjs_exporter-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=springload/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/springload/draftjs_exporter
COMMENT=	Library to convert Draft.js raw ContentState to HTML
LICENSE=	mit

GITHUB_PROJECT=	draftjs_exporter
GITHUB_TAG=	v${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-lxml>=4.2.0<5:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.4<4.9.2:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999<1.0.2:../../textproc/py-html5lib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
