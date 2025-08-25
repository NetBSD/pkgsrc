# $NetBSD: Makefile,v 1.7 2025/08/25 08:35:15 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	time_now
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/time_now/
COMMENT=	Library that reports the current time
LICENSE=	mit

USE_TOOLS+=	bash

OCAML_USE_DUNE=	yes
.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-jane-street-headers/buildlink3.mk"
.include "../../devel/ocaml-jst-config/buildlink3.mk"
.include "../../devel/ocaml-ppx_base/buildlink3.mk"
.include "../../devel/ocaml-ppx_optcomp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
