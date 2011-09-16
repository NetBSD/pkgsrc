# $NetBSD: Makefile,v 1.19 2011/09/16 02:26:45 obache Exp $

DISTNAME=	instiki-0.9.2
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/2515/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://instiki.org/show/HomePage
COMMENT=	Wiki clone that focuses on simple installation and running
LICENSE=	gnu-gpl-v2 OR ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

RCD_SCRIPTS=	instiki
FILES_SUBST+=	RUBY=${RUBY:Q}

REPLACE_RUBY=		instiki

INSTIKI_DIR=		share/${PKGBASE}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	app/controllers/wiki.rb
SUBST_SED.paths=							\
	-e 's,File.dirname(__FILE__) + "/../../storage,"${VARBASE}/instiki,g'

INSTALLATION_DIRS=	share/doc/${PKGBASE} ${INSTIKI_DIR}

post-patch:
	${MV} ${WRKSRC}/instiki ${WRKSRC}/instiki.tmp
	${TR} -d '\015' < ${WRKSRC}/instiki.tmp > ${WRKSRC}/instiki

do-install:
.for d in app libraries
	cd ${WRKSRC} && ${CP} -R ${d} ${DESTDIR}${PREFIX}/${INSTIKI_DIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/${INSTIKI_DIR}/${d}
.endfor
	${FIND} ${DESTDIR}${PREFIX}/${INSTIKI_DIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${PREFIX}/${INSTIKI_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_SCRIPT} ${WRKSRC}/instiki ${DESTDIR}${PREFIX}/${INSTIKI_DIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
