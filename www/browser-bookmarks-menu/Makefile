# $NetBSD: Makefile,v 1.1.1.1 2004/11/19 17:33:03 jmmv Exp $
#

DISTNAME=	browser-bookmarks-menu-0.3
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=browserbookapp/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://browserbookapp.sourceforge.net/
COMMENT=	Easy access to web bookmarks through a GNOME Panel Applet

NO_BUILD=		YES
USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty

PYTHON_PATCH_SCRIPTS=	browser-bookmarks-menu.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	"Fixing paths to installed files."
SUBST_FILES.paths=	BrowserBookmarksMenu.server
SUBST_FILES.paths+=	browser-bookmarks-menu.py
SUBST_SED.paths=	-e 's|/usr|${PREFIX}|g'

INSTALLATION_DIRS=	libexec

do-install:
	${INSTALL_DATA} ${WRKSRC}/BrowserBookmarksMenu.server \
		${PREFIX}/lib/bonobo/servers/
	${INSTALL_SCRIPT} ${WRKSRC}/browser-bookmarks-menu.py \
		${PREFIX}/libexec

.include "../../lang/python/application.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
