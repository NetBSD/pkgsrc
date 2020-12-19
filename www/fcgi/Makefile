# $NetBSD: Makefile,v 1.22 2020/12/19 10:48:13 nia Exp $

DISTNAME=		fcgi-2.4.0
PKGREVISION=		3
CATEGORIES=		www devel
#MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://fastcgi-archives.github.io/
COMMENT=		FastCGI application development kit

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

LIBS.NetBSD+=		-lm # frexp()

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
