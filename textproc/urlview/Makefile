# $NetBSD: Makefile,v 1.9 2003/09/27 17:07:38 grant Exp $

DISTNAME=	urlview-0.9
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/contrib/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/contrib/ \
		ftp://ftp.uib.no/pub/mutt/contrib/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/contrib/

MAINTAINER=	tron@NetBSD.org
COMMENT=	Extract URLs from text files and display them in a menu

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
