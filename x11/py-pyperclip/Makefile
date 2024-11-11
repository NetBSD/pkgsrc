# $NetBSD: Makefile,v 1.9 2024/11/11 07:29:30 wiz Exp $

DISTNAME=	pyperclip-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyperclip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/asweigart/pyperclip
COMMENT=	Python module for cross-platform clipboard functions
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
DEPENDS+=	xclip-[0-9]*:../../x11/xclip
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
