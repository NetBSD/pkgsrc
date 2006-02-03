# $NetBSD: Makefile,v 1.11 2006/02/03 00:58:25 wiz Exp $
#

DISTNAME=	kazehakase-0.3.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=kazehakase/17700/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://kazehakase.sourceforge.jp/
COMMENT=	Web browser with multiple layout engines support

BROKEN_IN=		pkgsrc-2005Q4

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.2
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

LIBTOOL_OVERRIDE=	libtool

.include "options.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

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
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../www/mozilla/gecko-depends.mk"
.include "../../mk/bsd.pkg.mk"
