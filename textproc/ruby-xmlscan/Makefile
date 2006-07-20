# $NetBSD: Makefile,v 1.2 2006/07/20 13:48:14 jlam Exp $
#

DISTNAME=	xmlscan-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-xmlscan-${VER}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/xmlscan/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.blue.sky.or.jp/atelier/ruby/xmlscan/
COMMENT=	Pure Ruby XML parser

VER=		0.2.3

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes

REPLACE_RUBY=	samples/getxmlchar.rb samples/xmlbench.rb \
		samples/xmlconftest.rb

DOCS=		ChangeLog README THANKS

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/xmlscan
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/xmlscan
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/changes.html ${RUBY_DOCDIR}/xmlscan
	${INSTALL_DATA} ${WRKSRC}/doc/changes.rd ${RUBY_DOCDIR}/xmlscan
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/xmlscan/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/conformance.html ${RUBY_DOCDIR}/xmlscan/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/conformance.rd ${RUBY_DOCDIR}/xmlscan/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/manual.html ${RUBY_DOCDIR}/xmlscan/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/manual.rd ${RUBY_DOCDIR}/xmlscan/en
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/xmlscan/ja
	${INSTALL_DATA} ${WRKSRC}/doc/ja/conformance.ja.html ${RUBY_DOCDIR}/xmlscan/ja
	${INSTALL_DATA} ${WRKSRC}/doc/ja/conformance.ja.rd ${RUBY_DOCDIR}/xmlscan/ja
	${INSTALL_DATA} ${WRKSRC}/doc/ja/manual.ja.html ${RUBY_DOCDIR}/xmlscan/ja
	${INSTALL_DATA} ${WRKSRC}/doc/ja/manual.ja.rd ${RUBY_DOCDIR}/xmlscan/ja
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/xmlscan
	cd ${WRKSRC}/samples && ${PAX} -rw -pp * ${RUBY_EXAMPLESDIR}/xmlscan

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
