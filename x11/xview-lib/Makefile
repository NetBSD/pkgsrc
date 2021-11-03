# $NetBSD: Makefile,v 1.42 2021/11/03 10:37:12 mef Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-lib-3.2.1
PKGREVISION=		9
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		OpenLook Toolkit libs, includes, and man pages

MAKE_JOBS_SAFE=		no

DEPENDS+=		xview-config>=3.2.1nb6:../../x11/xview-config

LICENSE=		sun-openlook-license
NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
# builds, but binaries in../xview-clients all crash
NOT_FOR_PLATFORM=	*-*-alpha
NOT_FOR_PLATFORM+=	Linux-*-*

USE_IMAKE=		yes

SUBST_CLASSES+=		relro
SUBST_MESSAGE.relro=	Add RELRO support
SUBST_FILES.relro=	lib/libxview/Makefile
SUBST_FILES.relro+=	lib/libolgx/Makefile
SUBST_STAGE.relro=	post-configure
#      SHLIBLDFLAGS = -shared -Wl,-rpath,$(USRLIBDIRPATH) -Wl,-rpath,$(REALPROJECTROOT)/lib -L $(REALPROJECTROOT)/lib $(SHLIBGLOBALSFLAGS)
SUBST_SED.relro=	'-e /SHLIBLDFLAGS = /s/-Wl,/-Wl,-z,relro -Wl,-z,now -Wl,/'

post-install:
	cd ${DESTDIR}${PREFIX}/lib && ${LN} -fs libolgx.so.3.2 libolgx.so.3 && \
		${LN} -fs libxview.so.3.2 libxview.so.3

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
