# $NetBSD: Makefile,v 1.3 2004/02/02 14:15:27 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		XFree86-libs-${XF_VER}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XFREE}
DISTFILES=		X430src-1.tgz X430src-2.tgz \
			X430src-3.tgz X430src-4.tgz

MAINTAINER=		xfree86@blef.org
HOMEPAGE=		http://www.xfree86.org/
COMMENT=		XFree86 Libraries

CONFLICTS+=		xextensions-[0-9]*
CONFLICTS+=		libX11-[0-9]*
CONFLICTS+=		libXau-[0-9]*

USE_IMAKE=		yes
DEPENDS=		imake>=4.3.0:../../x11/imake

.include "../../mk/bsd.prefs.mk"

FILES_SUBST+=		PKGBASE=${PKGBASE}
FILES_SUBST+=		X11ROOT=${X11ROOT}

.if ${OPSYS} == "NetBSD"
PLIST_SUBST+=		MANPAGE_SUFFIX=${IMAKE_MANNEWSUFFIX}
.else
PLIST_SUBST+=		MANPAGE_SUFFIX=${IMAKE_LIBMAN_SUFFIX}
.endif

# XXX later should add CONFLICTS with XFree86-libs to these packages too
.if ${X11PREFIX} == ${LOCALBASE}
CONFLICTS+=		render-[0-9]*
CONFLICTS+=		Xrender-[0-9]*
CONFLICTS+=		MesaLibs-[0-9]*
.endif

USE_BUILDLINK2=		YES

XBUILD_DIRS=		lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINCLUDE_DIRS=		programs/proxymngr
XINSTALL_DIRS=		include lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

post-patch:
	@${SED} -e 's,@MAKESTRS@,${X11PREFIX}/X11R6/bin/makestrs,g' \
		${WRKSRC}/config/cf/Library.tmpl \
		> ${WRKSRC}/config/cf/Library.tmpl.tmp && \
		${MV} ${WRKSRC}/config/cf/Library.tmpl.tmp \
		${WRKSRC}/config/cf/Library.tmpl

.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../meta-pkgs/XFree86/Makefile.common"

.include "../../mk/bsd.pkg.mk"
