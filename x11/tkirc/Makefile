# $NetBSD: Makefile,v 1.1.1.1 1997/11/09 23:46:03 hubertf Exp $

DISTNAME=	tkirc-1.147
DISTFILES=	tkirc1.147.tar.gz
WRKSRC=		${WRKDIR}/tkirc
MASTER_SITES=	ftp://ftp.informatik.uni-oldenburg.de/pub/tkirc/

MAINTAINER=	hubertf@netbsd.org
CATEGORIES=	net x11
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
