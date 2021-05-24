# $NetBSD: Makefile,v 1.21 2021/05/24 19:55:16 wiz Exp $
#

DISTNAME=	mknmz-wwwoffle-0.7.2
PKGREVISION=	5
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
