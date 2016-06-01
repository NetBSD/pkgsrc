# $NetBSD: Makefile,v 1.3 2016/06/01 12:34:42 wiz Exp $

DISTNAME=	pyperclip-1.5.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyperclip/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asweigart/pyperclip
COMMENT=	Python module for cross-platform clipboard functions
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	xclip-[0-9]*:../../x11/xclip

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
