# $NetBSD: Makefile,v 1.11 2005/01/28 14:08:02 taca Exp $

DISTNAME=	mod_ruby-${VERSION}
PKGNAME=	ap2-${RUBY_PKGPREFIX}-${VERSION}
PKGREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://www.modruby.net/archive/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://www.modruby.net/
COMMENT=	Embedded Ruby for Apache2 (development version)

CONFLICTS+=		ap-ruby*

RUBY_HAS_ARCHLIB=	yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
APACHE_MODULE=		yes
VERSION=		1.2.4
HAS_CONFIGURE=  	yes
INSTALL_TARGET=		site-install
CONFIGURE_SCRIPT=	${RUBY} configure.rb
CONFIGURE_ARGS+=	--with-apxs="${APXS}"
MAKE_FLAGS+= 		APACHE_INCLUDES='-I${PREFIX}/include/httpd \
				-I${PREFIX}/include/apr-0'
MESSAGE_SUBST+=		RUBY_DOCDIR=${RUBY_DOCDIR}
DOCS=			ChangeLog NOTICE README.en README.ja
REPLACE_RUBY+=		install-rb

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFVAR=		apache
PKG_SYSCONFSUBDIR?=	httpd
CONF_FILES+=		${RUBY_EXAMPLESDIR}/mod_ruby/mod_ruby.conf \
			${PKG_SYSCONFDIR}/mod_ruby.conf

post-build:
	cd ${WRKSRC}/doc; ${MAKE}
	${SED} -e 's|/usr/local/apache/libexec|${LOCALBASE}/lib/httpd|g' \
		${WRKSRC}/examples/httpd.conf > ${WRKSRC}/examples/mod_ruby.conf

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/mod_ruby/html
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mod_ruby
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.rd  ${RUBY_DOCDIR}/mod_ruby
	${INSTALL_DATA} ${WRKSRC}/doc/*.css  ${RUBY_DOCDIR}/mod_ruby/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html  ${RUBY_DOCDIR}/mod_ruby/html
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/mod_ruby
	${INSTALL_DATA} ${WRKSRC}/examples/mod_ruby.conf  \
		${RUBY_EXAMPLESDIR}/mod_ruby

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-eruby/buildlink3.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
