# $NetBSD: Makefile,v 1.26 2017/02/12 06:26:15 ryoon Exp $
#

DISTNAME=	sakura-${SAKURA_VER}
SAKURA_VER=	3.1.3
PKGREVISION=	5
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

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.20.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.0
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.vte029+=	vte029>=0.28
.include "../../x11/vte029/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
