# $NetBSD: Makefile,v 1.21 2014/05/05 00:48:33 ryoon Exp $
#

DISTNAME=	sakura-${SAKURA_VER}
SAKURA_VER=	3.1.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://launchpadlibrarian.net/159682501/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.pleyades.net/david/projects/sakura
COMMENT=	Sakura is a terminal emulator based on GTK and VTE that supports tab
LICENSE=	gnu-gpl-v2

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
