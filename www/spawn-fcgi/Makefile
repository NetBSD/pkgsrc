# $NetBSD: Makefile,v 1.9 2019/10/06 13:10:39 nia Exp $

DISTNAME=	spawn-fcgi-1.6.4
CATEGORIES=	www
MASTER_SITES=	https://download.lighttpd.net/spawn-fcgi/releases-1.6.x/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://redmine.lighttpd.net/projects/spawn-fcgi
COMMENT=	FastCGI deployment tool
LICENSE=	modified-bsd

CONFLICTS=	lighttpd<1.4.23

GNU_CONFIGURE=		yes

RCD_SCRIPTS=		spawnfcgi

.include "../../mk/bsd.pkg.mk"
