# $NetBSD: Makefile,v 1.5 2005/12/26 23:39:34 schmonz Exp $
#

DISTNAME=		kazehakase-0.3.0
CATEGORIES=		www
MASTER_SITES=		http://osdn.dl.sourceforge.jp/kazehakase/16207/ \
			http://keihanna.dl.sourceforge.jp/kazehakase/16027/

MAINTAINER=		lems@gmx.net
HOMEPAGE=		http://kazehakase.sourceforge.jp/
COMMENT=		Web browser with multiple layout engines support

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

LIBTOOL_OVERRIDE=	libtool

CONFIGURE_ARGS+=	--disable-ssl
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.kazehakase
.include "../../www/mozilla/gecko-options.mk"
.include "../../mk/bsd.options.mk"

PKG_SYSCONFSUBDIR=	kazehakase
EGDIR=		${PREFIX}/share/examples/kazehakase
EGFILES=	bookmarkbar.xml bookmarks.xml kz-ui-beginner.xml	\
		kz-ui-bookmarks.xml kz-ui-expert.xml kz-ui-medium.xml	\
		kzrc proxyrc smartbookmarks.xml
.for f in ${EGFILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

MAKE_DIRS+=	${PKG_SYSCONFDIR}/mozilla
CONF_FILES+=	${EGDIR}/mozilla/encodings.xml ${PKG_SYSCONFDIR}/mozilla/encodings.xml

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../www/mozilla/gecko-depends.mk"
.include "../../mk/bsd.pkg.mk"
