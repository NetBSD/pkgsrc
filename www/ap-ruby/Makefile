# $NetBSD: Makefile,v 1.38 2014/06/10 15:22:16 joerg Exp $
#

DISTNAME=	mod_ruby-${VERSION}
PKGNAME=	${APACHE_PKG_PREFIX}-${RUBY_PKGPREFIX}-${VERSION}
CATEGORIES=	www ruby
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Apache module that embeds Ruby interpreter within

# textproc/ruby-eruby is restricted to 1.8
RUBY_VERSION_SUPPORTED= 18

APACHE_MODULE=		yes
PKG_APACHE_ACCEPTED=	apache22
USE_APR=		yes
VERSION=		1.3.0
HAS_CONFIGURE=  	yes
INSTALL_TARGET=		site-install
INSTALLATION_DIRS=	${RUBY_DOC}/mod_ruby/html ${RUBY_EG}/mod_ruby
CONFIG_SHELL=		${RUBY}
CONFIGURE_SCRIPT=	configure.rb
CONFIGURE_ARGS+=	--with-apxs=${APXS:Q}
MESSAGE_SUBST+=		RUBY_DOC=${RUBY_DOC}
DOCS=			ChangeLog NOTICE README.en README.ja
REPLACE_RUBY+=		configure.rb install-rb


.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR?=	httpd
CONF_FILES+=		${PREFIX}/${RUBY_EG}/mod_ruby/mod_ruby.conf \
			${PKG_SYSCONFDIR}/mod_ruby.conf

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-build
SUBST_FILES.path=	examples/httpd.conf
SUBST_SED.path=		-e 's|/usr/local/apache/libexec|${PREFIX}/lib/httpd|g'
SUBST_MESSAGE.path=	Fixing configuration files.

post-build:
	cd ${WRKSRC}/doc; ${MAKE}

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/mod_ruby
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.rd  ${DESTDIR}${PREFIX}/${RUBY_DOC}/mod_ruby
	${INSTALL_DATA} ${WRKSRC}/doc/*.css  ${DESTDIR}${PREFIX}/${RUBY_DOC}/mod_ruby/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html  ${DESTDIR}${PREFIX}/${RUBY_DOC}/mod_ruby/html
	${INSTALL_DATA} ${WRKSRC}/examples/httpd.conf ${DESTDIR}${PREFIX}/${RUBY_EG}/mod_ruby/mod_ruby.conf

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-eruby/buildlink3.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
