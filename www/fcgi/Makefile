# $NetBSD: Makefile,v 1.6 2003/06/02 01:16:06 jschauma Exp $

DISTNAME=		fcgi-2.2.2
PKGREVISION=		1
CATEGORIES=		www devel
MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
