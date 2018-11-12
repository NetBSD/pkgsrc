# $NetBSD: Makefile,v 1.31 2018/11/12 03:53:13 ryoon Exp $
#

DISTNAME=	sakura-3.6.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/sakura/trunk/3.6.0/+download/
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
.include "../../x11/vte3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
