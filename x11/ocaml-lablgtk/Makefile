# $NetBSD: Makefile,v 1.12 2016/03/05 11:27:59 jperkin Exp $

DISTNAME=	lablgtk-2.18.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1479/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://lablgtk.forge.ocamlcore.org/
COMMENT=	GTK+ 2.x bindings for Objective Caml
# for installed files; more restrictions on applications/
LICENSE=	gnu-lgpl-v2

# remove on next update
DIST_SUBDIR=	lablgtk-2.18.3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-debug
USE_TOOLS+=		gmake pkg-config
OCAML_USE_FINDLIB=	yes

MAKE_JOBS_SAFE=		no
BUILD_TARGET=		world

BUILDLINK_DEPMETHOD.ocaml=	full

CONFLICTS=	lablgtk-[0-9]*
SUPERSEDES=	lablgtk-[0-9]*

.include "../../mk/bsd.prefs.mk"

# Stub libraries for functions missing from base system.
PLIST_VARS+=	stubs opt

.if ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly" || \
    ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "SunOS"  || ${OPSYS} == "Linux"
PLIST.stubs=	yes
.endif

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
PLIST.opt=	yes
.endif

.include "options.mk"

.include "../../lang/camlp4/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
