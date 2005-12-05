# $NetBSD: Makefile,v 1.22 2005/12/05 20:51:18 rillig Exp $

DISTNAME=	lablgtk-1.2.7
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/lablgtk.html
COMMENT=	GTK+ bindings for ocaml

USE_TOOLS+=	gmake

BUILDLINK_DEPMETHOD.ocaml=	full
BUILDLINK_DEPENDS.ocaml+=	ocaml>=3.0.5

.include "../../mk/bsd.prefs.mk"

# currently ocamlopt is only available on i386, sparc and powerpc.
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
USE_DOTOPT=	YES
.else
CAMLOPT=	ocamlc
MAKE_ENV+=	CAMLOPT=${CAMLOPT:Q}
PLIST_SRC=	${PKGDIR}/PLIST.noopt
.endif

.if ${OPSYS} == "Darwin"
PLIST_SRC+=	${PKGDIR}/PLIST.stub
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		configure USE_DOTOPT=${USE_DOTOPT} USE_CC=1 CC=${CC}

.if defined(USE_DOTOPT)
post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		opt
.endif

.include "../../x11/gtk/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
