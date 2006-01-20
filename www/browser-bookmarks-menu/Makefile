# $NetBSD: Makefile,v 1.5 2006/01/20 16:15:54 jmmv Exp $
#

DISTNAME=	browser-bookmarks-menu-0.3
PKGREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=browserbookapp/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://browserbookapp.sourceforge.net/
COMMENT=	Easy access to web bookmarks through a GNOME Panel Applet

USE_LANGUAGES=		# empty

PYTHON_PATCH_SCRIPTS=	browser-bookmarks-menu.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	"Fixing paths to installed files."
SUBST_FILES.paths=	BrowserBookmarksMenu.server
SUBST_FILES.paths+=	browser-bookmarks-menu.py
SUBST_SED.paths=	-e 's|/usr|${PREFIX}|g'

INSTALLATION_DIRS=	libexec

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/BrowserBookmarksMenu.server \
		${PREFIX}/lib/bonobo/servers/
	${INSTALL_SCRIPT} ${WRKSRC}/browser-bookmarks-menu.py \
		${PREFIX}/libexec

.include "../../lang/python/application.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
