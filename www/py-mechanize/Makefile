# $NetBSD: Makefile,v 1.31 2022/04/25 11:28:24 adam Exp $

DISTNAME=	mechanize-0.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mechanize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-mechanize/mechanize
COMMENT=	Stateful programmatic web browsing in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999999999:../../textproc/py-html5lib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
