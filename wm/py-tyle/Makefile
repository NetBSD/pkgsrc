# $NetBSD: Makefile,v 1.18 2019/04/26 13:14:19 maya Exp $

DISTNAME=	pytyle-0.7.5
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/pytyle/
COMMENT=	Manual tiling manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Xlib-[0-9]*:../../x11/py-Xlib

PYTHON_SELF_CONFLICT=	yes

USE_LANGUAGES=	#none

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 0.7.5

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
