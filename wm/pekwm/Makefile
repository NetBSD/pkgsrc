# $NetBSD: Makefile,v 1.21 2006/04/17 13:46:50 wiz Exp $
#

DISTNAME=	pekwm-0.1.4
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://pekwm.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.pekwm.org/
COMMENT=	Window manager based on aewm++

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl:run
USE_LANGUAGES+=	c++

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

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
