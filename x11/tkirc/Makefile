# New ports collection makefile for:    tkirc
# Version required:     1.147
# Date created:         1997/11/09
# Whom:                 Hubert Feyrer <hubertf@netbsd.org>
#
# $NetBSD: Makefile,v 1.2 1998/01/25 00:24:35 hubertf Exp $

DISTNAME=	tkirc-1.147
WRKSRC=		${WRKDIR}/tkirc
CATEGORIES=	net x11
MASTER_SITES=	ftp://ftp.informatik.uni-oldenburg.de/pub/tkirc/
DISTFILES=	tkirc1.147.tar.gz

MAINTAINER=	hubertf@netbsd.org

RUN_DEPENDS=	irc:${PORTSDIR}/net/ircII \
		wish8.0:${PORTSDIR}/x11/tk80

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tkirc	  ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/tkircrc-example ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/README	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/CHANGES	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/COPYING	  ${PREFIX}/share/doc/tkirc

.include <bsd.port.mk>
