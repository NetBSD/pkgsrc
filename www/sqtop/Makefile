# $NetBSD: Makefile,v 1.7 2015/08/18 07:31:19 wiz Exp $

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

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-resolver=netdb_getnameinfo
.endif

.include "../../mk/resolv.buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
