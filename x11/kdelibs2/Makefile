# $NetBSD: Makefile,v 1.18 2001/10/26 13:57:59 skrll Exp $
#

DISTNAME=	kdelibs-2.2.1
CATEGORIES=	x11 kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Support libraries for the KDE integrated X11 desktop

#DEPENDS+=		jade>=1.2.1:../../textproc/jade
USE_BUILDLINK_ONLY=	yes
USE_PERL=		yes

.include "../../x11/kde2/Makefile.part2"

LTCONFIG_OVERRIDE+=	${WRKSRC}/ksgmltools/ltconfig

USE_OPENSSL_VERSION=	${OPENSSL_VERSION_096}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_DIR}"
CONFIGURE_ENV+=		USER_LDFLAGS="${USER_LDFLAGS}"
LIBS+=			-Wl,--export-dynamic
USER_LDFLAGS=		-L${BUILDLINK_DIR}/lib
USER_LDFLAGS+=		-Wl,-R${LOCALBASE}/lib
USER_LDFLAGS+=		-Wl,-R${X11BASE}/lib

MKDIRS=	\
	share/kde/icons/hicolor/22x22/mimetypes \
	share/kde/icons/hicolor/22x22/filesystems
#	share/kde/icons/locolor/32x32/actions/kde \
#	share/kde/icons/locolor/22x22/mimetypes \
#	share/kde/icons/locolor/22x22/filesystems \
#	share/kde/icons/locolor/22x22/actions/kde \

REPLACE_PERL= \
	${WRKSRC}/kio/proxytype.pl \
	${WRKSRC}/kio/useragent.pl

post-install:
	for d in ${MKDIRS}; do \
		${INSTALL_DATA_DIR} ${PREFIX}/$$d; \
	done

BUILDLINK_DEPENDS.audiofile=  libaudiofile>=0.1.9

.include "../../archivers/bzip2/buildlink.mk"
.include "../../print/cups/buildlink.mk"
.include "../../audio/libaudiofile/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"
.include "../../devel/pcre/buildlink.mk"

.include "../../mk/bsd.pkg.mk"
