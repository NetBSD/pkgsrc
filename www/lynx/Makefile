# New ports collection makefile for:    lynx
# http://sol.slcc.edu/lynx/current/
# Version required:     2.8rel2
# Date created:         15 Dec 1994
# Whom:                 ache
#
# $NetBSD: Makefile,v 1.6 1998/03/10 23:03:02 tron Exp $
# FreeBSD Id: Makefile,v 1.71 1997/11/24 19:35:30 ache Exp
#

DISTNAME=       lynx2.8rel.2
PKGNAME=        lynx-2.8rel.2
WRKSRC=         ${WRKDIR}/lynx2-8
CATEGORIES=	www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	ache@FreeBSD.ORG

LIB_DEPENDS=	ncurses.3.4:${PORTSDIR}/devel/ncurses

CONFIGURE_ARGS+= --with-screen=ncurses --with-zlib --libdir="${PREFIX}/etc"
GNU_CONFIGURE=  YES
INSTALL_TARGET= install install-help
MAKEFILE=       makefile

MAN1=		lynx.1

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/etc/lynx_help

.include <bsd.port.mk>
