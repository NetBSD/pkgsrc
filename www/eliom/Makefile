# $NetBSD: Makefile,v 1.7 2014/02/12 23:18:44 tron Exp $
#

DISTNAME=	eliom-3.0.3
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocsigen.org/download/
COMMENT=	Dynamic webpage generation library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c
USE_TOOLS=	gmake
HAS_CONFIGURE=	yes

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	js_of_ocaml>=1.3.2:../../devel/js_of_ocaml
DEPENDS+=	ocsigen>=2.2:../../www/ocsigen
DEPENDS+=	ocaml-tyxml>=2.2:../../textproc/ocaml-tyxml
DEPENDS+=	ocaml-react>=0.9.2:../../devel/ocaml-react
DEPENDS+=	ocaml-calendar>=2.01.1:../../time/ocaml-calendar
DEPENDS+=	ocaml-deriving-ocsigen>=0.3:../../devel/ocaml-deriving-ocsigen

CONFIGURE_ARGS+=	--temproot ${DESTDIR} --prefix ${PREFIX} \
			--libdir ${PREFIX}/lib/ocaml/site-lib

INSTALLATION_DIRS=	lib/ocaml/site-lib

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
CONFIGURE_ARGS+=	--enable-natdynlink
.else
CONFIGURE_ARGS==	--disable-natdynlink
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
