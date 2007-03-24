# $NetBSD: Makefile,v 1.31 2007/03/24 09:37:33 taca Exp $
#

DISTNAME=	mod_ruby-${VERSION}
PKGNAME=	${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${VERSION}
CATEGORIES=	www ruby
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Apache module that embeds Ruby interpreter within

RUBY_HAS_ARCHLIB=	yes
APACHE_MODULE=		yes
PKG_APACHE_ACCEPTED=	apache13 apache2 apache22
USE_APR=		yes
VERSION=		1.2.6
HAS_CONFIGURE=  	yes
INSTALL_TARGET=		site-install
CONFIG_SHELL=		${RUBY}
CONFIGURE_SCRIPT=	configure.rb
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
MESSAGE_SUBST+=		RUBY_DOCDIR=${RUBY_DOCDIR}
DOCS=			ChangeLog NOTICE README.en README.ja
REPLACE_RUBY+=		configure.rb install-rb

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR?=	httpd
CONF_FILES+=		${RUBY_EXAMPLESDIR}/mod_ruby/mod_ruby.conf \
			${PKG_SYSCONFDIR}/mod_ruby.conf

.include "../../mk/apache.mk"

.if empty(PKG_APACHE:Mapache13)
.if empty(PKG_APACHE:Mapache22)
CONFIGURE_ARGS+=	--with-apr-includes=${PREFIX}/include/apr-0
.else
CONFIGURE_ARGS+=	--with-apr-includes=${PREFIX}/include/apr-1
.endif
.endif

post-build:
	cd ${WRKSRC}/doc; ${MAKE}
	${SED} -e 's|/usr/local/apache/libexec|${LOCALBASE}/lib/httpd|g' \
		${WRKSRC}/examples/httpd.conf > ${WRKDIR}/mod_ruby.conf

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mod_ruby/html
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mod_ruby
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.rd  ${RUBY_DOCDIR}/mod_ruby
	${INSTALL_DATA} ${WRKSRC}/doc/*.css  ${RUBY_DOCDIR}/mod_ruby/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html  ${RUBY_DOCDIR}/mod_ruby/html
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA} ${WRKDIR}/mod_ruby.conf  ${RUBY_EXAMPLESDIR}/mod_ruby

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-eruby/buildlink3.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
