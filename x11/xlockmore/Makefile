# $NetBSD: Makefile,v 1.14 1998/05/19 00:45:03 hubertf Exp $
# FreeBSD Id: Makefile,v 1.23 1997/10/10 09:24:38 tg Exp
#

DISTNAME=       xlockmore-4.10
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/

MAINTAINER=	hubertf@netbsd.org

DEPENDS+=	xpm-3.4j:../../graphics/xpm
DEPENDS+=	Mesa-2.6:../../graphics/Mesa

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-mesagl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas
USE_X11=	yes
MAN1=		xlock.1

.include "../../mk/bsd.pkg.mk"
