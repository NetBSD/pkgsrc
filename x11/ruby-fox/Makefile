# $NetBSD: Makefile,v 1.1.1.1 2001/08/05 17:24:31 sakamoto Exp $

DISTNAME=	FXRuby-0.99.174
PKGNAME=	${RUBY_PKGNAMEPREFIX}fox-0.99.174
CATEGORIES=	x11
MASTER_SITES=	http://prdownloads.sourceforge.net/fxruby/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://fxruby.sourceforge.net/
COMMENT=	Ruby interface to FOX GUI library

DEPENDS+=	ruby-opengl-*:../../graphics/ruby-opengl
BUILDLINK_DEPENDS.fox=${DISTNAME:C/FXRuby/fox/}

WRKDIST=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIST}/ext/fox

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF=#defined
CONFIGURE_ARGS+=--with-fox-include=${BUILDLINK_DIR}/include/fox
CONFIGURE_ARGS+=--with-opengl-include=${BUILDLINK_DIR}/include/GL
CONFIGURE_ARGS+=--with-fox-lib=${BUILDLINK_DIR}/lib

INSTALL_TARGET=	site-install

post-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/fox
	${INSTALL_DATA} ${WRKDIST}/lib/fox/*.rb ${RUBY_SITELIBDIR}/fox
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/fox
	${INSTALL_DATA} ${WRKDIST}/examples/README ${WRKDIST}/examples/*.rb ${RUBY_EXAMPLESDIR}/fox
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/fox/icons
	${INSTALL_DATA} ${WRKDIST}/examples/icons/* \
		${RUBY_EXAMPLESDIR}/fox/icons
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/fox/textedit
	${INSTALL_DATA} ${WRKDIST}/examples/textedit/* \
		${RUBY_EXAMPLESDIR}/fox/textedit
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/fox/tests
	${INSTALL_DATA} ${WRKDIST}/tests/* ${RUBY_EXAMPLESDIR}/fox/tests
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/fox
	${INSTALL_DATA} ${WRKDIST}/doc/* ${RUBY_DOCDIR}/fox

.include "../../x11/fox/buildlink.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
