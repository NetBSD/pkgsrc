# $NetBSD: Makefile,v 1.4 2001/06/20 04:26:43 jlam Exp $

DISTNAME=	urlview-0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/contrib/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/contrib/ \
		ftp://ftp.uib.no/pub/mutt/contrib/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/contrib/

MAINTAINER=	tron@netbsd.org
COMMENT=	extract URLs from text files and display them in a menu

GNU_CONFIGURE=		yes
USE_NCURSES=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
