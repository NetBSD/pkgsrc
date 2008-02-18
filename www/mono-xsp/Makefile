# $NetBSD: Makefile,v 1.4 2008/02/18 14:01:56 kefren Exp $

DISTNAME=	xsp-${MONO_VERSION}
PKGNAME=	mono-xsp-${MONO_VERSION}
CATEGORIES=	www
MASTER_SITES=	http://go-mono.com/sources/xsp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/ASP.NET
COMMENT=	Standalone web server written in C\#

.include "../../lang/mono/Makefile.version"

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
MAKE_JOBS_SAFE=	no

DEPENDS+=	sqlite3>=3.5.2:../../databases/sqlite3

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
