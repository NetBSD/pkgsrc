# New ports collection makefile for:	xlockmore
# Version required:     4.05
# Date created:		9 November 1994
# Whom:			smace
#
# $NetBSD: Makefile,v 1.6 1998/01/30 03:08:42 hubertf Exp $
# FreeBSD Id: Makefile,v 1.23 1997/10/10 09:24:38 tg Exp
#

DISTNAME=       xlockmore-4.07BETA
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	tg@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		MesaGL\\.2\\.:${PORTSDIR}/graphics/Mesa

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-mesagl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas
USE_X11=	yes
MAN1=		xlock.1

.include <bsd.port.mk>
