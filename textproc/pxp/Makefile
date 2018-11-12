# $NetBSD: Makefile,v 1.23 2018/11/12 16:10:28 jaapb Exp $
#

DISTNAME=		pxp-1.2.8
PKGREVISION=		7
CATEGORIES=		textproc
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://projects.camlcity.org/projects/pxp.html
COMMENT=		Polymorphic XML parser, a validating XML-1.0 parser (OCaml)
LICENSE=		mit

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-with-lex -with-wlex -lexlist utf8,iso88591
INSTALL_ENV=		OCAMLFIND_INSTALL_ARGS="install -destdir ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR}"
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

INSTALLATION_DIRS=	${OCAML_SITELIBDIR}/pxp
OCAML_USE_FINDLIB=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/ocaml.mk"

.if (${OCAML_USE_OPT_COMPILER} == "yes")
BUILD_TARGET+=	opt
.endif

.include "../../lang/camlp4/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
