# $NetBSD: Makefile,v 1.20 2007/12/31 07:05:00 obache Exp $
#

DISTNAME=	screws-0.56
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.nopcode.org/prj/screws/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.nopcode.org/?t=screws
COMMENT=	SCRipt Enhanced Web Server

USE_TOOLS+=	perl:run

PKG_GROUPS_VARS+=	SCREWS_GROUP
PKG_USERS_VARS+=	SCREWS_USER

PKG_USERS=	${SCREWS_USER}:${SCREWS_GROUP}
PKG_GROUPS=	${SCREWS_GROUP}

MAKE_ENV+=	ETCPREFIX=${PKG_SYSCONFDIR:Q}
MAKE_ENV+=	PERL=${PERL5:Q}

EGDIR=		${PREFIX}/share/examples/screws
CONF_FILES=	${EGDIR}/default.conf ${PKG_SYSCONFDIR}/screws.conf

RCD_SCRIPTS=		screws
RCD_SCRIPT_SRC.screws=	${WRKSRC}/src/Utils/files/screws.sh

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/Utils/screwsctl
SUBST_SED.paths=	-e 's|/var/log|${VARBASE}/log|g'

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	Makefile
SUBST_SED.man=		-e 's,PREFIX}/man,PREFIX}/${PKGMANDIR},g'

BUILD_DEFS+=		VARBASE

# The HSML files do not really contain a script interpreter, only
# something very similar.
CHECK_INTERPRETER_SKIP+=	*.hsml

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
