# $NetBSD: Makefile,v 1.1.1.1 2011/02/03 18:50:53 drochner Exp $
#

DISTNAME=	xmlada-${XMLADA_VERS}-${SNAPSHOT}
PKGNAME=	xmlada-${XMLADA_VERS}
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://libre.adacore.com/libre/tools/xmlada/
COMMENT=	Adacore XML suite for the Ada language
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
XMLADA_VERS=		4.1w
SNAPSHOT=		20101125
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c # ada is not valid enumeration
USE_TOOLS=		gmake
#CONFIGURE_ENV+=		CC=gnatgcc

# no special configuration options necessary
pre-configure:
	# explicitly request GNAT-AUX compiler
	# It is done here to fool tough pkgscr compiler checks
	${SETENV} CC=gnatgcc

post-wrapper:
	# We disable at least the wrapper binaries on all GNAT AUX ports to
	# avoid potential linkage problems
	${RM} ${WRKDIR}/.wrapper/bin/*

.include "../../lang/gnat-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
