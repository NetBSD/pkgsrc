# $NetBSD: Makefile,v 1.27 2008/06/20 01:09:38 joerg Exp $
#

DISTNAME=	source-highlight-2.9
SVR4_PKGNAME=	srchl
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=src-highlite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/src-highlite/
COMMENT=	Highlight syntax of various languages source into HTML document

PKG_DESTDIR_SUPPORT=	user-destdir

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
