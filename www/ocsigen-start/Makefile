# $NetBSD: Makefile,v 1.5 2018/11/12 16:10:29 jaapb Exp $

GITHUB_PROJECT=	ocsigen-start
DISTNAME=	${GITHUB_PROJECT}-1.1.0
PKGREVISION=	4
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

DEPENDS+=	eliom>=6.3:../../www/eliom

SUBST_CLASSES+=	fix-settings fix-md5
SUBST_STAGE.fix-settings=	pre-configure
SUBST_FILES.fix-settings= template.distillery/Makefile.db
SUBST_FILES.fix-settings+=	template.distillery/Makefile.options
SUBST_SED.fix-settings=	-e 's,$$(shell opam config var lib),${PREFIX}/${OCAML_SITELIBDIR},'
SUBST_SED.fix-settings+=	-e 's,$$(shell $$(OPAM) config var share),${PREFIX}/share,'
SUBST_SED.fix-settings+=	-e '/USE_SASS/s,yes,no,'
SUBST_SED.fix-settings+=	-e '/USE_NPM/s,yes,no,'

SUBST_STAGE.fix-md5=	pre-configure
SUBST_FILES.fix-md5=	template.distillery/Makefile.mobile
SUBST_FILES.fix-md5+=	template.distillery/Makefile.os
SUBST_FILES.fix-md5+=	template.distillery/Makefile.style
SUBST_SED.fix-md5=	-e 's,md5sum,md5,g'

pre-configure:
	${RUN} cd ${WRKSRC} && rm -f template.distillery/*.orig

.include "../../databases/ocaml-macaque/buildlink3.mk"
.include "../../devel/ocaml-lwt_camlp4/buildlink3.mk"
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../devel/ocaml-yojson/buildlink3.mk"
.include "../../security/ocaml-safepass/buildlink3.mk"
.include "../../www/ocsigen-i18n/buildlink3.mk"
.include "../../www/ocsigen-toolkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
