# $NetBSD: Makefile,v 1.1 2017/12/19 11:39:50 leot Exp $

DISTNAME=	todotxt-2.10
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=todotxt/}
GITHUB_PROJECT=	todo.txt-cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://todotxt.org/
COMMENT=	Simple and extensible shell script for managing your todo.txt file
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bash:run gsed:run

SUBST_CLASSES+=		todosh
SUBST_STAGE.todosh=	pre-configure
SUBST_MESSAGE.todosh=	Adjusting hard-coded paths, version and use GNU sed
SUBST_FILES.todosh+=	todo.sh
SUBST_SED.todosh+=	-e '/TODOTXT_GLOBAL_CFG_FILE=/ s,/etc/todo/config,${PKG_SYSCONFDIR}/todo.cfg,'
SUBST_SED.todosh+=	-E -e 's,([(| ])sed ,\1${TOOLS_PATH.gsed} ,g'
SUBST_SED.todosh+=	-e 's,@DEV_VERSION@,${PKGVERSION_NOREV},g'

SUBST_CLASSES+=		todocfg
SUBST_STAGE.todocfg=	pre-configure
SUBST_MESSAGE.todocfg=	Adjusting TOOL_DIR path to user's HOME
SUBST_FILES.todocfg+=	todo.cfg
SUBST_SED.todocfg+=	-e '/^export TODO_DIR/ s,=.*,=$$HOME/.todo,'

REPLACE_BASH=	todo.sh

USE_LANGUAGES=	# none

NO_BUILD=	yes

EGDIR=		${PREFIX}/share/examples/todotxt
DOCDIR=		${PREFIX}/share/doc/todotxt

PKG_SYSCONFSUBDIR=	todotxt
CONF_FILES=		${EGDIR}/todo.cfg \
			${PKG_SYSCONFDIR}/todo.cfg

INSTALLATION_DIRS=	bin ${DOCDIR} ${EGDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/todo.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/todo_completion ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.textile ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
