# $NetBSD: Makefile,v 1.24 2017/07/22 11:35:25 adam Exp $

DISTNAME=	Nevow-0.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=N/Nevow/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	https://github.com/twisted/nevow
COMMENT=	Next-generation web application templating system
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-twisted>=13.0:../../net/py-twisted

USE_LANGUAGES=		# none

REPLACE_PYTHON=		nevow/test/segfault.py

PYTHON_VERSIONS_ACCEPTED=	27

INSTALLATION_DIRS+=	share/doc

post-install:
	cd ${DESTDIR}${PREFIX} && mv doc share/doc/py-nevow

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
