# $NetBSD: Makefile,v 1.20.2.1 2012/10/03 12:09:45 spz Exp $
#

DISTNAME=	netsurf-1.2-src
PKGNAME=	${DISTNAME:S/-src$//}
PKGREVISION=	16
CATEGORIES=	www
MASTER_SITES=	http://www.netsurf-browser.org/downloads/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netsurf-browser.org/
COMMENT=	Web browser for RISC OS and UNIX-like platforms

BUILD_DEPENDS+=	lemon>=1.0:../../devel/lemon
BUILD_DEPENDS+=	re2c>=0.12.*:../../devel/re2c

PKG_DESTDIR_SUPPORT=	user-destdir

# current codebase needs strndup
NOT_FOR_PLATFORM=	NetBSD-[0-3]*-*

WRKSRC=		${WRKDIR}/netsurf

USE_TOOLS+=	gmake perl:build pax pkg-config

INSTALLATION_DIRS+=	share/netsurf bin

# needed for netsurf-1.2 and gtk2-2.20 -- remove on next update!
BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

post-extract:
	find ${WRKSRC}/!NetSurf -type f | xargs chmod a-x

do-install:
	cd ${WRKSRC} && pax -rw !NetSurf ${DESTDIR}${PREFIX}/share/netsurf/
	cd ${WRKSRC} && pax -rw gtk/res ${DESTDIR}${PREFIX}/share/netsurf/
	${INSTALL_PROGRAM} ${WRKSRC}/nsgtk ${DESTDIR}${PREFIX}/share/netsurf/nsgtk
	${INSTALL_SCRIPT} ${WRKSRC}/netsurf ${DESTDIR}${PREFIX}/bin/netsurf

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
