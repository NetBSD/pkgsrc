# $NetBSD: Makefile,v 1.8 2015/02/11 15:30:12 jaapb Exp $
#

VERSION=	4.1.0
PKGNAME=	eliom-${VERSION}
DISTNAME=	${VERSION}
DIST_SUBDIR=	eliom
CATEGORIES=	www
MASTER_SITES=	http://github.com/ocsigen/eliom/archive/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocsigen.org/download/
COMMENT=	Dynamic webpage generation library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
USE_LANGUAGES=	c
WRKSRC=	${WRKDIR}/eliom-${VERSION}

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	js_of_ocaml>=2.2:../../devel/js_of_ocaml # with ocaml-tyxml option
DEPENDS+=	ocsigen>=2.4:../../www/ocsigen
DEPENDS+=	ocaml-tyxml>=3:../../textproc/ocaml-tyxml
DEPENDS+=	ocaml-react>=0.9.3:../../devel/ocaml-react
DEPENDS+=	ocaml-calendar>=2.03.1:../../time/ocaml-calendar
DEPENDS+=	ocaml-deriving-ocsigen>=0.6:../../devel/ocaml-deriving-ocsigen

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET=	all
.else
BUILD_TARGET=	byte
.endif

do-install:
	cd ${WRKSRC} && opam-installer --install --prefix ${DESTDIR}${PREFIX} --libdir ${DESTDIR}${PREFIX}/${OCAML_SITELIBDIR} --docdir ${DESTDIR}${PREFIX}/share/doc eliom.install

.include "../../devel/ocaml-optcomp/buildlink3.mk"
.include "../../misc/ocaml-opam/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-opam?=    build
.include "../../net/ocaml-ipaddr/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
