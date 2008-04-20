# $NetBSD: Makefile,v 1.16.4.1 2008/04/20 04:19:35 rtr Exp $

DISTNAME=	urlview-0.9
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/contrib/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/contrib/ \
		ftp://ftp.uib.no/pub/mutt/contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extract URLs from text files and display them in a menu

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	${PKGMANDIR}/man1

GNU_CONFIGURE=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
