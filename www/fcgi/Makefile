# $NetBSD: Makefile,v 1.1.1.1 2002/06/24 19:32:08 tron Exp $

DISTNAME=		fcgi-2.2.2
CATEGORIES=		www devel
MASTER_SITES=		http://fastcgi.com/dist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://fastcgi.com/
COMMENT=		FastCGI application development kit

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
