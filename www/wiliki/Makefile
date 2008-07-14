# $NetBSD: Makefile,v 1.4 2008/07/14 12:56:14 joerg Exp $
#

DISTNAME=	WiLiKi-0.5.3
PKGNAME=	wiliki-0.5.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wiliki/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://wiliki.sourceforge.net/
COMMENT=	WikiWiki clone written in Scheme

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	Gauche>=0.8.3nb1:../../lang/gauche

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
