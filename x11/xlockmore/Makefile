# $NetBSD: Makefile,v 1.69 2006/01/09 21:18:31 hubertf Exp $

.include "Makefile.common"

COMMENT=	Like the XLock session-locker/screensaver, but with more

CONFIGURE_ARGS+=	--with-mesagl

PLIST_SUBST+=    LITE=""

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
