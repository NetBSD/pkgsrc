# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:50 wiz Exp $
#

DISTNAME=		Terminal-0.2.4
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://download.berlios.de/xfce-goodies/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		yui@yui.pe.kr
HOMEPAGE=		http://terminal.os-cillation.com/
COMMENT=		Terminal emulator primarly for the Xfce

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_DIRS+=		xdg-1.1

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libexo/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
