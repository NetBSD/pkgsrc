# $NetBSD: Makefile,v 1.16 2001/09/27 23:18:48 jlam Exp $

DISTNAME=	AfterStep-1.8.9
PKGNAME=	afterstep-1.8.9
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.afterstep.org/stable/ \
		ftp://ftp.digex.net/pub/X11/window-managers/afterstep/AfterStep/stable/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		fredb@netbsd.org
HOMEPAGE=		http://www.afterstep.org/
COMMENT=		NeXT-like window manager for X11

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf
# XXX
# XXX The following would be "RUN_DEPENDS," if we had such a thing.
# XXX
DEPENDS+=		asclock-[0-9]*:../../time/asclock
DEPENDS+=		xp-[0-9]*:../../x11/xp

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PERL5=		YES

CONFIGURE_ARGS+=	--disable-staticlibs
CONFIGURE_ARGS+=	--with-helpcommand="xpman"
CFLAGS+=		-I${BUILDLINK_DIR}/include/X11		# xpm.h

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

.include "../../audio/rplay/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
