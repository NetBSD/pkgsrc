# $NetBSD: Makefile,v 1.16 2000/07/14 16:04:28 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/03/07 12:29:49 obrien Exp
#

DISTNAME=		rxvt-2.7.3
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.rxvt.org/pub/rxvt/ \
			ftp://mason.primenet.com.au/pub/rxvt/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gcw@rxvt.org
HOMEPAGE=		http://www.rxvt.org/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-utmp \
			--enable-wtmp \
			--enable-lastlog \
			--enable-xpm-background \
			--enable-transparency \
			--enable-menubar \
			--enable-xterm-scroll \
			--enable-xim \
			--enable-kanji \
			--enable-big5 \
			--enable-gb \
			--enable-greek \
			--enable-ttygid \
			--enable-xgetdefault \
			--enable-frills \
			--enable-keepscrolling \
			--enable-mousewheel \
			--with-xpm-includes=`${SHOW_PREFIX1} xpm ${SHOW_PREFIX2}`/include/X11 \
			--with-xpm-library=`${SHOW_PREFIX1} xpm ${SHOW_PREFIX2}`/lib

.include "../../mk/bsd.pkg.mk"
