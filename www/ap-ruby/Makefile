# $NetBSD: Makefile,v 1.17 2004/05/04 23:46:37 snj Exp $
#

DISTNAME=	mod_ruby-${VERSION}
PKGNAME=	ap-${RUBY_PKGNAMEPREFIX}${VERSION}
CATEGORIES=	www ruby
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Apache module that embeds Ruby interpreter within

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
APACHE_MODULE=	YES
DIST_SUBDIR=	ruby
USE_RUBY=	YES
RUBY_REQD=	1.6
VERSION=	1.0.7

HAS_CONFIGURE=  yes
CONFIGURE_SCRIPT= ./configure.rb
CONFIGURE_ARGS=	--with-apxs="${APXS}" \
		--with-eruby-includes="${BUILDLINK_PREFIX.ruby-eruby}/include" \
		--with-eruby-libraries="${BUILDLINK_PREFIX.ruby-eruby}/lib"
INSTALL_TARGET=	site-install

FILES_SUBST+=	RUBY_DOCDIR=${RUBY_DOCDIR}
FILES_SUBST+=	RUBY_EXAMPLESDIR=${RUBY_EXAMPLESDIR}
MESSAGE_SUBST+=	RUBY_DOCDIR=${RUBY_DOCDIR}

DOCS=		ChangeLog README.en README.ja
HTMLDOCS=	classes.en.html directives.en.html faq.en.html \
		index.en.html install.en.html \
		classes.ja.jis.html directives.ja.jis.html faq.ja.jis.html \
		index.ja.jis.html install.ja.jis.html

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR?=	httpd
CONF_FILES+=		${RUBY_EXAMPLESDIR}/mod_ruby/mod_ruby.conf \
			${PKG_SYSCONFDIR}/mod_ruby.conf

post-build:
	cd ${WRKSRC}/doc; ${MAKE}
	${SED} -e 's|/usr/local/apache/libexec|${LOCALBASE}/lib/httpd|g' \
		${WRKSRC}/examples/httpd.conf > ${WRKDIR}/mod_ruby.conf

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mod_ruby
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mod_ruby
.endfor
.for f in ${HTMLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${RUBY_DOCDIR}/mod_ruby
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA} ${WRKDIR}/mod_ruby.conf  ${RUBY_EXAMPLESDIR}/mod_ruby

.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../textproc/ruby-eruby/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
