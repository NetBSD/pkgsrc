# $NetBSD: Makefile,v 1.10 2004/02/26 09:02:43 xtraeme Exp $
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
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES
USE_PERL5=	run
USE_PKGINSTALL=	YES
USE_GCC_SHLIB=	YES

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
.undef f

.include "../../lang/perl5/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
