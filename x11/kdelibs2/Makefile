# $NetBSD: Makefile,v 1.6 2001/07/05 05:53:53 jlam Exp $
#

DISTNAME=	kdelibs-2.1
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	x11 kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Support libraries for the KDE integrated X11 desktop

USE_BUILDLINK_ONLY=	yes

.include "../../x11/kde2/Makefile.part2"

LTCONFIG_OVERRIDE+=	${WRKSRC}/ksgmltools/ltconfig

.include "../../mk/bsd.prefs.mk"

.if (defined(KJS_USE_PCRE) && ${KJS_USE_PCRE} == yes)
.include "../../devel/pcre/buildlink.mk"
.endif

CONFIGURE_ENV+=		USER_LDFLAGS="${LDFLAGS}"
LIBS+=			-Wl,--export-dynamic

MKDIRS=	share/kde/icons/locolor/32x32/actions/kde \
	share/kde/icons/locolor/22x22/mimetypes \
	share/kde/icons/locolor/22x22/filesystems \
	share/kde/icons/locolor/22x22/actions/kde \
	share/kde/icons/hicolor/22x22/mimetypes \
	share/kde/icons/hicolor/22x22/filesystems

post-install:
	for d in ${MKDIRS}; do \
		${INSTALL_DATA_DIR} ${PREFIX}/$$d; \
	done

.include "../../archivers/bzip2/buildlink.mk"
.include "../../audio/libaudiofile/buildlink.mk"
.include "../../devel/libtool/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../textproc/jade/buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
