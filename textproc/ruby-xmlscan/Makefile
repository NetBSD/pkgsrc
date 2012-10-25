# $NetBSD: Makefile,v 1.9 2012/10/25 06:56:59 asau Exp $
#

DISTNAME=	xmlscan-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-xmlscan-${VER}
PKGREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.blue.sky.or.jp/atelier/ruby/xmlscan/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.blue.sky.or.jp/atelier/ruby/xmlscan/
COMMENT=	Pure Ruby XML parser
LICENSE=	ruby-license

VER=		0.2.3

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes
USE_TOOLS+=		pax

INSTALLATION_DIRS=	${RUBY_DOC}/xmlscan/en ${RUBY_DOC}/xmlscan/ja \
			${RUBY_EG}/xmlscan

DOCS=		ChangeLog README THANKS
REPLACE_RUBY=	samples/getxmlchar.rb samples/xmlbench.rb \
		samples/xmlconftest.rb

INSTALL_TARGET=	install --destdir=${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/changes.html ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan
	${INSTALL_DATA} ${WRKSRC}/doc/changes.rd ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan
	${INSTALL_DATA} ${WRKSRC}/doc/en/conformance.html ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/conformance.rd ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/manual.html ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/manual.rd ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan/en
	${INSTALL_DATA} ${WRKSRC}/doc/ja/conformance.ja.html ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan/ja
	${INSTALL_DATA} ${WRKSRC}/doc/ja/conformance.ja.rd ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan/ja
	${INSTALL_DATA} ${WRKSRC}/doc/ja/manual.ja.html ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan/ja
	${INSTALL_DATA} ${WRKSRC}/doc/ja/manual.ja.rd ${DESTDIR}${PREFIX}/${RUBY_DOC}/xmlscan/ja
	cd ${WRKSRC}/samples && pax -rw -pp * ${DESTDIR}${PREFIX}/${RUBY_EG}/xmlscan

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
