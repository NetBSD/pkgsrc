# $NetBSD: Makefile,v 1.13 2000/05/08 03:25:20 hubertf Exp $
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
			--with-xpm-includes=${X11BASE}/include/X11 \
			--with-xpm-library=${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
