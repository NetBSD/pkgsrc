# $NetBSD: Makefile,v 1.44 2023/10/24 22:11:31 wiz Exp $
#

VERSION=	5.0.1
GITHUB_PROJECT=	ocsigenserver
PKGNAME=	ocsigen-${VERSION}
PKGREVISION=	1
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Web programming framework for OCaml
LICENSE=	gnu-lgpl-v2.1

# ln: ./ocsipersist.mli: File exists
# Makefile:42: recipe for target 'ocsipersist.mli' failed
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	sed gmake

OCSIGEN_USER?=		${APACHE_USER}
OCSIGEN_GROUP?=		${APACHE_GROUP}
PKG_GROUPS=		${OCSIGEN_GROUP}
PKG_USERS=		${OCSIGEN_USER}:${OCSIGEN_GROUP}
PKG_GROUPS_VARS+=	OCSIGEN_GROUP
PKG_USERS_VARS+=	OCSIGEN_USER

BUILD_DEFS+=	APACHE_USER APACHE_GROUP OCSIGEN_USER OCSIGEN_GROUP VARBASE
FILES_SUBST+=	OCSIGEN_USER=${OCSIGEN_USER:Q} \
		OCSIGEN_GROUP=${OCSIGEN_GROUP:Q} \
		VARBASE=${VARBASE:Q}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--temproot ${DESTDIR} \
		--prefix ${PREFIX} \
		--bindir ${PREFIX}/bin \
		--libdir ${PREFIX}/lib/ocaml/site-lib \
		--mandir ${PREFIX}/${PKGMANDIR}/man1 \
		--docdir ${PREFIX}/share/doc \
		--sysconfdir ${PREFIX}/share/examples/ocsigen \
		--staticpagesdir ${PREFIX}/share/ocsigen/www \
		--uploaddir /tmp \
		--ocsigen-user ${OCSIGEN_USER} \
		--ocsigen-group ${OCSIGEN_GROUP} \
		--logdir ${VARBASE}/log/ocsigen \
		--datadir ${VARBASE}/lib/ocsigen \
		--commandpipe ${VARBASE}/run/ocsigen_command

#CONF_FILES+=	${DESTDIR}${PREFIX}/share/examples/ocsigen/ocsigenserver.conf.sample \
		${PKG_SYSCONFDIR}/ocsigenserver/ocsigenserver.conf

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	ocsigenserver
OCAML_USE_DUNE=		yes
OPAM_INSTALL_FILES=	ocsigenserver
INSTALL_UNSTRIPPED=	yes

.include "../../lang/ocaml/ocaml.mk"

#.if ${OCAML_USE_OPT_COMPILER} == "yes"
#CONFIGURE_ARGS+=		--enable-natdynlink
#BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.12.0
#.else
#CONFIGURE_ARGS+=		--disable-natdynlink
#.endif

post-extract:
	${RUN} ${CP} ${FILESDIR}/ocsigen_getcommandline.mli ${WRKSRC}/src/baselib/commandline
	${RUN} ${CP} ${FILESDIR}/ocsigen_getcommandline.mli ${WRKSRC}/src/baselib/nocommandline

post-configure:
	${RUN} cd ${WRKSRC} && gmake -C src confs

.include "../../mk/pthread.buildlink3.mk"
.include "../../archivers/ocaml-zip/buildlink3.mk"
.include "../../devel/ocaml-dune/buildlink3.mk"
.include "../../devel/ocaml-hmap/buildlink3.mk"
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../devel/ocaml-lwt_react/buildlink3.mk"
.include "../../devel/ocaml-lwt_ssl/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-react/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../net/ocaml-conduit/buildlink3.mk"
.include "../../net/ocaml-ipaddr/buildlink3.mk"
#.include "../../net/ocamlnet/buildlink3.mk"
.include "../../security/ocaml-cryptokit/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
#.include "../../textproc/ocaml-tyxml/buildlink3.mk"
.include "../../textproc/ocaml-xml-light/buildlink3.mk"
.include "../../www/ocaml-cohttp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
