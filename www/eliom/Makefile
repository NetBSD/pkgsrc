# $NetBSD: Makefile,v 1.1 2012/08/12 17:47:43 wiz Exp $
#

DISTNAME=	eliom-2.2.2
CATEGORIES=	www
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://ocsigen.org/download/
COMMENT=	Dynamic webpage generation library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
USE_TOOLS=	gmake
HAS_CONFIGURE=	yes

DEPENDS+=	js_of_ocaml>=1.2:../../devel/js_of_ocaml
DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	ocsigen>=2.1:../../www/ocsigen
DEPENDS+=	ocaml-tyxml>=2.1:../../textproc/ocaml-tyxml
DEPENDS+=	ocaml-react>=0.9.2:../../devel/ocaml-react
DEPENDS+=	ocaml-ssl>=0.4.4:../../security/ocaml-ssl
DEPENDS+=	ocaml-calendar>=2.01.1:../../time/ocaml-calendar
DEPENDS+=	ocaml-deriving-ocsigen>=0.3:../../devel/ocaml-deriving-ocsigen

CONFIGURE_ARGS+=	--temproot ${DESTDIR} --prefix ${PREFIX} \
			--libdir ${PREFIX}/lib/ocaml/site-lib --without-ocamlduce

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
CONFIGURE_ARGS+=	--enable-natdynlink
.else
CONFIGURE_ARGS==	--disable-natdynlink
.endif

pre-install:
	${MKDIR} ${DESTDIR}${PREFIX}/lib/ocaml/site-lib

.include "../../net/ocamlnet/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
