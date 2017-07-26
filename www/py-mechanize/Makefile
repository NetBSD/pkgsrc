# $NetBSD: Makefile,v 1.19 2017/07/26 10:58:52 adam Exp $

DISTNAME=	mechanize-0.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mechanize/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-mechanize/mechanize
COMMENT=	Stateful programmatic web browsing in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-html5lib>=0.999999999:../../textproc/py-html5lib

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.3.5

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
