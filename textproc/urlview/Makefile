# $NetBSD: Makefile,v 1.1.1.1 2000/07/04 16:07:21 tron Exp $

DISTNAME=	urlview-0.9
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/contrib/ \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/contrib/ \
		ftp://ftp.uib.no/pub/mutt/contrib/ \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/mail/mutt/contrib/

MAINTAINER=	tron@netbsd.org

DEPENDS+=	ncurses>=5.0:../../devel/ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
