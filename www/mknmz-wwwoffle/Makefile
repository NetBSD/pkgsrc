# $NetBSD: Makefile,v 1.6 2006/02/05 23:11:25 joerg Exp $
#

DISTNAME=	mknmz-wwwoffle-0.7.0
PKGREVISION=	1
CATEGORIES=	japanese www
MASTER_SITES=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/archive/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/index.html
COMMENT=	Full text indexing and searching system for wwwoffle's cache directory

DEPENDS+=	namazu>=2.0.5:../../textproc/namazu2
DEPENDS+=	wwwoffle>=2.6:../../www/wwwoffle

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	yes
CONFIG_ARGS+=	--prefix=${PREFIX}/share/namazu

.include "../../mk/bsd.pkg.mk"
