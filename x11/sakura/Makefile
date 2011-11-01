# $NetBSD: Makefile,v 1.2 2011/11/01 06:03:09 sbd Exp $
#

DISTNAME=	sakura-2.4.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://launchpad.net/sakura/trunk/2.4.2/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.pleyades.net/david/projects/sakura
COMMENT=	Sakura is a terminal emulator based on GTK and VTE that supports tab

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config pod2man
USE_CMAKE=	yes

SUBST_CLASSES+=			fix-man-path
SUBST_STAGE.fix-man-path=	post-patch
SUBST_MESSAGE.fix-man-path=	Fix path for man1.
SUBST_FILES.fix-man-path=	CMakeLists.txt
SUBST_SED.fix-man-path=		-e 's,share/man/man1,${PKGMANDIR}/man1,g'

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.20.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.16.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.vte+=	vte>=0.26
.include "../../x11/vte/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
