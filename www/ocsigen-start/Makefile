# $NetBSD: Makefile,v 1.9 2020/04/21 13:06:00 jaapb Exp $

GITHUB_PROJECT=	ocsigen-start
DISTNAME=	${GITHUB_PROJECT}-2.16.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/ocsigen-start/
COMMENT=	Application skeleton for Eliom
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
USE_TOOLS=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_ENV+=	NATIVE=yes
.else
MAKE_ENV+=	NATIVE=no
.endif

DEPENDS+=	eliom>=6.4:../../www/eliom

SUBST_CLASSES+=			fix-settings
SUBST_STAGE.fix-settings=	pre-configure
SUBST_FILES.fix-settings=	template.distillery/Makefile.db
SUBST_FILES.fix-settings+=	template.distillery/Makefile.options
SUBST_SED.fix-settings=		-e 's,$$(shell opam config var lib),${PREFIX}/${OCAML_SITELIBDIR},'
SUBST_SED.fix-settings+=	-e 's,$$(shell $$(OPAM) config var share),${PREFIX}/share,'
SUBST_SED.fix-settings+=	-e '/USE_SASS/s,yes,no,'
SUBST_SED.fix-settings+=	-e '/USE_NPM/s,yes,no,'

SUBST_CLASSES+=		fix-md5
SUBST_STAGE.fix-md5=	pre-configure
SUBST_FILES.fix-md5=	template.distillery/Makefile.mobile
SUBST_FILES.fix-md5+=	template.distillery/Makefile.os
SUBST_FILES.fix-md5+=	template.distillery/Makefile.style
SUBST_SED.fix-md5=	-e 's,md5sum,md5,g'

pre-configure:
	${RUN} cd ${WRKSRC} && rm -f template.distillery/*.orig

.include "../../databases/pgocaml/buildlink3.mk"
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../devel/ocaml-resource-pooling/buildlink3.mk"
.include "../../devel/ocaml-yojson/buildlink3.mk"
.include "../../security/ocaml-safepass/buildlink3.mk"
.include "../../www/ocaml-cohttp/buildlink3.mk"
.include "../../www/ocsigen-i18n/buildlink3.mk"
.include "../../www/ocsigen-toolkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
