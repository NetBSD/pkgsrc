# $NetBSD: Makefile,v 1.18 1998/08/20 15:17:39 tsarna Exp $
# FreeBSD Id: Makefile,v 1.23 1997/10/10 09:24:38 tg Exp
#

DISTNAME=       xlockmore-4.11
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tux.org/~bagleyd/xlockmore.html

DEPENDS+=	xpm-3.4k:../../graphics/xpm
# XXX Mesa support disabled for security reasons
#DEPENDS+=	Mesa-2.6:../../graphics/Mesa

CONFLICTS=	xlockmore-4.07 xlockmore-4.08 xlockmore-4.09 xlockmore-4.10

GNU_CONFIGURE=	yes
# XXX Mesa support disabled for security reasons
CONFIGURE_ARGS+= --without-mesagl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
