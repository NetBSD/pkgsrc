# $NetBSD: Makefile,v 1.17 2014/05/09 07:37:23 wiz Exp $

PKGVER=			0.8.4
DISTNAME=		ccsm-${PKGVER}
PKGREVISION=		3
CATEGORIES=		wm gnome
MASTER_SITES=		http://releases.compiz.org/${PKGVER}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://compiz.org/
COMMENT=		CompizConfig Settings Manager
LICENSE=		gnu-gpl-v2

DEPENDS+=		compizconfig-backend-gconf>=0.6.0:../../devel/compizconfig-backend-gconf
DEPENDS+=		${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

USE_TOOLS+=		pkg-config gmake msgfmt intltool

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
REPLACE_PYTHON=		${WRKSRC}/setup.py ${WRKSRC}/ccm/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2

MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}

.include "../../devel/py-compizconfig/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
