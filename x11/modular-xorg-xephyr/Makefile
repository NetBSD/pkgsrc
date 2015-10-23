# $NetBSD: Makefile,v 1.7 2015/10/23 10:58:28 tnn Exp $

DISTNAME=	xorg-server-${XORG_VERSION}
PKGNAME=	modular-xorg-xephyr-${XORG_VERSION}
PKGREVISION=	2

DISTINFO_FILE=		${.CURDIR}/../../x11/modular-xorg-server/distinfo
PATCHDIR=		${.CURDIR}/../../x11/modular-xorg-server/patches

MAINTAINER=	khorben@defora.org
COMMENT=	Xephyr server based on kdrive from modular X.org

NOT_FOR_PLATFORM+=	Darwin-*-*

.include "../../x11/modular-xorg-server/Makefile.common"

CONFIGURE_ARGS+=	--disable-xorg
CONFIGURE_ARGS+=	--disable-xnest
CONFIGURE_ARGS+=	--enable-xephyr
CONFIGURE_ARGS+=	--enable-kdrive
CONFIGURE_ARGS+=	--disable-xvfb

post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/xorg/protocol.txt
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/Xserver.1
	if [ -f ${DESTDIR}${PREFIX}/share/doc/xorg-server/Xserver-DTrace.xml ]; then \
		${RM} ${DESTDIR}${PREFIX}/share/doc/xorg-server/Xserver-DTrace.xml; \
	fi

.include "../../x11/modular-xorg-server/options.mk"

.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
