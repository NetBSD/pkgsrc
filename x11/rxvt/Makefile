# $NetBSD: Makefile,v 1.14 2000/07/11 09:31:33 agc Exp $
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
			--with-xpm-includes=`${PKG_INFO} -qp xpm | ${AWK} '{print $$2}'`/include/X11 \
			--with-xpm-library=`${PKG_INFO} -qp xpm | ${AWK} '{print $$2}'`/lib

.include "../../mk/bsd.pkg.mk"
