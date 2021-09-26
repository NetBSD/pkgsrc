# $NetBSD: Makefile,v 1.10 2021/09/26 01:21:51 mef Exp $
#

DISTNAME=	WiLiKi-0.6.2
PKGNAME=	wiliki-0.6.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wiliki/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	https://practical-scheme.net/wiliki/wiliki.cgi
COMMENT=	WikiWiki clone written in Scheme
LICENSE=	mit

# XXX Use >=0.9 to work-around `gauche-config --sitelibdir` change!
#DEPENDS+=	Gauche>=0.9:../../lang/gauche

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
.include "../../lang/gauche/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
