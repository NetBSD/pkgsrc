# $NetBSD: Makefile,v 1.14 2006/07/22 04:46:18 rillig Exp $
#

DISTNAME=		regexx-0.98.1
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=regexx/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bazar.conectiva.com.br/~niemeyer/projects/regexx/
COMMENT=		C++ regular expression library

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
