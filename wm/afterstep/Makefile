# $NetBSD: Makefile,v 1.10 2001/05/22 09:32:25 wiz Exp $

DISTNAME=	AfterStep-1.8.8
PKGNAME=	afterstep-1.8.8
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.afterstep.org/stable/ \
		ftp://ftp.digex.net/pub/X11/window-managers/afterstep/AfterStep/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		fb@enteract.com
HOMEPAGE=		http://www.afterstep.org/
COMMENT=		NeXT-like window manager for X11

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.11:../../graphics/png
DEPENDS+=		rplay>=3.3.2:../../audio/rplay
# XXX
# XXX The following would be "RUN_DEPENDS," if we had such a thing.
# XXX
DEPENDS+=		asclock-[0-9]*:../../time/asclock
DEPENDS+=		xp-*:../../x11/xp

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PERL5=		YES
USE_X11=		YES
USE_XPM=		YES

CONFIGURE_ARGS+=	--disable-staticlibs
CONFIGURE_ARGS+=	--with-helpcommand="xpman"
CONFIGURE_ARGS+=	--with-jpeg-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-png-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-png-lib=${LOCALBASE}/lib
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

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

.include "../../mk/bsd.pkg.mk"
