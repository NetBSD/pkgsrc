# $NetBSD: Makefile,v 1.63 2003/11/30 22:58:40 jschauma Exp $

.include "../../mk/bsd.prefs.mk"

# XLOCK_LIGHT will be deprecated, but support it for a while longer
# until users figure out to install xlockmore-lite instead of xlockmore
#
.if defined(XLOCK_LIGHT)
pre-extract:
	@${ECHO} ""
	@${ECHO} "***************************************************"
	@${ECHO} "*** You want to install xlockmore-lite instead. ***"
	@${ECHO} "***************************************************"
	@${ECHO} ""

.  include "../xlockmore-lite/Makefile"
.else

.include "Makefile.common"

PKGREVISION=	1
COMMENT=	Like the XLock session-locker/screensaver, but with more

CONFIGURE_ARGS+=	--with-mesagl

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

.endif	# XLOCK_LIGHT
