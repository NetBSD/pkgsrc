# $NetBSD: Makefile,v 1.10 2012/12/15 11:16:07 jaapb Exp $
#

VERSION=	2.2.0
PKGNAME=	ocsigen-${VERSION}
DISTNAME=	ocsigenserver-${VERSION}
CATEGORIES=	www
MASTER_SITES=	http://www.ocsigen.org/download/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Web programming framework for OCaml
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	ocaml-react-[0-9]*:../../devel/ocaml-react
DEPENDS+=	ocaml-text-[0-9]*:../../textproc/ocaml-text
DEPENDS+=	ocaml-tyxml>=2.2:../../textproc/ocaml-tyxml

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

MAKE_JOBS_SAFE=	no
INSTALLATION_DIRS=	lib/ocaml/site-lib

PLIST_VARS+=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+= 		--enable-natdynlink
BUILDLINK_API_DEPENDS.ocaml+=   ocaml>=3.12.0
PLIST.opt=	yes
.else
CONFIGURE_ARGS+=		--disable-natdynlink
.endif

CONF_FILES+=	${DESTDIR}${PREFIX}/share/examples/ocsigen/ocsigenserver.conf.sample \
		${PKG_SYSCONFDIR}/ocsigenserver/ocsigenserver.conf
USE_TOOLS+=	gmake
USE_LANGUAGES=	c

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/ocaml-dbm/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../net/ocamlnet/buildlink3.mk"
.include "../../security/ocaml-cryptokit/buildlink3.mk"
.include "../../security/ocaml-ssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
