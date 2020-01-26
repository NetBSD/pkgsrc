# $NetBSD: Makefile,v 1.19 2020/01/26 17:32:21 rillig Exp $
#

DISTNAME=	mknmz-wwwoffle-0.7.2
PKGREVISION=	3
CATEGORIES=	japanese www
MASTER_SITES=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.naney.org/comp/distrib/mknmz-wwwoffle/index.html
COMMENT=	Full text indexing and searching system for wwwoffle's cache directory
LICENSE=	gnu-gpl-v2

DEPENDS+=	namazu>=2.0.5:../../textproc/namazu
DEPENDS+=	wwwoffle>=2.6:../../www/wwwoffle

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	yes
CONFIG_ARGS+=	--prefix=${PREFIX}/share/namazu

.include "../../mk/bsd.pkg.mk"
