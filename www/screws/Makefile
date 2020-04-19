# $NetBSD: Makefile,v 1.48 2020/04/19 06:06:00 plunky Exp $
#

DISTNAME=	screws-0.56
PKGREVISION=	25
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.nopcode.org/prj/screws/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nopcode.org/?t=screws
COMMENT=	SCRipt Enhanced Web Server
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run pax gmake

PKG_GROUPS_VARS+=	SCREWS_GROUP
PKG_USERS_VARS+=	SCREWS_USER

PKG_USERS=	${SCREWS_USER}:${SCREWS_GROUP}
PKG_GROUPS=	${SCREWS_GROUP}

MAKE_ENV+=		ETCPREFIX=${PKG_SYSCONFDIR:Q}
MAKE_ENV+=		PERL=${PERL5:Q}
MAKE_ENV+=		COMPILER_RPATH_FLAG=${COMPILER_RPATH_FLAG}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

EGDIR=		${PREFIX}/share/examples/screws
CONF_FILES=	${EGDIR}/default.conf ${PKG_SYSCONFDIR}/screws.conf

REPLACE_PERL+=	src/Exec/obsd-qos.x
REPLACE_PERL+=	src/Exec/perl.pl
REPLACE_PERL+=	src/Exec/perl/*.pl
REPLACE_PERL+=	src/Exec/perl/htdocs/example.x

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

post-extract:
	${CP} ${FILESDIR}/*.[158] ${WRKSRC}/doc/manpage/

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
