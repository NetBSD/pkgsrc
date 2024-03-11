# $NetBSD: Makefile,v 1.24 2024/03/11 08:59:16 wiz Exp $

DISTNAME=		libXaw-1.0.16
CATEGORIES=		x11 graphics
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Athena Widgets Library from modular Xorg X11

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xaw6.pc.in
PKGCONFIG_OVERRIDE+=	xaw7.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

.include "../../mk/bsd.prefs.mk"

# remove compatibility links that never were in pkgsrc
post-install:
.if ${OBJECT_FMT} == "Mach-O"
	${RM} -f ${DESTDIR}${PREFIX}/lib/libXaw.dylib
	${RM} -f ${DESTDIR}${PREFIX}/lib/libXaw.6.dylib
	${RM} -f ${DESTDIR}${PREFIX}/lib/libXaw.7.dylib
.else
	${RM} -f ${DESTDIR}${PREFIX}/lib/libXaw.so
	${RM} -f ${DESTDIR}${PREFIX}/lib/libXaw.so.6
	${RM} -f ${DESTDIR}${PREFIX}/lib/libXaw.so.7
.endif

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
