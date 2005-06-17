# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:37 jlam Exp $

DISTNAME=	rtfm-1.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/	\
		ftp://ftp.pl.freebsd.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	NetBSD documentation and GNU Texinfo files search mechanism

INSTALLATION_DIRS=	bin man/man1

post-patch:
	${SED} "s,@LOCALBASE@,${LOCALBASE},g" ${WRKSRC}/rtfm.c		\
		> ${WRKSRC}/rtfm.c.done
	${MV} ${WRKSRC}/rtfm.c.done ${WRKSRC}/rtfm.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtfm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rtfm.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
