# $NetBSD: Makefile,v 1.9 2004/01/24 15:30:33 grant Exp $

DISTNAME=	lablgtk-1.2.5
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/lablgtk.html
COMMENT=	GTK+ bindings for ocaml

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make

.include "../../mk/bsd.prefs.mk"

# currently ocamlopt is only available on i386
.if (${MACHINE_ARCH} == "i386")
USE_DOTOPT=	YES
.else
CAMLOPT=	ocamlc
MAKE_ENV+=	CAMLOPT=${CAMLOPT}
PLIST_SRC=	${PKGDIR}/PLIST.noopt
.endif

.if exists(${LOCALBASE}/lib/ocaml/libthreadsnat.a)
PLIST_SUBST+=		NATIVE_THREADS=
.else
PLIST_SUBST+=		NATIVE_THREADS="@comment "
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		configure USE_DOTOPT=${USE_DOTOPT} USE_CC=1 CC=${CC}

.if (${MACHINE_ARCH} == "i386")
post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		opt
.endif

.include "../../x11/gtk/buildlink2.mk"
.include "../../lang/ocaml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
