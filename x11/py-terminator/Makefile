# $NetBSD: Makefile,v 1.4 2015/12/05 21:26:09 adam Exp $

DISTNAME=	terminator-0.98
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/terminator/trunk/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/terminator
COMMENT=	Terminator, multiple terminals in one window
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.98

REPLACE_PYTHON+= *.py
REPLACE_PYTHON+= terminatorlib/*.py
REPLACE_PYTHON+= terminatorlib/plugins/*.py

USE_TOOLS+=	intltool bash

REPLACE_SH+=	terminator.wrapper
REPLACE_BASH+=	terminatorlib/pylint.sh
REPLACE_BASH+=	run_tests

post-install:
	${RUN}${FIND} \
		${DESTDIR}${PREFIX}/${PKGMANDIR} \
		${DESTDIR}${PREFIX}/share/doc \
		${DESTDIR}${PREFIX}/share/icons \
		${DESTDIR}${PREFIX}/share/pixmaps \
			-type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

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
