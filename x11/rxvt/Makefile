# $NetBSD: Makefile,v 1.24 2001/07/15 09:49:54 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1997/03/07 12:29:49 obrien Exp
#

DISTNAME=		rxvt-2.7.3
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.rxvt.org/pub/rxvt/ \
			ftp://ftp.rxvt.org/pub/rxvt/devel/ \
			ftp://mason.primenet.com.au/pub/rxvt/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		gcw@rxvt.org
HOMEPAGE=		http://www.rxvt.org/
COMMENT=		Low memory usage xterm replacement that supports color

USE_BUILDLINK_ONKY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--enable-utmp \
			--enable-wtmp \
			--enable-lastlog \
			--enable-xpm-background \
			--enable-transparency \
			--enable-menubar \
			--enable-xterm-scroll \
			--enable-xim \
			--enable-ttygid \
			--enable-xgetdefault \
			--enable-frills \
			--enable-keepscrolling \
			--enable-mousewheel

CPPFLAGS+=		-I${BUILDLINK_DIR}/include/X11

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
