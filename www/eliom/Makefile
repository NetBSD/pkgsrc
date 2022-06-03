# $NetBSD: Makefile,v 1.37 2022/06/03 12:40:12 jaapb Exp $
#

GITHUB_PROJECT=	eliom
DISTNAME=	${GITHUB_PROJECT}-10.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocsigen.org/eliom/
COMMENT=	Dynamic webpage generation library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		gmake
USE_LANGUAGES=		c
OCAML_USE_FINDLIB=	yes
UNLIMIT_RESOURCES+=	stacksize

DEPENDS+=	ocsigen>=5.0.0:../../www/ocsigen
DEPENDS+=	ocsipersist>=1.0:../../databases/ocsipersist

.include "../../lang/ocaml/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET=	native
.else
BUILD_TARGET=	byte
.endif

do-install:
	cd ${WRKSRC} && opaline -install-cmd "${INSTALL_DATA}" \
	-destdir ${DESTDIR} \
	-prefix ${PREFIX} \
	-libdir ${PREFIX}/${OCAML_SITELIBDIR} \
	-docdir ${PREFIX}/share/doc \
        eliom.install

.include "../../devel/js_of_ocaml-ocamlbuild/buildlink3.mk"
.include "../../devel/js_of_ocaml/buildlink3.mk"
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../devel/ocaml-lwt_ppx/buildlink3.mk"
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../devel/ocaml-reactiveData/buildlink3.mk"
.include "../../devel/ocaml-reactiveData/buildlink3.mk"
.include "../../misc/ocaml-opaline/buildlink3.mk"
.include "../../net/ocaml-ipaddr/buildlink3.mk"
.include "../../textproc/ocaml-tyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
