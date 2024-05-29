# $NetBSD: Makefile,v 1.60 2024/05/29 16:34:53 adam Exp $

DISTNAME=	xsp-4.7.1
PKGNAME=	mono-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	https://download.mono-project.com/sources/xsp/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://www.mono-project.com/ASP.NET
COMMENT=	Standalone web server written in C\#
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	src/Mono.WebServer.XSP/xsp.pc.in
PKGCONFIG_OVERRIDE+=	src/Mono.WebServer.XSP/xsp-4.pc.in
PKGCONFIG_OVERRIDE+=	src/Mono.WebServer.XSP/xsp-2.pc.in

SUBST_CLASSES+=			unwrap_mk
SUBST_STAGE.unwrap_mk=		pre-install
SUBST_MESSAGE.unwrap_mk=	Unwrapping Tests.XSP.Security/Makefile
SUBST_FILES.unwrap_mk=		unittests/Tests.XSP.Security/Makefile
SUBST_SED.unwrap_mk=		-e 's,^MAKEINFO = .*,MAKEINFO = makeinfo,'
SUBST_SED.unwrap_mk+=		-e 's,^PKG_CONFIG = .*,PKG_CONFIG = ${PREFIX}/bin/pkg-config,'

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/xsp/test/2.0/treeview/TreeLineImages/*.gif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
