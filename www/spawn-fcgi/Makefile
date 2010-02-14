# $NetBSD: Makefile,v 1.3 2010/02/14 19:03:51 joerg Exp $

DISTNAME=	spawn-fcgi-1.6.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.lighttpd.net/download/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://redmine.lighttpd.net/projects/spawn-fcgi
COMMENT=	FastCGI deployment tool

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=       lighttpd<1.4.23

GNU_CONFIGURE=		yes

RCD_SCRIPTS=		spawnfcgi

.include "../../mk/bsd.pkg.mk"
