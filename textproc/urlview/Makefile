# $NetBSD: Makefile,v 1.3 2001/06/11 06:34:52 jlam Exp $

DISTNAME=	urlview-0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/contrib/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/contrib/ \
		ftp://ftp.uib.no/pub/mutt/contrib/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/contrib/

MAINTAINER=	tron@netbsd.org
COMMENT=	extract URLs from text files and display them in a menu

DEPENDS+=	ncurses>=5.0:../../devel/ncurses

#USE_CURSES=	yes
#REPLACE_NCURSES=	${WRKSRC}/configure ${WRKSRC}/enter.h ${WRKSRC}/urlview.c

GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
