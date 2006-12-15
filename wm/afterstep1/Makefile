# $NetBSD: Makefile,v 1.11 2006/12/15 20:33:01 joerg Exp $

DISTNAME=	AfterStep-1.8.11
PKGNAME=	${DISTNAME:S/AfterStep/afterstep/}
PKGREVISION=	6
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.afterstep.org/stable/ \
		ftp://ftp.digex.net/pub/X11/window-managers/afterstep/AfterStep/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		fredb@NetBSD.org
HOMEPAGE=		http://www.afterstep.org/
COMMENT=		NeXT-like window manager for X11

DEPENDS+=		asclock-[0-9]*:../../time/asclock
DEPENDS+=		xp-[0-9]*:../../x11/xp

GNU_CONFIGURE=		YES
USE_TOOLS+=		autoconf213 perl:run
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--disable-staticlibs
CONFIGURE_ARGS+=	--disable-xinerama
CONFIGURE_ARGS+=	--with-helpcommand=xpman
CONFIGURE_ARGS+=	--with-xpm-includes='${BUILDLINK_DIR}/include/X11'
CONFIGURE_ENV+=		ac_cv_prog_sgmltools='no'

post-patch:
	for i in `${FIND} ${WRKSRC} -name "*.man" -print` \
		${WRKSRC}/autoconf/Makefile.common.in; do \
	  ${MV} $$i $$i.orig ;\
	  ${SED} -e 's|/usr/local/|${PREFIX}/|g' -e 's|1x|1|g' < $$i.orig > $$i ; \
	done

pre-configure:
	cd ${WRKSRC} && \
	  autoconf --localdir=autoconf autoconf/configure.in > configure; \
	  ${CHMOD} 755 configure; \
	  autoheader --localdir=autoconf autoconf/configure.in > autoconf/config.h.in;

.include "../../audio/rplay/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
