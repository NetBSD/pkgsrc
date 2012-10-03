# $NetBSD: Makefile,v 1.8 2012/10/03 23:40:39 cheusov Exp $
#

DISTNAME=	pytyle-0.7.5
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pytyle.com/wiki/Main_Page
COMMENT=	Manual tiling manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Xlib-[0-9]*:../../x11/py-Xlib

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_SELF_CONFLICT=	yes

USE_LANGUAGES=	#none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
