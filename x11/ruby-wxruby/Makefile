# $NetBSD: Makefile,v 1.39 2022/01/16 14:29:29 taca Exp $
#

DISTNAME=	wxruby-2.0.1
PKGREVISION=	29
CATEGORIES=	x11
MASTER_SITES=	# http://rubyforge.org/frs/download.php/63379/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://wxruby.rubyforge.org/wiki/wiki.pl
COMMENT=	Cross-platform GUI library for creating desktop applications
LICENSE=	mit

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-redcloth>=4.2.0:../../textproc/ruby-redcloth

RUBY_VERSIONS_INCOMPATIBLE=	30 31

BUILD_TARGET=		default html_docs
RAKE=			${RAKE_NAME} -I "./lib"
USE_LANGUAGES=		c++
USE_TOOLS=		pax
REPLACE_RUBY_DIRS=	samples

MAKE_ENV+=		DESTDIR=${DESTDIR:Q}
INSTALLATION_DIRS+=	${RUBY_DOC}/wxruby ${RUBY_EG}/wxruby \
			${RUBY_VENDORLIB}/wx ${RUBY_VENDORARCHLIB}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	rake/rakenetbsd.rb
SUBST_VARS.path=	PREFIX
SUBST_MESSAGE.path=	Fixing include path.

pre-configure:
	cd ${WRKSRC}; ${FIND} . -type f -exec ${CHMOD} -x {} \;

do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RAKE} ${BUILD_TARGET}

do-install:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RAKE} ${INSTALL_TARGET}

post-install:
	cd ${WRKSRC}/doc/html; pax -rw . ${DESTDIR}${PREFIX}/${RUBY_DOC}/wxruby
	cd ${WRKSRC}/samples; \
		pax -rw -pm . ${DESTDIR}${PREFIX}/${RUBY_EG}/wxruby

.include "../../x11/wxGTK28-contrib/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
