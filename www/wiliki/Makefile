# $NetBSD: Makefile,v 1.6 2012/10/28 06:31:09 asau Exp $
#

DISTNAME=	WiLiKi-0.6.2
PKGNAME=	wiliki-0.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wiliki/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://wiliki.sourceforge.net/
COMMENT=	WikiWiki clone written in Scheme

# XXX Use >=0.9 to work-around `gauche-config --sitelibdir` change!
DEPENDS+=	Gauche>=0.9:../../lang/gauche

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
