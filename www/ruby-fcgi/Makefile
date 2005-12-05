# $NetBSD: Makefile,v 1.9 2005/12/05 20:51:14 rillig Exp $

DISTNAME=		ruby-fcgi-${VER}
PKGNAME=		${RUBY_PKGPREFIX}-fcgi-${VER}
CATEGORIES=		www devel ruby
MASTER_SITES=   	http://sugi.nemui.org/pub/ruby/fcgi/

MAINTAINER=		rasputnik@hellooperator.net
HOMEPAGE=		http://sugi.nemui.org/prod/ruby-fcgi/
COMMENT=		FastCGI interface for Ruby

USE_RUBY_SETUP=		yes
RUBY_SETUP=		install.rb
RUBY_EXTCONF_SUBDIRS=	ext/fcgi
VER=			0.8.6
CONFIGURE_ARGS+=	-- --with-fcgi-dir=${PREFIX}
DOCS=			README README.signals

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/fcgi
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/fcgi
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
