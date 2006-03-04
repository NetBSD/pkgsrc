# $NetBSD: Makefile,v 1.15 2006/03/04 21:30:58 jlam Exp $

DISTNAME=		fcgi-2.4.0
PKGREVISION=		1
CATEGORIES=		www devel
MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
