# $NetBSD: Makefile,v 1.1.1.1 2008/12/11 19:38:57 ahoka Exp $
#
# pkg-config says 1.0.2, let's combine it with the revision
# to give a sane version number.
#
DISTNAME=	WebKit-r35656
PKGNAME=	${DISTNAME:S/WebKit/webkit-gtk/:S/r/1.0.2./}
CATEGORIES=	www
MASTER_SITES=	http://nightly.webkit.org/files/trunk/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webkit.org/
COMMENT=	GTK2 port of the WebKit browser engine

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	bison gmake perl:build \
		automake autoconf autoheader \
		aclocal pkg-config bash:build

MAKE_FILE=	GNUmakefile
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-target=x11 \
			--with-http-backend=curl \
			--with-font-backend=freetype

REPLACE_PERL+=	JavaScriptCore/kjs/create_hash_table \
		JavaScriptCore/pcre/dftables \
		SunSpider/make-hosted \
		SunSpider/sunspider \
		SunSpider/sunspider-compare-results \
		WebCore/bindings/scripts/*.pl \
		WebCore/css/*.pl \
		WebCore/dom/*.pl \
		WebCore/platform/text/mac/*.pl \
		WebKit/WebKit.xcodeproj/project.pbxproj \
		WebKit/win/WebKit.vcproj/*.pl \
		WebKitTools/BuildSlaveSupport/build-launcher-app \
		WebKitTools/BuildSlaveSupport/build-launcher-dmg \
		WebKitTools/BuildSlaveSupport/run-performance-tests \
		WebKitTools/Scripts/*

pre-configure:
	cd ${WRKSRC} && ${SHELL} autogen.sh

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
# These are optional, but they need testing.
#.include "../../net/libsoup24/buildlink3.mk"
#.include "../../devel/pango/buildlink3.mk"
# A correct Webkit build requires flex 2.5.33
.include "../../devel/flex/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
