# $NetBSD: Makefile,v 1.28 2012/10/25 06:56:56 asau Exp $

DISTNAME=	eruby-${ERUBY_VERSION}
PKGREVISION=	8
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://modruby.net/en/index.rbx/eruby/
COMMENT=	Interprets Ruby code embedded in a text file
LICENSE=	gnu-gpl-v2

# manual page conflicts.
CONFLICTS+=	ruby[1-9][0-9]-eruby-*

# Need to update encoding processing.
RUBY_VERSION_SUPPORTED= 18

ERUBY_VERSION=		1.0.5
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${RUBY}
CONFIGURE_SCRIPT=	configure.rb
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

INSTALLATION_DIRS=	bin include lib ${RUBY_DOC}/eruby ${RUBY_EG}/eruby

post-build:
	cd ${WRKSRC}; ${RUBY_RD} eruby.rd > eruby.html

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/eruby
.endfor
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/eruby
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
