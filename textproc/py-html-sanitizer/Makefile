# $NetBSD: Makefile,v 1.7 2022/11/09 13:14:17 joerg Exp $

DISTNAME=	html-sanitizer-1.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/html-sanitizer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/matthiask/html-sanitizer
COMMENT=	White-list based HTML sanitizer
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.6.1:../../textproc/py-lxml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
