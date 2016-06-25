# $NetBSD: Makefile,v 1.10 2016/06/25 14:32:49 jaapb Exp $
#

DISTNAME=	ocaml-http-0.1.5
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/545/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://forge.ocamlcore.org/frs/download.php/545/
COMMENT=	Simple OCaml HTTP daemon library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ocaml-http_0.1.5
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
MAKE_ENV=	PKG_DESTDIR=${DESTDIR}/${PREFIX}/${OCAML_SITELIBDIR}

BUILD_TARGET=	all

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

.if (${OCAML_USE_OPT_COMPILER} == "yes")
BUILD_TARGET+=	opt
.endif

.include "../../lang/camlp4/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
