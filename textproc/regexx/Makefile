# $NetBSD: Makefile,v 1.5 2004/01/24 15:13:20 grant Exp $
#

DISTNAME=		regexx-0.98.1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=regexx/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bazar.conectiva.com.br/~niemeyer/projects/regexx/
COMMENT=		C++ regular expression library

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
