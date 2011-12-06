# $NetBSD: Makefile,v 1.5 2011/12/06 00:19:25 sbd Exp $
#

DISTNAME=		pxp-1.1.6
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://www.ocaml-programming.de/packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ocaml-programming.de/packages/
COMMENT=		Polymorphic XML parser, a validating XML-1.0 parser (OCaml)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=		ocamlnet-[0-9]*:../../net/ocamlnet

USE_TOOLS+=		gmake
BUILD_TARGET=		all opt
HAS_CONFIGURE=		yes
PLIST_SRC=		PLIST.opt PLIST
INSTALL_ENV=		OCAMLFIND_INSTALL_ARGS="install -destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib"

MAKE_JOBS_SAFE=		no

SUBST_CLASSES+=		ocamlfind
SUBST_STAGE.ocamlfind=	do-configure
SUBST_FILES.ocamlfind=			\
	src/pxp/Makefile		\
	src/pxp-engine/Makefile		\
	src/pxp-lex-iso88591/Makefile	\
	src/pxp-lex-utf8/Makefile	\
	src/pxp-wlex/Makefile
SUBST_SED.ocamlfind=	-e 's|\($$(OCAMLFIND)\) install|\1 $$(OCAMLFIND_INSTALL_ARGS)|'

INSTALLATION_DIRS=	lib/ocaml/site-lib/pxp

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
