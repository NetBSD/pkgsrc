# $NetBSD: Makefile,v 1.6 2005/06/01 18:03:29 jlam Exp $
#

DISTNAME=	multi-aterm-0.0.4
CATEGORIES=	x11
MASTER_SITES=	http://www.materm.tuxfamily.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.materm.tuxfamily.org/
COMMENT=	Multi-terminal for the X Window System based on aterm

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-mousewheel
CONFIGURE_ARGS+=	--enable-swapscreen
CONFIGURE_ARGS+=	--enable-keepscrolling
CONFIGURE_ARGS+=	--enable-half-shadow
CONFIGURE_ARGS+=	--enable-shading
CONFIGURE_ARGS+=	--enable-fading
CONFIGURE_ARGS+=	--enable-transparency
CONFIGURE_ARGS+=	--with-xpm=${BUILDLINK_PREFIX.xpm}

BUILD_DEFS+=		ATERM_USE_KANJI ATERM_USE_XTERM_SCROLL
BUILD_DEFS+=		ATERM_USE_BIG5 ATERM_USE_GREEK

.include "../../mk/bsd.prefs.mk"

.if defined(ATERM_USE_XTERM_SCROLL) && ${ATERM_USE_XTERM_SCROLL} != NO
CONFIGURE_ARGS+=	--enable-xterm-scroll
.endif

.if defined(ATERM_USE_KANJI) && ${ATERM_USE_KANJI} != NO
CONFIGURE_ARGS+=	--enable-kanji
.endif

.if defined(ATERM_USE_BIG5) && ${ATERM_USE_BIG5} != NO
CONFIGURE_ARGS+=	--enable-big5
.endif

.if defined(ATERM_USE_GREEK) && ${ATERM_USE_GREEK} != NO
CONFIGURE_ARGS+=	--enable-greek
.endif

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
