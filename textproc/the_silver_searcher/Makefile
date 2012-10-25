# $NetBSD: Makefile,v 1.2 2012/10/25 06:57:04 asau Exp $
#

DISTNAME=	the_silver_searcher-0.5
CATEGORIES=	textproc
MASTER_SITES=	http://cloud.github.com/downloads/ggreer/the_silver_searcher/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggreer/the_silver_searcher
COMMENT=	Attempt to improve on ack, which itself is better than grep
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	aclocal autoheader autoconf automake pkg-config

pre-configure:
	cd ${WRKSRC} && sh build.sh

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
