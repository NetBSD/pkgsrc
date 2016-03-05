# $NetBSD: Makefile,v 1.20 2016/03/05 11:29:38 jperkin Exp $
#

VERSION=	2.6
PKGNAME=	ocsigen-${VERSION}
PKGREVISION=	1
DISTNAME=	${VERSION}
DIST_SUBDIR=	ocsigenserver
CATEGORIES=	www
MASTER_SITES=	http://github.com/ocsigen/ocsigenserver/archive/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Web programming framework for OCaml
LICENSE=	gnu-lgpl-v2.1

# ln: ./ocsipersist.mli: File exists
# Makefile:42: recipe for target 'ocsipersist.mli' failed
MAKE_JOBS_SAFE=	no

DEPENDS+=     ocaml-react-[0-9]*:../../devel/ocaml-react
DEPENDS+=     ocaml-text-[0-9]*:../../textproc/ocaml-text

OCSIGEN_USER?=	${APACHE_USER}
OCSIGEN_GROUP?=	${APACHE_GROUP}
PKG_GROUPS=	${OCSIGEN_GROUP}
PKG_USERS=	${OCSIGEN_USER}:${OCSIGEN_GROUP}
PKG_GROUPS_VARS+=	OCSIGEN_GROUP
PKG_USERS_VARS+=	OCSIGEN_USER

BUILD_DEFS+=	APACHE_USER APACHE_GROUP OCSIGEN_USER OCSIGEN_GROUP VARBASE
FILES_SUBST+=	OCSIGEN_USER=${OCSIGEN_USER:Q} \
		OCSIGEN_GROUP=${OCSIGEN_GROUP:Q} \
		VARBASE=${VARBASE:Q}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug \
		--temproot ${DESTDIR} \
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

CONF_FILES+=	${DESTDIR}${PREFIX}/share/examples/ocsigen/ocsigenserver.conf.sample \
		${PKG_SYSCONFDIR}/ocsigenserver/ocsigenserver.conf
USE_TOOLS+=	gmake
WRKSRC=	${WRKDIR}/ocsigenserver-${VERSION}

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
CONFIGURE_ARGS+= 		--enable-natdynlink
BUILDLINK_API_DEPENDS.ocaml+=   ocaml>=3.12.0
.else
CONFIGURE_ARGS+=		--disable-natdynlink
.endif

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../net/ocaml-ipaddr/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../security/ocaml-cryptokit/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../textproc/ocaml-tyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
