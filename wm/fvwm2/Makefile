# $NetBSD: Makefile,v 1.11 2001/12/17 07:30:07 martti Exp $
# FreeBSD Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp
#

DISTNAME=	fvwm-${FVWM_VER}
PKGNAME=	fvwm2-${FVWM_VER}
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.fvwm.org/pub/fvwm/version-2/ \
		http://www.fvwm.org/generated/icon_download/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/
DISTFILES+=	fvwm-${FVWM_VER}.tar.gz fvwm_icons.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Newer version of X11 Virtual window manager

DEPENDS+=	xpmroot-2.*:../../x11/xpmroot

CONFLICTS=	fvwm-2.*
EXTRACT_ONLY=	${DISTNAME}.tar.gz
FVWM_VER=	2.4.4

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES

PLIST_SUBST+=		FVWM_VER=${FVWM_VER}

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--enable-extras --without-gnome
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/lib/X11/fvwm2
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/lib/X11
CONFIGURE_ARGS+=	--with-xpm-includes=${XPMDIR}/include
CONFIGURE_ARGS+=	--with-iconpath=${PREFIX}/lib/X11/fvwm2/pixmaps:${X11BASE}/include/X11/bitmaps:${X11BASE}/include/X11/pixmaps

post-extract:
	${MKDIR} ${WRKDIR}/icons
	${GTAR} -xzf ${DISTDIR}/fvwm_icons.tgz -C ${WRKDIR}/icons

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} \
		${WRKDIR}/icons/*.xpm \
		${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fvwm2
	${INSTALL_DATA} \
		${WRKSRC}/sample.fvwmrc/decor_examples \
		${WRKSRC}/sample.fvwmrc/system.fvwm2rc-sample-* \
		${PREFIX}/lib/X11/fvwm2
	${INSTALL_DATA} \
		${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
		${PREFIX}/lib/X11/fvwm2/system.fvwm2rc.example
	if [ ! -f ${PREFIX}/lib/X11/fvwm2/system.fvwm2rc ]; then \
		${INSTALL_DATA} \
			${PREFIX}/lib/X11/fvwm2/system.fvwm2rc.example \
			${PREFIX}/lib/X11/fvwm2/system.fvwm2rc ; \
	fi

.if defined(FVWM2_USE_GTK) && ${FVWM2_USE_GTK} == "YES"
.include "../../x11/gtk/buildlink.mk"
PLIST_SUBST+=	    GTK=""
.else
PLIST_SUBST+=	    GTK="@comment "
CONFIGURE_ARGS+=    --without-gtk-prefix
.endif

.if defined(FVWM2_USE_RPLAY) && ${FVWM2_USE_RPLAY} == "YES"
.include "../../audio/rplay/buildlink.mk"
.endif

.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
