# $NetBSD: Makefile,v 1.12 2018/02/26 08:24:42 adam Exp $

DISTNAME=	html5lib-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/html5lib/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/html5lib/html5lib-python
COMMENT=	HTML5 parser and tokenizer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-webencodings-[0-9]*:../../textproc/py-webencodings

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
