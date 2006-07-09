# $NetBSD: Makefile,v 1.20 2006/07/09 15:08:30 taca Exp $

DISTNAME=	eruby-${ERUBY_VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://modruby.net/en/index.rbx/eruby/
COMMENT=	Interprets Ruby code embedded in a text file

# manual page conflicts.
CONFLICTS+=	ruby[1-9][0-9]-eruby-*

RUBY_HAS_ARCHLIB=	yes
ERUBY_VERSION=		1.0.5
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${RUBY} configure.rb
CONFIGURE_ARGS+=	--enable-shared \
			--with-charset=${ERUBY_DEFAULT_CHARSET:Q}
INSTALL_TARGET=		site-install
PLIST_SUBST+=		ERUBY_MAJOR=${ERUBY_MAJOR:Q} \
			ERUBY_MINOR=${ERUBY_MINOR:Q} \
			ERUBY_TEENY=${ERUBY_TEENY:Q}

.include "../../mk/bsd.prefs.mk"

ERUBY_DEFAULT_CHARSET?=	ISO-8859-1
ERUBY_MAJOR=		${ERUBY_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
ERUBY_MINOR=		${ERUBY_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
ERUBY_TEENY=		${ERUBY_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\3/}
MAN1=			eruby.1
DOCS=			ChangeLog README.en README.ja eruby.rd eruby.html
EXAMPLES=		e2r.rb foo.rhtml test.rb test.rhtml

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

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
