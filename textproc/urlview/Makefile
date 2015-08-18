# $NetBSD: Makefile,v 1.23 2015/08/18 07:31:19 wiz Exp $

DISTNAME=	urlview-0.9
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/contrib/ \
		ftp://ftp.uib.no/pub/mutt/contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extract URLs from text files and display them in a menu

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	cp -p ${WRKSRC}/url_handler.sh ${DESTDIR}/${PREFIX}/bin/

GNU_CONFIGURE=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
