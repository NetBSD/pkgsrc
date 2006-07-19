# $NetBSD: Makefile,v 1.14 2006/07/19 19:48:21 jlam Exp $

DISTNAME=       wwwcount2.5
PKGNAME=        wwwcount-2.5
PKGREVISION=	1
CATEGORIES=     www
MASTER_SITES=   ${MASTER_SITE_BACKUP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muquit.com/muquit/software/Count/Count.html
COMMENT=	Graphical access counter, clock and date indicator for WWW pages

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1				\
			share/doc/wwwcount/Count2.5/images		\
			share/doc/wwwcount/Count2.5/eximages		\
			share/examples

CONF_FILES_PERMS=	/dev/null ${VARBASE}/log/wwwcount nobody nogroup 0644
CONF_FILES=		${PREFIX}/share/examples/wwwcount.conf		\
			${PKG_SYSCONFDIR}/wwwcount.conf

pre-configure:
	cd ${WRKSRC}; yes "" | PREFIX=${PREFIX} PKG_SYSCONFDIR=${PKG_SYSCONFDIR} VARBASE=${VARBASE} ./Count-config

do-install:
	cd ${WRKSRC}; yes "" | ./Count-install
	${INSTALL_DATA} ${FILESDIR}/wwwcount.conf ${PREFIX}/share/examples
	${INSTALL_PROGRAM} ${WRKSRC}/utils/extdgts/extdgts ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/mkstrip/mkstrip ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/utils/mkstrip/mkstrip.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/docs/blues.gif ${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count.html ${PREFIX}/share/doc/wwwcount
	( cd ${PREFIX}/share/doc/wwwcount && ${LN} -s Count.html index.html )
	${INSTALL_MAN} ${WRKSRC}/docs/Count2_5-ex.html ${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count_Changelog.html ${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count_FAQ.html ${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count_download.html ${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count_mirrors.html ${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/c-c.txt ${PREFIX}/share/doc/wwwcount/Count2.5
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/gen-c.txt ${PREFIX}/share/doc/wwwcount/Count2.5
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleA.gif ${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleB.gif ${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleC.gif ${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleD.gif ${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleE.gif ${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/stylecd.gif ${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/stylecdd.gif ${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/stylecdr.gif ${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/eximages/* ${PREFIX}/share/doc/wwwcount/Count2.5/eximages
	${INSTALL_SCRIPT} ${WRKSRC}/utils/mkstrip/mkstrip.sh ${PREFIX}/libdata/wwwcount/digits

.include "../../mk/bsd.pkg.mk"
