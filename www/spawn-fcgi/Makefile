# $NetBSD: Makefile,v 1.11 2022/11/09 13:14:18 joerg Exp $

DISTNAME=	spawn-fcgi-1.6.4
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://download.lighttpd.net/spawn-fcgi/releases-1.6.x/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://redmine.lighttpd.net/projects/spawn-fcgi
COMMENT=	FastCGI deployment tool
LICENSE=	modified-bsd

CONFLICTS=	lighttpd<1.4.23

GNU_CONFIGURE=		yes

RCD_SCRIPTS=		spawnfcgi

INSTALLATION_DIRS+=	share/doc/spawn-fcgi

post-install:
	${INSTALL_DATA} ${FILESDIR}/README-rc.txt ${DESTDIR}${PREFIX}/share/doc/spawn-fcgi

.include "../../mk/bsd.pkg.mk"
