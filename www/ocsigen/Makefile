# $NetBSD: Makefile,v 1.2 2008/01/18 05:09:52 tnn Exp $
#

DISTNAME=	ocsigen-0.6.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Web programming framework for OCaml

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	ocamlnet-[0-9]*:../../net/ocamlnet

BUILD_DEFS+=	VARBASE

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c
CONFIGURE_ARGS=	--enable-bytecode \
		--disable-newocamlnet \
		--disable-debug \
		--prefix ${PREFIX} \
		--bindir bin \
		--libdir share/examples \
		--mandir ${PKGMANDIR}/man1 \
		--docdir share/doc \
		--sysconfdir ${PKG_SYSCONFDIR}/ocsigen \
		--logdir ${VARBASE}/ocsigen \
		--staticpagesdir share/ocsigen/www \
		--uploaddir /tmp \
		--ocsigen-user www \
		--ocsigen-group www
CONF_FILES+=	${PREFIX}/share/examples/ocsigen/ocsigen.conf \
		${PKG_SYSCONFDIR}/ocsigen/ocsigen.conf
USE_TOOLS+=	gmake
BUILD_TARGET=	all
BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.09
INSTALL_TARGET=	fullinstall
MAKE_ENV=	EGDIR=${PREFIX}/share/examples/ocsigen

PKG_USERS+=	www
PKG_GROUPS+=	www
OWN_DIRS+=	${VARBASE}/ocsigen
OWN_DIRS_PERMS+=	${VARBASE}/ocsigen www www 0755

post-extract:
	rm ${WRKSRC}/baselib/ocsiconfig.ml

pre-install:
	mkdir -p ${PKG_SYSCONFDIR}/ocsigen

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
