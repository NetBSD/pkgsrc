# $NetBSD: Makefile,v 1.24 1999/03/09 02:09:28 hubertf Exp $
# FreeBSD Id: Makefile,v 1.23 1997/10/10 09:24:38 tg Exp
#

DISTNAME=       xlockmore-4.13
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tux.org/~bagleyd/xlockmore.html

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Mesa-3.0:../../graphics/Mesa

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
CONFIGURE_ARGS+= --with-mesagl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk
CONFIGURE_ENV+=	INSTALL='${INSTALL}' \
		INSTALL_PROGRAM='${INSTALL_PROGRAM}' \
		INSTALL_DATA='${INSTALL_DATA}'

.include "../../mk/bsd.pkg.mk"
