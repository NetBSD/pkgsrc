# $NetBSD: Makefile,v 1.9 2002/08/25 21:52:30 jlam Exp $
#

DISTNAME=	aterm-0.4.2
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aterm/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://aterm.sourceforge.net/
COMMENT=	aterm (Afterstep XVT) - a VT102 emulator for the X window system

USE_BUILDLINK2=	YES
USE_X11=	YES
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

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
