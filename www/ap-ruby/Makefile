# $NetBSD: Makefile,v 1.3 2002/01/19 10:20:12 taca Exp $
# $FreeBSD: ports/www/mod_ruby/Makefile,v 1.10 2000/12/31 10:14:53 knu Exp $

DISTNAME=	mod_ruby-${VERSION}
PKGNAME=	ap-${RUBY_PKGNAMEPREFIX}${VERSION}
CATEGORIES=	www
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Apache module that embeds Ruby interpreter within

DEPENDS+=	apache>=1.3.12:../../www/apache
DEPENDS+=	${RUBY_PKGNAMEPREFIX}eruby>=0.9:../../textproc/ruby-eruby

DIST_SUBDIR=	ruby
USE_RUBY=	yes
RUBY_REQD=	1.6
VERSION=	0.9.5

APXS=		${LOCALBASE}/sbin/apxs

HAS_CONFIGURE=  yes
CONFIGURE_SCRIPT= ./configure.rb
CONFIGURE_ARGS=	--with-apxs="${APXS}" \
		--with-eruby-includes="${LOCALBASE}/include" \
		--with-eruby-libraries="${LOCALBASE}/lib"

CONF_FILES=	${RUBY_EXAMPLESDIR}/mod_ruby/mod_ruby.conf \
		${LOCALBASE}/etc/httpd/mod_ruby.conf
FILES_SUBST+=	RUBY_DOCDIR=${RUBY_DOCDIR}
FILES_SUBST+=	RUBY_EXAMPLESDIR=${RUBY_EXAMPLESDIR}

DOCS=		ChangeLog README.en README.ja

post-build:
	${SED} -e 's|/usr/local/apache/libexec|${LOCALBASE}/lib/httpd|g' \
		${WRKSRC}/examples/httpd.conf > ${WRKDIR}/mod_ruby.conf

do-install:
	${APXS} -i -A -n ruby ${WRKSRC}/mod_ruby.so
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA} ${WRKDIR}/mod_ruby.conf  ${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mod_ruby
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mod_ruby
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
