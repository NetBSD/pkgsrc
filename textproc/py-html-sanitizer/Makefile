# $NetBSD: Makefile,v 1.4 2018/12/09 20:52:52 adam Exp $

DISTNAME=	html-sanitizer-1.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/html-sanitizer/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/matthiask/html-sanitizer/
COMMENT=	White-list based HTML sanitizer
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.6.1:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
