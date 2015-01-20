# $NetBSD: Makefile,v 1.23 2015/01/20 14:24:38 jaapb Exp $

.include "../../lang/ocaml/Makefile.common"
DISTINFO_FILE= ${PKGDIR}/../../lang/ocaml/distinfo
PATCHDIR= ${PKGDIR}/../../lang/ocaml/patches

PKGNAME=		${DISTNAME:S/ocaml/ocaml-graphics/}
PKGREVISION=	2

COMMENT+=		(graphics library)

CONFIGURE_ARGS+=	-x11include ${X11BASE}/include
CONFIGURE_ARGS+=	-x11lib ${X11BASE}/lib

BUILD_DIRS=		otherlibs/graph
BUILD_TARGET=		all
INSTALL_TARGET=		install

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=		allopt
INSTALL_TARGET+=	installopt
.endif

PLIST_VARS+=		natdynlib
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.  if !empty(MACHINE_PLATFORM:MLinux-*-*) || \
      !empty(MACHINE_PLATFORM:MDarwin-*-*) || \
      !empty(MACHINE_PLATFORM:MFreeBSD-*-*) || \
      !empty(MACHINE_PLATFORM:MDragonFly-*-*) || \
      !empty(MACHINE_PLATFORM:MNetBSD-*-*)
PLIST.natdynlib=		yes
.  endif
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.stub
.endif

BUILDLINK_DEPMETHOD.ocaml=	full

SUBST_CLASSES+=		depend
SUBST_STAGE.depend=	post-patch
SUBST_FILES.depend=	otherlibs/graph/.depend
SUBST_SED.depend=	-e 's,/usr/X11R6,${X11BASE},g'
SUBST_MESSAGE.depend=	Fixing .depend in otherlibs/graph.

SUBST_CLASSES+=		mklib
SUBST_STAGE.mklib=	post-patch
SUBST_FILES.mklib=	otherlibs/Makefile.shared
SUBST_SED.mklib=	-e 's,^MKLIB=.*,MKLIB=ocamlmklib,g'
SUBST_MESSAGE.mklib=	Fixing MKLIB in otherlibs/Makefile.shared.

SUBST_CLASSES+=               comp
SUBST_STAGE.comp=     post-patch
SUBST_FILES.comp=     otherlibs/Makefile
SUBST_SED.comp=               -e 's,^CAMLC=.*,CAMLC=ocamlc,g'
SUBST_SED.comp+=      -e 's,^CAMLOPT=.*,CAMLOPT=ocamlopt,g'
SUBST_MESSAGE.comp=   Fixing CAMLC OCAMLOPT in otherlibs/Makefile.

INSTALLATION_DIRS+=	lib/ocaml/stublibs

post-build:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
