# $NetBSD: Makefile,v 1.1.1.1 2003/03/15 08:53:08 rh Exp $
#

DISTNAME=		regexx-0.98.1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=regexx/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://bazar.conectiva.com.br/~Eniemeyer/projects/regexx/
COMMENT=		C++ regular expression library

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
