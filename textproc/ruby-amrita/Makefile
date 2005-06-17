# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:37 jlam Exp $

DISTNAME=	amrita-1.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc ruby www
MASTER_SITES=	http://www.brain-tokyo.jp/research/amrita/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.brain-tokyo.jp/research/amrita/
COMMENT=	HTML/XHTML template library for Ruby

CONFLICTS+=	ruby[1-9][0-9]-amrita-*

NO_BUILD=	yes
DOCS=		ChangeLog README README_ja
REPLACE_RUBY=	bin/ams bin/amshandler bin/amx

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == 16
DEPENDS+=	${RUBY_PKGPREFIX}-strscan>=0.6.5:../../devel/ruby-strscan
.endif

INSTALLATION_DIRS=	bin

post-patch:
	@${FIND} ${WRKSRC} -name '.cvsignore' -exec ${RM} -f {} \;

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.for f in ${REPLACE_RUBY}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/amrita
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_DOCDIR}/amrita
.endfor
	${CP} -R ${WRKSRC}/docs/* ${RUBY_DOCDIR}/amrita
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/amrita
	${CP} -R ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/amrita

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
