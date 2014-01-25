# $NetBSD: Makefile,v 1.11 2014/01/25 09:24:26 wiz Exp $

DISTNAME=	pytyle-0.7.5
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pytyle/
COMMENT=	Manual tiling manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Xlib-[0-9]*:../../x11/py-Xlib

PYTHON_SELF_CONFLICT=	yes

USE_LANGUAGES=	#none

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.7.5

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
