# $NetBSD: Makefile,v 1.7 2007/10/20 10:43:11 adrianp Exp $
#

DISTNAME=	mknmz-wwwoffle-0.7.0
PKGREVISION=	2
CATEGORIES=	japanese www
MASTER_SITES=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/archive/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/index.html
COMMENT=	Full text indexing and searching system for wwwoffle's cache directory

DEPENDS+=	namazu>=2.0.5:../../textproc/namazu
DEPENDS+=	wwwoffle>=2.6:../../www/wwwoffle

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	yes
CONFIG_ARGS+=	--prefix=${PREFIX}/share/namazu

.include "../../mk/bsd.pkg.mk"
