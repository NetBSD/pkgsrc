# $NetBSD: Makefile,v 1.21 2005/01/28 14:08:02 taca Exp $

DISTNAME=	FXRuby-1.0.29
PKGNAME=	${RUBY_PKGPREFIX}-fox-1.0.29
PKGREVISION=	2
CATEGORIES=	x11 ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/983/ \
		${MASTER_SITE_SOURCEFORGE:=fxruby/}
MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.fxruby.org/
COMMENT=	Ruby interface to FOX GUI library

RUBY_HAS_ARCHLIB=	yes
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
USE_X11=		yes
INSTALL_TARGET=		site-install
WRKDIST=		${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIST}/ext/fox
CONFIGURE_ARGS+= --with-fox-include=${BUILDLINK_PREFIX.fox}/include/fox
CONFIGURE_ARGS+= --with-opengl-include=${BUILDLINK_PREFIX.Mesa}/include/GL
CONFIGURE_ARGS+= --with-fox-lib=${BUILDLINK_PREFIX.fox}/lib

DEPENDS+=	${RUBY_PKGPREFIX}-opengl>=0.32:../../graphics/ruby-opengl

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
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/fox ${RUBY_DOCDIR}/fox/images
	${INSTALL_DATA} ${WRKDIST}/doc/*.html ${RUBY_DOCDIR}/fox
	${INSTALL_DATA} ${WRKDIST}/doc/images/* ${RUBY_DOCDIR}/fox/images

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/fox/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
