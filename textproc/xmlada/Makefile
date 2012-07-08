# $NetBSD: Makefile,v 1.4 2012/07/08 20:03:08 marino Exp $
#

DISTNAME=	xmlada-${XMLADA_VERS}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://libre.adacore.com/libre/tools/xmlada/
COMMENT=	Adacore XML suite for the Ada language
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
XMLADA_VERS=		4.2.0.0
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
SUBST_CLASSES+= 	rpath
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adjust rpaths of shared libraries
SUBST_FILES.rpath=	sax/sax.gpr
SUBST_FILES.rpath+=	dom/dom.gpr
SUBST_FILES.rpath+=	input_sources/input_sources.gpr
SUBST_FILES.rpath+=	schema/schema.gpr
SUBST_SED.rpath=	-e "s,@ADDITIONAL_RPATH@,${PREFIX}/lib,"

.include "../../mk/bsd.pkg.mk"
