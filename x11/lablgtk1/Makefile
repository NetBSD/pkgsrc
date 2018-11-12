# $NetBSD: Makefile,v 1.23 2018/11/12 16:10:17 jaapb Exp $

DISTNAME=	lablgtk-1.2.7
PKGNAME=	lablgtk1-1.2.7
PKGREVISION=	20
CATEGORIES=	x11
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/571/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/lablgtk.html
COMMENT=	GTK+ bindings for ocaml
LICENSE=	gnu-lgpl-v2.1

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake

BUILDLINK_DEPMETHOD.ocaml=	full
BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.0.5

CONFLICTS+=	lablgtk-1.*

.include "../../mk/bsd.prefs.mk"

# currently ocamlopt is only available on i386, sparc and powerpc.
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || ${MACHINE_ARCH} == "x86_64"
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
		configure USE_DOTOPT=${USE_DOTOPT} USE_CC=1 CC=${CC:Q}

.if defined(USE_DOTOPT)
post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} \
		opt
.endif

INSTALLATION_DIRS+=	bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
