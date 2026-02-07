# $NetBSD: Makefile,v 1.63 2026/02/07 08:21:55 wiz Exp $

DISTNAME=	sakura-3.8.9
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/sakura/trunk/${PKGVERSION_NOREV}/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.pleyades.net/david/projects/sakura
COMMENT=	Terminal emulator based on GTK and VTE that supports tab
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config pod2man xgettext

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.20.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
