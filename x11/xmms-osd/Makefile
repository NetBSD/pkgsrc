# $NetBSD: Makefile,v 1.25 2012/10/29 05:07:16 asau Exp $
#

.include "../../x11/xosd/Makefile.common"

PKGNAME=		${DISTNAME:S/xosd/xmms-osd/}
PKGREVISION=		8

COMMENT=		XMMS plugin that shows current status on your desktop
CONFLICTS=		xosd<=2.2.0

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=YES
CONFIGURE_ARGS+=	--enable-new-plugin

BUILD_DIRS=		src/xmms_plugin
INSTALL_DIRS=		src/xmms_plugin

.include "../../audio/xmms/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
