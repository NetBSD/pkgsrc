# $NetBSD: Makefile,v 1.11 2018/08/22 09:47:11 wiz Exp $

PKGREVISION= 1
.include "../../textproc/libhighlight/Makefile.common"

PKGNAME=		p5-highlight-${VERSION}
COMMENT+=		 (Perl bindings)

BUILD_DEPENDS+=		swig3-[0-9]*:../../devel/swig3

BUILD_DIRS=		extras/swig
BUILD_TARGET=		perl

USE_TOOLS+=		perl:run
CFLAGS+=		-fPIC

INSTALLATION_DIRS=	${PERL5_SUB_INSTALLVENDORARCH}/auto/highlight

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PERL_DLEXT=		bundle
SUBST_CLASSES+=		load
SUBST_STAGE.load=	pre-configure
SUBST_FILES.load=	extras/swig/makefile
SUBST_SED.load=		-e 's|-shared -s highlight_wrap\.o|-bundle -s highlight_wrap.o|g'
.else
PERL_DLEXT=		so
.endif
PLIST_SUBST+=		PERL_DLEXT=${PERL_DLEXT}

do-install:
	cd ${WRKSRC}/extras/swig && \
	${INSTALL_DATA} highlight.pm ${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORARCH}/ && \
	${INSTALL_LIB} highlight.so ${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORARCH}/auto/highlight/highlight.${PERL_DLEXT}

PERL5_LDFLAGS=		-L${PERL5_INSTALLARCHLIB}/CORE
.include "../../lang/perl5/module.mk"
.include "../../textproc/libhighlight/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
