# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.7.1ac
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $NetBSD: Makefile,v 1.5 1998/01/30 13:58:05 agc Exp $
# FreeBSD Id: Makefile,v 1.71 1997/11/24 19:35:30 ache Exp
#

DISTNAME=       lynx2.7.1ac-0.102
PKGNAME=        lynx-2.7.1ac-0.102
WRKSRC=         ${WRKDIR}/lynx2-7-1
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

LIB_DEPENDS=	ncurses.3.4:${PORTSDIR}/devel/ncurses

CONFIGURE_ARGS= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
GNU_CONFIGURE=  YES
MAKEFILE=       makefile
MAN1=		lynx.1

.include <bsd.port.mk>
