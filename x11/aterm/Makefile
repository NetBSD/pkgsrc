# $NetBSD: Makefile,v 1.6 2001/12/11 16:02:08 wiz Exp $
#

DISTNAME=	aterm-0.4.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aterm/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://aterm.sourceforge.net/
COMMENT=	aterm (Afterstep XVT) - a VT102 emulator for the X window system

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-background-image \
		--enable-transparency \
		--enable-fading \
		--enable-graphics \
		--enable-xterm-scroll \
		--enable-kanji \
		--enable-big5 \
		--enable-greek \
		--with-xpm \
		--with-xpm-includes=${BUILDLINK_DIR}/include \
		--with-xpm-library=${BUILDLINK_DIR}/lib \
		--with-jpeg \
		--with-jpeg-includes=${BUILDLINK_DIR}/include \
		--with-jpeg-library=${BUILDLINK_DIR}/lib \
		--with-png \
		--with-png-library=${BUILDLINK_DIR}/lib \
		--with-png-includes=${BUILDLINK_DIR}/include \
		--enable-utmp \
		--enable-wtmp

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
