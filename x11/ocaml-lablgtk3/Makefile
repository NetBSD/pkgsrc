# $NetBSD: Makefile,v 1.35 2024/11/24 14:45:32 gdt Exp $

GITHUB_PROJECT=	lablgtk
GITHUB_TAG=	${VERSION}
VERSION=	3.1.3
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${GITHUB_PROJECT}3-${VERSION}
PKGREVISION=	18
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=garrigue/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/garrigue/lablgtk/
COMMENT=	GTK+ 3.x bindings for OCaml
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

OCAML_USE_DUNE=		yes
OCAML_FINDLIB_DIRS=	lablgtk3
OPAM_INSTALL_FILES=	${OCAML_FINDLIB_DIRS}
DUNE_BUILD_PACKAGES=	${OCAML_FINDLIB_DIRS}

## BEGIN DUNE/PKG-CONFIG KLUDGES

# See the dune sources, otherlibs/configurator/src/v1.ml and look for
# pkg-config and "which", if trying to understand why this fails.

# dune tries to run pkg-config, and this fails under pkgsrc for some reason.
# But when run in pre-configure, it seems to be ok.
test-dune-config:
	${ECHO} Testing dune calling pkg-config.
	(cd ${WRKSRC} && \
		dune exec -- ./_build/default/.bin/dune_config -verbose -pkg gtk+-3.0 -version 3.18) || ${TRUE}

# Undo the wrapper, in the hope that dune finds real pkg-config.  Does not help.
no-pkgconfig-wrapper:
	${RM} ${WRKDIR}/.tools/bin/pkg-config
	${CP} ${PREFIX}/bin/pkg-config ${WRKDIR}/.tools/bin/pkg-config

# This is a huge hack, to undefine PKG_CONFIG in the environment,
# which apparently breaks dune's searching for pkg-config.  Copied
# from ocaml/ocaml.mk, to where it should perhaps be hoisted.
do-build:
	${RUN} ${_ULIMIT_CMD} \
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SETENV} -u PKG_CONFIG \
		dune build -j ${MAKE_JOBS:U1} \
		${DUNE_BUILD_FLAGS} -p ${DUNE_BUILD_PACKAGES:ts,} \
		${DUNE_BUILD_TARGETS}

## END DUNE/PKG-CONFIG KLUDGES

.include "../../lang/ocaml/ocaml.mk"

.include "options.mk"

.include "../../devel/camlp-streams/buildlink3.mk"
.include "../../graphics/ocaml-cairo/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
