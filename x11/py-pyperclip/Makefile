# $NetBSD: Makefile,v 1.4 2018/02/26 11:38:00 leot Exp $

DISTNAME=	pyperclip-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyperclip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asweigart/pyperclip
COMMENT=	Python module for cross-platform clipboard functions
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	xclip-[0-9]*:../../x11/xclip

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
