# $NetBSD: Makefile,v 1.12 2007/09/21 13:04:26 wiz Exp $
#

DISTNAME=	browser-bookmarks-menu-0.6
PKGREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=browserbookapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://browserbookapp.sourceforge.net/
COMMENT=	Easy access to web bookmarks through a GNOME Panel Applet

NO_BUILD=	yes
PYTHON_PATCH_SCRIPTS=	browser-bookmarks-menu.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing paths to installed files.
SUBST_FILES.paths=	BrowserBookmarksMenu.server
SUBST_SED.paths= -e 's|/usr/lib/browser-bookmarks-menu|${PREFIX}/libexec|g'
SUBST_SED.paths+= -e 's|/usr/share|${PREFIX}/share|g'

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

do-install:
	${INSTALL_DATA} ${WRKSRC}/BrowserBookmarksMenu.server \
		${PREFIX}/lib/bonobo/servers/
	${INSTALL_SCRIPT} ${WRKSRC}/browser-bookmarks-menu.py \
		${PREFIX}/libexec
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/libexec

.include "../../lang/python/application.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
