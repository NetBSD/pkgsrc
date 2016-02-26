# $NetBSD: Makefile,v 1.8 2016/02/26 10:57:46 jperkin Exp $

DISTNAME=	sqtop-2013-12-17
PKGNAME=	${DISTNAME:C/([0-9])-/\1/g}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://sqtop.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sqtop/
COMMENT=	Display active client connections for Squid
LICENSE=	gnu-gpl-v2

DEPENDS+=	squid-[0-9]*:../../www/squid3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS.NetBSD+=	--with-resolver=netdb_getnameinfo

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/resolv.buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
