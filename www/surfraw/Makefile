# $NetBSD: Makefile,v 1.34 2007/10/27 11:25:29 wiz Exp $
#

DISTNAME=	surfraw-2.2.0
CATEGORIES=	www
MASTER_SITES=	http://surfraw.alioth.debian.org/dist/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://surfraw.alioth.debian.org/
COMMENT=	Shell Users' Revolutionary Front Rage Against the Web

CONFLICTS+=	surfaw-[0-9]*

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/surfraw
EGDIR=			${PREFIX}/share/examples/surfraw
INSTALLATION_DIRS=	${DOCDIR}

CONF_FILES=		${EGDIR}/surfraw.conf ${PKG_SYSCONFDIR}/surfraw.conf
CONF_FILES+=		${EGDIR}/surfraw.bookmarks ${PKG_SYSCONFDIR}/surfraw.bookmarks

# avoid installing useless manpage links
post-patch:
	${MV} ${WRKSRC}/links.IN ${WRKSRC}/links.IN.orig
	${GREP} -v elvi.1sr.gz ${WRKSRC}/links.IN.orig > ${WRKSRC}/links.IN

# Override installation to install config files in example dir
do-install:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_ARGS} sysconfdir=${EGDIR} install

# fix man page name; install additional documentation
post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${MV} ${PREFIX}/${PKGMANDIR}/man1/elvi.1sr ${PREFIX}/${PKGMANDIR}/man1/elvi.1

.include "../../mk/bsd.pkg.mk"
