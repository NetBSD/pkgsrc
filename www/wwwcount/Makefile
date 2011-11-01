# $NetBSD: Makefile,v 1.20 2011/11/01 13:45:06 hans Exp $

DISTNAME=	wwwcount2.5
PKGNAME=	wwwcount-2.5
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.muquit.com/muquit/software/Count/Count.html
COMMENT=	Graphical access counter, clock and date indicator for WWW pages

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1				\
			share/doc/wwwcount/Count2.5/images		\
			share/doc/wwwcount/Count2.5/eximages		\
			share/examples

CONF_FILES_PERMS=	/dev/null ${VARBASE}/log/wwwcount nobody nogroup 0644
CONF_FILES=		${PREFIX}/share/examples/wwwcount.conf		\
			${PKG_SYSCONFDIR}/wwwcount.conf

MAKE_JOBS_SAFE=		NO

SUBST_CLASSES+=		destdir
SUBST_STAGE.destdir=	pre-install
SUBST_FILES.destdir=	Config.tmpl
SUBST_SED.destdir=	-e s,=\"${PREFIX},=\"${DESTDIR}${PREFIX},

pre-configure:
	cd ${WRKSRC}; PREFIX=${PREFIX} PKG_SYSCONFDIR=${PKG_SYSCONFDIR} VARBASE=${VARBASE} ./Count-config < /dev/null

do-install:
	cd ${WRKSRC}; ./Count-install < /dev/null
	${INSTALL_DATA} ${FILESDIR}/wwwcount.conf ${DESTDIR}${PREFIX}/share/examples
	${INSTALL_PROGRAM} ${WRKSRC}/utils/extdgts/extdgts ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/mkstrip/mkstrip ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/utils/mkstrip/mkstrip.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/docs/blues.gif ${DESTDIR}${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count.html ${DESTDIR}${PREFIX}/share/doc/wwwcount
	( cd ${DESTDIR}${PREFIX}/share/doc/wwwcount && ${LN} -s Count.html index.html )
	${INSTALL_MAN} ${WRKSRC}/docs/Count2_5-ex.html ${DESTDIR}${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count_Changelog.html ${DESTDIR}${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count_FAQ.html ${DESTDIR}${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count_download.html ${DESTDIR}${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count_mirrors.html ${DESTDIR}${PREFIX}/share/doc/wwwcount
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/c-c.txt ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/gen-c.txt ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleA.gif ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleB.gif ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleC.gif ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleD.gif ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/styleE.gif ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/stylecd.gif ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/stylecdd.gif ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/images/stylecdr.gif ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5/images
	${INSTALL_MAN} ${WRKSRC}/docs/Count2.5/eximages/* ${DESTDIR}${PREFIX}/share/doc/wwwcount/Count2.5/eximages
	${INSTALL_SCRIPT} ${WRKSRC}/utils/mkstrip/mkstrip.sh ${DESTDIR}${PREFIX}/libdata/wwwcount/digits

.include "../../mk/bsd.pkg.mk"
