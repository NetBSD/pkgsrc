# $NetBSD: Makefile,v 1.5 2005/03/24 21:13:02 wiz Exp $

DISTNAME=	rtfm-1.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/	\
		ftp://ftp.pl.freebsd.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	NetBSD documentation and GNU Texinfo files search mechanism

post-patch:
	${SED} "s,@LOCALBASE@,${LOCALBASE},g" ${WRKSRC}/rtfm.c		\
		> ${WRKSRC}/rtfm.c.done
	${MV} ${WRKSRC}/rtfm.c.done ${WRKSRC}/rtfm.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtfm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rtfm.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
