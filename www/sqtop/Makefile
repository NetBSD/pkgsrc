# $NetBSD: Makefile,v 1.13 2023/06/06 11:41:58 taca Exp $

DISTNAME=	sqtop-2017-04-16
PKGNAME=	${DISTNAME:C/([0-9])-/\1/g}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=paleg/}
GITHUB_TAG=	14891045be96ed3f856ac37310ad1d9fb8ac068e

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/paleg/sqtop
COMMENT=	Display active client connections for Squid
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
FAKE_NCURSES=	yes

CONFIGURE_ARGS.NetBSD+=	--with-resolver=netdb_getnameinfo

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
