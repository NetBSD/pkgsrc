# $NetBSD: Makefile,v 1.8 2004/04/25 04:16:44 xtraeme Exp $
#

.include "../xosd/Makefile.common"

PKGNAME=		${DISTNAME:S/xosd/xmms-osd/}
PKGREVISION=		1

COMMENT=		XMMS plugin that shows current status on your desktop
CONFLICTS=		xosd<=2.2.0

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=YES
CONFIGURE_ARGS+=	--enable-new-plugin

BUILD_DIRS=		${WRKSRC}/src/xmms_plugin
INSTALL_DIRS=		${WRKSRC}/src/xmms_plugin

.include "../../audio/xmms/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
