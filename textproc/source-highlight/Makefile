# $NetBSD: Makefile,v 1.26 2008/03/13 16:45:33 wiz Exp $
#

DISTNAME=	source-highlight-2.9
SVR4_PKGNAME=	srchl
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/src-highlite/
COMMENT=	Highlight syntax of various languages source into HTML document

DEPENDS+=	exctags-[0-9]*:../../devel/exctags

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
CONFIGURE_ENV+=	CTAGS=${LOCALBASE}/bin/exctags

INFO_FILES=	YES

# this is only really needed for the 'test' target
USE_TOOLS+=	gmake gsed
TEST_TARGET=	check

CONFIGURE_ARGS+=	--with-boost-regex

BUILDLINK_TRANSFORM+=	l:boost_regex:boost_regex-mt

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# We really need GNU sed not NetBSD's GNuish sed
TOOLS_PLATFORM.gsed=	# empty
.endif

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
