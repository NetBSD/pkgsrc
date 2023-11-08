# $NetBSD: Makefile,v 1.19 2023/11/08 13:21:08 wiz Exp $

DISTNAME=	html5-parser-0.4.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/html5-parser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kovidgoyal/html5-parser
COMMENT=	Fast, standards-compliant, C-based HTML5 parser
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.8.0:../../textproc/py-lxml

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-beautifulsoup4

.include "../../lang/python/egg.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
