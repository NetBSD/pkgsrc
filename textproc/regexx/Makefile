# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:21 tv Exp $
#

DISTNAME=		regexx-0.98.1
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=regexx/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://bazar.conectiva.com.br/~niemeyer/projects/regexx/
COMMENT=		C++ regular expression library

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
