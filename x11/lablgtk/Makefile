# $NetBSD: Makefile,v 1.11 2004/04/22 09:20:31 tron Exp $

DISTNAME=	lablgtk-1.2.6
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/lablgtk.html
COMMENT=	GTK+ bindings for ocaml

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

BUILDLINK_DEPMETHOD.ocaml=	full

.include "../../mk/bsd.prefs.mk"

# currently ocamlopt is only available on i386
.if (${MACHINE_ARCH} == "i386")
USE_DOTOPT=	YES
.else
CAMLOPT=	ocamlc
MAKE_ENV+=	CAMLOPT=${CAMLOPT}
PLIST_SRC=	${PKGDIR}/PLIST.noopt
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		configure USE_DOTOPT=${USE_DOTOPT} USE_CC=1 CC=${CC}

.if (${MACHINE_ARCH} == "i386")
post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		opt
.endif

.include "../../x11/gtk/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
