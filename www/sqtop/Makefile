# $NetBSD: Makefile,v 1.12 2020/05/05 14:04:44 wiz Exp $

DISTNAME=	sqtop-2013-12-17
PKGNAME=	${DISTNAME:C/([0-9])-/\1/g}
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://sqtop.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/paleg/sqtop
COMMENT=	Display active client connections for Squid
LICENSE=	gnu-gpl-v2

DEPENDS+=	squid-[0-9]*:../../www/squid4

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
FAKE_NCURSES=	yes

CONFIGURE_ARGS.NetBSD+=	--with-resolver=netdb_getnameinfo

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
