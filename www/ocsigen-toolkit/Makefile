# $NetBSD: Makefile,v 1.6 2020/04/21 12:56:17 jaapb Exp $

GITHUB_PROJECT=	ocsigen-toolkit
DISTNAME=	${GITHUB_PROJECT}-2.5.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/ocsigen-toolkit/
COMMENT=	User interface widgets for Ocsigen applications
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

DEPENDS+=	eliom>=6.7:../../www/eliom

post-install:
	${RUN} cd ${WRKSRC} && opaline -install-cmd "${INSTALL_DATA}" \
		-destdir ${DESTDIR} \
		-prefix ${PREFIX} \
		ocsigen-toolkit.install

.include "../../misc/ocaml-opaline/buildlink3.mk"
.include "../../time/ocaml-calendar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
