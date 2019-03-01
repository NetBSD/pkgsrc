# $NetBSD: Makefile,v 1.1 2019/03/01 04:26:05 gutteridge Exp $

VERSION=	0.6
DISTNAME=	python-markdown-math-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-markdown-math/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/mitya57/python-markdown-math
COMMENT=	Python extension adding math formula support to py-markdown
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
