# $NetBSD: Makefile,v 1.4 2001/02/17 17:06:15 wiz Exp $
#

DISTNAME=	aterm-0.4.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aterm/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://aterm.sourceforge.net/
COMMENT=	aterm (Afterstep XVT) - a VT102 emulator for the X window system

USE_XPM=	YES
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
		--with-xpm-includes=${X11BASE}/include \
		--with-xpm-library=${X11BASE}/lib \
		--with-jpeg \
		--with-jpeg-includes=${LOCALBASE}/include \
		--with-jpeg-library=${LOCALBASE}/lib \
		--with-png \
		--with-png-library=${LOCALBASE}/lib \
		--with-png-includes=${LOCALBASE}/include \
		--enable-utmp \
		--enable-wtmp

.include "../../mk/bsd.pkg.mk"
