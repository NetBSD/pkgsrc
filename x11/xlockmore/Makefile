# $NetBSD: Makefile,v 1.64 2004/01/06 07:17:13 jlam Exp $

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

.include "../../audio/esound/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

.endif	# XLOCK_LIGHT
