# $NetBSD: Makefile,v 1.6 2003/09/26 11:23:43 jmmv Exp $
#

.include "../xosd/Makefile.common"

PKGNAME=		${DISTNAME:S/xosd/xmms-osd/}

COMMENT=		XMMS plugin that shows current status on your desktop
CONFLICTS=		xosd<=2.2.0

CONFIGURE_ENV+=		XOSD_XMMS_PLUGIN=YES
CONFIGURE_ARGS+=	--enable-new-plugin

BUILD_DIRS=		${WRKSRC}/src/xmms_plugin
INSTALL_DIRS=		${WRKSRC}/src/xmms_plugin

.include "../../audio/xmms/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/xosd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
