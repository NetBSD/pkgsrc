# $NetBSD: Makefile,v 1.59 2003/06/30 07:28:59 jlam Exp $

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
COMMENT=	like the XLock session-locker/screensaver, but with more

CONFIGURE_ARGS+=	--with-mesagl

# xlock is installed setuid-root, so mark it as such in the binary package.
#
USE_PKGINSTALL=		YES
SPECIAL_PERMS=		${PREFIX}/bin/xlock ${SETUID_ROOT_PERMS}

.include "../../audio/esound/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

.endif	# XLOCK_LIGHT
