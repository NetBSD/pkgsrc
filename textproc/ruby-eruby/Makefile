# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 14:01:56 taca Exp $
# FreeBSD: ports/textproc/eruby/Makefile,v 1.9 2000/12/12 14:04:26 knu Exp

DISTNAME=	eruby-0.9.5
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Interprets Ruby code embedded in a text file

DIST_SUBDIR=	ruby
USE_RUBY=	yes

RUBY_REQD=	1.6

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT= ./configure.rb
CONFIGURE_ARGS=	--enable-shared --with-charset="${DEFAULT_CHARSET}"
INSTALL_TARGET=	site-install

DEFAULT_CHARSET?= ISO-8859-1

MAN1=		eruby.1

DOCS_EN=	ChangeLog README.en eruby.rd eruby.html
DOCS_JA=	README.ja
EXAMPLES=	e2r.rb foo.rhtml test.rb test.rhtml

post-build:
	cd ${WRKSRC}; ${RUBY_RD} eruby.rd > eruby.html

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/eruby/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/eruby
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/eruby/ja
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/eruby
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/eruby
.endfor

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
