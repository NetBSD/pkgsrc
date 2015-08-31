# $NetBSD: Makefile,v 1.7 2015/08/31 09:31:34 kleink Exp $

DISTNAME=	webassets-0.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/w/webassets/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://elsdoerfer.name/docs/webassets/
COMMENT=	Asset management for Python web development
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

REPLACE_PYTHON+=src/webassets/filter/rjsmin/rjsmin.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
