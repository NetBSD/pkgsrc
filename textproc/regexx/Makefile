# $NetBSD: Makefile,v 1.4 2003/09/19 23:08:29 dent Exp $
#

DISTNAME=		regexx-0.98.1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=regexx/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bazar.conectiva.com.br/~niemeyer/projects/regexx/
COMMENT=		C++ regular expression library

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
