# $NetBSD: Makefile,v 1.10 2018/03/12 11:17:53 wiz Exp $

DISTNAME=	lxterminal-0.2.0
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://www.lxde.org/
COMMENT=	Desktop-independent VTE-based terminal emulator with tabs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool pkg-config msgfmt

LDFLAGS.SunOS+=	-lsocket

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
