# $NetBSD: Makefile,v 1.16 2005/12/05 20:51:09 rillig Exp $
#

DISTNAME=	pekwm-0.1.3
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://pekwm.pekdon.net/files/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://pekwm.org/
COMMENT=	Window manager based on aewm++

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl:run
USE_PKGINSTALL=	YES
USE_LANGUAGES+=	c++

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

CONFIGURE_ARGS+=	--enable-harbour
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

REPLACE_PERL=		data/scripts/pekwm_themeset.pl \
			data/scripts/pekwm_ws_menu.pl

PKG_SYSCONFSUBDIR=	pekwm

EGDIR=			${PREFIX}/share/examples/pekwm
CONF_FILES=
.for f in autoproperties config keys menu mouse start
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
