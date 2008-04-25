# $NetBSD: Makefile,v 1.7 2008/04/25 08:26:45 kefren Exp $

DISTNAME=	xsp-1.9.1
PKGNAME=	mono-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://go-mono.com/sources/xsp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/ASP.NET
COMMENT=	Standalone web server written in C\#

.include "../../lang/mono/Makefile.common"

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
MAKE_JOBS_SAFE=	no

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
