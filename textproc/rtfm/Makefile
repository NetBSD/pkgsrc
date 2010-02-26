# $NetBSD: Makefile,v 1.9 2010/02/26 10:28:35 wiz Exp $

DISTNAME=	rtfm-1.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/	\
		ftp://ftp.pl.freebsd.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	NetBSD documentation and GNU Texinfo files search mechanism

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-patch:
	${SED} "s,@LOCALBASE@,${LOCALBASE},g" ${WRKSRC}/rtfm.c		\
		> ${WRKSRC}/rtfm.c.done
	${MV} ${WRKSRC}/rtfm.c.done ${WRKSRC}/rtfm.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtfm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rtfm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
