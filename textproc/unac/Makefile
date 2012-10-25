# $NetBSD: Makefile,v 1.2 2012/10/25 06:57:04 asau Exp $
#

DISTNAME=	unac-1.7.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.senga.org/download/unac/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.senga.org/download/unac/
COMMENT=	C library that removes accents from characters
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	unac.pc.in

.include "../../mk/bsd.pkg.mk"
