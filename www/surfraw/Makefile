# $NetBSD: Makefile,v 1.62 2022/06/28 11:37:50 wiz Exp $

DISTNAME=	surfraw-2.3.0
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://surfraw.alioth.debian.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/surfraw/Surfraw
COMMENT=	Shell Users' Revolutionary Front Rage Against the Web
LICENSE=	public-domain

CONFLICTS+=	surfaw-[0-9]*

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-sr
USE_TOOLS+=		perl:run sed
REPLACE_PERL+=		surfraw-update-path.IN opensearch-discover \
			opensearch-genquery

DOCDIR=			${PREFIX}/share/doc/surfraw
EGDIR=			${PREFIX}/share/examples/surfraw
INSTALLATION_DIRS=	${DOCDIR}
INSTALL_MAKE_FLAGS=	sysconfdir=${EGDIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/surfraw
CONF_FILES=		${EGDIR}/xdg/surfraw/conf ${PKG_SYSCONFDIR}/xdg/surfraw/conf
CONF_FILES+=		${EGDIR}/xdg/surfraw/bookmarks ${PKG_SYSCONFDIR}/xdg/surfraw/bookmarks

# avoid installing useless manpage links
post-patch:
	-${GREP} -v elvi.1sr.gz ${WRKSRC}/links.IN > ${WRKSRC}/links.IN.new
	${MV} ${WRKSRC}/links.IN.new ${WRKSRC}/links.IN
	${SED} -e s/sr/surfraw/g ${WRKSRC}/surfraw.1.IN > ${WRKSRC}/surfraw.1.IN.new
	${MV} ${WRKSRC}/surfraw.1.IN.new ${WRKSRC}/surfraw.1.IN
	${SED} -e s/sr/surfraw/g ${WRKSRC}/elvi.1sr.IN > ${WRKSRC}/elvi.1sr.IN.new
	${MV} ${WRKSRC}/elvi.1sr.IN.new ${WRKSRC}/elvi.1sr.IN

# fix man page name; install additional documentation
post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/elvi.1sr \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/elvi.1

.include "../../mk/bsd.pkg.mk"
