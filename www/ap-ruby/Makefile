# $NetBSD: Makefile,v 1.10 2002/10/25 12:58:27 wiz Exp $
#

DISTNAME=	mod_ruby-${VERSION}
PKGNAME=	ap-${RUBY_PKGNAMEPREFIX}${VERSION}
CATEGORIES=	www
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Apache module that embeds Ruby interpreter within

USE_BUILDLINK2=	YES
DIST_SUBDIR=	ruby
USE_RUBY=	YES
RUBY_REQD=	1.6
VERSION=	0.9.7

HAS_CONFIGURE=  yes
CONFIGURE_SCRIPT= ./configure.rb
CONFIGURE_ARGS=	--with-apxs="${APXS}" \
		--with-eruby-includes="${BUILDLINK_PREFIX.ruby-eruby}/include" \
		--with-eruby-libraries="${BUILDLINK_PREFIX.ruby-eruby}/lib"
INSTALL_TARGET=	site-install

CONF_FILES=	${RUBY_EXAMPLESDIR}/mod_ruby/mod_ruby.conf \
		${LOCALBASE}/etc/httpd/mod_ruby.conf
FILES_SUBST+=	RUBY_DOCDIR=${RUBY_DOCDIR}
FILES_SUBST+=	RUBY_EXAMPLESDIR=${RUBY_EXAMPLESDIR}

DOCS=		ChangeLog README.en README.ja

post-build:
	${SED} -e 's|/usr/local/apache/libexec|${LOCALBASE}/lib/httpd|g' \
		${WRKSRC}/examples/httpd.conf > ${WRKDIR}/mod_ruby.conf

post-install:
	${APXS} -i -A -n ruby ${WRKSRC}/mod_ruby.so
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA} ${WRKDIR}/mod_ruby.conf  ${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mod_ruby
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mod_ruby
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../textproc/ruby-eruby/buildlink2.mk"
.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
