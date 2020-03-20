# $NetBSD: Makefile,v 1.74 2020/03/20 11:58:33 nia Exp $

DISTNAME=	browser-bookmarks-menu-0.6
PKGREVISION=	46
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=browserbookapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://browserbookapp.sourceforge.net/
COMMENT=	Easy access to web bookmarks through a GNOME Panel Applet

NO_BUILD=	yes
REPLACE_PYTHON=	browser-bookmarks-menu.py
PYTHON_VERSIONS_ACCEPTED=	27 # py-ORBit via py-gnome2

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing paths to installed files.
SUBST_FILES.paths=	BrowserBookmarksMenu.server
SUBST_SED.paths=	-e 's|/usr/lib/browser-bookmarks-menu|${PREFIX}/libexec|g'
SUBST_SED.paths+=	-e 's|/usr/share|${PREFIX}/share|g'

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
