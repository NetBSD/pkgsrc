# $NetBSD: Makefile,v 1.19 2000/08/30 00:01:03 wiz Exp $
# FreeBSD Id: Makefile,v 1.13 1997/03/07 12:29:49 obrien Exp
#

DISTNAME=		rxvt-2.7.3
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.rxvt.org/pub/rxvt/ \
			ftp://mason.primenet.com.au/pub/rxvt/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gcw@rxvt.org
HOMEPAGE=		http://www.rxvt.org/

USE_X11BASE=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--enable-utmp \
			--enable-wtmp \
			--enable-lastlog \
			--enable-xpm-background \
			--enable-transparency \
			--enable-menubar \
			--enable-xterm-scroll \
			--enable-xim \
			--enable-languages \
			--enable-greek \
			--enable-ttygid \
			--enable-xgetdefault \
			--enable-frills \
			--enable-keepscrolling \
			--enable-mousewheel \
			--with-xpm-includes=${XPMDIR}/include/X11 \
			--with-xpm-library=${XPMDIR}/lib

.include "../../mk/bsd.pkg.mk"
