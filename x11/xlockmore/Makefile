# New ports collection makefile for:	xlockmore
# Version required:     4.08
# Date created:		2 March 1998
# Whom:			hubertf
#
# $NetBSD: Makefile,v 1.11 1998/03/24 07:54:53 hubertf Exp $
# FreeBSD Id: Makefile,v 1.23 1997/10/10 09:24:38 tg Exp
#

DISTNAME=       xlockmore-4.09
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/

MAINTAINER=	hubertf@netbsd.org

LIB_DEPENDS=	Xpm.4.:${PORTSDIR}/graphics/xpm \
		MesaGL.2.:${PORTSDIR}/graphics/Mesa

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-mesagl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas
USE_X11=	yes
MAN1=		xlock.1

.include <bsd.port.mk>
