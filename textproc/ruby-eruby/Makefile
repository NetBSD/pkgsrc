# $NetBSD: Makefile,v 1.4 2002/01/19 09:42:47 taca Exp $
# FreeBSD: ports/textproc/eruby/Makefile,v 1.9 2000/12/12 14:04:26 knu Exp

DISTNAME=	eruby-0.9.7
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Interprets Ruby code embedded in a text file

DIST_SUBDIR=	ruby
USE_RUBY_RD=	yes
RUBY_REQD=	1.6

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT= ./configure.rb
CONFIGURE_ARGS=	--enable-shared --with-charset="${DEFAULT_CHARSET}"
INSTALL_TARGET=	site-install

DEFAULT_CHARSET?= ISO-8859-1

MAN1=		eruby.1

DOCS=		ChangeLog README.en README.ja eruby.rd eruby.html
EXAMPLES=	e2r.rb foo.rhtml test.rb test.rhtml

post-build:
	cd ${WRKSRC}; ${RUBY_RD} eruby.rd > eruby.html

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/eruby
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/eruby
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/eruby
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${RUBY_EXAMPLESDIR}/eruby
.endfor

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
