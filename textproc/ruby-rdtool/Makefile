# $NetBSD: Makefile,v 1.5 2002/02/04 15:30:17 taca Exp $
# FreeBSD: ports/textproc/ruby-rdtool/Makefile,v 1.15 2001/01/30 19:20:09 knu Exp

DISTNAME=	rdtool-${RUBY_RD_VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www2.pos.to/~tosh/ruby/rdtool/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www2.pos.to/~tosh/ruby/rdtool/
COMMENT=	RD (Ruby Document) converter to HTML/man/etc

DEPENDS+=	${RUBY_PKGNAMEPREFIX}optparse>=0.7:../../devel/ruby-optparse
DEPENDS+=	${RUBY_PKGNAMEPREFIX}racc>=1.3.6:../../devel/ruby-racc
DEPENDS+=	${RUBY_PKGNAMEPREFIX}strscan>=0.6.1:../../devel/ruby-strscan
#DEPENDS+=	${RUBY_PKGNAMEPREFIX}forwardable>=1.1:../../devel/ruby14-forwardable

DIST_SUBDIR=	ruby
USE_RUBY=	yes
USE_RUBY_AMSTD=	yes
INSTALL_TARGET=	install install-rmi2html

REPLACE_RUBY=	rmi2html.rb utils/rdswap.rb

DOCS_RD=	README.rd README.rd.ja doc/rd-draft.rd doc/rd-draft.rd.ja
DOCS=		${DOCS_RD} README.html README.html.ja \
		doc/rd-draft.html doc/rd-draft.html.ja

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} rdtoolconf.rb

post-build:
.for f in ${DOCS_RD}
	cd ${WRKSRC}; ${RUBY} -I. rd2 -r rd/rd2html-lib.rb ${f} \
		> ${f:S/.rd/.html/}
.endfor

post-install:
	${LN} -sf rmi2html.rb ${PREFIX}/bin/rmi2html
	${INSTALL_SCRIPT} ${WRKSRC}/utils/rdswap.rb ${PREFIX}/bin/rdswap
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rd
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rd
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/rd
	${INSTALL_DATA} ${RUBY_SITELIBDIR}/rd/dot.rd2rc ${RUBY_EXAMPLESDIR}/rd

.include "Makefile.common"
.include "../../devel/ruby-amstd/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
