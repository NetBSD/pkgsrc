# $NetBSD: Makefile,v 1.21 1998/09/30 19:49:43 tron Exp $
# FreeBSD Id: Makefile,v 1.23 1997/10/10 09:24:38 tg Exp
#

DISTNAME=       xlockmore-4.12
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tux.org/~bagleyd/xlockmore.html

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	Mesa-3.0:../../graphics/Mesa

CONFLICTS=	xlockmore-4.07 xlockmore-4.08 xlockmore-4.09 xlockmore-4.10 \
		xlockmore-4.11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-mesagl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
