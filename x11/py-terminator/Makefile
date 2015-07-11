# $NetBSD: Makefile,v 1.1 2015/07/11 11:54:02 kamil Exp $

DISTNAME=	terminator-0.97
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/terminator/trunk/0.97/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/terminator
COMMENT=	Terminator, multiple terminals in one window
LICENSE=	gnu-gpl-v2

REPLACE_PYTHON+= *.py
REPLACE_PYTHON+= terminatorlib/*.py
REPLACE_PYTHON+= terminatorlib/plugins/*.py

USE_TOOLS+=	intltool

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/py-notify-python/buildlink3.mk"
.include "../../x11/py-keybinder/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
