# $NetBSD: Makefile,v 1.26 2022/06/30 11:18:55 nia Exp $

DISTNAME=	xmlada-${XMLADA_VERS}
PKGREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.dragonlace.net/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libre.adacore.com/libre/tools/xmlada/
COMMENT=	Adacore XML suite for the Ada language
LICENSE=	gnu-gpl-v3

XMLADA_VERS=		4.4.0.0
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c ada
USE_TOOLS=		gmake makeinfo
MAKE_JOBS_SAFE=		no

# Link options were added for the sax, dom, schema, and input_sources libraries
# "-R" option disables all rpaths except adalib and compiler libs.  This is
#      done because by default the rpaths will points at the WRKOBJDIR because
#      it doesn't support the concept of DESTDIR.
# "-Wl,-R" adds a second rpath string.
# -Wl,-rpath is a better choice, but synonym -Wl,-R works on all BSD and SunOS
SUBST_CLASSES+=		rpath docs
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adjust rpaths of shared libraries
SUBST_FILES.rpath=	sax/sax.gpr
SUBST_FILES.rpath+=	dom/dom.gpr
SUBST_FILES.rpath+=	input_sources/input_sources.gpr
SUBST_FILES.rpath+=	schema/schema.gpr
SUBST_SED.rpath=	-e "s,@ADDITIONAL_RPATH@,${PREFIX}/lib,"

SUBST_STAGE.docs=	pre-configure
SUBST_MESSAGE.docs=	Set build xmlada documentation option
SUBST_FILES.docs=	Makefile.in
SUBST_SED.docs=		-e 's/^all: \(.*\)/all: \1 docs/g'

MAKE_ENV+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}

DESTSTATIC=	${DESTDIR}${PREFIX}/lib/xmlada/static
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx1
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 4.4.0.0

post-install:
	# There is no reason to install sphinx source files
	${RM} -rf ${DESTDIR}${PREFIX}/share/doc/xmlada/_sources
	# Fix static library permissions
	${CHMOD} a-x ${DESTSTATIC}/libxmlada_dom.a \
		     ${DESTSTATIC}/libxmlada_input_sources.a \
		     ${DESTSTATIC}/libxmlada_sax.a \
		     ${DESTSTATIC}/libxmlada_schema.a \
		     ${DESTSTATIC}/libxmlada_unicode.a

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
