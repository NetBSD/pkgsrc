# $NetBSD: Makefile,v 1.2 2026/01/27 08:40:51 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-25.2.0
PKGREVISION=	1
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	gtkada
GITHUB_TAG=	25.2

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gtkada/
COMMENT=	Ada graphical toolkit based on gtk
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config perl

USE_LANGUAGES=	c ada

GNU_CONFIGURE=	yes

CHECK_PIE_SKIP+=	${GNAT_PKGBASE}/bin/gtkada-dialog

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Replace version in ${SUBST_FILES.version}
SUBST_STAGE.version=	post-extract
SUBST_FILES.version=	configure
SUBST_SED.version=	-e "s,18.0w,${GITHUB_TAG},g"

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		preproc
SUBST_MESSAGE.preproc=	Replace imported symbols with preprocessed ones in ${SUBST_FILES.preproc}
SUBST_STAGE.preproc=	post-extract
SUBST_FILES.preproc=	src/gtkada-intl.gpb
SUBST_SED.preproc+=	-e "s,\"setlocale\",\"__netbsd_setlocale\","
#SUBST_SED.preproc+=	-e "s,\"-lintl\",\"\","

.endif

GNU_CONFIGURE_PREFIX=	${GNAT_PREFIX}

CONFIGURE_ARGS+=	--enable-build=Production

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
CONFIGURE_ARGS+=		--enable-shared
CONFIGURE_ARGS+=		--enable-static-pic
.else
CONFIGURE_ARGS+=		--disable-shared
CONFIGURE_ARGS+=		--disable-static-pic
.endif
CONFIGURE_ARGS+=		--enable-static

post-install:
	${CHMOD} -x ${DESTDIR}${GNAT_PREFIX}/share/examples/gtkada/testgtk/global_exception_handler.ad?

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.${SHLIB_EXT}.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../x11/gtk3/buildlink3.mk"

.include "../../lang/python/tool.mk"

.include "../../mk/bsd.pkg.mk"
