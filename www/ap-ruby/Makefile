# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 14:13:48 taca Exp $
# $FreeBSD: ports/www/mod_ruby/Makefile,v 1.10 2000/12/31 10:14:53 knu Exp $

DISTNAME=	mod_ruby-${VERSION}
PKGNAME=	ap-${RUBY_PKGNAMEPREFIX}${VERSION}
CATEGORIES=	www
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Apache module that embeds Ruby interpreter within

DEPENDS+=	apache>=1.3.12:../../www/apache
DEPENDS+=	${RUBY_PKGNAMEPREFIX}eruby>=0.9:../../textproc/ruby-eruby

DIST_SUBDIR=	ruby
USE_RUBY=	yes
RUBY_REQD=	1.6
VERSION=	0.8.5

APXS=		${LOCALBASE}/sbin/apxs

HAS_CONFIGURE=  yes
CONFIGURE_SCRIPT= ./configure.rb
CONFIGURE_ARGS=	--with-apxs="${APXS}" \
		--with-eruby-includes="${LOCALBASE}/include" \
		--with-eruby-libraries="${LOCALBASE}/lib"

DOCS_EN=	ChangeLog README.en
DOCS_JA=	README.ja

post-build:
	${SED} -e 's|/usr/local/apache/libexec|${LOCALBASE}/lib/httpd|g' \
		${WRKSRC}/examples/httpd.conf > ${WRKDIR}/mod_ruby.conf

do-install:
	${APXS} -i -A -n ruby ${WRKSRC}/mod_ruby.so
	${INSTALL_DATA} ${WRKDIR}/mod_ruby.conf ${LOCALBASE}/etc/httpd
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mod_ruby/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mod_ruby
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mod_ruby/ja
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
