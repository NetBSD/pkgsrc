# $NetBSD: Makefile,v 1.3 2017/05/12 11:34:07 jperkin Exp $
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

LIBS.SunOS+=	-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
