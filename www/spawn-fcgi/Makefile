# $NetBSD: Makefile,v 1.10 2020/08/19 18:28:40 wiz Exp $

DISTNAME=	spawn-fcgi-1.6.4
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://download.lighttpd.net/spawn-fcgi/releases-1.6.x/

MAINTAINER=	joerg@NetBSD.org
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
