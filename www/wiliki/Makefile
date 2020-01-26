# $NetBSD: Makefile,v 1.8 2020/01/26 17:32:25 rillig Exp $
#

DISTNAME=	WiLiKi-0.6.2
PKGNAME=	wiliki-0.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wiliki/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	https://practical-scheme.net/wiliki/wiliki.cgi
COMMENT=	WikiWiki clone written in Scheme

# XXX Use >=0.9 to work-around `gauche-config --sitelibdir` change!
DEPENDS+=	Gauche>=0.9:../../lang/gauche

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
