# $NetBSD: Makefile,v 1.1 2018/06/05 16:17:10 jaapb Exp $

GITHUB_PROJECT=	ocsigen-start
DISTNAME=	${GITHUB_PROJECT}-1.1.0
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

MAKE_JOBS_SAFE=	no # for debugging, remove before flight

.include "../../databases/ocaml-macaque/buildlink3.mk"
.include "../../devel/ocaml-lwt_camlp4/buildlink3.mk"
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../devel/ocaml-yojson/buildlink3.mk"
.include "../../security/ocaml-safepass/buildlink3.mk"
.include "../../www/ocsigen-i18n/buildlink3.mk"
.include "../../www/ocsigen-toolkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
