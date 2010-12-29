# $NetBSD: Makefile,v 1.5 2010/12/29 12:24:46 uebayasi Exp $
#

DISTNAME=	WiLiKi-0.6.2
PKGNAME=	wiliki-0.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wiliki/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://wiliki.sourceforge.net/
COMMENT=	WikiWiki clone written in Scheme

PKG_DESTDIR_SUPPORT=	user-destdir

# XXX Use >=0.9 to work-around `gauche-config --sitelibdir` change!
DEPENDS+=	Gauche>=0.9:../../lang/gauche

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
