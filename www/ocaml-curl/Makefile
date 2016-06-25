# $NetBSD: Makefile,v 1.14 2016/06/25 14:32:27 jaapb Exp $
#

DISTNAME=		ocurl-0.5.3
PKGNAME=		ocaml-curl-0.5.3
EXTRACT_SUFX=		.tgz
PKGREVISION=		12
CATEGORIES=		www net devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ocurl/}

MAINTAINER=		rich.neswold@gmail.com
HOMEPAGE=		http://sourceforge.net/projects/ocurl/
COMMENT=		OCaml bindings to the CURL library
LICENSE=		mit

MAKE_JOBS_SAFE=         no

USE_TOOLS=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-findlib

OCAML_USE_FINDLIB=	yes

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/ocurl
USE_LANGUAGES=		c

.include "../../www/curl/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
