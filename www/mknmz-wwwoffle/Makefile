# $NetBSD: Makefile,v 1.2 2003/07/17 22:55:42 grant Exp $
#

DISTNAME=	mknmz-wwwoffle-0.7.0
CATEGORIES=	japanese www
MASTER_SITES=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/archive/

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.naney.org/comp/distrib/mknmz-wwwoffle/index.html
COMMENT=	full text indexing and searching system for wwwoffle's cache directory

DEPENDS+=	namazu>=2.0.5:../../textproc/namazu2
DEPENDS+=	wwwoffle>=2.6:../../www/wwwoffle

USE_PERL5=	# defined
GNU_CONFIGURE=	# defined
CONFIG_ARGS+=	--prefix=${PREFIX}/share/namazu

.include "../../mk/bsd.pkg.mk"
