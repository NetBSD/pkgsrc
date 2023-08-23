# $NetBSD: Makefile,v 1.45 2023/08/23 00:33:46 gutteridge Exp $

DISTNAME=	viewvc-1.2.3
PKGREVISION=	2
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=viewvc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.viewvc.org/
COMMENT=	View the content of CVS/SVN repositories with a web browser
LICENSE=	2-clause-bsd

REPLACE_PYTHON=	viewvc-install bin/* bin/cgi/*.cgi lib/*.py
# https://github.com/viewvc/viewvc/issues/138
PYTHON_VERSIONS_ACCEPTED=	27	# not yet ported as of 1.2.3

.if exists(/usr/bin/rlog)
RCSPATH=	/usr/bin
.else
DEPENDS+=	rcs-[0-9]*:../../devel/rcs
RCSPATH=	${PREFIX}/bin
.endif

NO_BUILD=	YES

DOCDIR=		share/doc/viewvc
EGDIR=		share/examples/viewvc
VIEWVCDIR=	share/viewvc

CFGFILES=	cvsgraph.conf mimetypes.conf viewvc.conf
DOCFILES=	CHANGES INSTALL \
		docs/template-authoring-guide.html \
		docs/upgrading-howto.html \
		docs/url-reference.html

PKG_SYSCONFSUBDIR=	viewvc

.for cfg in ${CFGFILES}
CONF_FILES+=		${EGDIR}/${cfg} ${PKG_SYSCONFDIR}/${cfg}
.endfor

PLIST_SUBST+=		VIEWVCDIR=${VIEWVCDIR:Q}

PRINT_PLIST_AWK+=	{ gsub(/^${VIEWVCDIR:S|/|\\/|g}/, "$${VIEWVCDIR}"); }

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing pkgsrc paths.
SUBST_FILES.paths+=	lib/viewvc.py
SUBST_FILES.paths+=	viewvc-install
SUBST_VARS.paths=	PREFIX PKG_SYSCONFDIR

DIFF=			${TOOLS_PATH.diff}

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Fixing configuration files.
SUBST_FILES.conf=	conf/viewvc.conf.dist
SUBST_VARS.conf=	PREFIX PKG_SYSCONFBASE PKG_SYSCONFDIR
SUBST_VARS.conf+=	VIEWVCDIR DIFF RCSPATH CVSGRAPH_OPT

CHECK_PORTABILITY_SKIP=	tools/make-release

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} viewvc-install \
		--prefix=${PREFIX}/${VIEWVCDIR} --destdir=${DESTDIR})
.for cfg in ${CFGFILES}
	${INSTALL_DATA} ${WRKSRC}/conf/${cfg}.dist \
		${DESTDIR}${PREFIX}/${EGDIR}/${cfg}
.endfor
.for doc in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${doc} \
		${DESTDIR}${PREFIX}/${DOCDIR}/${doc:T}
.endfor

post-install:
	( cd ${DESTDIR}/${PREFIX}/${VIEWVCDIR}/bin/mod_python ; \
		${CHMOD} ${SHAREMODE} .htaccess *.py)

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
