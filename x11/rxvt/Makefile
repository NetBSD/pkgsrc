# $NetBSD: Makefile,v 1.11 1999/08/25 00:59:52 hubertf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/03/07 12:29:49 obrien Exp
#

DISTNAME=		rxvt-2.6.1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.rxvt.org/pub/rxvt/ \
			${MASTER_SITE_SUNSITE:=utils/file/managers/mc/rxvt/} \
			ftp://ftp.nuclecu.unam.mx/linux/local/rxvt/  \
			ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin.X11/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gcw@rxvt.org
HOMEPAGE=		http://www.rxvt.org/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-utmp \
			--enable-wtmp \
			--enable-xpm-background \
			--enable-transparency \
			--enable-menubar \
			--enable-xterm-scroll \
			--enable-xim \
			--enable-kanji \
			--enable-big5 \
			--enable-gb \
			--enable-greek \
			--enable-xgetdefault \
			--disable-memset \
			--with-xpm-includes=${X11BASE}/include/X11 \
			--with-xpm-library=${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
