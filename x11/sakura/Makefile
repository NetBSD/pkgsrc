# $NetBSD: Makefile,v 1.9.2.1 2012/10/03 12:10:05 spz Exp $
#

DISTNAME=	sakura-${SAKURA_VER}
SAKURA_VER=	3.0.4
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://launchpadlibrarian.net/103638542/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.pleyades.net/david/projects/sakura
COMMENT=	Sakura is a terminal emulator based on GTK and VTE that supports tab
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config pod2man xgettext
USE_CMAKE=	yes

SUBST_CLASSES+=			fix-man-path
SUBST_STAGE.fix-man-path=	post-patch
SUBST_MESSAGE.fix-man-path=	Fix path for man1.
SUBST_FILES.fix-man-path=	CMakeLists.txt
SUBST_SED.fix-man-path=		-e 's,share/man/man1,${PKGMANDIR}/man1,g'

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.20.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.0
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.vte029+=	vte029>=0.28
.include "../../x11/vte029/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
