# $NetBSD: Makefile,v 1.12 2015/01/20 14:24:37 jaapb Exp $
#

DISTNAME=		pxp-1.2.3
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://projects.camlcity.org/projects/pxp.html
COMMENT=		Polymorphic XML parser, a validating XML-1.0 parser (OCaml)
LICENSE=		mit

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-with-lex -with-wlex -lexlist utf8,iso88591
INSTALL_ENV=		OCAMLFIND_INSTALL_ARGS="install -destdir ${DESTDIR}${PREFIX}/lib/ocaml/site-lib"
BUILD_TARGET=		all

MAKE_JOBS_SAFE=		no

SUBST_CLASSES+=		ocamlfind
SUBST_STAGE.ocamlfind=	do-configure
SUBST_FILES.ocamlfind=			\
	src/pxp/Makefile		\
	src/pxp-engine/Makefile		\
	gensrc/pxp-lex-iso88591/Makefile	\
	gensrc/pxp-lex-utf8/Makefile	\
	gensrc/pxp-wlex/Makefile
SUBST_SED.ocamlfind=	-e 's|\($$(OCAMLFIND)\) install|\1 $$(OCAMLFIND_INSTALL_ARGS)|'

INSTALLATION_DIRS=	lib/ocaml/site-lib/pxp

.include "../../mk/bsd.prefs.mk"

PLIST_VARS=     opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "arm")
PLIST.opt=      yes
BUILD_TARGET+=	opt
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
