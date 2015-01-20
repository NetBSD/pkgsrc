# $NetBSD: Makefile,v 1.6 2015/01/20 14:24:37 jaapb Exp $
#

DISTNAME=	ocaml-http-0.1.5
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/545/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://forge.ocamlcore.org/frs/download.php/545/
COMMENT=	Simple OCaml HTTP daemon library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ocaml-http_0.1.5
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
MAKE_ENV=	PKG_DESTDIR=${DESTDIR}/${PREFIX}/lib/ocaml/site-lib/

BUILD_TARGET=	all

PLIST_VARS=     opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "arm")
PLIST.opt=      yes
BUILD_TARGET+=	opt
.endif

.include "../../lang/camlp4/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
