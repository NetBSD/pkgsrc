# $NetBSD: Makefile,v 1.1.1.1 2004/03/12 05:15:26 taca Exp $
# FreeBSD: ports/textproc/ruby-amrita/Makefile,v 1.5 2003/02/18 05:38:23 knu Exp
#

DISTNAME=	amrita-1.0.2
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc www
MASTER_SITES=	http://www.brain-tokyo.jp/research/amrita/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.brain-tokyo.jp/research/amrita/
COMMENT=	HTML/XHTML template library for Ruby

DEPENDS+=	${RUBY_PKGNAMEPREFIX}strscan>=0.6.5:../../devel/ruby-strscan

NO_BUILD=	# defined

BINS=           bin/ams bin/amshandler bin/amx
DOCS=           ChangeLog README README_ja
REPLACE_RUBY=	${BINS}

post-patch:
	@${FIND} ${WRKSRC} -name '.cvsignore' -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.for f in ${BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/amrita
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_DOCDIR}/amrita
.endfor
	${CP} -R ${WRKSRC}/docs/* ${RUBY_DOCDIR}/amrita
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/amrita
	${CP} -R ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/amrita

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
