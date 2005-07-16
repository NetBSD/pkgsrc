# $NetBSD: Makefile,v 1.4 2005/07/16 01:19:25 jlam Exp $
#

DISTNAME=	mknmz-wwwoffle-0.7.0
CATEGORIES=	japanese www
MASTER_SITES=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/archive/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/index.html
COMMENT=	Full text indexing and searching system for wwwoffle's cache directory

DEPENDS+=	namazu>=2.0.5:../../textproc/namazu2
DEPENDS+=	wwwoffle>=2.6:../../www/wwwoffle

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	# defined
CONFIG_ARGS+=	--prefix=${PREFIX}/share/namazu

.include "../../mk/bsd.pkg.mk"
