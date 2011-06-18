# $NetBSD: Makefile,v 1.1.1.1 2011/06/18 10:44:24 wiz Exp $
#

DISTNAME=	pytyle-0.7.5
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pytyle.com/wiki/Main_Page
COMMENT=	Manual tiling manager
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Xlib-[0-9]*:../../x11/py-Xlib

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=	yes
PY_PATCHLIST=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
