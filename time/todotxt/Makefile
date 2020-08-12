# $NetBSD: Makefile,v 1.4 2020/08/12 12:16:54 leot Exp $

DISTNAME=	todotxt-2.12.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=todotxt/}
GITHUB_PROJECT=	todo.txt-cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://todotxt.org/
COMMENT=	Simple and extensible shell script for managing your todo.txt file
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bash:run gmake:test gsed:run

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

# XXX: REPLACE_BASH only affect the `#!' on the first line, so we need to
# XXX: manually adjust the other in the middle of the shell script.
SUBST_CLASSES+=		shebang
SUBST_STAGE.shebang=	pre-configure
SUBST_MESSAGE.shebang=	Replace hardcoded /bin/bash in the middle of scripts
SUBST_FILES.shebang+=	tests/actions-test-lib.sh
SUBST_SED.shebang+=	-e '2,$$s;!/bin/bash;!${BASH};'
SUBST_NOOP_OK.shebang=	yes

REPLACE_BASH+=	todo.sh
REPLACE_BASH+=	tests/*.sh

USE_LANGUAGES=	# none

NO_BUILD=	yes

EGDIR=		${PREFIX}/share/examples/todotxt
DOCDIR=		${PREFIX}/share/doc/todotxt

PKG_SYSCONFSUBDIR=	todotxt
CONF_FILES=		${EGDIR}/todo.cfg \
			${PKG_SYSCONFDIR}/todo.cfg

TEST_TARGET=	test

INSTALLATION_DIRS=	bin ${DOCDIR} ${EGDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/todo.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/todo.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/todo_completion ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/USAGE.md ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
