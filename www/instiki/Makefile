# $NetBSD: Makefile,v 1.3 2005/02/04 15:33:43 wiz Exp $

DISTNAME=	instiki-0.9.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/2515/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://instiki.org/
COMMENT=	Wiki clone that focuses on simple installation and running

DEPENDS+=	ruby>=1.8.1:../../lang/ruby
DEPENDS+=	ruby${RUBY_VER}-digest-[0-9]*:../../security/ruby-digest
DEPENDS+=	ruby${RUBY_VER}-zlib-[0-9]*:../../devel/ruby-zlib

NO_BUILD=	# defined
USE_PKGINSTALL=	yes

RCD_SCRIPTS=	instiki
FILES_SUBST+=	RUBY=${RUBY}

RUBY_VERSION_SUPPORTED=	18
REPLACE_RUBY=		instiki

INSTIKI_DIR=	${PREFIX}/share/${PKGBASE}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	app/controllers/wiki.rb
SUBST_SED.paths=							\
	-e 's,File.dirname(__FILE__) + "/../../storage,"${VARBASE}/instiki,g'

.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/rubyversion.mk"

post-patch:
	${MV} ${WRKSRC}/instiki ${WRKSRC}/instiki.tmp
	${TR} -d '\015' < ${WRKSRC}/instiki.tmp > ${WRKSRC}/instiki

do-install:
	${INSTALL_DATA_DIR} ${INSTIKI_DIR}
.for d in app libraries
	cd ${WRKSRC} && ${CP} -R $d ${INSTIKI_DIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTIKI_DIR}/$d
.endfor
	${FIND} ${INSTIKI_DIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${INSTIKI_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_SCRIPT} ${WRKSRC}/instiki ${INSTIKI_DIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
