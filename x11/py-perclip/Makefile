# $NetBSD: Makefile,v 1.1 2016/06/14 08:37:24 kamil Exp $

DISTNAME=	pyperclip-1.5.27
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	x11 python
# There are no tags on GitHub
MASTER_SITES=	https://pypi.python.org/packages/source/p/pyperclip/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asweigart/pyperclip
COMMENT=	Cross-platform clipboard module for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
