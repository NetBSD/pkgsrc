# $NetBSD: Makefile,v 1.32.2.1 2012/10/03 12:09:43 spz Exp $
#

DISTNAME=	browser-bookmarks-menu-0.6
PKGREVISION=	19
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=browserbookapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://browserbookapp.sourceforge.net/
COMMENT=	Easy access to web bookmarks through a GNOME Panel Applet

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
PYTHON_PATCH_SCRIPTS=	browser-bookmarks-menu.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing paths to installed files.
SUBST_FILES.paths=	BrowserBookmarksMenu.server
SUBST_SED.paths= -e 's|/usr/lib/browser-bookmarks-menu|${PREFIX}/libexec|g'
SUBST_SED.paths+= -e 's|/usr/share|${PREFIX}/share|g'

INSTALLATION_DIRS=	lib/bonobo/servers libexec

do-install:
	${INSTALL_DATA} ${WRKSRC}/BrowserBookmarksMenu.server \
	    ${DESTDIR}${PREFIX}/lib/bonobo/servers/
	${INSTALL_SCRIPT} ${WRKSRC}/browser-bookmarks-menu.py \
	    ${DESTDIR}${PREFIX}/libexec
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/libexec

.include "../../lang/python/application.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
