# $NetBSD: Makefile,v 1.14 2005/03/06 17:19:07 taca Exp $
# FreeBSD: ports/textproc/ruby-rdtool/Makefile,v 1.15 2001/01/30 19:20:09 knu Exp

DISTNAME=	rdtool-0.6.14
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www2.pos.to/~tosh/ruby/rdtool/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2.pos.to/~tosh/ruby/rdtool/
COMMENT=	RD (Ruby Document) converter to HTML/man/etc

# Since rd2 commands depends its name and it can't rename, we cannot
# install multiple ruby??-rd2 package (unless supported by pkgview.
CONFLICTS+=	ruby[1-9][0-9]-rdtool-*

REPLACE_RUBY=	rd2 rmi2html.rb utils/rdswap.rb
INSTALL_TARGET=	install install-rmi2html

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "16"
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-racc>=1.3.6:../../devel/ruby16-racc
DEPENDS+=	${RUBY_PKGPREFIX}-optparse>=0.7:../../devel/ruby-optparse
DEPENDS+=	${RUBY_PKGPREFIX}-strscan>=0.6.1:../../devel/ruby-strscan
.else
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-racc>=1.3.6:../../devel/ruby-racc
.endif

MAKE_ENV+=	RACC=${RACC}
DOCS_RD=	README.rd README.rd.ja doc/rd-draft.rd doc/rd-draft.rd.ja
DOCS=		${DOCS_RD} README.html README.html.ja \
		doc/rd-draft.html doc/rd-draft.html.ja

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} rdtoolconf.rb
	@cd ${WRKSRC}; \
		${RM} -f rd/rdinlineparser.tab.rb rd/rdblockparser.tab.rb

post-build:
.for f in ${DOCS_RD}
	cd ${WRKSRC}; ${RUBY} -I. rd2 -r rd/rd2html-lib.rb ${f} \
		> ${f:S/.rd/.html/}
.endfor

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/utils/rdswap.rb ${PREFIX}/bin/rdswap
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/rd
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rd
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/rd
	${INSTALL_DATA} ${RUBY_SITELIBDIR}/rd/dot.rd2rc ${RUBY_EXAMPLESDIR}/rd

.include "../../lang/ruby/modules.mk"
.include "../../devel/ruby-racc/raccversion.mk"
.include "../../mk/bsd.pkg.mk"
