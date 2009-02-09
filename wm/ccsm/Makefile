# $NetBSD: Makefile,v 1.6 2009/02/09 21:55:23 joerg Exp $
#

DISTNAME=		ccsm-0.6.0
PKGREVISION=		1
CATEGORIES=		wm gnome
MASTER_SITES=		http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.compiz-fusion.org/
COMMENT=		CompizConfig Settings Manager

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config gmake msgfmt
USE_DIRS+=		xdg-1.1

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_PATCH_SCRIPTS=	setup.py
PYTHON_PATCH_SCRIPTS+=	ccm/*.py

MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}

PYTHON_VERSIONS_ACCEPTED=	25

DEPENDS+=	compizconfig-backend-gconf>=0.6.0:../../devel/compizconfig-backend-gconf
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

.include "../../devel/py-compizconfig/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
