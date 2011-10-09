# $NetBSD: Makefile,v 1.2 2011/10/09 22:29:44 marino Exp $
#

DISTNAME=	xmlada-${XMLADA_VERS}
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
USE_LANGUAGES=		c # ada is not valid enumeration
USE_TOOLS=		gmake makeinfo
MAKE_JOBS_SAFE=		no

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
