# $NetBSD: Makefile,v 1.13 2006/06/06 15:12:39 joerg Exp $
#

DISTNAME=		regexx-0.98.1
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=regexx/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bazar.conectiva.com.br/~niemeyer/projects/regexx/
COMMENT=		C++ regular expression library

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
