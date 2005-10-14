# $NetBSD: Makefile,v 1.1.1.1 2005/10/14 00:32:53 minskim Exp $
#

DISTNAME=		rxvt-unicode-5.7
CATEGORIES=		x11
MASTER_SITES=		http://dist.schmorp.de/rxvt-unicode/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		lems@gmx.net
HOMEPAGE=		http://software.schmorp.de/#rxvt-unicode
COMMENT=		rxvt clone supporting Xft fonts and Unicode

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-combining		\
			--enable-xft			\
			--enable-font-styles		\
			--enable-utmp			\
			--enable-wtmp			\
			--enable-lastlog		\
			--enable-xpm-background		\
			--enable-transparency		\
			--enable-tinting		\
			--enable-fading			\
			--enable-menubar		\
			--enable-rxvt-scroll		\
			--enable-next-scroll		\
			--enable-xterm-scroll		\
			--enable-plain-scroll		\
			--enable-xim			\
			--enable-ttygid			\
			--enable-xgetdefault		\
			--disable-strings		\
			--enable-swapscreen		\
			--enable-iso14755		\
			--enable-frills			\
			--enable-24bit			\
			--disable-keepscrolling		\
			--enable-selectionscrolling	\
			--enable-mouswheel		\
			--enable-slipwheeling		\
			--enable-text-blink		\
			--enable-pointer-blank		\
			--with-codesets=all		\
			--with-term=rxvt

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
