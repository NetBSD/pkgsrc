# $NetBSD: Makefile,v 1.27 2007/06/11 21:07:50 xtraeme Exp $
#

DISTNAME=	pekwm-0.1.6
CATEGORIES=	wm
MASTER_SITES=	http://www.pekwm.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.pekwm.org/trac
COMMENT=	Window manager based on aewm++

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:run
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q:S/\/pekwm//}

REPLACE_PERL=		data/scripts/pekwm_themeset.pl \
			data/scripts/pekwm_ws_menu.pl

PKG_SYSCONFSUBDIR=	pekwm

EGDIR=			${PREFIX}/share/examples/pekwm
CONF_FILES=
.for f in autoproperties config keys menu mouse start vars
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
