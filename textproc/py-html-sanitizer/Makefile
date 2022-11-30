# $NetBSD: Makefile,v 1.8 2022/11/30 16:43:32 adam Exp $

DISTNAME=	html_sanitizer-1.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/html-sanitizer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matthiask/html-sanitizer
COMMENT=	White-list based HTML sanitizer
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.6.5:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
