# $NetBSD: Makefile,v 1.2 2002/03/17 15:22:12 taca Exp $
# FreeBSD: ports/net/ruby-uri/Makefile,v 1.7 2000/12/25 15:54:08 knu Exp

DISTNAME=	uri-4.27
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://www02.so-net.ne.jp/~greentea/ruby/uri/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www02.so-net.ne.jp/%7Egreentea/ruby/uri/
COMMENT=	Ruby interface to parse URIs according to RFC 2396

RUBY_VER=	1.4		# now this is for ruby 1.4 only.

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/uri

MODULES=	uri.rb urireg.rb
DOCS=		index.html
EXAMPLES=	in-uri.txt test-uri.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/uri
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/uri
.endfor
	${MKDIR} ${RUBY_DOCDIR}/uri
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/uri
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
