# $NetBSD: Makefile,v 1.9 2003/11/10 17:25:13 gavan Exp $

DISTNAME=		fcgi-2.4.0
CATEGORIES=		www devel
MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

USE_BUILDLINK2=		YES
USE_GCC_SHLIB=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
