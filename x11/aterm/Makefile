# $NetBSD: Makefile,v 1.12 2003/07/17 22:56:21 grant Exp $
#

DISTNAME=	aterm-0.4.2
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aterm/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://aterm.sourceforge.net/
COMMENT=	aterm (Afterstep XVT) - a VT102 emulator for the X window system

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES
BUILD_DEFS+=	ATERM_USE_KANJI ATERM_USE_XTERM_SCROLL
BUILD_DEFS+=	ATERM_USE_BIG5 ATERM_USE_GREEK

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=--enable-background-image \
		--enable-transparency \
		--enable-fading \
		--enable-graphics \
		--with-xpm \
		--with-xpm-includes=${BUILDLINK_PREFIX.xpm}/include \
		--with-xpm-library=${BUILDLINK_PREFIX.xpm}/lib \
		--with-jpeg \
		--with-jpeg-includes=${BUILDLINK_PREFIX.jpeg}/include \
		--with-jpeg-library=${BUILDLINK_PREFIX.jpeg}/lib \
		--with-png \
		--with-png-library=${BUILDLINK_PREFIX.png}/lib \
		--with-png-includes=${BUILDLINK_PREFIX.png}/include \
		--enable-utmp \
		--enable-wtmp

.if defined(ATERM_USE_XTERM_SCROLL) && ${ATERM_USE_XTERM_SCROLL} != NO
CONFIGURE_ARGS+=--enable-xterm-scroll
.endif

.if defined(ATERM_USE_KANJI) && ${ATERM_USE_KANJI} != NO
CONFIGURE_ARGS+=--enable-kanji
.endif

.if defined(ATERM_USE_BIG5) && ${ATERM_USE_BIG5} != NO
CONFIGURE_ARGS+=--enable-big5
.endif

.if defined(ATERM_USE_GREEK) && ${ATERM_USE_GREEK} != NO
CONFIGURE_ARGS+=--enable-greek
.endif

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
