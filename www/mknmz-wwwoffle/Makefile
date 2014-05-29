# $NetBSD: Makefile,v 1.13 2014/05/29 23:37:58 wiz Exp $
#

DISTNAME=	mknmz-wwwoffle-0.7.0
PKGREVISION=	5
CATEGORIES=	japanese www
MASTER_SITES=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/index.html
COMMENT=	Full text indexing and searching system for wwwoffle's cache directory

DEPENDS+=	namazu>=2.0.5:../../textproc/namazu
DEPENDS+=	wwwoffle>=2.6:../../www/wwwoffle

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	yes
CONFIG_ARGS+=	--prefix=${PREFIX}/share/namazu

.include "../../mk/bsd.pkg.mk"
