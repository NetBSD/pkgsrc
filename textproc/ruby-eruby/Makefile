# $NetBSD: Makefile,v 1.7 2004/03/16 02:01:11 taca Exp $
# FreeBSD: ports/textproc/eruby/Makefile,v 1.9 2000/12/12 14:04:26 knu Exp

DISTNAME=	eruby-${ERUBY_VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Interprets Ruby code embedded in a text file

DIST_SUBDIR=	ruby
USE_RUBY_RD=	yes
RUBY_REQD=	1.6
ERUBY_MAJOR=	1
ERUBY_MINOR=	0
ERUBY_TEENY=	5
ERUBY_VERSION=	${ERUBY_MAJOR}.${ERUBY_MINOR}.${ERUBY_TEENY}

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT= ./configure.rb
CONFIGURE_ARGS=	--enable-shared --with-charset="${ERUBY_DEFAULT_CHARSET}"
INSTALL_TARGET=	site-install
PLIST_SUBST+=	ERUBY_MAJOR=${ERUBY_MAJOR} ERUBY_MINOR=${ERUBY_MINOR}

.include "../../mk/bsd.prefs.mk"

ERUBY_DEFAULT_CHARSET?= ISO-8859-1

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
