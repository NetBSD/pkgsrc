# $NetBSD: Makefile,v 1.79.2.1 2009/10/21 12:44:36 tron Exp $

.include "Makefile.common"

PKGREVISION=	3
COMMENT=	Like the XLock session-locker/screensaver, but with more

CONFIGURE_ARGS+=	--with-mesagl

PLIST_SUBST+=    LITE=""

USE_TOOLS+=	pkg-config

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
