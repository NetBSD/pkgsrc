# $NetBSD: Makefile,v 1.50 2020/04/12 08:28:09 adam Exp $

DISTNAME=	xsp-3.8
PKGNAME=	mono-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	www
MASTER_SITES=	https://download.mono-project.com/sources/xsp/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://www.mono-project.com/ASP.NET
COMMENT=	Standalone web server written in C\#

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	src/Mono.WebServer/xsp.pc.in
PKGCONFIG_OVERRIDE+=	src/Mono.WebServer/xsp-2.pc.in

SUBST_CLASSES+=			unwrap_mk
SUBST_STAGE.unwrap_mk=		pre-install
SUBST_MESSAGE.unwrap_mk=	Unwrapping Tests.XSP.Security/Makefile
SUBST_FILES.unwrap_mk=		unittests/Tests.XSP.Security/Makefile
SUBST_SED.unwrap_mk=		-e 's,^MAKEINFO = .*,MAKEINFO = makeinfo,'
SUBST_SED.unwrap_mk+=		-e 's,^PKG_CONFIG = .*,PKG_CONFIG = ${PREFIX}/bin/pkg-config,'

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	pre-configure
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
