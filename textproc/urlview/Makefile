# $NetBSD: Makefile,v 1.25 2017/01/19 18:52:28 agc Exp $

DISTNAME=	urlview-0.9
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/contrib/
MASTER_SITES+=	ftp://ftp.uib.no/pub/mutt/contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extract URLs from text files and display them in a menu

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	cp -p ${WRKSRC}/url_handler.sh ${DESTDIR}/${PREFIX}/bin/

GNU_CONFIGURE=	yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
