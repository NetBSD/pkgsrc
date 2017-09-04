# $NetBSD: Makefile,v 1.16 2017/09/04 18:01:03 wiz Exp $

DISTNAME=	Paste-2.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Paste/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://pythonpaste.org/
COMMENT=	Middleware for Python WSGI applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six

USE_LANGUAGES=	# none

post-extract:
	cd ${WRKSRC}/paste && \
	${RM} httpserver.py.orig urlmap.py.orig util/template.py.orig

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
