# $NetBSD: Makefile,v 1.1.1.1 2004/01/24 08:45:41 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		XFree86-clients-${XF_VER}
CATEGORIES=		xfree86 x11
MASTER_SITES=		${MASTER_SITE_XFREE}
DISTFILES=		X430src-1.tgz X430src-2.tgz \
			X430src-3.tgz X430src-4.tgz

MAINTAINER=		xfree86@blef.org
HOMEPAGE=		http://www.xfree86.org/
COMMENT=		XFree86 client programs and related files

USE_BUILDLINK2=		yes
DISTINFO_FILE=		${.CURDIR}/../../x11/XFree86-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/XFree86-libs/patches

XBUILD_DIRS=		lib/xtrans lib/lbxutil programs fonts/util
XINSTALL_DIRS=		programs fonts/util
XINSTALL_MAN_DIRS=	programs

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.include "../../security/PAM/buildlink2.mk"
.endif

post-configure:
	@${MKDIR} ${WRKSRC}/exports/lib
	@for l in fntstubs Xss FS fontenc Xau Xxf86vm Xxf86dga xkbfile \
			Xxf86misc Xdmcp Xfontcache Xinerama Xfont; do \
		${LN} -sf ${PREFIX}/lib/lib$${l}.a ${WRKSRC}/exports/lib/ ; \
	done

.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../x11/XFree86-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
