# $NetBSD: Makefile,v 1.21 2002/08/31 16:07:28 wiz Exp $

DISTNAME=	AfterStep-1.8.11
PKGNAME=	afterstep-1.8.11
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.afterstep.org/stable/ \
		ftp://ftp.digex.net/pub/X11/window-managers/afterstep/AfterStep/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		fredb@netbsd.org
HOMEPAGE=		http://www.afterstep.org/
COMMENT=		NeXT-like window manager for X11

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf
DEPENDS+=		asclock-[0-9]*:../../time/asclock
DEPENDS+=		xp-[0-9]*:../../x11/xp

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

CONFIGURE_ARGS+=	--disable-staticlibs
CONFIGURE_ARGS+=	--disable-xinerama
CONFIGURE_ARGS+=	--with-helpcommand=xpman
CONFIGURE_ARGS+=	--with-xpm-includes='${BUILDLINK_DIR}/include/X11'
CONFIGURE_ENV+=		PERL='${LOCALBASE}/bin/perl'
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

.include "../../audio/rplay/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
